﻿// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include "NFLogicPlayerModule.h"
#include "Player/NFPlayer.h"
#include "Player/NFPlayerMgr.h"
#include "DescStore/ConstantConstantDesc.h"
#include "NFServerComm/NFServerCommon/NFILogicServerModule.h"


NFCLogicPlayerModule::NFCLogicPlayerModule(NFIPluginManager *p) : NFFishDynamicModule(p)
{

}

NFCLogicPlayerModule::~NFCLogicPlayerModule()
{
}

bool NFCLogicPlayerModule::Awake()
{
    FindModule<NFILogicServerModule>()->SetCheckStoreServer(true);
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_WTL_PLAYER_LOGIN_REQ>(NF_ST_LOGIC_SERVER, this,
                                                                                     &NFCLogicPlayerModule::OnRpcServicePlayerLogin, true);
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_WTL_PLAYER_RECONNECT_MSG_REQ>(NF_ST_LOGIC_SERVER, this,
                                                                                     &NFCLogicPlayerModule::OnRpcServicePlayerReconnect, true);

    RegisterServerMessage(NF_ST_LOGIC_SERVER, proto_ff::NF_WTL_PLAYER_DISCONNECT_MSG);
    //////////player enter game////////////////////////////////////
    return true;
}

bool NFCLogicPlayerModule::Execute()
{
    return true;
}

bool NFCLogicPlayerModule::OnDynamicPlugin()
{
    return true;
}

int NFCLogicPlayerModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_LOGIC_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}


int NFCLogicPlayerModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_LOGIC_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        case proto_ff::NF_WTL_PLAYER_DISCONNECT_MSG:
        {
            OnHandlePlayerDisconnectMsg(msgId, packet, param1, param2);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}

int NFCLogicPlayerModule::OnRpcServicePlayerLogin(proto_ff::Proto_WorldToLogicLoginReq &request, proto_ff::Proto_LogicToWorldLoginRsp &respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    respone.set_user_id(request.user_id());
    respone.set_result(0);
    respone.set_create_player_db_data(false);

    proto_ff::tbFishPlayerData selectobj;
    NFPlayer* pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(request.user_id());
    bool isCreatePlayer = false;
    if (pPlayer == NULL)
    {
        isCreatePlayer = true;
        selectobj.set_player_id(request.user_id());
        int iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_LOGIC_SERVER, request.user_id(),
                                                                                selectobj);
        if (iRet != 0)
        {
            if (iRet == proto_ff::ERR_CODE_STORESVR_ERRCODE_SELECT_EMPTY)
            {
                respone.set_create_player_db_data(true);

                proto_ff::tbFishPlayerData insertObj;
                insertObj.set_player_id(request.user_id());
                insertObj.set_nickname("gaoyi");
                insertObj.set_age(18);
                insertObj.set_gender(0);
                insertObj.set_regdate(NFTime::Now().UnixSec());

                insertObj.set_faceid(1);
                insertObj.set_jetton(1000000);
                auto pJettonDesc = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EN_CONST_USER_INIT_JETTON);
                if (pJettonDesc)
                {
                    insertObj.set_jetton(pJettonDesc->m_constantdata);
                }

                auto pFaceDesc = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EN_CONST_USER_INIT_FACE);
                if (pFaceDesc)
                {
                    insertObj.set_faceid(pFaceDesc->m_constantdata);
                }

                insertObj.set_regdate(NFTime::Now().UnixSec());
                insertObj.set_phonenum(0);
                insertObj.set_ip(request.client_ip());

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "Ready Create Player InTo Mysql:{}", insertObj.DebugString());

                iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(NF_ST_LOGIC_SERVER,
                                                                                    request.user_id(), insertObj);
                if (iRet != 0)
                {
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Insert Player:{} Failed, iRet:{}", request.user_id(), GetErrorStr(iRet));
                    respone.set_result(iRet);
                    return 0;
                }

                iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_LOGIC_SERVER,
                                                                                    request.user_id(), selectobj);
                if (iRet != 0)
                {
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Insert Player:{} Success, But Select Player Failed, iRet:{}", request.user_id(),
                              GetErrorStr(iRet));
                    respone.set_result(iRet);
                    return 0;
                }

                pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->CreatePlayer(selectobj.player_id(), selectobj, true);
                if (pPlayer == NULL)
                {
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFPlayerMgr CreatePlayer:{} Failed", request.user_id());
                    respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
                    return 0;
                }
            }
            else
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Select Player:{} Failed, iRet:{}", request.user_id(), GetErrorStr(iRet));
                respone.set_result(iRet);
                return 0;
            }
        }
        else
        {
            pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->CreatePlayer(selectobj.player_id(), selectobj, false);
            if (pPlayer == NULL)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFPlayerMgr CreatePlayer:{} Failed", request.user_id());
                respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
                return 0;
            }
        }
    }

    CHECK_NULL(pPlayer);

    int iRet = pPlayer->OnLogin(request, *respone.mutable_detail_data(), isCreatePlayer);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFPlayer:{} OnLogin(request):{} Failed", request.user_id(), GetErrorStr(iRet));
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    iRet = pPlayer->OnLogin();
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFPlayer:{} OnLogin:{} Failed", request.user_id(), GetErrorStr(iRet));
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCLogicPlayerModule::OnRpcServicePlayerReconnect(proto_ff::WTLPlayerReconnectReq& request, proto_ff::LTWPlayerReconnectRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    respone.set_player_id(request.player_id());
    respone.set_result(proto_ff::ERR_CODE_OK);

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    NF_ASSERT(pConfig);

    NFPlayer* pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(request.player_id());
    if (pPlayer == NULL)
    {
        respone.set_result(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        return 0;
    }

    pPlayer->SetProxyId(request.proxy_bus_id());
    pPlayer->OnReconnect();

    if (pPlayer->GetGameId() > 0 && pPlayer->GetGameId() == request.game_id() && pPlayer->GetRoomId() == request.room_id())
    {
        proto_ff::LTGPlayerReconnectReq gameReq;
        gameReq.set_player_id(request.player_id());
        gameReq.set_proxy_bus_id(request.proxy_bus_id());
        gameReq.set_logic_bus_id(pConfig->GetBusId());
        proto_ff::GTLPlayerReconnectRsp gameRsp;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_LTG_PLAYER_RECONNECT_MSG_REQ>(NF_ST_LOGIC_SERVER, NF_ST_GAME_SERVER, pPlayer->GetGameBusId(),
                                                                                                            gameReq, gameRsp, request.player_id());
        //check ptr
        pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(request.player_id());
        CHECK_NULL(pPlayer);

        if (iRet != 0 || gameRsp.result() != 0)
        {
            if (iRet != 0)
            {
                respone.set_result(iRet);
            }
            else {
                respone.set_result(gameRsp.result());
            }

            NFLogError(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(), "player logic server reconnect game server failed");
            return 0;
        }
    }
    else if (pPlayer->GetGameId() > 0 && (pPlayer->GetGameId() != request.game_id() || pPlayer->GetRoomId() != request.room_id())) {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        NFLogError(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(), "player logic server reconnect game server failed");
        return 0;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(), "player:{} reconnect success", pPlayer->GetPlayerId());

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCLogicPlayerModule::OnHandlePlayerDisconnectMsg(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    proto_ff::NotifyPlayerDisconnect xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFPlayer* pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(xMsg.player_id());
    if (pPlayer)
    {
        pPlayer->OnDisconnect();
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, xMsg.player_id(), "player:{} disconnect..............", xMsg.player_id());

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

