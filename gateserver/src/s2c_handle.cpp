//
// Created by dguco on 18-1-30.
//

#include <sharemem.h>
#include <my_assert.h>
#include <commondef.h>
#include <acceptor.h>
#include "net_work.h"
#include "../inc/s2c_handle.h"
#include "../inc/gate_def.h"

CS2cHandle::CS2cHandle()
	: m_iSendIndex(0),
	  m_bHasRecv(false),
	  m_iSCIndex(0),
	  m_nSCLength(0)
{
	int iTempSize = sizeof(CSharedMem) + CCodeQueue::CountQueueSize(PIPE_SIZE);
	system("touch ./scpipefile");
	char *pcTmpSCPipeID = getenv("SC_PIPE_ID");
	int iTmpSCPipeID = 0;
	if (pcTmpSCPipeID) {
		iTmpSCPipeID = atoi(pcTmpSCPipeID);
	}
	key_t iTmpKeyS2C = MakeKey("./scpipefile", iTmpSCPipeID);
	BYTE *pbyTmpS2CPipe = CreateShareMem(iTmpKeyS2C, iTempSize);
	MY_ASSERT(pbyTmpS2CPipe != NULL, exit(0));
	CSharedMem::pbCurrentShm = pbyTmpS2CPipe;
	CCodeQueue::pCurrentShm = CSharedMem::CreateInstance(iTmpKeyS2C, iTempSize, EIMode::SHM_INIT);
	m_pS2CPipe = CCodeQueue::CreateInstance(PIPE_SIZE, IDX_PIPELOCK_S2C);
}

CS2cHandle::~CS2cHandle()
{

}

int CS2cHandle::PrepareToRun()
{
	return 0;
}

int CS2cHandle::Run()
{
	while (true) {
		CondBlock();
		CheckWaitSendData();
	}
}

bool CS2cHandle::IsToBeBlocked()
{
	return m_pS2CPipe->IsQueueEmpty();
}

bool CS2cHandle::CheckData()
{
	if (!m_pS2CPipe->IsQueueEmpty()) {
		WakeUp();
	}
}

void CS2cHandle::CheckWaitSendData()
{
	int iTmpRet = 0;
	int i = 0;
	int unTmpCodeLength = 0;

	if (m_iSendIndex < m_oMesHead.socketinfos().size()) {
		//有数据未发送，继续发送
		SendClientData();
	}
	else {
		//当前没有接收到数据，先接收数据
		if (false == m_bHasRecv) {
			//没有可发送的数据或者发送完成,则接收gate数据
			iTmpRet = RecvServerData();
			//没有数据可接收，则发送队列无数据发送，退出
			if (iTmpRet == 0) {
				break;
			}
			m_bHasRecv = true;
		}//处理已经接收到的数据
		else {
			//组织服务器发送到客户端的数据信息头，设置相关索引和游标
			m_iSendIndex = 0;
			m_iSCIndex = 0;
			m_nSCLength = 0;
			//反序列化消息的CTcpHead,取出发送游标和长度,把数据存入发送消息缓冲区m_szMsgBuf
			iTmpRet = ClientCommEngine::ConvertStreamToMessage(m_acSCMsgBuf,
															   unTmpCodeLength,
															   &m_MesHead,
															   NULL,
															   NULL,
															   &m_iSendIndex);
			//序列化失败继续发送
			if (iTmpRet < 0) {
				LOG_ERROR("default",
						  "CTCPCtrl::CheckWaitSendData Error, ClientCommEngine::ConvertMsgToStream return %d.",
						  iTmpRet);
				m_MesHead.Clear();
				m_iSendIndex = 0;
				continue;
			}

			//接收成功,取出数据长度
			char *pTmp = m_acSCMsgBuf;
			pTmp += m_iSCIndex;
			m_nSCLength = *(unsigned short *) pTmp;
		}
	}
}

int CS2cHandle::SendClientData()
{
	BYTE *pbTmpSend = NULL;
	unsigned short unTmpShort;
	time_t tTmpTimeStamp;
	int iTmpSendBytes;
	int nTmpIndex;
	unsigned short unTmpPackLen;
	int iTmpCloseFlag;

	auto *pSendList = m_oMesHead.mutable_socketinfos();
	//client socket索引非法，不存在要发送的client
	if (m_iSendIndex >= pSendList->size())
		return 0;
	CSocketInfo tmpSocketInfo = pSendList->Get(m_iSendIndex);

	//向后移动socket索引
	m_iSendIndex++;
	nTmpIndex = tmpSocketInfo.socketid();
	tTmpTimeStamp = tmpSocketInfo.createtime();

	//socket 非法
	if (nTmpIndex <= 0 || MAX_SOCKET_NUM <= nTmpIndex) {
		LOG_ERROR("default", "Invalid socket index %d", nTmpIndex);
		return -1;
	}

	/*
	 * 时间不一样，说明这个socket是个新的连接，原来的连接已经关闭,注(原来的
	 * 的连接断开后，新的客户端用了原来的socket fd ，因此数据不是现在这个连
	 * 接的数据，原来连接的数据,中断发送
	*/
	// 该过程需要在线程锁内完成
	{
#ifdef _POSIX_MT_
		std::lock_guard<std::mutex> guard(CNetWork::m_stMutex);
#endif
		CAcceptor *pTmpAcceptor = CNetWork::GetSingletonPtr()->FindAcceptor(tmpSocketInfo.socketid());
		if (pTmpAcceptor == NULL) {
			LOG_ERROR("default", "CAcceptor has gone socket %d", tmpSocketInfo.socketid());
			return -1;
		}
		if (pTmpAcceptor->GetCreateTime() != tTmpTimeStamp) {
			LOG_ERROR("default", "sokcet[%d] already closed(tcp createtime:%d:gate createtime:%d) : gate ==> client[%d] bytes \
                failed", nTmpIndex, pTmpAcceptor->GetCreateTime(), tTmpTimeStamp, m_nSCLength);
			return -1;
		}
		iTmpCloseFlag = tmpSocketInfo.state();
		unTmpPackLen = m_nSCLength;
		//发送数据
		if (unTmpPackLen > 0) {
			//根据发送给客户端的数据在m_szSCMsgBuf中的数组下标取出数据
			pbTmpSend = (BYTE *) m_acSCMsgBuf[m_iSCIndex];
			memcpy((void *) &unTmpShort, (const void *) pbTmpSend, sizeof(unsigned short));
			if (unTmpShort != unTmpPackLen) {
				LOG_ERROR("default",
						  "Code length not matched,left length %u is less than body length %u",
						  unTmpPackLen,
						  unTmpShort);
				return -1;
			}
			iTmpSendBytes = TcpWrite(m_pSocketInfo->m_iSocket, (char *) pbTmpSend, unTmpPackLen);
			if (unTmpPackLen == iTmpSendBytes) {
#ifdef _DEBUG_
				LOG_DEBUG("default", "[us:%lu]TCP gate ==> client[%d][%s][%d Bytes]", GetUSTime(), nTmpIndex, \
                    m_astSocketInfo[nTmpIndex].m_szClientIP, iTmpSendBytes);
#endif
				//统计信息
				m_stTcpStat.m_iPkgSend++;
				m_stTcpStat.m_iPkgSizeSend += iTmpSendBytes;
				//设置发送标志位已发送
				m_pSocketInfo->m_iSendFlag = MAIN_HAVE_SEND_DATA;
			}
			else {
				//发送失败
				ClearSocketInfo(Err_ClientClose);
				LOG_ERROR("default", "send to client %s Failed due to error %d", m_pSocketInfo->m_szClientIP, errno);
				return 0;
			}
		}
		if (unTmpPackLen > 0 && iTmpCloseFlag == 0) {
			return 0;
		}

		if (iTmpCloseFlag == -1) {
			//
		}
		ClearSocketInfo(TCP_SUCCESS);
		return 0;
	}
}

int CS2cHandle::RecvServerData()
{
	int unTmpCodeLength = MAX_PACKAGE_LEN;
	if (m_pS2CPipe->GetHeadCode((BYTE *) m_acSCMsgBuf, &unTmpCodeLength) < 0) {
		unTmpCodeLength = 0;
	}
	return unTmpCodeLength;
}