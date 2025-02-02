#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Functionunlock.pb.h"
#include "E_Functionunlock_s.h"

#define DEFINE_SHEET_FUNCTIONUNLOCKFUNCTIONUNLOCK_E_FUNCTIONUNLOCKFUNCTIONUNLOCK_LIST_MAX_NUM 512
#define DEFINE_SHEET_FUNCTIONUNLOCKPREVIEW_E_FUNCTIONUNLOCKPREVIEW_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_FunctionunlockFunctionunlock_s : public NFDescStoreSeqOP {
		E_FunctionunlockFunctionunlock_s();
		virtual ~E_FunctionunlockFunctionunlock_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_functionId;//功能id
		int32_t m_openDaily;//开服多少天开放
		int32_t m_openType;//开放方式
		int64_t m_openVal;//开放数值
		int32_t m_defaultClosed;//客户端默认为关闭
		int32_t m_iconOpenVal;//提前显示icon参数
		int32_t m_iconDisapearID;//icon消失ID
		int32_t m_belong;//附属

		virtual void write_to_pbmsg(::proto_ff::E_FunctionunlockFunctionunlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FunctionunlockFunctionunlock & msg);
		static ::proto_ff::E_FunctionunlockFunctionunlock* new_pbmsg(){ return new ::proto_ff::E_FunctionunlockFunctionunlock(); }
		static ::proto_ff::E_FunctionunlockFunctionunlock make_pbmsg(){ return ::proto_ff::E_FunctionunlockFunctionunlock(); }
	};
	typedef struct E_FunctionunlockFunctionunlock_s E_FunctionunlockFunctionunlock_t;

	struct Sheet_FunctionunlockFunctionunlock_s : public NFDescStoreSeqOP {
		Sheet_FunctionunlockFunctionunlock_s();
		virtual ~Sheet_FunctionunlockFunctionunlock_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FunctionunlockFunctionunlock_s, DEFINE_SHEET_FUNCTIONUNLOCKFUNCTIONUNLOCK_E_FUNCTIONUNLOCKFUNCTIONUNLOCK_LIST_MAX_NUM> E_FunctionunlockFunctionunlock_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FunctionunlockFunctionunlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FunctionunlockFunctionunlock & msg);
		static ::proto_ff::Sheet_FunctionunlockFunctionunlock* new_pbmsg(){ return new ::proto_ff::Sheet_FunctionunlockFunctionunlock(); }
		static ::proto_ff::Sheet_FunctionunlockFunctionunlock make_pbmsg(){ return ::proto_ff::Sheet_FunctionunlockFunctionunlock(); }
	};
	typedef struct Sheet_FunctionunlockFunctionunlock_s Sheet_FunctionunlockFunctionunlock_t;

	struct E_FunctionunlockPreview_s : public NFDescStoreSeqOP {
		E_FunctionunlockPreview_s();
		virtual ~E_FunctionunlockPreview_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_functionId;//功能id
		int32_t m_rewardItem;//奖励的道具ID
		int32_t m_rewardNum;//道具的数量

		virtual void write_to_pbmsg(::proto_ff::E_FunctionunlockPreview & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FunctionunlockPreview & msg);
		static ::proto_ff::E_FunctionunlockPreview* new_pbmsg(){ return new ::proto_ff::E_FunctionunlockPreview(); }
		static ::proto_ff::E_FunctionunlockPreview make_pbmsg(){ return ::proto_ff::E_FunctionunlockPreview(); }
	};
	typedef struct E_FunctionunlockPreview_s E_FunctionunlockPreview_t;

	struct Sheet_FunctionunlockPreview_s : public NFDescStoreSeqOP {
		Sheet_FunctionunlockPreview_s();
		virtual ~Sheet_FunctionunlockPreview_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FunctionunlockPreview_s, DEFINE_SHEET_FUNCTIONUNLOCKPREVIEW_E_FUNCTIONUNLOCKPREVIEW_LIST_MAX_NUM> E_FunctionunlockPreview_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FunctionunlockPreview & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FunctionunlockPreview & msg);
		static ::proto_ff::Sheet_FunctionunlockPreview* new_pbmsg(){ return new ::proto_ff::Sheet_FunctionunlockPreview(); }
		static ::proto_ff::Sheet_FunctionunlockPreview make_pbmsg(){ return ::proto_ff::Sheet_FunctionunlockPreview(); }
	};
	typedef struct Sheet_FunctionunlockPreview_s Sheet_FunctionunlockPreview_t;

}

