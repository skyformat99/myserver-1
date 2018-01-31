//
// Created by dguco on 18-1-27.
//

#include <my_assert.h>
#include "buffev_interface.h"

IBufferEvent::IBufferEvent()
	: m_pReactor(NULL),
	  m_pStBufEv(NULL),
	  m_uMaxOutBufferSize(MAX_PACKAGE_LEN),
	  m_uMaxInBufferSize(MAX_PACKAGE_LEN),
	  m_uRecvPackLen(0)
{

}

IBufferEvent::IBufferEvent(IEventReactor *pReactor,
						   bufferevent *buffevent)
	: m_pReactor(pReactor),
	  m_pStBufEv(buffevent),
	  m_uMaxOutBufferSize(MAX_PACKAGE_LEN),
	  m_uMaxInBufferSize(MAX_PACKAGE_LEN),
	  m_uRecvPackLen(0)
{

}

IBufferEvent::~IBufferEvent()
{
	if (m_pStBufEv != NULL) {
		bufferevent_free(m_pStBufEv);
	}
}

PipeResult IBufferEvent::Send(const void *pData, unsigned int uSize)
{
	if (uSize > m_uMaxOutBufferSize) {
		return ePR_OutPipeBuf;
	}

	MY_ASSERT(IsEventBuffAvailable(), return ePR_BufNull);
	bufferevent_write(m_pStBufEv, pData, uSize);
	return ePR_OK;
}

unsigned int IBufferEvent::RecvData(char *data, unsigned int size)
{
	MY_ASSERT(IsEventBuffAvailable(), return 0);
	return bufferevent_read(m_pStBufEv, data, size);
}

PACK_LEN IBufferEvent::GetRecvPackLen()
{
	//包头前两个字节为数据总长度，如果数据长度小于两个字节返回0
	if (GetRecvDataSize() < sizeof(PACK_LEN)) {
		return 0;
	}
	RecvData((char *) (&m_uRecvPackLen), sizeof(PACK_LEN));
	m_uRecvPackLen = ntohs(m_uRecvPackLen);
	return m_uRecvPackLen;
}

unsigned int IBufferEvent::GetRecvDataSize()
{
	MY_ASSERT(IsEventBuffAvailable(), return 0);
	struct evbuffer *in = bufferevent_get_input(m_pStBufEv);
	MY_ASSERT(in != NULL, return 0);
	return evbuffer_get_length(in);
}

unsigned int IBufferEvent::GetSendDataSize()
{
	MY_ASSERT(IsEventBuffAvailable(), return 0);
	struct evbuffer *out = bufferevent_get_output(m_pStBufEv);
	MY_ASSERT(out != NULL, return 0);
	return evbuffer_get_length(out);
}

void IBufferEvent::SetMaxSendBufSize(unsigned int uSize)
{
	MY_ASSERT(IsEventBuffAvailable() && uSize > 0, return;);
	m_uMaxOutBufferSize = uSize;
	bufferevent_setwatermark(m_pStBufEv, EV_WRITE, 0, m_uMaxOutBufferSize);
}

template<unsigned int RECV_BUFFLEN>
unsigned int IBufferEvent::GetMaxSendBufSize()
{
	return m_uMaxOutBufferSize;
}

void IBufferEvent::SetMaxRecvBufSize(unsigned int uSize)
{
	MY_ASSERT(IsEventBuffAvailable() && uSize > 0, return;);
	m_uMaxInBufferSize = uSize;
	bufferevent_setwatermark(m_pStBufEv, EV_READ, 0, m_uMaxInBufferSize);
}

bool IBufferEvent::IsEventBuffAvailable()
{
	if (m_pStBufEv == NULL) {
		BuffEventAvailableCall();
		return false;
	}
	return true;
}

PACK_LEN IBufferEvent::GetRecvPackLen() const
{
	return m_uRecvPackLen;
}

void IBufferEvent::CurrentPackRecved()
{
	m_uRecvPackLen = 0;
}

unsigned int IBufferEvent::GetMaxRecvBufSize()
{
	return m_uMaxInBufferSize;
}

bool IBufferEvent::RegisterToReactor()
{
	m_pStBufEv = bufferevent_socket_new(GetReactor()->GetEventBase(),
										-1,
										BEV_OPT_CLOSE_ON_FREE | BEV_OPT_THREADSAFE);
	bufferevent_setwatermark(m_pStBufEv, EV_READ, 0, m_uMaxInBufferSize);
	bufferevent_setwatermark(m_pStBufEv, EV_WRITE, 0, m_uMaxOutBufferSize);
	MY_ASSERT_STR(NULL != m_pStBufEv, return false, "BufferEvent_new failed!!");
	AfterBuffEventCreated();
	return true;
}

IEventReactor *IBufferEvent::GetReactor()
{
	return m_pReactor;
}

bool IBufferEvent::UnRegisterFromReactor()
{
	bufferevent_disable(m_pStBufEv, EV_READ | EV_WRITE);
	return true;
}