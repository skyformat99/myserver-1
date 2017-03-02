#include <stdarg.h>
#include <string.h>

#include "../base/base.h"
#include "thread.h"
#include "../log/log.h"

void* ThreadProc( void *pvArgs )
{
	if( !pvArgs )
	{
		return NULL;
	}

	CThread *pThread = (CThread *)pvArgs;

	if( pThread->PrepareToRun() )  // handle
	{
		return NULL;
	}

	pThread->Run();

	return NULL;
}

CThread::CThread()
{
	m_iRunStatus = rt_init;
	memset((void *)&m_stLogCfg, 0, sizeof(m_stLogCfg));
}
CThread::~CThread()
{
}

int CThread::CreateThread()
{
	pthread_attr_init( &m_stAttr );
	// 设置线程状态为与系统中所有线程一起竞争CPU时间
	pthread_attr_setscope( &m_stAttr, PTHREAD_SCOPE_SYSTEM );  
	/*
	 *设置线程的分离状态为PTHREAD_CREATE_JOINABLE或PTHREAD_CREATE_DETACHED。
	 *默认是joinable，有一些资源会在线程结束后仍然保持占用状态，直到另外的线程对
	 *这个线程使用pthread_join。detached线程不是这样子的，它没有被其他的线程所等
	 *待（join），自己运行结束了，线程也就终止了，马上释放系统资源。
	 *若成功返回0，若失败返回-1。
	*/
	//pthread_attr_setdetachstate( &m_stAttr, PTHREAD_CREATE_DETACHED );
	pthread_attr_setdetachstate( &m_stAttr, PTHREAD_CREATE_JOINABLE );  

	pthread_cond_init( &m_stCond, NULL );
	pthread_mutex_init( &m_stMutex, NULL );
	m_iRunStatus = rt_running;

	pthread_create( &m_hTrd, &m_stAttr, ThreadProc, (void *)this );

	return 0;
}

int CThread::CondBlock()
{
	// 该过程需要在线程锁内完成
	pthread_mutex_lock( &m_stMutex );

	// 线程被阻塞或者停止
	while( IsToBeBlocked() || m_iRunStatus == rt_stopped )  
	{
		// 如果线程需要停止则终止线程
		if( m_iRunStatus == rt_stopped )  
		{
			ThreadLogDebug( "Thread exit.");
			pthread_exit( (void *)m_abyRetVal );
		}
		ThreadLogDebug( "Thread would blocked." );
		m_iRunStatus = rt_blocked;
		// 进入休眠状态
		pthread_cond_wait( &m_stCond, &m_stMutex );  
	}

	if( m_iRunStatus != rt_running )  
	{
		ThreadLogDebug( "Thread waked up.");
	}

	// 线程状态变为rt_running
	m_iRunStatus = rt_running;  
	pthread_mutex_unlock( &m_stMutex );  

	return 0;
}

int CThread::WakeUp()
{
	// 该过程需要在线程锁内完成
	pthread_mutex_lock( &m_stMutex );

	if( !IsToBeBlocked() && m_iRunStatus == rt_blocked )
    {
		// 向线程发出信号以唤醒
		pthread_cond_signal( &m_stCond );  
	}

	pthread_mutex_unlock( &m_stMutex );

	return 0;
}

int CThread::StopThread()
{
	pthread_mutex_lock( &m_stMutex );

	m_iRunStatus = rt_stopped;
	pthread_cond_signal( &m_stCond );

	pthread_mutex_unlock( &m_stMutex );

	// 等待该线程终止
	pthread_join( m_hTrd, NULL );
	ThreadLogDebug("Thread stopped.");

	return 0;
}

void CThread::ThreadLogInit(char *sPLogBaseName, long lPMaxLogSize, int iPMaxLogNum, int iShow, int iLevel /*= 0*/)
{
	memset(m_stLogCfg.szLogBaseName, 0, sizeof(m_stLogCfg.szLogBaseName));
	strncpy(m_stLogCfg.szLogBaseName, sPLogBaseName, sizeof(m_stLogCfg.szLogBaseName)-1);
	m_stLogCfg.lMaxLogSize = lPMaxLogSize;
	m_stLogCfg.iMaxLogNum = iPMaxLogNum;
	strncpy( m_stLogCfg.szThreadKey, m_stLogCfg.szLogBaseName, sizeof( m_stLogCfg.szThreadKey )-1 ) ;
	
	INIT_ROLLINGFILE_LOG( m_stLogCfg.szThreadKey, m_stLogCfg.szLogBaseName, (LogLevel) iLevel, m_stLogCfg.lMaxLogSize, m_stLogCfg.iMaxLogNum ); 
}

void CThread::ThreadLogDebug(const char *sFormat, ...)
{
	va_list va;
	va_start( va, sFormat );
	LogDebug_va( m_stLogCfg.szThreadKey, sFormat, va );
	va_end( va );
}

void CThread::ThreadLogInfo(const char *sFormat, ...)
{
	va_list va;
	va_start( va, sFormat );
	LogInfo_va( m_stLogCfg.szThreadKey, sFormat, va );
	va_end( va );
}

void CThread::ThreadLogNotice(const char *sFormat, ...)
{
	va_list va;
	va_start( va, sFormat );
	LogNotice_va( m_stLogCfg.szThreadKey, sFormat, va );
	va_end( va );
}

void CThread::ThreadLogWarn(const char *sFormat, ...)
{
	va_list va;
	va_start( va, sFormat );
	LogWarn_va( m_stLogCfg.szThreadKey, sFormat, va );
	va_end( va );
}

void CThread::ThreadLogError(const char *sFormat, ...)
{
	va_list va;
	va_start( va, sFormat );
	LogError_va( m_stLogCfg.szThreadKey, sFormat, va );
	va_end( va );
}

void CThread::ThreadLogFatal(const char *sFormat, ...)
{
	va_list va;
	va_start( va, sFormat );
	LogFatal_va( m_stLogCfg.szThreadKey, sFormat, va );
	va_end( va );
}
