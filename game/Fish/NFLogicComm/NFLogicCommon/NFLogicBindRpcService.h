// -------------------------------------------------------------------------
//    @FileName         :    NFLogicBindRpcService.h
//    @Author           :    gaoyi
//    @Date             :    23-7-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicBindRpcService
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIRpcService.h"
#include "AllProtocol.h"

/**
 * @brief 账号登录rpc, proxy server to login server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_AccountLoginReq, proto_ff::Proto_CSAccountLoginReq, proto_ff::Proto_SCAccountLoginRsp)

/**
 * @brief 账号注册rpc, proxy server to login server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_RegisterAccountReq, proto_ff::Proto_CSRegisterAccountReq, proto_ff::Proto_SCRegisterAccountRsp)

/**
 * @brief 玩家登录rpc, proxy server to world server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_PTW_PLAYER_LOGIN_REQ, proto_ff::Proto_PTWUserLoginReq, proto_ff::Proto_WTPPlayerLoginRsp)

/**
 * @brief 玩家登录rpc, world server to logic server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_WTL_PLAYER_LOGIN_REQ, proto_ff::Proto_WorldToLogicLoginReq, proto_ff::Proto_LogicToWorldLoginRsp)

/**
 * @brief 玩家登录rpc, world server to sns server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_WTS_PLAYER_LOGIN_REQ, proto_ff::Proto_WTSLoginReq, proto_ff::Proto_STWLoginRsp)

/**
 * @brief 玩家重连rpc, proxy server to world server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_PTW_PLAYER_RECONNECT_MSG_REQ, proto_ff::PTWPlayerReconnectReq, proto_ff::WTPPlayerReconnctRsp)

/**
 * @brief 玩家重连rpc, world server to logic server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_WTL_PLAYER_RECONNECT_MSG_REQ, proto_ff::WTLPlayerReconnectReq, proto_ff::LTWPlayerReconnectRsp)

/**
 * @brief 玩家重连rpc, world server to sns server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_WTS_PLAYER_RECONNECT_MSG_REQ, proto_ff::WTSPlayerReconnectReq, proto_ff::STWPlayerReconnectRsp)

/**
 * @brief 玩家重连rpc, world server to game server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_LTG_PLAYER_RECONNECT_MSG_REQ, proto_ff::LTGPlayerReconnectReq, proto_ff::GTLPlayerReconnectRsp)

/**
 * @brief logic sns银行筹码, logic server to sns server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_LTS_PLAYER_ADD_BANK_JETTON_RPC, proto_ff::Proto_LTS_PlayerAddBankJettonReq, proto_ff::Proto_STL_PlayerAddBankJettonRsp)

/**
 * @brief logic sns银行筹码, logic server to sns server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_LTS_PLAYER_REDUCE_BANK_JETTON_RPC, proto_ff::Proto_LTS_PlayerReduceBankJettonReq, proto_ff::Proto_STL_PlayerReduceBankJettonRsp)

/**
 * @brief query user data,  sns rpc
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_TS_QUERY_PLAYER_SIMPLE_DATA_RPC, proto_ff::Proto_TS_QueryPlayerSimpleDataReq, proto_ff::Proto_ST_QueryPlayerSimpleDataRsp)

/**
 * @brief game register room to world server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_GTW_REGISTER_ROOM_INFO_RPC, proto_ff::Proto_GTW_RegisterRoomInfoReq, proto_ff::Proto_WTG_RegisterRoomInfoRsp)

/**
 * @brief world,logic,game req desk list rpc
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_DeskListReq, proto_ff::DeskListReq, proto_ff::DeskListRsp)

/**
 * @brief world,logic,game req desk list rpc
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_ChairCheckReq, proto_ff::ChairCheckReq, proto_ff::ChairCheckRsp)

/**
 * @brief world,logic,game req enter game rpc
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_EnterGameReq, proto_ff::EnterGameReq, proto_ff::EnterGameRsp)

/**
 * @brief world,to proxy and logic, game bus change rpc
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STS_PLAYER_CHANGE_GAME_SERVER, proto_ff::Proto_STS_PlayerChangeGameServerReq, proto_ff::Proto_STS_PlayerChangeGameServerRsp)

/**
 * @brief world,logic,game req exit game rpc
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_ExitGameReq, proto_ff::ExitGameReq, proto_ff::ExitGameRsp)

/**
 * @brief world,logic,game req exit room rpc
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_ExitRoomReq, proto_ff::ExitRoomReq, proto_ff::ExitRoomRsp)

/**
 * @brief world,logic,game req recome game rpc
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_UserRecomeReq, proto_ff::UserRecomeReq, proto_ff::UserRecomeRsp)

/**
 * @brief game to logic get coin balance rpc
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_GTL_COIN_QUERY_BALANCE_RPC, proto_ff::Proto_QueryCoinBalanceReq, proto_ff::Proto_QueryCoinBalanceRsp)