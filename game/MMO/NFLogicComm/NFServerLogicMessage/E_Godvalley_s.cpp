#include "E_Godvalley_s.h"

namespace proto_ff_s {

E_GodvalleyBattle_s::E_GodvalleyBattle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodvalleyBattle_s::CreateInit() {
	m_id = (int64_t)0;
	m_roomPlayersMax = (int32_t)0;
	m_winScore = (int32_t)0;
	m_timeScore = (int32_t)0;
	m_killScore = (int32_t)0;
	m_killKeepScore = (int32_t)0;
	m_breakKillKeepScore = (int32_t)0;
	m_killMonsterScore = (int32_t)0;
	m_crystalPoints = (int32_t)0;
	m_crystalScore = (int32_t)0;
	m_interceptPoints = (int32_t)0;
	m_interceptScore = (int32_t)0;
	m_crystalReBornTime = (int32_t)0;
	m_crystalMonsterId = (int32_t)0;
	m_match_s = (int32_t)0;
	m_duration_s = (int32_t)0;
	m_mapid = (int64_t)0;
	m_actId = (int32_t)0;
	m_skill = (int32_t)0;
	return 0;
}

int E_GodvalleyBattle_s::ResumeInit() {
	return 0;
}

void E_GodvalleyBattle_s::write_to_pbmsg(::proto_ff::E_GodvalleyBattle & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_roomplayersmax((int32_t)m_roomPlayersMax);
	msg.set_m_team1n(m_team1n.data());
	msg.set_m_team2n(m_team2n.data());
	msg.set_m_name1(m_name1.data());
	msg.set_m_name2(m_name2.data());
	msg.set_m_winscore((int32_t)m_winScore);
	msg.set_m_timescore((int32_t)m_timeScore);
	msg.set_m_killscore((int32_t)m_killScore);
	msg.set_m_killkeepscore((int32_t)m_killKeepScore);
	msg.set_m_breakkillkeepscore((int32_t)m_breakKillKeepScore);
	msg.set_m_killmonsterscore((int32_t)m_killMonsterScore);
	msg.set_m_crystalpoints((int32_t)m_crystalPoints);
	msg.set_m_crystalscore((int32_t)m_crystalScore);
	msg.set_m_interceptpoints((int32_t)m_interceptPoints);
	msg.set_m_interceptscore((int32_t)m_interceptScore);
	msg.set_m_crystalreborntime((int32_t)m_crystalReBornTime);
	msg.set_m_crystalmonsterid((int32_t)m_crystalMonsterId);
	msg.set_m_crystalpos(m_crystalPos.data());
	msg.set_m_match_s((int32_t)m_match_s);
	msg.set_m_duration_s((int32_t)m_duration_s);
	msg.set_m_matchmapentry(m_matchMapEntry.data());
	msg.set_m_mapid((int64_t)m_mapid);
	msg.set_m_mapentry1(m_mapEntry1.data());
	msg.set_m_mapentry2(m_mapEntry2.data());
	msg.set_m_monster1(m_monster1.data());
	msg.set_m_revivalpoint1(m_revivalPoint1.data());
	msg.set_m_monster2(m_monster2.data());
	msg.set_m_revivalpoint2(m_revivalPoint2.data());
	msg.set_m_monster3(m_monster3.data());
	msg.set_m_revivalpoint3(m_revivalPoint3.data());
	msg.set_m_npc1pos(m_npc1pos.data());
	msg.set_m_npc2pos(m_npc2pos.data());
	msg.set_m_actid((int32_t)m_actId);
	msg.set_m_skill((int32_t)m_skill);
}

void E_GodvalleyBattle_s::read_from_pbmsg(const ::proto_ff::E_GodvalleyBattle & msg) {
	m_id = msg.m_id();
	m_roomPlayersMax = msg.m_roomplayersmax();
	m_team1n = msg.m_team1n();
	m_team2n = msg.m_team2n();
	m_name1 = msg.m_name1();
	m_name2 = msg.m_name2();
	m_winScore = msg.m_winscore();
	m_timeScore = msg.m_timescore();
	m_killScore = msg.m_killscore();
	m_killKeepScore = msg.m_killkeepscore();
	m_breakKillKeepScore = msg.m_breakkillkeepscore();
	m_killMonsterScore = msg.m_killmonsterscore();
	m_crystalPoints = msg.m_crystalpoints();
	m_crystalScore = msg.m_crystalscore();
	m_interceptPoints = msg.m_interceptpoints();
	m_interceptScore = msg.m_interceptscore();
	m_crystalReBornTime = msg.m_crystalreborntime();
	m_crystalMonsterId = msg.m_crystalmonsterid();
	m_crystalPos = msg.m_crystalpos();
	m_match_s = msg.m_match_s();
	m_duration_s = msg.m_duration_s();
	m_matchMapEntry = msg.m_matchmapentry();
	m_mapid = msg.m_mapid();
	m_mapEntry1 = msg.m_mapentry1();
	m_mapEntry2 = msg.m_mapentry2();
	m_monster1 = msg.m_monster1();
	m_revivalPoint1 = msg.m_revivalpoint1();
	m_monster2 = msg.m_monster2();
	m_revivalPoint2 = msg.m_revivalpoint2();
	m_monster3 = msg.m_monster3();
	m_revivalPoint3 = msg.m_revivalpoint3();
	m_npc1pos = msg.m_npc1pos();
	m_npc2pos = msg.m_npc2pos();
	m_actId = msg.m_actid();
	m_skill = msg.m_skill();
}

Sheet_GodvalleyBattle_s::Sheet_GodvalleyBattle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodvalleyBattle_s::CreateInit() {
	return 0;
}

int Sheet_GodvalleyBattle_s::ResumeInit() {
	return 0;
}

void Sheet_GodvalleyBattle_s::write_to_pbmsg(::proto_ff::Sheet_GodvalleyBattle & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodvalleyBattle_List.size(); ++i) {
		::proto_ff::E_GodvalleyBattle* temp_e_godvalleybattle_list = msg.add_e_godvalleybattle_list();
		E_GodvalleyBattle_List[i].write_to_pbmsg(*temp_e_godvalleybattle_list);
	}
}

void Sheet_GodvalleyBattle_s::read_from_pbmsg(const ::proto_ff::Sheet_GodvalleyBattle & msg) {
	E_GodvalleyBattle_List.resize((int)msg.e_godvalleybattle_list_size() > (int)E_GodvalleyBattle_List.max_size() ? E_GodvalleyBattle_List.max_size() : msg.e_godvalleybattle_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodvalleyBattle_List.size(); ++i) {
		const ::proto_ff::E_GodvalleyBattle & temp_e_godvalleybattle_list = msg.e_godvalleybattle_list(i);
		E_GodvalleyBattle_List[i].read_from_pbmsg(temp_e_godvalleybattle_list);
	}
}

E_GodvalleyRewardsRewardDesc_s::E_GodvalleyRewardsRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodvalleyRewardsRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_GodvalleyRewardsRewardDesc_s::ResumeInit() {
	return 0;
}

void E_GodvalleyRewardsRewardDesc_s::write_to_pbmsg(::proto_ff::E_GodvalleyRewardsRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_GodvalleyRewardsRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_GodvalleyRewardsRewardDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_GodvalleyRewards_s::E_GodvalleyRewards_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodvalleyRewards_s::CreateInit() {
	m_id = (int32_t)0;
	m_score = (int32_t)0;
	return 0;
}

int E_GodvalleyRewards_s::ResumeInit() {
	return 0;
}

void E_GodvalleyRewards_s::write_to_pbmsg(::proto_ff::E_GodvalleyRewards & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_score((int32_t)m_score);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_GodvalleyRewardsRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_GodvalleyRewards_s::read_from_pbmsg(const ::proto_ff::E_GodvalleyRewards & msg) {
	m_id = msg.m_id();
	m_score = msg.m_score();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_GodvalleyRewardsRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_GodvalleyRewards_s::Sheet_GodvalleyRewards_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodvalleyRewards_s::CreateInit() {
	return 0;
}

int Sheet_GodvalleyRewards_s::ResumeInit() {
	return 0;
}

void Sheet_GodvalleyRewards_s::write_to_pbmsg(::proto_ff::Sheet_GodvalleyRewards & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodvalleyRewards_List.size(); ++i) {
		::proto_ff::E_GodvalleyRewards* temp_e_godvalleyrewards_list = msg.add_e_godvalleyrewards_list();
		E_GodvalleyRewards_List[i].write_to_pbmsg(*temp_e_godvalleyrewards_list);
	}
}

void Sheet_GodvalleyRewards_s::read_from_pbmsg(const ::proto_ff::Sheet_GodvalleyRewards & msg) {
	E_GodvalleyRewards_List.resize((int)msg.e_godvalleyrewards_list_size() > (int)E_GodvalleyRewards_List.max_size() ? E_GodvalleyRewards_List.max_size() : msg.e_godvalleyrewards_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodvalleyRewards_List.size(); ++i) {
		const ::proto_ff::E_GodvalleyRewards & temp_e_godvalleyrewards_list = msg.e_godvalleyrewards_list(i);
		E_GodvalleyRewards_List[i].read_from_pbmsg(temp_e_godvalleyrewards_list);
	}
}

E_GodvalleyAttributeAttributeDesc_s::E_GodvalleyAttributeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodvalleyAttributeAttributeDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_Type = (int32_t)0;
	return 0;
}

int E_GodvalleyAttributeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_GodvalleyAttributeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_GodvalleyAttributeAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_type((int32_t)m_Type);
}

void E_GodvalleyAttributeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_GodvalleyAttributeAttributeDesc & msg) {
	m_Value = msg.m_value();
	m_Type = msg.m_type();
}

E_GodvalleyAttribute_s::E_GodvalleyAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodvalleyAttribute_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_GodvalleyAttribute_s::ResumeInit() {
	return 0;
}

void E_GodvalleyAttribute_s::write_to_pbmsg(::proto_ff::E_GodvalleyAttribute & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_GodvalleyAttributeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_GodvalleyAttribute_s::read_from_pbmsg(const ::proto_ff::E_GodvalleyAttribute & msg) {
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_GodvalleyAttributeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_GodvalleyAttribute_s::Sheet_GodvalleyAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodvalleyAttribute_s::CreateInit() {
	return 0;
}

int Sheet_GodvalleyAttribute_s::ResumeInit() {
	return 0;
}

void Sheet_GodvalleyAttribute_s::write_to_pbmsg(::proto_ff::Sheet_GodvalleyAttribute & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodvalleyAttribute_List.size(); ++i) {
		::proto_ff::E_GodvalleyAttribute* temp_e_godvalleyattribute_list = msg.add_e_godvalleyattribute_list();
		E_GodvalleyAttribute_List[i].write_to_pbmsg(*temp_e_godvalleyattribute_list);
	}
}

void Sheet_GodvalleyAttribute_s::read_from_pbmsg(const ::proto_ff::Sheet_GodvalleyAttribute & msg) {
	E_GodvalleyAttribute_List.resize((int)msg.e_godvalleyattribute_list_size() > (int)E_GodvalleyAttribute_List.max_size() ? E_GodvalleyAttribute_List.max_size() : msg.e_godvalleyattribute_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodvalleyAttribute_List.size(); ++i) {
		const ::proto_ff::E_GodvalleyAttribute & temp_e_godvalleyattribute_list = msg.e_godvalleyattribute_list(i);
		E_GodvalleyAttribute_List[i].read_from_pbmsg(temp_e_godvalleyattribute_list);
	}
}

}
