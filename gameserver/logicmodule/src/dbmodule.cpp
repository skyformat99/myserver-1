//
// Created by dguco on 17-9-12.
//

#include "../inc/dbmodule.h"
#include "../../inc/gameserver.h"
#include "../../inc/sceneobjmanager.h"
#include "../../../framework/message/server_comm_engine.h"
#include "../../../framework/message/player.pb.h"
#include "../../../framework/message/client_comm_engine.h"

using namespace slg::protocol;

template<> CDbModule* CSingleton<CDbModule>::spSingleton = NULL;

CDbModule::CDbModule() {

}

CDbModule::~CDbModule() {

}

int CDbModule::OnLaunchServer()
{

}

int CDbModule::OnExitServer()
{

}

void CDbModule::OnRouterMessage(CProxyMessage *pMsg)
{
    MY_ASSERT_LOG("db", pMsg != NULL , return );
    switch(pMsg->msghead().messageid())
    {
        case CMsgExecuteSqlResponse::MsgID:
        {
            OnMsgExecuteSqlResponse(pMsg);
            break;
        }
        default:
        {
            LOG_ERROR("db", "[%s : %d : %s] invalid message id(%8x).",
                      __MY_FILE__, __LINE__, __FUNCTION__, pMsg->msghead().messageid());
            break;
        }
    }
}

void CDbModule::OnClientMessage(CPlayer *pTeam,CMessage *pMsg)
{

}

int CDbModule::OnCreateEntity(CPlayer *pTeam)
{

}

void CDbModule::OnDestroyEntity(CPlayer *pTeam)
{

}

void CDbModule::OnMsgExecuteSqlResponse(CProxyMessage* pMsg) {
    MY_ASSERT_LOG("db", pMsg != NULL, return);
    CMsgExecuteSqlResponse *pTmpSqlRsp = (CMsgExecuteSqlResponse *) pMsg->msgpara();
    MY_ASSERT_LOG("db", pTmpSqlRsp != NULL, return);

    CSession *pTmpSession = NULL;
    if (pTmpSqlRsp->sessionid() != 0) {
        // 如果有session
        pTmpSession = (CSession *) CTimerManager::GetSingletonPtr()->GetObject(pTmpSqlRsp->sessionid());

        if (NULL == pTmpSession) {
            LOG_ERROR("db", "[%s : %d : %s] Session doesn't exsit (logictype:%d:sessionid:%u ), has been deleted.",
                      __MY_FILE__, __LINE__, __FUNCTION__,
                      pTmpSqlRsp->logictype(), pTmpSqlRsp->sessionid());
            return;
        }
        if (pTmpSession->GetTimeout() != (time_t) pTmpSqlRsp->timestamp()) {
            LOG_ERROR("db", "[%s : %d : %s] Session doesn't exsit (logictype:%d:sessionid:%u ), has been reused.",
                      __MY_FILE__, __LINE__, __FUNCTION__,
                      pTmpSqlRsp->logictype(), pTmpSqlRsp->sessionid());
            return;
        }
    }

    switch (pTmpSqlRsp->logictype())
    {
        //*********************************************************************************
        // 读取战队数据
        //*********************************************************************************
        case emDBLogicType::emDBTypeFindOrCreateUser : {
            FindOrCreateUserResponse(pTmpSession, pTmpSqlRsp,pMsg->mutable_msghead());
            break;
        }
    }
}
int CDbModule::ExecuteSql(emDBLogicType nLogicType,
                          unsigned long ulTeamID,
                          int iSessionID,
                          long nTimeStamp,
                          SQLTYPE nSqlType,
                          int nProduOutNumber,
                          CALLBACK nIsCallBack,
                          const char* pSql,
                          MesHead* mesHead, ... )
{
    MY_ASSERT_LOG("db", pSql != NULL, return -1);

    // 参数整理
    va_list tmpArgs;
    char acTmpSqlCommond[MAX_PACKAGE_LEN] = {0};
    va_start( tmpArgs, pSql);
    int iTmpLen = ::vsnprintf( acTmpSqlCommond, sizeof(acTmpSqlCommond), pSql, tmpArgs );
    MY_ASSERT_LOG("db", iTmpLen > -1, return -2);
    va_end(tmpArgs);

    // 发往dbserver消息整理
    static CProxyMessage tmpMsg;
    static CMsgExecuteSqlRequest tmpMsgSqlRqt;
    tmpMsg.Clear();
    tmpMsgSqlRqt.Clear();

    CProxyHead* pTmpHead = tmpMsg.mutable_msghead();
    pbmsg_setmessagehead(pTmpHead, CMsgExecuteSqlRequest::MsgID );
    if (mesHead != NULL)
    {
        ClientCommEngine::CopyMesHead(mesHead,pTmpHead->mutable_msghead());
    }

    tmpMsgSqlRqt.set_logictype(nLogicType);
    tmpMsgSqlRqt.set_sessionid(iSessionID);
    tmpMsgSqlRqt.set_timestamp(nTimeStamp);
    tmpMsgSqlRqt.set_teamid(ulTeamID);
    tmpMsgSqlRqt.set_sqltype(nSqlType);
    tmpMsgSqlRqt.set_outnumber(nProduOutNumber);
    tmpMsgSqlRqt.set_callback(nIsCallBack);
    tmpMsgSqlRqt.set_sql(acTmpSqlCommond);
    tmpMsgSqlRqt.set_hasblob(NONEBLOB);
    tmpMsg.set_msgpara((unsigned long)&tmpMsgSqlRqt);

	LOG_DEBUG("db", "[%s]", ((Message*)tmpMsg.msgpara())->ShortDebugString().c_str());

    MY_ASSERT_LOG("db", CGameServer::GetSingletonPtr()->SendMessageToDB(&tmpMsg), return -3);

    return 0;
}

int CDbModule::ExecuteSqlForBlob(emDBLogicType nLogicType,
                                 unsigned long ulTeamID,
                                 int iSessionID,
                                 long nTimeStamp,
                                 SQLTYPE nSqlType,
                                 int nProduOutNumber,
                                 CALLBACK nIsCallBack,
                                 const char* pSql,
                                 const int iBlobSize,
                                 const char* pBlob,
                                 const char* pSQLWhere,
                                 MesHead* mesHead,... )
{
    MY_ASSERT_LOG("db", pSql != NULL && pBlob != NULL && pSQLWhere != NULL, return -1);

    // 发往dbserver消息整理
    static CProxyMessage tmpMsg;
    static CMsgExecuteSqlRequest tmpMsgSqlRqt;
    tmpMsg.Clear();
    tmpMsgSqlRqt.Clear();

    CProxyHead* pTmpHead = tmpMsg.mutable_msghead();
    pbmsg_setmessagehead(pTmpHead, CMsgExecuteSqlRequest::MsgID );
    if (mesHead != NULL)
    {
        ClientCommEngine::CopyMesHead(mesHead,pTmpHead->mutable_msghead());
    }

    tmpMsgSqlRqt.set_logictype(nLogicType);
    tmpMsgSqlRqt.set_sessionid(iSessionID);
    tmpMsgSqlRqt.set_timestamp(nTimeStamp);
    tmpMsgSqlRqt.set_teamid(ulTeamID);
    tmpMsgSqlRqt.set_sqltype(nSqlType);
    tmpMsgSqlRqt.set_outnumber(nProduOutNumber);
    tmpMsgSqlRqt.set_callback(nIsCallBack);
    tmpMsgSqlRqt.set_sql(pSql);

    tmpMsgSqlRqt.set_bufsize( iBlobSize );
    tmpMsgSqlRqt.set_buffer( (void*)pBlob, iBlobSize );
    tmpMsgSqlRqt.set_sqlwhere( pSQLWhere );
    tmpMsgSqlRqt.set_hasblob(HASBLOB);

    tmpMsg.set_msgpara((unsigned long)&tmpMsgSqlRqt);
	LOG_DEBUG("db", "[%s]", ((Message*)tmpMsg.msgpara())->ShortDebugString().c_str());
    MY_ASSERT_LOG("db", CGameServer::GetSingletonPtr()->SendMessageToDB(&tmpMsg ), return -2);
    return 0;
}

void CDbModule::FindOrCreateUserRequest(const std::string &platform,const std::string &puid,MesHead* mesHead)
{
    char* pcTmpSql = (char*)"SELECT `player_id` FROM user WHERE `platform` = %s AND `puid` = %s";
    int iRet = CDbModule::GetSingletonPtr()->ExecuteSql(
            emDBLogicType::emDBTypeFindOrCreateUser,
            0,
            0,
            0,
            SELECT,
            0,
            MUSTCALLBACK,
            pcTmpSql,
            mesHead,
            platform,
            puid
    );
    if (iRet != 0)
    {
        LOG_ERROR("db", "[%s : %d : %s] ExecuteSql failed, iRet=%d.",
                  __MY_FILE__, __LINE__, __FUNCTION__, iRet);
//        exit(0);
    }
}

void CDbModule::FindOrCreateUserResponse(CSession *pSession, CMsgExecuteSqlResponse *pMsgSql,CProxyHead* proxyHead)
{
    MY_ASSERT_LOG("db",  pMsgSql != NULL && pSession != NULL && proxyHead != NULL, return);

    int iTmpRowCount = pMsgSql->rowcount();		// 行数
    int iTmpColCount = pMsgSql->colcount();		// 列数

    // 必须对行数列数判断
    if ( 1 == pMsgSql->resultcode() &&  emCol1 == iTmpColCount )
    {
        OBJ_ID player_id = 0;	// 帐号
        // 表示有返回结果
        for(int i = 0; i < iTmpRowCount ; i++)
        {
            player_id = atol((char*)pMsgSql->fieldvalue( 0 + i * iTmpColCount ).c_str());
        }

        if (player_id == 0)
        {
            player_id = (OBJ_ID)CSceneObjManager::GetSingletonPtr()->GetPlayerManager()->GetValidId();
        }
        UserAccountLoginResponse response;
        response.set_playerid(player_id);
        CGameServer::GetSingletonPtr()->SendResponse(&response,proxyHead->mutable_msghead());
    }
    else
    {
        // 拉取数据失败,则退出
        LOG_ERROR("db", "[%s : %d : %s] LoadAllAccountResponse failed, resultcode=%d, row=%d, col=%d.",
                  __MY_FILE__, __LINE__, __FUNCTION__, pMsgSql->resultcode(), iTmpRowCount, iTmpColCount);
        return;
    }
}