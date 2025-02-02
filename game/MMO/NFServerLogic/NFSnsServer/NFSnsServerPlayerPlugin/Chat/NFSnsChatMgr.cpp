// -------------------------------------------------------------------------
//    @FileName         :    NFSnsChatMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsChatMgr
//
// -------------------------------------------------------------------------

#include "NFSnsChatMgr.h"

#include <Cache/NFCacheMgr.h>
#include <DescStore/ChatChatDesc.h>
#include <Faction/NFFactionMgr.h>
#include <Relation/NFSnsRelationMgr.h>
#include <Team/NFSnsTeamMgr.h>

#include "NFSnsChatPart.h"

NFSnsChatMgr::NFSnsChatMgr()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFSnsChatMgr::~NFSnsChatMgr()
{
}

int NFSnsChatMgr::CreateInit()
{
    m_virForbidFlag = false;
    return 0;
}

int NFSnsChatMgr::ResumeInit()
{
    return 0;
}

void NFSnsChatMgr::SendWorldBroadcastChat(BROADCAST_TYPE id, SystemChatMsgData& msgData)
{
    proto_ff::GCSystemChatMsgNotify msg;

    if (GetSystemChatMsg(id, msgData, msg))
    {
        SendWorldMsg(proto_ff::LOGIC_TO_CLIENT_SYSTEM_CHAT_MSG_NOTIFY, msg);
    }
}

void NFSnsChatMgr::SendBroadcastChat(BROADCAST_TYPE id, SystemChatMsgData& msgData, SET_UINT64& playerIdList)
{
    proto_ff::GCSystemChatMsgNotify msg;

    if (GetSystemChatMsg(id, msgData, msg))
    {
        SendW2C(proto_ff::LOGIC_TO_CLIENT_SYSTEM_CHAT_MSG_NOTIFY, playerIdList, msg);
    }
}

bool NFSnsChatMgr::GetSystemChatMsg(BROADCAST_TYPE id, SystemChatMsgData& msgData, proto_ff::GCSystemChatMsgNotify& chatMsg)
{
    auto pCfg = ChatChatDesc::Instance()->GetDesc(id);
    if (nullptr == pCfg)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[center] ChatManager::SendWorldBroadcastChat ... nullptr == pCfg...nBroadcastChatID:%lu ", id);
        return false;
    }

    if (pCfg->m_chatType < proto_ff::CHAT_CHANNEL_NONE || pCfg->m_chatType > proto_ff::CHAT_CHANNEL_LIMIT)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[center] ChatManager::SendG2WBroadcast ...pCfg chatType is error .nBroadcastChatID:%lu,type:%d ", id, pCfg->m_chatType);
        return false;
    }
    if (!proto_ff::CHAT_CHANNEL_IsValid(pCfg->m_chatType))
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[center] ChatManager::SendG2WBroadcast ...CHAT_CHANNEL_IsValid .nBroadcastChatID:%lu,type:%d ", id, pCfg->m_chatType);
        return false;
    }

    chatMsg.set_channel(proto_ff::CHAT_CHANNEL(pCfg->m_chatType));
    chatMsg.set_msgtype(id);


    //填充角色信息
    for (uint32_t i = 0; i < msgData.players.size(); i++)
    {
        chatMsg.add_players()->CopyFrom(msgData.players[i]);
    }

    //填充text
    for (uint32_t i = 0; i < msgData.text.size(); i++)
    {
        chatMsg.add_text(msgData.text[i]);
    }

    //填充parmas
    for (uint32_t i = 0; i < msgData.params.size(); i++)
    {
        chatMsg.add_parmas(msgData.params[i]);
    }

    //填充items
    for (uint32_t i = 0; i < msgData.items.size(); ++i)
    {
        proto_ff::ItemProtoInfo *proto = chatMsg.add_items();
        if (nullptr != proto)
        {
            proto->CopyFrom(msgData.items.at(i));
        }
    }

    return true;
}

void NFSnsChatMgr::InitPlayerMiniInfoStruct(CharIDType playerId, proto_ff::RolePlayerMiniInfo& info)
{
    auto pOfflineCharacterData = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(playerId);
    if (nullptr == pOfflineCharacterData)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, playerId, "[center] ChatCenter::InitOffLinePlayerMiniInfoStruct but OfflineCharacterData is nullptr,charID:%llu ", playerId);
        return;
    }

    info.set_playerid(playerId);
    info.set_playername(pOfflineCharacterData->GetName());
    info.set_level(pOfflineCharacterData->Level());
    info.set_prof(pOfflineCharacterData->Prof());
    info.set_unionid(NFSnsFactionMgr::Instance(m_pObjPluginManager)->RoleFactionId(playerId));
    info.set_teamid(NFSnsTeamMgr::Instance(m_pObjPluginManager)->GetCharTeamID(playerId));
    info.set_viplevel(pOfflineCharacterData->VipLevel());
    info.mutable_facade()->CopyFrom(pOfflineCharacterData->FacadeToPB());
}

void NFSnsChatMgr::InitPlayerMiniInfoStruct(const std::string& szPlayerName, proto_ff::RolePlayerMiniInfo& info)
{
    auto pOfflineCharacterData = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimpleByName(szPlayerName);
    if (nullptr == pOfflineCharacterData)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[center] ChatCenter::InitOffLinePlayerMiniInfoStruct but OfflineCharacterData is nullptr, szPlayerName:{} ", szPlayerName);
        return;
    }

    info.set_playerid(pOfflineCharacterData->Cid());
    info.set_playername(pOfflineCharacterData->GetName());
    info.set_level(pOfflineCharacterData->Level());
    info.set_prof(pOfflineCharacterData->Prof());
    info.set_unionid(NFSnsFactionMgr::Instance(m_pObjPluginManager)->RoleFactionId(pOfflineCharacterData->Cid()));
    info.set_teamid(NFSnsTeamMgr::Instance(m_pObjPluginManager)->GetCharTeamID(pOfflineCharacterData->Cid()));
    info.set_viplevel(pOfflineCharacterData->VipLevel());
    info.mutable_facade()->CopyFrom(pOfflineCharacterData->FacadeToPB());
}

bool NFSnsChatMgr::SendWorldMsg(uint32_t cmd, const google::protobuf::Message& xData)
{
    NFCacheMgr::Instance(m_pObjPluginManager)->SendMsgToAllClient(cmd, xData);
    return true;
}

bool NFSnsChatMgr::SendW2C(uint32_t cmd, CharIDType playerId, const google::protobuf::Message& xData)
{
    NFCacheMgr::Instance(m_pObjPluginManager)->SendMsgToClient(playerId, cmd, xData);
    return true;
}

bool NFSnsChatMgr::SendW2C(uint32_t cmd, const SET_UINT64& playerIdList, const google::protobuf::Message& xData)
{
    NFCacheMgr::Instance(m_pObjPluginManager)->SendMsgToClient(playerIdList, cmd, xData);
    return true;
}

bool NFSnsChatMgr::SendCampMsg(uint32_t cmd, int8_t campID, const google::protobuf::Message& xData)
{
    return true;
}

bool NFSnsChatMgr::SendEnlistMsg(uint32_t cmd, int8_t campID, const google::protobuf::Message& xData)
{
    return true;
}

bool NFSnsChatMgr::SendUnionMsg(uint32_t cmd, uint32_t unionId, const google::protobuf::Message& xData)
{
    if (unionId > 0)
    {
        SET_UINT64 members;
        NFSnsFactionMgr::Instance(m_pObjPluginManager)->FactionAllMem(unionId, members);
        SendW2C(cmd, members, xData);
    }

    return true;
}

bool NFSnsChatMgr::SendPokerMsg(uint32_t cmd, const google::protobuf::Message& xData)
{
    return true;
}

bool NFSnsChatMgr::IsVirForbid(uint64_t cid)
{
    return m_setVirForbidCid.find(cid) != m_setVirForbidCid.end();
}

bool NFSnsChatMgr::ValidatePrivateChat(CharIDType srcID, CharIDType dstID)
{
    return NFSnsRelationMgr::Instance(m_pObjPluginManager)->IsInBlack(srcID, dstID);
}

int NFSnsChatMgr::SendOfflineMsgByRpc(CharIDType srcID, CharIDType dstID, const proto_ff::ChatContentInfo& chatContent)
{
    NFPlayerDetail* pDstDetail = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerDetailByRpc(srcID, dstID);
    CHECK_EXPR(pDstDetail, -1, "can't find detail data, srcId:{} dstID:{}", srcID, dstID);

    NFSnsChatPart* pDstChat = dynamic_cast<NFSnsChatPart*>(pDstDetail->GetPart(SNS_PART_CHAT));
    CHECK_NULL(pDstChat);

    pDstChat->AddOfflineMsg(srcID, chatContent);
    return 0;
}

bool NFSnsChatMgr::ChatBackEndRumor(const std::string& content, uint32_t loopCount)
{
    return true;
}

int NFSnsChatMgr::RegisterMessage()
{
    RegisterServerMessage(proto_ff::CENTER_SERVER_PROTOCOL_GWSYSCHATMSGNOTIFY);
    RegisterServerMessage(proto_ff::SERVER_TO_SERVER_CROSS_CHAT);
    return 0;
}

int NFSnsChatMgr::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSnsChatMgr::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::CENTER_SERVER_PROTOCOL_GWSYSCHATMSGNOTIFY:
        {
            OnHandleSysChatMsgNotify(msgId, packet);
            break;
        }
        case proto_ff::SERVER_TO_SERVER_CROSS_CHAT:
        {
            OnHandleCrossChat(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

/**
 * \brief 逻辑服通知世界服转发传闻或广播
 * \param msgId
 * \param packet
 * \return
 */
int NFSnsChatMgr::OnHandleSysChatMsgNotify(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::GWSysChatMsgNotify notifyMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, notifyMsg);

    if (!proto_ff::CHAT_CHANNEL_IsValid(notifyMsg.channel()))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CHAT_CHANNEL_IsValid..channelID:{}",notifyMsg.channel());
        return 0;
    }

    proto_ff::GCSystemChatMsgNotify msg;
    msg.set_channel(notifyMsg.channel());
    msg.set_msgtype(notifyMsg.msgtype());
    msg.mutable_players()->CopyFrom(notifyMsg.players());
    msg.mutable_text()->CopyFrom(notifyMsg.text());
    msg.mutable_parmas()->CopyFrom(notifyMsg.parmas());
    msg.mutable_items()->CopyFrom(notifyMsg.items());

    switch (notifyMsg.channel())
    {
        case proto_ff::CHAT_CHANNEL_TEAM:
        {
            //g_GetTeamMgr()->BroadcastTeam(notifyMsg.extraid(), EMODULE_ID_CHAT, LOGIC_TO_CLIENT_SYSTEM_CHAT_MSG_NOTIFY, &msg, false, false);
            break;
        }
        case proto_ff::CHAT_CHANNEL_GUILD:
        {
            SendUnionMsg(proto_ff::LOGIC_TO_CLIENT_SYSTEM_CHAT_MSG_NOTIFY, notifyMsg.extraid(), msg);
            break;
        }
        default:
        {
            SendWorldMsg(proto_ff::LOGIC_TO_CLIENT_SYSTEM_CHAT_MSG_NOTIFY, msg);
        }
        break;
    }

    return 0;
}

int NFSnsChatMgr::OnHandleCrossChat(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::TransChatCrossServerProto chatMsgReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, chatMsgReq);

    proto_ff::GCChatMsgRsp chatMsgRsp;
    proto_ff::CHAT_CHANNEL channelID = chatMsgReq.channel();
    if (!proto_ff::CHAT_CHANNEL_IsValid(channelID))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[center] OnCrossServerChatReq..CHAT_CHANNEL_IsValid..channelID:{}", channelID);
        return false;
    }
    chatMsgRsp.set_channel(channelID);
    chatMsgRsp.mutable_fromplayerinfo()->CopyFrom(*chatMsgReq.mutable_fromplayerinfo());
    chatMsgRsp.mutable_chatcontent()->CopyFrom(*chatMsgReq.mutable_chatcontent());

    //聊天内容
    string strcontent;
    uint64_t cid = 0;
    if (chatMsgReq.has_chatcontent())
    {
        strcontent = chatMsgReq.chatcontent().describes();
    }
    if (chatMsgReq.has_fromplayerinfo())
    {
        cid = chatMsgReq.fromplayerinfo().playerid();
    }

    switch (channelID)
    {
        case proto_ff::CHAT_CHANNEL_ENLIST:
        case proto_ff::CHAT_CHANNEL_CROSS:
        {
            SendWorldMsg(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
            break;
        }
        case proto_ff::CHAT_CHANNEL_TEAM:
        {
            for (int i = 0; i < (int)chatMsgReq.toplayers_size(); i++)
            {
                SendW2C(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgReq.toplayers(i), chatMsgRsp);
            }
            break;
        }
        default:
            break;
    }

    return 0;
}