//
// Created by DGuco on 17-7-13.
//

#ifndef _DBCTRL_HPP_
#define _DBCTRL_HPP_

#include "dbhandle.h"
#include "net_work.h"
#include "thread_pool.h"

//#include "protoconfig.h"

#ifdef _ASYNC_SQL_
#include "asqlexe.h"
#endif

#define MAXPROXYNUMBER                2                    // 最大proxy server 数目

#define MAXHANDLENUMBER                2

#define SECSOFONEHOUR                3600

#define CHECKINTERVAL                10                    // 检查时间间隔，单位：秒
#define PROXYKEEPALIVESECONDS        (3*CHECKINTERVAL)    // 与proxy的心跳超时时间
#define MAXPROXYCODELEN                1024                // 向proxy发送纯命令的最大块长度
#define STATISTICSLEN                1024
#define MAXNUMBERLEN                10
#define SAVEINTERVAL                300


class CSharedMem;

class CDBCtrl: public CSingleton<CDBCtrl>
{
public:
	CDBCtrl();
	~CDBCtrl();

	int Initialize();
	int PrepareToRun();
	int Run();

	// 运行标志
	enum ERunFlag
	{
		EFLG_CTRL_NO = 0,
		EFLG_CTRL_QUIT = 1,
		EFLG_CTRL_SHUTDOWN = 2,
		EFLG_CTRL_RELOAD = 3
	};

	void SetRunFlag(int iFlag);
	void ClearRunFlag(int iFlag);
	bool IsRunFlagSet(int iFlag);
	int SendMessageTo(CProxyMessage *pMsg);
	int Event(CProxyMessage *pMsg);
	int ProcessExecuteSqlRequest(CProxyMessage *pMsg);
	void ReleaseResult(QueryResult *res)
	{
		if (res != NULL) {
			delete res;
			res = NULL;
		}
	}
private:
	int ConnectToProxyServer();
	int RegisterToProxyServer();
	int SendkeepAliveToProxy();     // 向proxy发送心跳消息
	int DispatchOneCode(int nCodeLength, BYTE *pbyCode);
private:
	static void lcb_OnConnected(CConnector *pConnector);
	//断开连接回调
	static void lcb_OnCnsDisconnected(CConnector *pConnector);
	//客户端上行数据回调
	static void lcb_OnCnsSomeDataRecv(CConnector *pConnector);
	static void lcb_OnConnectFailed(CConnector *pConnector);
	static void lcb_OnCnsSomeDataSend(CConnector *pConnector);
	static void lcb_OnPingServer(CConnector *pConnector);
private:
	int m_iRunFlag;    // 运行标志
	time_t m_tLastSendKeepAlive;        // 最后发送proxy心跳消息时间
	time_t m_tLastRecvKeepAlive;        // 最后接收proxy心跳消息时间
	time_t m_lastTick;
	Database *m_pDatabase;
	CMessageFactory *mMsgFactory;
	CProxyHead m_stCurrentProxyHead;    //当前处理请求的Proxy头部
	CNetWork *m_pNetWork;
private:
	static char m_acRecvBuff[MAX_PACKAGE_LEN];
	static int m_iProxyId;
};

#endif


