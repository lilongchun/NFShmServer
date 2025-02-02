﻿// -------------------------------------------------------------------------
//    @FileName         :    NFCProxyClientModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCProxyClientModule
//
// -------------------------------------------------------------------------

#include "NFProxyPlayerModule.h"
#include "NFServerComm/NFServerCommon/NFIProxyServerModule.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFLogicCommon/NFLoginDefine.h"

NFCProxyPlayerModule::NFCProxyPlayerModule(NFIPluginManager *p) : NFFishDynamicModule(p)
{
}

NFCProxyPlayerModule::~NFCProxyPlayerModule()
{
}

bool NFCProxyPlayerModule::Awake()
{
    NFGlobalSystem::Instance()->RegisterSpecialMsg(NF_MODULE_CLIENT, proto_ff::NF_CS_Msg_HeartBeat_REQ);
    NFGlobalSystem::Instance()->RegisterSpecialMsg(NF_MODULE_CLIENT, proto_ff::NF_SC_Msg_HeartBeat_RSP);
    NFGlobalSystem::Instance()->RegisterSpecialMsg(NF_MODULE_CLIENT, proto_ff::NF_SERVER_TO_SERVER_HEART_BEAT);
    NFGlobalSystem::Instance()->RegisterSpecialMsg(NF_MODULE_CLIENT, proto_ff::NF_SERVER_TO_SERVER_HEART_BEAT_RSP);

    m_packetConfig.LoadConfig(m_pObjPluginManager->GetConfigPath() + "/Server", "ProxyServer");
    SetTimer(NF_PROXY_CLIENT_TIMER_ID, NF_PROXY_CLIENT_INTERVAL_TIME);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////来自客户端的协议////////////////////////////////////////
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::NF_CS_MSG_AccountLoginReq, true);
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::NF_CS_MSG_RegisterAccountReq, true);
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::NF_CS_MSG_UserLoginReq, true);
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::NF_CS_Msg_HeartBeat_REQ);
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_TO_SERVER_HEART_BEAT);
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::NF_CS_Msg_ReConnect_REQ, true);

    /////////来自Login Server返回的协议//////////////////////////////////////////////////
    /////来自World Server返回的协议////////////////////////////////////////
    RegisterServerMessage(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_REDIRECT_MSG_TO_PROXY_SERVER_CMD);
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_STS_PLAYER_CHANGE_GAME_SERVER>(NF_ST_PROXY_SERVER, this,
                                                                                           &NFCProxyPlayerModule::OnRpcServicePlayerChangeGameServer);

    return true;
}

bool NFCProxyPlayerModule::Init()
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig)
    {
        uint64_t proxyClientLinkId = FindModule<NFIMessageModule>()->GetClientLinkId(NF_ST_PROXY_SERVER);
        if (proxyClientLinkId > 0)
        {
            /*
            注册服务器事件
            */
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_PROXY_SERVER, proxyClientLinkId, this,
                                                             &NFCProxyPlayerModule::OnProxyClientSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_PROXY_SERVER, proxyClientLinkId, this,
                                                             &NFCProxyPlayerModule::OnHandleProxyClientOtherMessage);
        }
        else
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Get NF_ST_PROXY_SERVER ClientLinkId Failed!");
            return false;
        }

        uint64_t proxyServerLinkId = FindModule<NFIMessageModule>()->GetServerLinkId(NF_ST_PROXY_SERVER);
        if (proxyServerLinkId > 0)
        {
            /*
            注册服务器事件
            */
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_PROXY_SERVER, proxyServerLinkId, this,
                                                             &NFCProxyPlayerModule::OnHandleOtherServerToClientMsg);
        }
        else
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Get NF_ST_PROXY_SERVER ClientLinkId Failed!");
            return false;
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "I Can't get the Proxy Server config!");
        return false;
    }

    return true;
}

bool NFCProxyPlayerModule::Execute()
{
    return true;
}

bool NFCProxyPlayerModule::OnDynamicPlugin()
{
    return true;
}

int NFCProxyPlayerModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == NF_PROXY_CLIENT_TIMER_ID)
    {
        HandleProxyClientTick();
        HandlePlayerTick();
    }
    return 0;
}

int NFCProxyPlayerModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_PROXY_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Proxy Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Proxy Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo)
    {
        int count = 0;
        int interval = 0;
        uint64_t roleID = 0;
        pLinkInfo->AddPkgStatistic(packet.nMsgId, pLinkInfo->GetPlayerId(), unLinkId);
        int ret = pLinkInfo->CheckPkgRate(&m_packetConfig, packet.nMsgId, count, interval);
        if (ret != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "pkg check and kick player:{| linkId:{} count:{} interval:{} ret:{} packet:{}", roleID, unLinkId, count,
                       interval, ret, packet.ToString());
            return 0;
        }
    }

    switch (packet.nMsgId)
    {
        case proto_ff::NF_SERVER_TO_SERVER_HEART_BEAT:
        {
            FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_HEART_BEAT_RSP, NULL, 0);
        }
        case proto_ff::NF_CS_Msg_HeartBeat_REQ:
        {
            OnHandleClientHeartBeat(unLinkId, packet);
            break;
        }
        case proto_ff::NF_CS_MSG_AccountLoginReq:
        {
            OnHandleAccountLoginFromClient(unLinkId, packet);
            break;
        }
        case proto_ff::NF_CS_MSG_RegisterAccountReq:
        {
            OnHandleRegisterLoginFromClient(unLinkId, packet);
            break;
        }
        case proto_ff::NF_CS_MSG_UserLoginReq:
        {
            OnHandlePlayerLoginFromClient(unLinkId, packet);
            break;
        }
        case proto_ff::NF_CS_Msg_ReConnect_REQ:
        {
            OnHandlePlayerReconnectFromClient(unLinkId, packet);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}


int NFCProxyPlayerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_PROXY_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        case proto_ff::NF_SERVER_REDIRECT_MSG_TO_PROXY_SERVER_CMD:
        {
            OnHandleRedirectMsg(unLinkId, packet);
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

/*
	处理客户端链接事件
*/
int NFCProxyPlayerModule::OnProxyClientSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    if (nEvent == eMsgType_CONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        uint32_t port = FindModule<NFIMessageModule>()->GetPort(unLinkId);
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "client ip:{} port:{} linkId:{} connected proxy server success!", ip, port, unLinkId);

        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
        CHECK_EXPR_ASSERT(pLinkInfo == NULL, -1, "unLinkId:{} Exist", unLinkId);
        if (pLinkInfo == nullptr)
        {
            pLinkInfo = NF_SHARE_PTR<NFProxySession>(NF_NEW NFProxySession());
            pLinkInfo->SetLinkId(unLinkId);
            pLinkInfo->SetIpAddr(ip);
            pLinkInfo->SetPort(port);
            pLinkInfo->SetLastActiveTime(NFTime::Now().UnixSec());
            mClientLinkInfo.AddElement(unLinkId, pLinkInfo);
        }
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        uint32_t port = FindModule<NFIMessageModule>()->GetPort(unLinkId);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "client ip:{} port:{} link:{} disconnected proxy server!", ip, port, unLinkId);
        OnHandleClientDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

/*
	处理客户端未注册协议
*/
int NFCProxyPlayerModule::OnHandleProxyClientOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == nullptr)
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "can't find the link, ip:{} packet:{}",
                     ip, packet.ToString());

        FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        return 0;
    }

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->GetPlayerId());
    if (pPlayerInfo == nullptr)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find the clientId:{} 's playerId:{}, drop msg:{}", unLinkId, pLinkInfo->GetPlayerId(), packet.ToString());
        return 0;
    }

    pPlayerInfo->SetOnline(true);

    uint32_t msgId = packet.nMsgId;
    uint32_t gameId = 0;
    if (msgId >= NF_NET_MAX_MSG_ID)
    {
        gameId = HIGH_UINT16(packet.nMsgId);
        msgId = LOW_UINT16(packet.nMsgId);
    }

    int count = 0;
    int interval = 0;
    pLinkInfo->AddPkgStatistic(msgId, pLinkInfo->GetPlayerId(), unLinkId);
    int ret = pLinkInfo->CheckPkgRate(&m_packetConfig, msgId, count, interval);
    if (ret != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "pkg check player:{} linkId:{} count:{} interval:{} ret:{} packet:{}", pLinkInfo->GetPlayerId(), unLinkId, count,
                   interval, ret, packet.ToString());
        return 0;
    }

    {
        if (!pPlayerInfo->IsLogin())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "the clientId:{} 's playerId:{} not login, drop msg:{}", unLinkId, pLinkInfo->GetPlayerId(),
                       packet.ToString());
            return 0;
        }

        uint32_t serverType = FindModule<NFIProxyServerModule>()->GetClientMsgServer(msgId);
        if (serverType == NF_ST_WORLD_SERVER)
        {
            NF_SHARE_PTR<NFServerData> pWorldServer = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                                                NF_ST_WORLD_SERVER,
                                                                                                                pPlayerInfo->GetPlayerId());
            if (pWorldServer)
            {
                NFLogDebug(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "recv packet = {}, transfer to world server", packet.ToString());
                FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pWorldServer->mServerInfo.bus_id(),
                                                                          NF_MODULE_CLIENT, msgId,
                                                                          packet.GetBuffer(), packet.GetSize(), pPlayerInfo->GetPlayerId(),
                                                                          0);
            }
            else
            {
                NFLogWarning(NF_LOG_SYSTEMLOG, pLinkInfo->GetPlayerId(),
                             "can't find the player:{} info, the cmd don't find the trans to world server, world server not exist, ip:{} packet:{}",
                             pLinkInfo->GetPlayerId(), ip, packet.ToString());
            }
        }
        else if (serverType == NF_ST_LOGIC_SERVER)
        {
            if (pPlayerInfo->GetLogicBusId() > 0)
            {
                NFLogDebug(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "recv packet = {}, transfer to logic server", packet.ToString());
                FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->GetLogicBusId(), NF_MODULE_CLIENT,
                                                                          msgId,
                                                                          packet.GetBuffer(), packet.GetSize(), pPlayerInfo->GetPlayerId(),
                                                                          0);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "recv nMsgId = {}, not transfer to logic server", packet.ToString());
            }
        }
        else if (serverType == NF_ST_GAME_SERVER)
        {
            if (gameId == pPlayerInfo->GetGameId() && pPlayerInfo->GetGameBusId() > 0)
            {
                NFLogDebug(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "recv packet = {}, transfer to game server", packet.ToString());
                FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->GetGameBusId(), NF_MODULE_CLIENT,
                                                                          msgId,
                                                                          packet.GetBuffer(), packet.GetSize(), pPlayerInfo->GetPlayerId(),
                                                                          0);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "recv nMsgId = {}, not transfer to game server", packet.ToString());
            }
        }
        else if (serverType == NF_ST_SNS_SERVER)
        {
            NF_SHARE_PTR<NFServerData> pSnsServer = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                                              NF_ST_SNS_SERVER,
                                                                                                              pPlayerInfo->GetPlayerId());
            if (pSnsServer)
            {
                NFLogDebug(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "recv packet = {}, transfer to sns server", packet.ToString());
                FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pSnsServer->mServerInfo.bus_id(), NF_MODULE_CLIENT,
                                                                          msgId,
                                                                          packet.GetBuffer(), packet.GetSize(), pPlayerInfo->GetPlayerId(),
                                                                          0);
            }
            else
            {
                NFLogWarning(NF_LOG_SYSTEMLOG, pLinkInfo->GetPlayerId(),
                             "can't find the player:{} info, the cmd don't find the trans to sns server, sns server not exist, ip:{} packet:{}",
                             pLinkInfo->GetPlayerId(), ip, packet.ToString());
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "no server handle the msg, drop msg:{}", packet.ToString());
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::OnHandleClientDisconnect(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo)
    {
        if (pLinkInfo->GetPlayerId() > 0)
        {
            NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->GetPlayerId());
            if (pPlayerInfo)
            {
                if (pPlayerInfo->GetLinkId() == unLinkId)
                {
                    NotifyPlayerDisconnect(unLinkId, pPlayerInfo);
                }
                else if (pPlayerInfo->GetLinkId() > 0)
                {
                    NF_SHARE_PTR<NFProxySession> pOtherLinkInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
                    if (pOtherLinkInfo == NULL)
                    {
                        NotifyPlayerDisconnect(unLinkId, pPlayerInfo);
                    }
                }
            }
        }
        mClientLinkInfo.RemoveElement(unLinkId);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::NotifyPlayerDisconnect(uint64_t unLinkId, NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo)
{
    CHECK_NULL(pPlayerInfo);
    pPlayerInfo->SetLinkId(0);
    pPlayerInfo->SetOnline(false);
    pPlayerInfo->SetDisconnectTime(NFTime::Now().UnixSec());

    if (pPlayerInfo->GetWorldBusId() > 0)
    {
        proto_ff::NotifyPlayerDisconnect xMsg;
        xMsg.set_player_id(pPlayerInfo->GetPlayerId());
        FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->GetWorldBusId(), NF_MODULE_SERVER,
                                                                  proto_ff::NF_PTW_PLAYER_DISCONNECT_MSG, xMsg, pPlayerInfo->GetPlayerId());
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "player:{} link:{} disconenct.........", pPlayerInfo->GetPlayerId(), unLinkId);
    return 0;
}


int NFCProxyPlayerModule::OnHandleClientHeartBeat(uint64_t unLinkId, NFDataPackage &packet)
{
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find unLinkId:{}", unLinkId);
        FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        return -1;
    }

    pLinkInfo->SetLastActiveTime(NFTime::Now().UnixSec());

    proto_ff::Proto_SCHeartBeatRsp xData;
    xData.set_result(0);
    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_HeartBeat_RSP, xData);

    return 0;
}

int NFCProxyPlayerModule::HandleProxyClientTick()
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    auto pProxyClient = mClientLinkInfo.First();
    while (pProxyClient)
    {
        if (pProxyClient->GetPlayerId() <= 0 && pProxyClient->GetLastActiveTime() > 0 &&
            NFTime::Now().UnixSec() - pProxyClient->GetLastActiveTime() >= pConfig->HeartBeatTimeout)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "check heart beat timeout........., disconnect link:{} ", pProxyClient->GetLinkId());
            FindModule<NFIMessageModule>()->CloseLinkId(pProxyClient->GetLinkId());
        }

        if (pProxyClient->GetPlayerId() > 0 && pProxyClient->GetLastActiveTime() > 0 &&
            NFTime::Now().UnixSec() - pProxyClient->GetLastActiveTime() >= pConfig->ClientKeepAliveTimeout)
        {
            NFLogError(NF_LOG_SYSTEMLOG, pProxyClient->GetPlayerId(), "check player keep alive timeout........., disconnect link:{} playerId:{}",
                       pProxyClient->GetLinkId(), pProxyClient->GetPlayerId());
            FindModule<NFIMessageModule>()->CloseLinkId(pProxyClient->GetLinkId());
        }

        pProxyClient = mClientLinkInfo.Next();
    }
    return 0;
}

int NFCProxyPlayerModule::OnHandleOtherServerToClientMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    uint64_t playerId = packet.nParam1;
    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(playerId);
    if (pPlayerInfo)
    {
        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
        if (pLinkInfo == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find player linkId, player disconnect:{}", unLinkId);
            return -1;
        }

        uint32_t srcBusId = packet.nSrcId;
        auto pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, srcBusId);
        if (pServerData)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "trans {} msg to client, packet:{}", pServerData->mServerInfo.server_name(),
                       packet.ToString());
        }

        if (pServerData->mServerInfo.server_type() == NF_ST_GAME_SERVER)
        {
            uint32_t msgId = MAKE_UINT32(packet.nMsgId, pPlayerInfo->GetGameId());
            FindModule<NFIMessageModule>()->Send(pPlayerInfo->GetLinkId(), NF_MODULE_CLIENT, msgId, (const char*)packet.GetBuffer(), (uint32_t)packet.GetSize());
        }
        else {
            FindModule<NFIMessageModule>()->Send(pPlayerInfo->GetLinkId(), NF_MODULE_CLIENT, packet.nMsgId, (const char*)packet.GetBuffer(), (uint32_t)packet.GetSize());
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find player:{} info or clientId change, other server msg:{} not handle", playerId, packet.ToString());
    }

    return 0;
}

int NFCProxyPlayerModule::OnHandleRedirectMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    proto_ff::Proto_SvrPkg xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    const ::proto_ff::Proto_RedirectInfo &redirectInfo = xMsg.redirect_info();
    for (int i = 0; i < (int) redirectInfo.id_size(); i++)
    {
        uint64_t playerId = redirectInfo.id(i);
        NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(playerId);
        if (pPlayerInfo)
        {
            NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
            if (pLinkInfo == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find player linkId, player disconnect:{}", unLinkId);
                return -1;
            }

            FindModule<NFIMessageModule>()->Send(pPlayerInfo->GetLinkId(), (uint32_t) xMsg.msg_id(), xMsg.msg_data());
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find player:{} info, other server msg:{} not handle", playerId, packet.ToString());
        }
    }

    return 0;
}

int NFCProxyPlayerModule::HandlePlayerTick()
{
    std::vector<uint64_t> vec;
    auto pPlayerInfo = mPlayerLinkInfo.First();
    while (pPlayerInfo)
    {
        if (pPlayerInfo->IsOnline() == false)
        {
/*            if (NFTime::Now().UnixSec() - pPlayerInfo->GetDisconnectTime() >= PLAYER_MAX_DISCONNECT_EXIST_TIME)
            {
                vec.push_back(pPlayerInfo->GetUid());
            }

            if (pPlayerInfo->IsLogin())
            {
                if (NFTime::Now().UnixSec() - pPlayerInfo->GetDisconnectTime() >= PLAYER_MAX_DISCONNECT_RECONNECT_TIME)
                {
                    pPlayerInfo->SetIsLogin(false);
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "player disconnect 60s, islogin = false:{}", pPlayerInfo->GetUid());
                }
            }*/
        }
        pPlayerInfo = mPlayerLinkInfo.Next();
    }

    for (int i = 0; i < (int) vec.size(); i++)
    {
        mPlayerLinkInfo.RemoveElement(vec[i]);
    }
    return 0;
}

int NFCProxyPlayerModule::OnHandleAccountLoginFromClient(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::Proto_CSAccountLoginReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgMsg);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);

    auto pServerData = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                 NF_ST_LOGIN_SERVER, cgMsg.account());
    if (pServerData)
    {
        uint32_t loginId = pServerData->mServerInfo.bus_id();
        proto_ff::Proto_SCAccountLoginRsp respone;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_CS_MSG_AccountLoginReq>(NF_ST_PROXY_SERVER, NF_ST_LOGIN_SERVER, loginId, cgMsg, respone);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_RPC_SERVICE_GET_SERVER_INFO_REQ Failed!");
            return 0;
        }

        pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
        if (pLinkInfo == nullptr)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "clientLinkId:{} not exist, client maybe disconnect!", unLinkId);
            return 0;
        }

        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_MSG_AccountLoginRsp, respone);
    }
    else
    {
        KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Get Login Server Bus Id Failed");
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::OnHandleRegisterLoginFromClient(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::Proto_CSRegisterAccountReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgMsg);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);

    auto pServerData = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                 NF_ST_LOGIN_SERVER, cgMsg.account());
    if (pServerData)
    {
        uint32_t loginId = pServerData->mServerInfo.bus_id();
        proto_ff::Proto_SCRegisterAccountRsp respone;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_CS_MSG_RegisterAccountReq>(NF_ST_PROXY_SERVER, NF_ST_LOGIN_SERVER, loginId, cgMsg, respone);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_RPC_SERVICE_GET_SERVER_INFO_REQ Failed!");
            return 0;
        }

        pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
        if (pLinkInfo == nullptr)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "clientLinkId:{} not exist, client maybe disconnect!", unLinkId);
            return 0;
        }

        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_MSG_RegisterAccountRsp, respone);
    }
    else
    {
        KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Get Login Server Bus Id Failed");
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::KickPlayer(uint64_t unLinkId, int reason)
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "kick linkId:{}", unLinkId);
    proto_ff::Proto_SCKetPlayerNotify kitMsg;
    kitMsg.set_result(reason);
    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_KitPlayer_Notify, kitMsg);
    FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
    return 0;
}

int NFCProxyPlayerModule::OnHandlePlayerLoginFromClient(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::Proto_CSUserLoginReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgMsg);

    uint64_t now = NFTime::Now().UnixSec();
    if (now - cgMsg.login_time() >= 30)
    {
        proto_ff::Proto_SCUserLoginRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_TOKEN_TIMEOUT);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_MSG_UserLoginRsp, rspMsg);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "account user:{} token timeout", cgMsg.account(), cgMsg.user_id())
        return 0;
    }

    std::string token = NFLogicCommon::GetLoginToken(cgMsg.account(), cgMsg.user_id(), cgMsg.login_time(), FISH_LOGIN_TOKEN);
    if (cgMsg.token() != token)
    {
        proto_ff::Proto_SCUserLoginRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_TOKEN_ERROR);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_MSG_UserLoginRsp, rspMsg);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "account user:{} token:{} error, real token:{}", cgMsg.account(), cgMsg.user_id(), cgMsg.token(), token);
        return 0;
    }

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(cgMsg.user_id());
    if (pPlayerInfo == nullptr) {
        pPlayerInfo = NF_SHARE_PTR<NFProxyPlayerInfo>(NF_NEW NFProxyPlayerInfo());

        pPlayerInfo->SetLinkId(unLinkId);
        pPlayerInfo->SetIpAddr(pLinkInfo->GetIpAddr());
        pPlayerInfo->SetIsLogin(true);
        pPlayerInfo->SetPlayerId(cgMsg.user_id());
        pPlayerInfo->SetAccount(cgMsg.account());

        mPlayerLinkInfo.AddElement(pPlayerInfo->GetPlayerId(), pPlayerInfo);

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "create player:{} link:{}............", pPlayerInfo->GetPlayerId(), unLinkId);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "new link, player:{} link:{}............", pPlayerInfo->GetPlayerId(), unLinkId);
    }
    else {
        if (pPlayerInfo->GetLinkId() > 0 && pPlayerInfo->GetLinkId() != unLinkId) {
            auto pOtherInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
            if (pOtherInfo) {
                KickPlayer(pPlayerInfo->GetLinkId());
                pOtherInfo->SetPlayerId(0);
            }
        }

        pPlayerInfo->SetLinkId(unLinkId);
        pPlayerInfo->SetIpAddr(pLinkInfo->GetIpAddr());
        pPlayerInfo->SetIsLogin(true);
        pPlayerInfo->SetPlayerId(cgMsg.user_id());
        pPlayerInfo->SetAccount(cgMsg.account());

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "new link, player:{} link:{}............", pPlayerInfo->GetPlayerId(), unLinkId);
    }

    pPlayerInfo->SetOnline(true);

    pLinkInfo->SetPlayerId(cgMsg.user_id());

    if (pPlayerInfo->GetWorldBusId() == 0) {
        auto pServerData = FindModule<NFIMessageModule>()->GetFirstServerByServerType(NF_ST_PROXY_SERVER,
                                                                                NF_ST_WORLD_SERVER);
        if (pServerData) {
            pPlayerInfo->SetWorldBusId(pServerData->mServerInfo.bus_id());
        }
        else {
            proto_ff::Proto_SCUserLoginRsp rspMsg;
            rspMsg.set_result(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);
            FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_MSG_UserLoginRsp, rspMsg);

            KickPlayer(pPlayerInfo->GetLinkId());
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Get World Bus Id Failed!");
            return 0;
        }
    }

    proto_ff::Proto_PTWUserLoginReq loginReq;
    loginReq.set_user_id(pPlayerInfo->GetPlayerId());
    loginReq.set_account(pPlayerInfo->GetAccount());
    loginReq.set_client_ip(pLinkInfo->GetIpAddr());
    loginReq.mutable_ext_data()->CopyFrom(cgMsg.ext_data());

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig)
    {
        loginReq.set_proxy_bus_id(pConfig->GetBusId());
    }

    proto_ff::Proto_WTPPlayerLoginRsp respone;
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_PTW_PLAYER_LOGIN_REQ>(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER, pPlayerInfo->GetWorldBusId(), loginReq, respone);
    if (iRet != 0)
    {
        proto_ff::Proto_SCUserLoginRsp rspMsg;
        rspMsg.set_result(iRet);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_MSG_UserLoginRsp, rspMsg);

        KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_PTW_PLAYER_LOGIN_REQ Failed! iRet:{}", GetErrorStr(iRet));
        return 0;
    }

    if (respone.result() != 0)
    {
        proto_ff::Proto_SCUserLoginRsp rspMsg;
        rspMsg.set_result(respone.result());
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_MSG_UserLoginRsp, rspMsg);

        KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_PTW_PLAYER_LOGIN_REQ result:{}!", GetErrorStr(respone.result()));
        return 0;
    }



    /**
     * @brief 异步后需要重新查找
     */
    pPlayerInfo = mPlayerLinkInfo.GetElement(respone.user_id());
    CHECK_NULL(pPlayerInfo);

    pPlayerInfo->SetIsLogin(true);
    pPlayerInfo->SetGameId(respone.game_id());
    pPlayerInfo->SetRoomId(respone.room_id());
    pPlayerInfo->SetGameBusId(respone.game_bus_id());
    pPlayerInfo->SetLogicBusId(respone.logic_bus_id());

    proto_ff::Proto_SCUserLoginRsp rspMsg;
    rspMsg.set_result(respone.result());
    rspMsg.set_user_id(respone.user_id());
    rspMsg.mutable_detail_data()->CopyFrom(respone.detail_data());

    NFLogError(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "Player:{} Login World Success!", pPlayerInfo->GetPlayerId());

    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_MSG_UserLoginRsp, rspMsg);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::OnHandlePlayerReconnectFromClient(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::Proto_CSReconnectReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgMsg);

    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerLinkInfo = mPlayerLinkInfo.GetElement(cgMsg.userid());
    if (pPlayerLinkInfo == nullptr) {
        NFLogError(NF_LOG_SYSTEMLOG, cgMsg.userid(), "Player:{} reconnect proxy server, reconnect failed!",
                  cgMsg.userid());
        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
        return 0;
    }

    if (pPlayerLinkInfo->IsLogin() == false)
    {
        NFLogError(NF_LOG_SYSTEMLOG, cgMsg.userid(), "Player:{} reconnect proxy server, islogin == false, reconnect failed!",
                  cgMsg.userid());
        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
        return 0;
    }

    if (pPlayerLinkInfo->GetLinkId() > 0) {
        if (pPlayerLinkInfo->GetLinkId() == unLinkId) {
            NFLogError(NF_LOG_SYSTEMLOG, cgMsg.userid(),
                      "Player:{} reconnect proxy server, but unlink not change! some wrong!", cgMsg.userid());
        } else {
            NFLogInfo(NF_LOG_SYSTEMLOG, cgMsg.userid(), "Player:{} reconnect proxy server, but unlink exist",
                      cgMsg.userid());
            auto pOtherInfo = mClientLinkInfo.GetElement(pPlayerLinkInfo->GetLinkId());
            if (pOtherInfo) {
                //disconnect, but new connect first, close old connect
                pOtherInfo->SetPlayerId(0);

                KickPlayer(pPlayerLinkInfo->GetLinkId(), proto_ff::ERR_CODE_OTHER_PLACE_LOGIN_ACCOUNT);
            }
        }
    }

    pPlayerLinkInfo->SetLinkId(unLinkId);
    pPlayerLinkInfo->SetIpAddr(ip);
    pPlayerLinkInfo->SetOnline(true);

    pLinkInfo->SetPlayerId(pPlayerLinkInfo->GetPlayerId());
    pLinkInfo->SetIpAddr(ip);

    proto_ff::PTWPlayerReconnectReq reconnectReq;
    reconnectReq.set_player_id(pPlayerLinkInfo->GetPlayerId());
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    {
        reconnectReq.set_proxy_bus_id(pConfig->GetBusId());
    }

    proto_ff::WTPPlayerReconnctRsp respone;
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_PTW_PLAYER_RECONNECT_MSG_REQ>(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER, pPlayerLinkInfo->GetWorldBusId(), reconnectReq, respone);
    if (iRet != 0)
    {
        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(iRet);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
        return 0;
    }

    if (respone.result() != 0)
    {
        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(respone.result());
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
        return 0;
    }

    pPlayerLinkInfo = mPlayerLinkInfo.GetElement(respone.player_id());
    if (pPlayerLinkInfo == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, respone.player_id(), "Player:{} reconnect rsp form wolrd server failed, can't find player info in the proxy server",
                   respone.player_id());

        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(respone.result());
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());

        KickPlayer(unLinkId, 0);
        return 0;
    }

    pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, respone.player_id(), "Player:{} reconnect rsp form wolrd server failed, can't find player link:{} in the proxy server",
                   respone.player_id(), unLinkId);

        NotifyPlayerDisconnect(unLinkId, pPlayerLinkInfo);
        return 0;
    }


    pPlayerLinkInfo->SetIsLogin(true);
    pPlayerLinkInfo->SetGameId(respone.game_id());
    pPlayerLinkInfo->SetRoomId(respone.room_id());
    pPlayerLinkInfo->SetGameBusId(respone.game_bus_id());
    pPlayerLinkInfo->SetLogicBusId(respone.logic_bus_id());

    NF_SHARE_PTR<NFServerData> pLogicServer = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, pPlayerLinkInfo->GetLogicBusId());
    if (pLogicServer == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, pPlayerLinkInfo->GetPlayerId(), "proxy donot connect logic server:{}", pPlayerLinkInfo->GetLogicBusId());
        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(-1);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());

        KickPlayer(unLinkId, 0);
        return 0;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerLinkInfo->GetPlayerId(), "player:{} reconnect success", pPlayerLinkInfo->GetPlayerId());

    proto_ff::Proto_SCReconnectRsp gcMsg;
    gcMsg.set_result(0);
    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::OnRpcServicePlayerChangeGameServer(proto_ff::Proto_STS_PlayerChangeGameServerReq &request, proto_ff::Proto_STS_PlayerChangeGameServerRsp &respone)
{
    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerLinkInfo = mPlayerLinkInfo.GetElement(request.player_id());
    if (pPlayerLinkInfo == nullptr) {
        NFLogError(NF_LOG_SYSTEMLOG, request.player_id(), "Can't find player info, change game server",
                   request.player_id());
        respone.set_ret_code(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        return 0;
    }

    pPlayerLinkInfo->SetGameId(request.game_id());
    pPlayerLinkInfo->SetRoomId(request.room_id());
    pPlayerLinkInfo->SetGameBusId(request.game_bus_id());

    respone.set_ret_code(proto_ff::ERR_CODE_OK);
    return 0;
}