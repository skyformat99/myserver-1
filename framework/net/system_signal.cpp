#include "system_signal.h"

CSystemSignal::CSystemSignal(IEventReactor *pReactor,uint32 uSignal, FuncOnSignal pFunc, void *pContext)
	: m_pReactor(pReactor),
      m_pFuncOnSignal(pFunc),
      m_iSignal(uSignal),
      m_pContext(pContext)
{
}

CSystemSignal::~CSystemSignal()
{
	event_del(&m_event);
}

IEventReactor *CSystemSignal::GetReactor()
{
	return m_pReactor;
}

void CSystemSignal::RegisterSignal()
{
	GetReactor()->Register(this);
}

bool CSystemSignal::RegisterToReactor()
{
	event_set(&m_event, m_iSignal, EV_SIGNAL, lcb_OnSignal, this);
	event_base_set(GetReactor()->GetEventBase(), &m_event);
	event_add(&m_event, NULL);
	return true;
}

void CSystemSignal::lcb_OnSignal(int fd, short event, void *arg)
{
	CSystemSignal *pSignal = static_cast<CSystemSignal *>(arg);
	pSignal->OnSignalReceive();
}

void CSystemSignal::OnSignalReceive()
{
	if (m_iSignal == EVENT_SIGNAL(&m_event)) {
		m_pFuncOnSignal(m_iSignal, m_pContext);
	}
}