//
//  gate_handle.h
//  gate_handle 管理类头文件
//  Created by DGuco on 16/12/6.
//  Copyright © 2016年 DGuco. All rights reserved.
//

#ifndef _GATE_HANDLE_H_
#define _GATE_HANDLE_H_

#include <map>
#include "../../framework/thread/thread.h"
#include "../../framework/json/config.h"
#include "gate_conn.h"


enum EMHandleType {
	EHandleType_FIRST 	= 0,
	EHandleType_SECOND 	= 1,
	EHandleType_THIRD 	= 2,
	EHandleType_NUM 	= 3
};

#define MAXSVRNUMBER (6) 								// 单个线程最大连接数量
#define MAX_CONNS_NUM (MAXSVRNUMBER*EHandleType_NUM) 	// 所有线程最大连接数量
#define MAXCLEANBLOCKCODES (512)

struct TStatLog {
	int iRcvCnt;
	int iRcvSize;
	int iRcvErrCnt;
	int iSndCnt;
	int iSndSize;
	int iClnCnt;
	int iClnSize;

	TStatLog() {
		Clear();
	}

	void Clear() {
		iRcvCnt = 0;
		iRcvSize = 0;
		iRcvErrCnt = 0;
		iSndCnt = 0;
		iSndSize = 0;
		iClnCnt = 0;
		iClnSize = 0;
	}
};

// 通过handletype和遍历时的参数i，获取conn的数组下标
#define GETCURRENTHANDLEID(handletype ,i) (handletype + (i * EHandleType_NUM))


typedef std::map<int, CMyTCPConn*> CONNS_MAP;

class CGateHandle : public CThread
{
public:
	CGateHandle();
	virtual ~CGateHandle();

	int Initialize(EMHandleType eHandleType, CDoubleLinkerInfo* pInfo, CONNS_MAP* pMap);

	virtual int PrepareToRun() ;
	virtual int Run() ;
	virtual bool IsToBeBlocked();

private:

	// 转发数据
	int DoTransfer();
	// 转发一个数据包
	int TransferOneCode(short nCodeLength, BYTE* pbyCode);
	// 通过FE和ID创建KEY
	int MakeConnKey(const short nType, const short nID);
	// 通过KEY获取连接信息
	CMyTCPConn* GetConnByKey(int iKey);
	// 发送数据
	int SendOneCodeTo(short nCodeLength, BYTE* pbyCode, int  iKey, bool bKeepalive = false);
	// 检测被block的数据
	int CheckBlockCodes();
	// 检测发送信息
	void CheckStatLog();

	timeval m_tvLastCheck;

	EMHandleType m_eHandleType;

	CDoubleLinkerInfo* m_pInfo;
	CONNS_MAP* m_pConnsMap;

	TStatLog m_stStatLog;
	time_t m_tCheckStatLog;
};

#endif // _GATE_HANDLE_H_
