#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Teleport.pb.h"
#include "E_Teleport_s.h"

#define DEFINE_SHEET_TELEPORTTELEPORT_E_TELEPORTTELEPORT_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_TeleportTeleport_s : public NFDescStoreSeqOP {
		E_TeleportTeleport_s();
		virtual ~E_TeleportTeleport_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_teleportID;//传送点ID
		int32_t m_teleportType;//传送门类型
		NFShmString<64> m_name;//传送点名称
		int64_t m_monsterId;//传送门怪物ID
		int32_t m_showCondition;//出现条件
		NFShmString<64> m_conditionValue;//条件参数
		int32_t m_canEnter;//进入权限
		int64_t m_showPathID;//默认位置点
		int64_t m_toPathID;//传送目的位置点
		int64_t m_toDuplicateId;//传送副本ID
		NFShmString<64> m_enterCost;//进入道具消耗
		int32_t m_trigRange;//触发范围
		int32_t m_livingTime;//传送门存在时间
		int64_t m_openChatId;//开启时的跑马灯ID
		int64_t m_progressChatId;//进度跑马灯ID

		virtual void write_to_pbmsg(::proto_ff::E_TeleportTeleport & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TeleportTeleport & msg);
		static ::proto_ff::E_TeleportTeleport* new_pbmsg(){ return new ::proto_ff::E_TeleportTeleport(); }
		static ::proto_ff::E_TeleportTeleport make_pbmsg(){ return ::proto_ff::E_TeleportTeleport(); }
	};
	typedef struct E_TeleportTeleport_s E_TeleportTeleport_t;

	struct Sheet_TeleportTeleport_s : public NFDescStoreSeqOP {
		Sheet_TeleportTeleport_s();
		virtual ~Sheet_TeleportTeleport_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TeleportTeleport_s, DEFINE_SHEET_TELEPORTTELEPORT_E_TELEPORTTELEPORT_LIST_MAX_NUM> E_TeleportTeleport_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TeleportTeleport & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TeleportTeleport & msg);
		static ::proto_ff::Sheet_TeleportTeleport* new_pbmsg(){ return new ::proto_ff::Sheet_TeleportTeleport(); }
		static ::proto_ff::Sheet_TeleportTeleport make_pbmsg(){ return ::proto_ff::Sheet_TeleportTeleport(); }
	};
	typedef struct Sheet_TeleportTeleport_s Sheet_TeleportTeleport_t;

}

