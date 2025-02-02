// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ComDefine.proto

#ifndef PROTOBUF_ComDefine_2eproto__INCLUDED
#define PROTOBUF_ComDefine_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include "yd_fieldoptions.pb.h"
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ComDefine_2eproto();
void protobuf_AssignDesc_ComDefine_2eproto();
void protobuf_ShutdownFile_ComDefine_2eproto();


enum PingConfig {
  CLIENT_PING_INTERVAL = 9,
  SERVER_PING_INTERVAL = 9
};
bool PingConfig_IsValid(int value);
const PingConfig PingConfig_MIN = CLIENT_PING_INTERVAL;
const PingConfig PingConfig_MAX = CLIENT_PING_INTERVAL;
const int PingConfig_ARRAYSIZE = PingConfig_MAX + 1;

const ::google::protobuf::EnumDescriptor* PingConfig_descriptor();
inline const ::std::string& PingConfig_Name(PingConfig value) {
  return ::google::protobuf::internal::NameOfEnum(
    PingConfig_descriptor(), value);
}
inline bool PingConfig_Parse(
    const ::std::string& name, PingConfig* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PingConfig>(
    PingConfig_descriptor(), name, value);
}
enum Proto_CS_ErrorCode {
  ERR_CODE_SYSTEM_ERROR = -1,
  ERR_CODE_OK = 0,
  ERR_CODE_SYSTEM_TIMEOUT = 10000,
  ERR_CODE_SYSTEM_DATABASE_ERROR = 10001,
  ERR_CODE_MSG_PARAM_ERROR = 10002,
  ERR_CODE_ACCOUNT_PASSWORD_ERROR = 10101,
  ERR_CODE_NEED_RELOGIN = 10102,
  ERR_CODE_ACCOUNT_NOT_EXIST = 10103,
  ERR_CODE_PLAYER_NOT_EXIST = 10104,
  ERR_CODE_TOKEN_ERROR = 10106,
  ERR_CODE_TOKEN_TIMEOUT = 10107,
  ERR_CODE_ACCOUNT_ALREADY_EXIST_NO_RESITER = 10108,
  ERR_CODE_BIND_PHONE_ALREADY = 10109,
  ERR_CODE_PHONE_AUTO_CODE_ERROR = 10110,
  ERR_CODE_PHONE_AUTO_CODE_TIMEOUT = 10111,
  ERR_CODE_PHONE_SEND_TOO_MUCH = 10112,
  ERR_CODE_PHONE_NOT_RIGHT = 10113,
  ERR_CODE_PHONE_ALREADY_BIND = 10114,
  ERR_CODE_VISITOR_LOGIN_DEVICE_ERROR = 10115,
  ERR_CODE_PASSWORD_NOT_CHANGE = 10120,
  ERR_CODE_OTHER_PLACE_LOGIN_ACCOUNT = 10121,
  ERR_CODE_USER_IS_BAN = 10122,
  ERR_CODE_USER_IS_NO_TRANSFER = 10123,
  ERR_CODE_USER_AGENT_DEAD_CYCLE = 10124,
  ERR_CODE_PLAYER_OFFLINE = 10200,
  ERR_CODE_WORLD_MAX_PLAYER_COUNT = 10201,
  ERR_CODE_GAME_ROOM_NOT_ONLINE = 10202,
  ERR_CODE_GAME_ROOM_NOT_EXIST = 10203,
  ERR_CODE_MAIL_CANT_DEL_NO_READ = 10300,
  ERR_CODE_ROLE_MAIL_NOT_FIND = 10301,
  ERR_CODE_GET_MAIL_FAIL = 10304,
  ERR_CODE_READ_MAIL_FAIL = 10305,
  ERR_CODE_DEL_MAIL_FAIL = 10306,
  ERR_CODE_BANK_PASSWORD_NOT_RIGHT = 10400,
  ERR_CODE_BANK_PASSWORD_FORMAT_NOT_RIGHT = 10401,
  ERR_CODE_FACE_NOT_EXIST = 10402,
  ERR_CODE_BANK_GIVE_MONEY_NOT_TO_MYSELF = 10403,
  ERR_CODE_IN_GAMEING_NOT_BANK = 10404,
  ERR_CODE_FIRST_BIND_PHONE = 10405,
  ERR_CODE_BANK_NOT_VIP_ZHUAN_NOT_VIP = 10406,
  ERR_CODE_BANK_DRAW_MIN_JETTON = 10407,
  ERR_CODE_MODIFY_MONEY_LESS_ZERO = 10501,
  ERR_CODE_MODIFY_MONEY_TIMEOUT = 10502,
  ERR_CODE_PLAYER_ALREADY_BIND_PHONE = 10503,
  ERR_CODE_PLAYER_DONOT_CHANGE_PHONE = 10504,
  ERR_CODE_PLAYER_PHONE_AUTO_CODE_TOO_MUCH = 10505,
  ERR_CODE_EXIT_NOT_PERMITED_WHILE_PLAYING = 10600,
  EOT_CODE_REDEEM_CODE_USED = 10700,
  EOT_CODE_REDEEM_CODE_NOT_EXIST = 10701,
  EOT_CODE_REDEEM_CODE_UNREG_USER = 10702,
  EOT_CODE_REDEEM_CODE_HAS_USED = 10703,
  ERR_CODE_USER_MONEY_NOT_ENOUGH = 11000,
  ERR_CODE_USER_IN_GAMEING = 11001,
  ERR_CODE_CHAIR_HAS_OTHER_PLAYTER = 11002,
  ERR_CODE_CHAIR_NOT_RIGHT = 11003,
  ERR_CODE_USER_MONEY_TOO_MUCH = 11004,
  ERR_CODE_DESK_NOT_EXIST = 11005
};
bool Proto_CS_ErrorCode_IsValid(int value);
const Proto_CS_ErrorCode Proto_CS_ErrorCode_MIN = ERR_CODE_SYSTEM_ERROR;
const Proto_CS_ErrorCode Proto_CS_ErrorCode_MAX = ERR_CODE_DESK_NOT_EXIST;
const int Proto_CS_ErrorCode_ARRAYSIZE = Proto_CS_ErrorCode_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_CS_ErrorCode_descriptor();
inline const ::std::string& Proto_CS_ErrorCode_Name(Proto_CS_ErrorCode value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_CS_ErrorCode_descriptor(), value);
}
inline bool Proto_CS_ErrorCode_Parse(
    const ::std::string& name, Proto_CS_ErrorCode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_CS_ErrorCode>(
    Proto_CS_ErrorCode_descriptor(), name, value);
}
enum Proto_AccountType {
  E_VISITOR = 0,
  E_ACCOUNT = 1,
  E_WECHAT = 2,
  E_PHONE = 3,
  E_ROBOT = 10
};
bool Proto_AccountType_IsValid(int value);
const Proto_AccountType Proto_AccountType_MIN = E_VISITOR;
const Proto_AccountType Proto_AccountType_MAX = E_ROBOT;
const int Proto_AccountType_ARRAYSIZE = Proto_AccountType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_AccountType_descriptor();
inline const ::std::string& Proto_AccountType_Name(Proto_AccountType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_AccountType_descriptor(), value);
}
inline bool Proto_AccountType_Parse(
    const ::std::string& name, Proto_AccountType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_AccountType>(
    Proto_AccountType_descriptor(), name, value);
}
enum Proto_SexType {
  E_MALE = 0,
  E_FEMALE = 1
};
bool Proto_SexType_IsValid(int value);
const Proto_SexType Proto_SexType_MIN = E_MALE;
const Proto_SexType Proto_SexType_MAX = E_FEMALE;
const int Proto_SexType_ARRAYSIZE = Proto_SexType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_SexType_descriptor();
inline const ::std::string& Proto_SexType_Name(Proto_SexType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_SexType_descriptor(), value);
}
inline bool Proto_SexType_Parse(
    const ::std::string& name, Proto_SexType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_SexType>(
    Proto_SexType_descriptor(), name, value);
}
enum Proto_PlatType {
  E_PLAT_NONE = 0,
  E_PLAT_ANDROID = 1,
  E_PLAT_IOS = 2,
  E_PLAT_WP = 3,
  E_PLAT_MAX = 4
};
bool Proto_PlatType_IsValid(int value);
const Proto_PlatType Proto_PlatType_MIN = E_PLAT_NONE;
const Proto_PlatType Proto_PlatType_MAX = E_PLAT_MAX;
const int Proto_PlatType_ARRAYSIZE = Proto_PlatType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_PlatType_descriptor();
inline const ::std::string& Proto_PlatType_Name(Proto_PlatType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_PlatType_descriptor(), value);
}
inline bool Proto_PlatType_Parse(
    const ::std::string& name, Proto_PlatType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_PlatType>(
    Proto_PlatType_descriptor(), name, value);
}
enum Proto_NetworkType {
  E_NETWORK_2G = 0,
  E_NETWORK_3G = 1,
  E_NETWORK_4G = 2,
  E_NETWORK_WIFI = 3
};
bool Proto_NetworkType_IsValid(int value);
const Proto_NetworkType Proto_NetworkType_MIN = E_NETWORK_2G;
const Proto_NetworkType Proto_NetworkType_MAX = E_NETWORK_WIFI;
const int Proto_NetworkType_ARRAYSIZE = Proto_NetworkType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_NetworkType_descriptor();
inline const ::std::string& Proto_NetworkType_Name(Proto_NetworkType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_NetworkType_descriptor(), value);
}
inline bool Proto_NetworkType_Parse(
    const ::std::string& name, Proto_NetworkType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_NetworkType>(
    Proto_NetworkType_descriptor(), name, value);
}
enum Proto_PlayerCreateState {
  E_CREATE_SUCESS = 0,
  E_CREATE_REGIST_NAME = 1,
  E_CREATE_WAIT_NAME = 2
};
bool Proto_PlayerCreateState_IsValid(int value);
const Proto_PlayerCreateState Proto_PlayerCreateState_MIN = E_CREATE_SUCESS;
const Proto_PlayerCreateState Proto_PlayerCreateState_MAX = E_CREATE_WAIT_NAME;
const int Proto_PlayerCreateState_ARRAYSIZE = Proto_PlayerCreateState_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_PlayerCreateState_descriptor();
inline const ::std::string& Proto_PlayerCreateState_Name(Proto_PlayerCreateState value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_PlayerCreateState_descriptor(), value);
}
inline bool Proto_PlayerCreateState_Parse(
    const ::std::string& name, Proto_PlayerCreateState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_PlayerCreateState>(
    Proto_PlayerCreateState_descriptor(), name, value);
}
enum PlayerStatus {
  PLAYER_STATUS_NONE = 0,
  PLAYER_STATUS_ONLINE = 1,
  PLAYER_STATUS_OFFLINE = 2,
  PLAYER_STATUS_LOGOUT = 3,
  PLAYER_STATUS_DEAD = 4
};
bool PlayerStatus_IsValid(int value);
const PlayerStatus PlayerStatus_MIN = PLAYER_STATUS_NONE;
const PlayerStatus PlayerStatus_MAX = PLAYER_STATUS_DEAD;
const int PlayerStatus_ARRAYSIZE = PlayerStatus_MAX + 1;

const ::google::protobuf::EnumDescriptor* PlayerStatus_descriptor();
inline const ::std::string& PlayerStatus_Name(PlayerStatus value) {
  return ::google::protobuf::internal::NameOfEnum(
    PlayerStatus_descriptor(), value);
}
inline bool PlayerStatus_Parse(
    const ::std::string& name, PlayerStatus* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PlayerStatus>(
    PlayerStatus_descriptor(), name, value);
}
enum enConstType {
  EN_CONST_NONE = 0,
  EN_CONST_USER_INIT_JETTON = 1,
  EN_CONST_USER_INIT_FACE = 2,
  EN_CONST_USER_INIT_BANK_JETTON = 3,
  EN_CONST_USER_ACH_WITH_FEE = 4,
  EN_CONST_USER_FEE_WITH_POUR = 5,
  EN_CONST_USER_MIN_BANK_DRAW = 6
};
bool enConstType_IsValid(int value);
const enConstType enConstType_MIN = EN_CONST_NONE;
const enConstType enConstType_MAX = EN_CONST_USER_MIN_BANK_DRAW;
const int enConstType_ARRAYSIZE = enConstType_MAX + 1;

const ::google::protobuf::EnumDescriptor* enConstType_descriptor();
inline const ::std::string& enConstType_Name(enConstType value) {
  return ::google::protobuf::internal::NameOfEnum(
    enConstType_descriptor(), value);
}
inline bool enConstType_Parse(
    const ::std::string& name, enConstType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<enConstType>(
    enConstType_descriptor(), name, value);
}
enum eAccountMoneyType {
  E_ACCOUNT_TYPE_JETTON = 0,
  E_ACCOUNT_TYPE_BANK_JETTON = 1,
  E_ACCOUNT_TYPE_MAX = 2
};
bool eAccountMoneyType_IsValid(int value);
const eAccountMoneyType eAccountMoneyType_MIN = E_ACCOUNT_TYPE_JETTON;
const eAccountMoneyType eAccountMoneyType_MAX = E_ACCOUNT_TYPE_MAX;
const int eAccountMoneyType_ARRAYSIZE = eAccountMoneyType_MAX + 1;

const ::google::protobuf::EnumDescriptor* eAccountMoneyType_descriptor();
inline const ::std::string& eAccountMoneyType_Name(eAccountMoneyType value) {
  return ::google::protobuf::internal::NameOfEnum(
    eAccountMoneyType_descriptor(), value);
}
inline bool eAccountMoneyType_Parse(
    const ::std::string& name, eAccountMoneyType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<eAccountMoneyType>(
    eAccountMoneyType_descriptor(), name, value);
}
enum eChangeMoneyType {
  E_CHAGEMONEY_GAME_ADD = 0,
  E_CHAGEMONEY_GAME_REMOVE = 1,
  E_CHAGEMONEY_GAME_ADD_GM = 2,
  E_CHAGEMONEY_GAME_REMOVE_GM = 3,
  E_CHAGEMONEY_BANK_SAVE_MONEY_REMOVE = 4,
  E_CHAGEMONEY_BANK_GET_MONEY_ADD = 5,
  E_CHAGEMONEY_MAIL_ADD = 6,
  E_CHAGEMONEY_GIVE_JETTON_TO_OTHER_REMOVE = 7,
  E_CHAGEMONEY_OTHER_GEVE_JETTON_TO_ME_ADD = 8,
  E_CHAGEMONEY_TYPE_MAX = 9
};
bool eChangeMoneyType_IsValid(int value);
const eChangeMoneyType eChangeMoneyType_MIN = E_CHAGEMONEY_GAME_ADD;
const eChangeMoneyType eChangeMoneyType_MAX = E_CHAGEMONEY_TYPE_MAX;
const int eChangeMoneyType_ARRAYSIZE = eChangeMoneyType_MAX + 1;

const ::google::protobuf::EnumDescriptor* eChangeMoneyType_descriptor();
inline const ::std::string& eChangeMoneyType_Name(eChangeMoneyType value) {
  return ::google::protobuf::internal::NameOfEnum(
    eChangeMoneyType_descriptor(), value);
}
inline bool eChangeMoneyType_Parse(
    const ::std::string& name, eChangeMoneyType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<eChangeMoneyType>(
    eChangeMoneyType_descriptor(), name, value);
}
enum eOperationType {
  E_USER_JETTON_OPER_TYPE_GAME_BALANCED_WIN = 0,
  E_USER_JETTON_OPER_TYPE_GAME_BALANCED_LOST = 1,
  E_USER_JETTON_OPER_TYPE_EXCHANGE = 2,
  E_USER_JETTON_OPER_TYPE_TRANSFER = 3,
  E_USER_JETTON_OPER_TYPE_RECHARGE = 4,
  E_USER_JETTON_OPER_TYPE_WEB_DEDUCT_NONEY = 5,
  E_USER_JETTON_OPER_TYPE_WEB_GIVE_MONEY = 6,
  E_USER_JETTON_OPER_TYPE_GIVE_JETTON = 7,
  E_USER_JETTON_OPER_TYPE_DRAW = 8,
  E_USER_JETTON_OPER_TYPE_MAX = 9
};
bool eOperationType_IsValid(int value);
const eOperationType eOperationType_MIN = E_USER_JETTON_OPER_TYPE_GAME_BALANCED_WIN;
const eOperationType eOperationType_MAX = E_USER_JETTON_OPER_TYPE_MAX;
const int eOperationType_ARRAYSIZE = eOperationType_MAX + 1;

const ::google::protobuf::EnumDescriptor* eOperationType_descriptor();
inline const ::std::string& eOperationType_Name(eOperationType value) {
  return ::google::protobuf::internal::NameOfEnum(
    eOperationType_descriptor(), value);
}
inline bool eOperationType_Parse(
    const ::std::string& name, eOperationType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<eOperationType>(
    eOperationType_descriptor(), name, value);
}
enum eDrawReasonType {
  E_RECHARGE_PAY_TYPE_VIP_DRAW = 1
};
bool eDrawReasonType_IsValid(int value);
const eDrawReasonType eDrawReasonType_MIN = E_RECHARGE_PAY_TYPE_VIP_DRAW;
const eDrawReasonType eDrawReasonType_MAX = E_RECHARGE_PAY_TYPE_VIP_DRAW;
const int eDrawReasonType_ARRAYSIZE = eDrawReasonType_MAX + 1;

const ::google::protobuf::EnumDescriptor* eDrawReasonType_descriptor();
inline const ::std::string& eDrawReasonType_Name(eDrawReasonType value) {
  return ::google::protobuf::internal::NameOfEnum(
    eDrawReasonType_descriptor(), value);
}
inline bool eDrawReasonType_Parse(
    const ::std::string& name, eDrawReasonType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<eDrawReasonType>(
    eDrawReasonType_descriptor(), name, value);
}
enum eRechargeResonType {
  E_RECHARGE_PAY_TYPE_VIP_RECHARGE = 1,
  E_RECHARGE_PAY_TYPE_WEB_ZHUANGZHANG_PLATFORM = 2,
  E_RECHARGE_PAY_TYPE_POINTCARD = 3,
  E_RECHARGE_PAY_TYPE_ALIPAY = 4,
  E_RECHARGE_PAY_TYPE_TENPAY = 5,
  E_RECHARGE_PAY_TYPE_APPLE = 6,
  E_RECHARGE_PAY_TYPE_YINGYONGBAO = 7
};
bool eRechargeResonType_IsValid(int value);
const eRechargeResonType eRechargeResonType_MIN = E_RECHARGE_PAY_TYPE_VIP_RECHARGE;
const eRechargeResonType eRechargeResonType_MAX = E_RECHARGE_PAY_TYPE_YINGYONGBAO;
const int eRechargeResonType_ARRAYSIZE = eRechargeResonType_MAX + 1;

const ::google::protobuf::EnumDescriptor* eRechargeResonType_descriptor();
inline const ::std::string& eRechargeResonType_Name(eRechargeResonType value) {
  return ::google::protobuf::internal::NameOfEnum(
    eRechargeResonType_descriptor(), value);
}
inline bool eRechargeResonType_Parse(
    const ::std::string& name, eRechargeResonType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<eRechargeResonType>(
    eRechargeResonType_descriptor(), name, value);
}
enum eGameBalanceOperationWinReason {
  E_GAME_BALANCE_REASON_PLAY_GAME_WIN = 0,
  E_GAME_BALANCE_REASON_TYPE_DO_LOTTERY_WIN = 1,
  E_GAME_BALANCE_REASON_WIN_MAX = 2
};
bool eGameBalanceOperationWinReason_IsValid(int value);
const eGameBalanceOperationWinReason eGameBalanceOperationWinReason_MIN = E_GAME_BALANCE_REASON_PLAY_GAME_WIN;
const eGameBalanceOperationWinReason eGameBalanceOperationWinReason_MAX = E_GAME_BALANCE_REASON_WIN_MAX;
const int eGameBalanceOperationWinReason_ARRAYSIZE = eGameBalanceOperationWinReason_MAX + 1;

const ::google::protobuf::EnumDescriptor* eGameBalanceOperationWinReason_descriptor();
inline const ::std::string& eGameBalanceOperationWinReason_Name(eGameBalanceOperationWinReason value) {
  return ::google::protobuf::internal::NameOfEnum(
    eGameBalanceOperationWinReason_descriptor(), value);
}
inline bool eGameBalanceOperationWinReason_Parse(
    const ::std::string& name, eGameBalanceOperationWinReason* value) {
  return ::google::protobuf::internal::ParseNamedEnum<eGameBalanceOperationWinReason>(
    eGameBalanceOperationWinReason_descriptor(), name, value);
}
enum eGameBalanceOperationLostReason {
  E_GAME_BALANCE_REASON_PLAY_GAME_LOST = 0,
  E_GAME_BALANCE_REASON_TYPE_DO_LOTTERY_LOST = 1,
  E_GAME_BALANCE_REASON_LOST_MAX = 2
};
bool eGameBalanceOperationLostReason_IsValid(int value);
const eGameBalanceOperationLostReason eGameBalanceOperationLostReason_MIN = E_GAME_BALANCE_REASON_PLAY_GAME_LOST;
const eGameBalanceOperationLostReason eGameBalanceOperationLostReason_MAX = E_GAME_BALANCE_REASON_LOST_MAX;
const int eGameBalanceOperationLostReason_ARRAYSIZE = eGameBalanceOperationLostReason_MAX + 1;

const ::google::protobuf::EnumDescriptor* eGameBalanceOperationLostReason_descriptor();
inline const ::std::string& eGameBalanceOperationLostReason_Name(eGameBalanceOperationLostReason value) {
  return ::google::protobuf::internal::NameOfEnum(
    eGameBalanceOperationLostReason_descriptor(), value);
}
inline bool eGameBalanceOperationLostReason_Parse(
    const ::std::string& name, eGameBalanceOperationLostReason* value) {
  return ::google::protobuf::internal::ParseNamedEnum<eGameBalanceOperationLostReason>(
    eGameBalanceOperationLostReason_descriptor(), name, value);
}
enum eGiveMoneyReason {
  E_GIVE_MONEY_REASON_WEB_SYSTEM = 0,
  E_GIVE_MONEY_REASON_PROMOTE = 1,
  E_GIVE_MONEY_REASON_FIRST_RECHARGE = 2,
  E_GIVE_MONEY_REASON_BUY_PROP = 3,
  E_GIVE_MONEY_SHARE_GAME = 4,
  E_GIVE_MONEY_REASON_RECLAIM_PROP = 5,
  E_GIVE_MONEY_REASON_FIRST_REGISTER = 6,
  E_GIVE_MONEY_REASON_PLAT_USER_CHANGE_TO_AGENT_USER = 7,
  E_GIVE_MONEY_REASON_FINISH_TASK = 8,
  E_GIVE_MONEY_REASON_RELIF_FUND = 9,
  E_GIVE_MONEY_REASON_EVERYDAY_LOGIN_COMMERCE = 10,
  E_GIVE_MONEY_REASON_COMPLETE_USER_INFO = 11,
  E_GIVE_MONEY_REASON_TOOL_CMD = 12,
  E_GIVE_MONEY_REASON_PROMOTE_PROFIT = 13,
  E_GIVE_MONEY_REASON_MAX = 14
};
bool eGiveMoneyReason_IsValid(int value);
const eGiveMoneyReason eGiveMoneyReason_MIN = E_GIVE_MONEY_REASON_WEB_SYSTEM;
const eGiveMoneyReason eGiveMoneyReason_MAX = E_GIVE_MONEY_REASON_MAX;
const int eGiveMoneyReason_ARRAYSIZE = eGiveMoneyReason_MAX + 1;

const ::google::protobuf::EnumDescriptor* eGiveMoneyReason_descriptor();
inline const ::std::string& eGiveMoneyReason_Name(eGiveMoneyReason value) {
  return ::google::protobuf::internal::NameOfEnum(
    eGiveMoneyReason_descriptor(), value);
}
inline bool eGiveMoneyReason_Parse(
    const ::std::string& name, eGiveMoneyReason* value) {
  return ::google::protobuf::internal::ParseNamedEnum<eGiveMoneyReason>(
    eGiveMoneyReason_descriptor(), name, value);
}
enum eMoneyExchangeReason {
  E_EXCHANGE_REASON_SAVE_MONEY = 0,
  E_EXCHANGE_REASON_DRAW_MONEY = 1,
  E_EXCHANGE_REASON_MAX = 2
};
bool eMoneyExchangeReason_IsValid(int value);
const eMoneyExchangeReason eMoneyExchangeReason_MIN = E_EXCHANGE_REASON_SAVE_MONEY;
const eMoneyExchangeReason eMoneyExchangeReason_MAX = E_EXCHANGE_REASON_MAX;
const int eMoneyExchangeReason_ARRAYSIZE = eMoneyExchangeReason_MAX + 1;

const ::google::protobuf::EnumDescriptor* eMoneyExchangeReason_descriptor();
inline const ::std::string& eMoneyExchangeReason_Name(eMoneyExchangeReason value) {
  return ::google::protobuf::internal::NameOfEnum(
    eMoneyExchangeReason_descriptor(), value);
}
inline bool eMoneyExchangeReason_Parse(
    const ::std::string& name, eMoneyExchangeReason* value) {
  return ::google::protobuf::internal::ParseNamedEnum<eMoneyExchangeReason>(
    eMoneyExchangeReason_descriptor(), name, value);
}
enum eMoneyTransferReason {
  E_TRANSFER_REASON_USER = 0,
  E_TRANSFER_REASON_FROM_USER = 1,
  E_TRANSFER_REASON_VIP_ZHUANRU = 2,
  E_TRANSFER_REASON_VIP_ZHUANCHU = 3,
  E_TRANSFER_REASON_VIP_TO_VIP = 4,
  E_TRANSFER_REASON_MAX = 5
};
bool eMoneyTransferReason_IsValid(int value);
const eMoneyTransferReason eMoneyTransferReason_MIN = E_TRANSFER_REASON_USER;
const eMoneyTransferReason eMoneyTransferReason_MAX = E_TRANSFER_REASON_MAX;
const int eMoneyTransferReason_ARRAYSIZE = eMoneyTransferReason_MAX + 1;

const ::google::protobuf::EnumDescriptor* eMoneyTransferReason_descriptor();
inline const ::std::string& eMoneyTransferReason_Name(eMoneyTransferReason value) {
  return ::google::protobuf::internal::NameOfEnum(
    eMoneyTransferReason_descriptor(), value);
}
inline bool eMoneyTransferReason_Parse(
    const ::std::string& name, eMoneyTransferReason* value) {
  return ::google::protobuf::internal::ParseNamedEnum<eMoneyTransferReason>(
    eMoneyTransferReason_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::PingConfig>() {
  return ::proto_ff::PingConfig_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_CS_ErrorCode>() {
  return ::proto_ff::Proto_CS_ErrorCode_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_AccountType>() {
  return ::proto_ff::Proto_AccountType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_SexType>() {
  return ::proto_ff::Proto_SexType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_PlatType>() {
  return ::proto_ff::Proto_PlatType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_NetworkType>() {
  return ::proto_ff::Proto_NetworkType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_PlayerCreateState>() {
  return ::proto_ff::Proto_PlayerCreateState_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::PlayerStatus>() {
  return ::proto_ff::PlayerStatus_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::enConstType>() {
  return ::proto_ff::enConstType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::eAccountMoneyType>() {
  return ::proto_ff::eAccountMoneyType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::eChangeMoneyType>() {
  return ::proto_ff::eChangeMoneyType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::eOperationType>() {
  return ::proto_ff::eOperationType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::eDrawReasonType>() {
  return ::proto_ff::eDrawReasonType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::eRechargeResonType>() {
  return ::proto_ff::eRechargeResonType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::eGameBalanceOperationWinReason>() {
  return ::proto_ff::eGameBalanceOperationWinReason_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::eGameBalanceOperationLostReason>() {
  return ::proto_ff::eGameBalanceOperationLostReason_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::eGiveMoneyReason>() {
  return ::proto_ff::eGiveMoneyReason_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::eMoneyExchangeReason>() {
  return ::proto_ff::eMoneyExchangeReason_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::eMoneyTransferReason>() {
  return ::proto_ff::eMoneyTransferReason_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ComDefine_2eproto__INCLUDED
