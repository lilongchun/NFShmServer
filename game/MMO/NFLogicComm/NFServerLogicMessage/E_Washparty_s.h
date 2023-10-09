#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Washparty.pb.h"
#include "E_Washparty_s.h"

#define DEFINE_SHEET_WASHPARTYWASHPARTY_E_WASHPARTYWASHPARTY_LIST_MAX_NUM 16
#define DEFINE_SHEET_WASHPARTYEXP_E_WASHPARTYEXP_LIST_MAX_NUM 512


namespace proto_ff_s {

	struct E_WashpartyWashparty_s : public NFDescStoreSeqOP {
		E_WashpartyWashparty_s();
		virtual ~E_WashpartyWashparty_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_collectid;//采集物id
		int32_t m_collectnum;//采集次数
		int32_t m_collectposid;//采集物位置id
		int32_t m_collectgeninterval;//采集物刷新时间间隔
		int32_t m_collectmax;//采集物最大数量
		int32_t m_splashnum;//泼水次数
		int32_t m_splashreward;//泼水奖励id
		int32_t m_massagenum;//按摩次数
		int32_t m_massagetime;//按摩时长
		int32_t m_massagereward;//按摩奖励id
		int32_t m_pairexpaddition;//双修时经验加成
		int32_t m_mapid;//所在地图id
		int32_t m_duration;//持续时间
		int32_t m_expaddinterval;//多少秒获得一次经验
		int32_t m_splashsi;//泼水技能ID
		int32_t m_birthareaid;//出生区域
		int32_t m_actid;//活动ID

		virtual void write_to_pbmsg(::proto_ff::E_WashpartyWashparty & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WashpartyWashparty & msg);
		static ::proto_ff::E_WashpartyWashparty* new_pbmsg(){ return new ::proto_ff::E_WashpartyWashparty(); }
		static ::proto_ff::E_WashpartyWashparty make_pbmsg(){ return ::proto_ff::E_WashpartyWashparty(); }
	};
	typedef struct E_WashpartyWashparty_s E_WashpartyWashparty_t;

	struct Sheet_WashpartyWashparty_s : public NFDescStoreSeqOP {
		Sheet_WashpartyWashparty_s();
		virtual ~Sheet_WashpartyWashparty_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WashpartyWashparty_s, DEFINE_SHEET_WASHPARTYWASHPARTY_E_WASHPARTYWASHPARTY_LIST_MAX_NUM> E_WashpartyWashparty_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WashpartyWashparty & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WashpartyWashparty & msg);
		static ::proto_ff::Sheet_WashpartyWashparty* new_pbmsg(){ return new ::proto_ff::Sheet_WashpartyWashparty(); }
		static ::proto_ff::Sheet_WashpartyWashparty make_pbmsg(){ return ::proto_ff::Sheet_WashpartyWashparty(); }
	};
	typedef struct Sheet_WashpartyWashparty_s Sheet_WashpartyWashparty_t;

	struct E_WashpartyExp_s : public NFDescStoreSeqOP {
		E_WashpartyExp_s();
		virtual ~E_WashpartyExp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_washexp;//泡澡经验

		virtual void write_to_pbmsg(::proto_ff::E_WashpartyExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WashpartyExp & msg);
		static ::proto_ff::E_WashpartyExp* new_pbmsg(){ return new ::proto_ff::E_WashpartyExp(); }
		static ::proto_ff::E_WashpartyExp make_pbmsg(){ return ::proto_ff::E_WashpartyExp(); }
	};
	typedef struct E_WashpartyExp_s E_WashpartyExp_t;

	struct Sheet_WashpartyExp_s : public NFDescStoreSeqOP {
		Sheet_WashpartyExp_s();
		virtual ~Sheet_WashpartyExp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WashpartyExp_s, DEFINE_SHEET_WASHPARTYEXP_E_WASHPARTYEXP_LIST_MAX_NUM> E_WashpartyExp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WashpartyExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WashpartyExp & msg);
		static ::proto_ff::Sheet_WashpartyExp* new_pbmsg(){ return new ::proto_ff::Sheet_WashpartyExp(); }
		static ::proto_ff::Sheet_WashpartyExp make_pbmsg(){ return ::proto_ff::Sheet_WashpartyExp(); }
	};
	typedef struct Sheet_WashpartyExp_s Sheet_WashpartyExp_t;

}
