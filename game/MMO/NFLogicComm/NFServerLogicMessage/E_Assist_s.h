#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Assist.pb.h"
#include "E_Assist_s.h"

#define DEFINE_SHEET_ASSISTBOX_E_ASSISTBOX_LIST_MAX_NUM 8
#define DEFINE_SHEET_ASSISTTHANK_E_ASSISTTHANK_LIST_MAX_NUM 16
#define DEFINE_SHEET_ASSISTCONST_E_ASSISTCONST_LIST_MAX_NUM 2


namespace proto_ff_s {

	struct E_AssistBox_s : public NFDescStoreSeqOP {
		E_AssistBox_s();
		virtual ~E_AssistBox_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_times;//需要协助次数
		int32_t m_itemid;//礼包物品id

		virtual void write_to_pbmsg(::proto_ff::E_AssistBox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AssistBox & msg);
		static ::proto_ff::E_AssistBox* new_pbmsg(){ return new ::proto_ff::E_AssistBox(); }
		static ::proto_ff::E_AssistBox make_pbmsg(){ return ::proto_ff::E_AssistBox(); }
	};
	typedef struct E_AssistBox_s E_AssistBox_t;

	struct Sheet_AssistBox_s : public NFDescStoreSeqOP {
		Sheet_AssistBox_s();
		virtual ~Sheet_AssistBox_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AssistBox_s, DEFINE_SHEET_ASSISTBOX_E_ASSISTBOX_LIST_MAX_NUM> E_AssistBox_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AssistBox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AssistBox & msg);
		static ::proto_ff::Sheet_AssistBox* new_pbmsg(){ return new ::proto_ff::Sheet_AssistBox(); }
		static ::proto_ff::Sheet_AssistBox make_pbmsg(){ return ::proto_ff::Sheet_AssistBox(); }
	};
	typedef struct Sheet_AssistBox_s Sheet_AssistBox_t;

	struct E_AssistThank_s : public NFDescStoreSeqOP {
		E_AssistThank_s();
		virtual ~E_AssistThank_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_msg;//消息

		virtual void write_to_pbmsg(::proto_ff::E_AssistThank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AssistThank & msg);
		static ::proto_ff::E_AssistThank* new_pbmsg(){ return new ::proto_ff::E_AssistThank(); }
		static ::proto_ff::E_AssistThank make_pbmsg(){ return ::proto_ff::E_AssistThank(); }
	};
	typedef struct E_AssistThank_s E_AssistThank_t;

	struct Sheet_AssistThank_s : public NFDescStoreSeqOP {
		Sheet_AssistThank_s();
		virtual ~Sheet_AssistThank_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AssistThank_s, DEFINE_SHEET_ASSISTTHANK_E_ASSISTTHANK_LIST_MAX_NUM> E_AssistThank_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AssistThank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AssistThank & msg);
		static ::proto_ff::Sheet_AssistThank* new_pbmsg(){ return new ::proto_ff::Sheet_AssistThank(); }
		static ::proto_ff::Sheet_AssistThank make_pbmsg(){ return ::proto_ff::Sheet_AssistThank(); }
	};
	typedef struct Sheet_AssistThank_s Sheet_AssistThank_t;

	struct E_AssistConst_s : public NFDescStoreSeqOP {
		E_AssistConst_s();
		virtual ~E_AssistConst_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_senderGift;//求助者礼包id
		int32_t m_senderGiftNum;//求助者礼包每日数量
		int32_t m_helperGift;//协助者礼包id
		int32_t m_helperGiftNum;//协助者礼包每日数量
		int32_t m_prestigeDaylimit;//每日日常声望获取上限
		int32_t m_prestigeDayBosslimit;//每日boss协助声望获取上限

		virtual void write_to_pbmsg(::proto_ff::E_AssistConst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AssistConst & msg);
		static ::proto_ff::E_AssistConst* new_pbmsg(){ return new ::proto_ff::E_AssistConst(); }
		static ::proto_ff::E_AssistConst make_pbmsg(){ return ::proto_ff::E_AssistConst(); }
	};
	typedef struct E_AssistConst_s E_AssistConst_t;

	struct Sheet_AssistConst_s : public NFDescStoreSeqOP {
		Sheet_AssistConst_s();
		virtual ~Sheet_AssistConst_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AssistConst_s, DEFINE_SHEET_ASSISTCONST_E_ASSISTCONST_LIST_MAX_NUM> E_AssistConst_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AssistConst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AssistConst & msg);
		static ::proto_ff::Sheet_AssistConst* new_pbmsg(){ return new ::proto_ff::Sheet_AssistConst(); }
		static ::proto_ff::Sheet_AssistConst make_pbmsg(){ return ::proto_ff::Sheet_AssistConst(); }
	};
	typedef struct Sheet_AssistConst_s Sheet_AssistConst_t;

}

