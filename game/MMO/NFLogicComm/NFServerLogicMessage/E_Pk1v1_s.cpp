#include "E_Pk1v1_s.h"

namespace proto_ff_s {

E_Pk1v1Rank_s::E_Pk1v1Rank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_Pk1v1Rank_s::CreateInit() {
	m_id = (int32_t)0;
	m_mark = (int32_t)0;
	m_scoreMin = (int32_t)0;
	m_scoreMax = (int32_t)0;
	m_sucessScore = (int32_t)0;
	m_defeatScore = (int32_t)0;
	m_sucessBox = (int32_t)0;
	m_defeatBox = (int32_t)0;
	m_tieBox = (int32_t)0;
	return 0;
}

int E_Pk1v1Rank_s::ResumeInit() {
	return 0;
}

void E_Pk1v1Rank_s::write_to_pbmsg(::proto_ff::E_Pk1v1Rank & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_mark((int32_t)m_mark);
	msg.set_m_scoremin((int32_t)m_scoreMin);
	msg.set_m_scoremax((int32_t)m_scoreMax);
	msg.set_m_sucessscore((int32_t)m_sucessScore);
	msg.set_m_defeatscore((int32_t)m_defeatScore);
	msg.set_m_sucessbox((int32_t)m_sucessBox);
	msg.set_m_defeatbox((int32_t)m_defeatBox);
	msg.set_m_tiebox((int32_t)m_tieBox);
}

void E_Pk1v1Rank_s::read_from_pbmsg(const ::proto_ff::E_Pk1v1Rank & msg) {
	m_id = msg.m_id();
	m_mark = msg.m_mark();
	m_scoreMin = msg.m_scoremin();
	m_scoreMax = msg.m_scoremax();
	m_sucessScore = msg.m_sucessscore();
	m_defeatScore = msg.m_defeatscore();
	m_sucessBox = msg.m_sucessbox();
	m_defeatBox = msg.m_defeatbox();
	m_tieBox = msg.m_tiebox();
}

Sheet_Pk1v1Rank_s::Sheet_Pk1v1Rank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_Pk1v1Rank_s::CreateInit() {
	return 0;
}

int Sheet_Pk1v1Rank_s::ResumeInit() {
	return 0;
}

void Sheet_Pk1v1Rank_s::write_to_pbmsg(::proto_ff::Sheet_Pk1v1Rank & msg) const {
	for(int32_t i = 0; i < (int32_t)E_Pk1v1Rank_List.size(); ++i) {
		::proto_ff::E_Pk1v1Rank* temp_e_pk1v1rank_list = msg.add_e_pk1v1rank_list();
		E_Pk1v1Rank_List[i].write_to_pbmsg(*temp_e_pk1v1rank_list);
	}
}

void Sheet_Pk1v1Rank_s::read_from_pbmsg(const ::proto_ff::Sheet_Pk1v1Rank & msg) {
	E_Pk1v1Rank_List.resize((int)msg.e_pk1v1rank_list_size() > (int)E_Pk1v1Rank_List.max_size() ? E_Pk1v1Rank_List.max_size() : msg.e_pk1v1rank_list_size());
	for(int32_t i = 0; i < (int32_t)E_Pk1v1Rank_List.size(); ++i) {
		const ::proto_ff::E_Pk1v1Rank & temp_e_pk1v1rank_list = msg.e_pk1v1rank_list(i);
		E_Pk1v1Rank_List[i].read_from_pbmsg(temp_e_pk1v1rank_list);
	}
}

E_Pk1v1Reward_s::E_Pk1v1Reward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_Pk1v1Reward_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_Pk1v1Reward_s::ResumeInit() {
	return 0;
}

void E_Pk1v1Reward_s::write_to_pbmsg(::proto_ff::E_Pk1v1Reward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_boxid((int32_t)m_boxid);
	for(int32_t i = 0; i < (int32_t)m_typeArg.size(); ++i) {
		msg.add_m_typearg((int32_t)m_typeArg[i]);
	}
}

void E_Pk1v1Reward_s::read_from_pbmsg(const ::proto_ff::E_Pk1v1Reward & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_boxid = msg.m_boxid();
	m_typeArg.resize((int)msg.m_typearg_size() > (int)m_typeArg.max_size() ? m_typeArg.max_size() : msg.m_typearg_size());
	for(int32_t i = 0; i < (int32_t)m_typeArg.size(); ++i) {
		m_typeArg[i] = msg.m_typearg(i);
	}
}

Sheet_Pk1v1Reward_s::Sheet_Pk1v1Reward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_Pk1v1Reward_s::CreateInit() {
	return 0;
}

int Sheet_Pk1v1Reward_s::ResumeInit() {
	return 0;
}

void Sheet_Pk1v1Reward_s::write_to_pbmsg(::proto_ff::Sheet_Pk1v1Reward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_Pk1v1Reward_List.size(); ++i) {
		::proto_ff::E_Pk1v1Reward* temp_e_pk1v1reward_list = msg.add_e_pk1v1reward_list();
		E_Pk1v1Reward_List[i].write_to_pbmsg(*temp_e_pk1v1reward_list);
	}
}

void Sheet_Pk1v1Reward_s::read_from_pbmsg(const ::proto_ff::Sheet_Pk1v1Reward & msg) {
	E_Pk1v1Reward_List.resize((int)msg.e_pk1v1reward_list_size() > (int)E_Pk1v1Reward_List.max_size() ? E_Pk1v1Reward_List.max_size() : msg.e_pk1v1reward_list_size());
	for(int32_t i = 0; i < (int32_t)E_Pk1v1Reward_List.size(); ++i) {
		const ::proto_ff::E_Pk1v1Reward & temp_e_pk1v1reward_list = msg.e_pk1v1reward_list(i);
		E_Pk1v1Reward_List[i].read_from_pbmsg(temp_e_pk1v1reward_list);
	}
}

E_Pk1v1Dailyreward_s::E_Pk1v1Dailyreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_Pk1v1Dailyreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_times = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_Pk1v1Dailyreward_s::ResumeInit() {
	return 0;
}

void E_Pk1v1Dailyreward_s::write_to_pbmsg(::proto_ff::E_Pk1v1Dailyreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_times((int32_t)m_times);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_Pk1v1Dailyreward_s::read_from_pbmsg(const ::proto_ff::E_Pk1v1Dailyreward & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_times = msg.m_times();
	m_boxid = msg.m_boxid();
}

Sheet_Pk1v1Dailyreward_s::Sheet_Pk1v1Dailyreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_Pk1v1Dailyreward_s::CreateInit() {
	return 0;
}

int Sheet_Pk1v1Dailyreward_s::ResumeInit() {
	return 0;
}

void Sheet_Pk1v1Dailyreward_s::write_to_pbmsg(::proto_ff::Sheet_Pk1v1Dailyreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_Pk1v1Dailyreward_List.size(); ++i) {
		::proto_ff::E_Pk1v1Dailyreward* temp_e_pk1v1dailyreward_list = msg.add_e_pk1v1dailyreward_list();
		E_Pk1v1Dailyreward_List[i].write_to_pbmsg(*temp_e_pk1v1dailyreward_list);
	}
}

void Sheet_Pk1v1Dailyreward_s::read_from_pbmsg(const ::proto_ff::Sheet_Pk1v1Dailyreward & msg) {
	E_Pk1v1Dailyreward_List.resize((int)msg.e_pk1v1dailyreward_list_size() > (int)E_Pk1v1Dailyreward_List.max_size() ? E_Pk1v1Dailyreward_List.max_size() : msg.e_pk1v1dailyreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_Pk1v1Dailyreward_List.size(); ++i) {
		const ::proto_ff::E_Pk1v1Dailyreward & temp_e_pk1v1dailyreward_list = msg.e_pk1v1dailyreward_list(i);
		E_Pk1v1Dailyreward_List[i].read_from_pbmsg(temp_e_pk1v1dailyreward_list);
	}
}

}
