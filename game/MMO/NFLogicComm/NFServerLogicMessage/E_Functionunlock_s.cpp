#include "E_Functionunlock_s.h"

namespace proto_ff_s {

E_FunctionunlockFunctionunlock_s::E_FunctionunlockFunctionunlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FunctionunlockFunctionunlock_s::CreateInit() {
	m_functionId = (int32_t)0;
	m_openDaily = (int32_t)0;
	m_openType = (int32_t)0;
	m_openVal = (int64_t)0;
	m_defaultClosed = (int32_t)0;
	m_iconOpenVal = (int32_t)0;
	m_iconDisapearID = (int32_t)0;
	m_belong = (int32_t)0;
	return 0;
}

int E_FunctionunlockFunctionunlock_s::ResumeInit() {
	return 0;
}

void E_FunctionunlockFunctionunlock_s::write_to_pbmsg(::proto_ff::E_FunctionunlockFunctionunlock & msg) const {
	msg.set_m_functionid((int32_t)m_functionId);
	msg.set_m_opendaily((int32_t)m_openDaily);
	msg.set_m_opentype((int32_t)m_openType);
	msg.set_m_openval((int64_t)m_openVal);
	msg.set_m_defaultclosed((int32_t)m_defaultClosed);
	msg.set_m_iconopenval((int32_t)m_iconOpenVal);
	msg.set_m_icondisapearid((int32_t)m_iconDisapearID);
	msg.set_m_belong((int32_t)m_belong);
}

void E_FunctionunlockFunctionunlock_s::read_from_pbmsg(const ::proto_ff::E_FunctionunlockFunctionunlock & msg) {
	m_functionId = msg.m_functionid();
	m_openDaily = msg.m_opendaily();
	m_openType = msg.m_opentype();
	m_openVal = msg.m_openval();
	m_defaultClosed = msg.m_defaultclosed();
	m_iconOpenVal = msg.m_iconopenval();
	m_iconDisapearID = msg.m_icondisapearid();
	m_belong = msg.m_belong();
}

Sheet_FunctionunlockFunctionunlock_s::Sheet_FunctionunlockFunctionunlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FunctionunlockFunctionunlock_s::CreateInit() {
	return 0;
}

int Sheet_FunctionunlockFunctionunlock_s::ResumeInit() {
	return 0;
}

void Sheet_FunctionunlockFunctionunlock_s::write_to_pbmsg(::proto_ff::Sheet_FunctionunlockFunctionunlock & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FunctionunlockFunctionunlock_List.size(); ++i) {
		::proto_ff::E_FunctionunlockFunctionunlock* temp_e_functionunlockfunctionunlock_list = msg.add_e_functionunlockfunctionunlock_list();
		E_FunctionunlockFunctionunlock_List[i].write_to_pbmsg(*temp_e_functionunlockfunctionunlock_list);
	}
}

void Sheet_FunctionunlockFunctionunlock_s::read_from_pbmsg(const ::proto_ff::Sheet_FunctionunlockFunctionunlock & msg) {
	E_FunctionunlockFunctionunlock_List.resize((int)msg.e_functionunlockfunctionunlock_list_size() > (int)E_FunctionunlockFunctionunlock_List.max_size() ? E_FunctionunlockFunctionunlock_List.max_size() : msg.e_functionunlockfunctionunlock_list_size());
	for(int32_t i = 0; i < (int32_t)E_FunctionunlockFunctionunlock_List.size(); ++i) {
		const ::proto_ff::E_FunctionunlockFunctionunlock & temp_e_functionunlockfunctionunlock_list = msg.e_functionunlockfunctionunlock_list(i);
		E_FunctionunlockFunctionunlock_List[i].read_from_pbmsg(temp_e_functionunlockfunctionunlock_list);
	}
}

E_FunctionunlockPreview_s::E_FunctionunlockPreview_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FunctionunlockPreview_s::CreateInit() {
	m_functionId = (int32_t)0;
	m_rewardItem = (int32_t)0;
	m_rewardNum = (int32_t)0;
	return 0;
}

int E_FunctionunlockPreview_s::ResumeInit() {
	return 0;
}

void E_FunctionunlockPreview_s::write_to_pbmsg(::proto_ff::E_FunctionunlockPreview & msg) const {
	msg.set_m_functionid((int32_t)m_functionId);
	msg.set_m_rewarditem((int32_t)m_rewardItem);
	msg.set_m_rewardnum((int32_t)m_rewardNum);
}

void E_FunctionunlockPreview_s::read_from_pbmsg(const ::proto_ff::E_FunctionunlockPreview & msg) {
	m_functionId = msg.m_functionid();
	m_rewardItem = msg.m_rewarditem();
	m_rewardNum = msg.m_rewardnum();
}

Sheet_FunctionunlockPreview_s::Sheet_FunctionunlockPreview_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FunctionunlockPreview_s::CreateInit() {
	return 0;
}

int Sheet_FunctionunlockPreview_s::ResumeInit() {
	return 0;
}

void Sheet_FunctionunlockPreview_s::write_to_pbmsg(::proto_ff::Sheet_FunctionunlockPreview & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FunctionunlockPreview_List.size(); ++i) {
		::proto_ff::E_FunctionunlockPreview* temp_e_functionunlockpreview_list = msg.add_e_functionunlockpreview_list();
		E_FunctionunlockPreview_List[i].write_to_pbmsg(*temp_e_functionunlockpreview_list);
	}
}

void Sheet_FunctionunlockPreview_s::read_from_pbmsg(const ::proto_ff::Sheet_FunctionunlockPreview & msg) {
	E_FunctionunlockPreview_List.resize((int)msg.e_functionunlockpreview_list_size() > (int)E_FunctionunlockPreview_List.max_size() ? E_FunctionunlockPreview_List.max_size() : msg.e_functionunlockpreview_list_size());
	for(int32_t i = 0; i < (int32_t)E_FunctionunlockPreview_List.size(); ++i) {
		const ::proto_ff::E_FunctionunlockPreview & temp_e_functionunlockpreview_list = msg.e_functionunlockpreview_list(i);
		E_FunctionunlockPreview_List[i].read_from_pbmsg(temp_e_functionunlockpreview_list);
	}
}

}
