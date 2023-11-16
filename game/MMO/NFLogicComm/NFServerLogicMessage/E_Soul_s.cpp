#include "E_Soul_s.h"

namespace proto_ff_s {

E_SoulOpen_s::E_SoulOpen_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulOpen_s::CreateInit() {
	m_id = (int32_t)0;
	m_lv = (int32_t)0;
	m_box = (int32_t)0;
	return 0;
}

int E_SoulOpen_s::ResumeInit() {
	return 0;
}

void E_SoulOpen_s::write_to_pbmsg(::proto_ff::E_SoulOpen & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_box((int32_t)m_box);
}

void E_SoulOpen_s::read_from_pbmsg(const ::proto_ff::E_SoulOpen & msg) {
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_box = msg.m_box();
}

Sheet_SoulOpen_s::Sheet_SoulOpen_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulOpen_s::CreateInit() {
	return 0;
}

int Sheet_SoulOpen_s::ResumeInit() {
	return 0;
}

void Sheet_SoulOpen_s::write_to_pbmsg(::proto_ff::Sheet_SoulOpen & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulOpen_List.size(); ++i) {
		::proto_ff::E_SoulOpen* temp_e_soulopen_list = msg.add_e_soulopen_list();
		E_SoulOpen_List[i].write_to_pbmsg(*temp_e_soulopen_list);
	}
}

void Sheet_SoulOpen_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulOpen & msg) {
	E_SoulOpen_List.resize((int)msg.e_soulopen_list_size() > (int)E_SoulOpen_List.max_size() ? E_SoulOpen_List.max_size() : msg.e_soulopen_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulOpen_List.size(); ++i) {
		const ::proto_ff::E_SoulOpen & temp_e_soulopen_list = msg.e_soulopen_list(i);
		E_SoulOpen_List[i].read_from_pbmsg(temp_e_soulopen_list);
	}
}

E_SoulSoul_s::E_SoulSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulSoul_s::CreateInit() {
	m_id = (int32_t)0;
	m_lvItem = (int32_t)0;
	m_advanceItem = (int32_t)0;
	m_sacrificeSkill = (int32_t)0;
	return 0;
}

int E_SoulSoul_s::ResumeInit() {
	return 0;
}

void E_SoulSoul_s::write_to_pbmsg(::proto_ff::E_SoulSoul & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_lvitem((int32_t)m_lvItem);
	msg.set_m_advanceitem((int32_t)m_advanceItem);
	msg.set_m_sacrificeskill((int32_t)m_sacrificeSkill);
	msg.set_m_skilllv(m_SkillLv.data());
}

void E_SoulSoul_s::read_from_pbmsg(const ::proto_ff::E_SoulSoul & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_lvItem = msg.m_lvitem();
	m_advanceItem = msg.m_advanceitem();
	m_sacrificeSkill = msg.m_sacrificeskill();
	m_SkillLv = msg.m_skilllv();
}

Sheet_SoulSoul_s::Sheet_SoulSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulSoul_s::CreateInit() {
	return 0;
}

int Sheet_SoulSoul_s::ResumeInit() {
	return 0;
}

void Sheet_SoulSoul_s::write_to_pbmsg(::proto_ff::Sheet_SoulSoul & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulSoul_List.size(); ++i) {
		::proto_ff::E_SoulSoul* temp_e_soulsoul_list = msg.add_e_soulsoul_list();
		E_SoulSoul_List[i].write_to_pbmsg(*temp_e_soulsoul_list);
	}
}

void Sheet_SoulSoul_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulSoul & msg) {
	E_SoulSoul_List.resize((int)msg.e_soulsoul_list_size() > (int)E_SoulSoul_List.max_size() ? E_SoulSoul_List.max_size() : msg.e_soulsoul_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulSoul_List.size(); ++i) {
		const ::proto_ff::E_SoulSoul & temp_e_soulsoul_list = msg.e_soulsoul_list(i);
		E_SoulSoul_List[i].read_from_pbmsg(temp_e_soulsoul_list);
	}
}

E_SoulSoulbasicAttributeDesc_s::E_SoulSoulbasicAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulSoulbasicAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulSoulbasicAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulSoulbasicAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulSoulbasicAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulSoulbasicAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulSoulbasicAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulSoulbasic_s::E_SoulSoulbasic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulSoulbasic_s::CreateInit() {
	m_id = (int32_t)0;
	m_soulId = (int32_t)0;
	m_soulLv = (int32_t)0;
	m_soulExp = (int32_t)0;
	return 0;
}

int E_SoulSoulbasic_s::ResumeInit() {
	return 0;
}

void E_SoulSoulbasic_s::write_to_pbmsg(::proto_ff::E_SoulSoulbasic & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_soulid((int32_t)m_soulId);
	msg.set_m_soullv((int32_t)m_soulLv);
	msg.set_m_soulexp((int32_t)m_soulExp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulSoulbasicAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulSoulbasic_s::read_from_pbmsg(const ::proto_ff::E_SoulSoulbasic & msg) {
	m_id = msg.m_id();
	m_soulId = msg.m_soulid();
	m_soulLv = msg.m_soullv();
	m_soulExp = msg.m_soulexp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulSoulbasicAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulSoulbasic_s::Sheet_SoulSoulbasic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulSoulbasic_s::CreateInit() {
	return 0;
}

int Sheet_SoulSoulbasic_s::ResumeInit() {
	return 0;
}

void Sheet_SoulSoulbasic_s::write_to_pbmsg(::proto_ff::Sheet_SoulSoulbasic & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulSoulbasic_List.size(); ++i) {
		::proto_ff::E_SoulSoulbasic* temp_e_soulsoulbasic_list = msg.add_e_soulsoulbasic_list();
		E_SoulSoulbasic_List[i].write_to_pbmsg(*temp_e_soulsoulbasic_list);
	}
}

void Sheet_SoulSoulbasic_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulSoulbasic & msg) {
	E_SoulSoulbasic_List.resize((int)msg.e_soulsoulbasic_list_size() > (int)E_SoulSoulbasic_List.max_size() ? E_SoulSoulbasic_List.max_size() : msg.e_soulsoulbasic_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulSoulbasic_List.size(); ++i) {
		const ::proto_ff::E_SoulSoulbasic & temp_e_soulsoulbasic_list = msg.e_soulsoulbasic_list(i);
		E_SoulSoulbasic_List[i].read_from_pbmsg(temp_e_soulsoulbasic_list);
	}
}

E_SoulSouladvanceAttributeDesc_s::E_SoulSouladvanceAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulSouladvanceAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulSouladvanceAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulSouladvanceAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulSouladvanceAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulSouladvanceAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulSouladvanceAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulSouladvance_s::E_SoulSouladvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulSouladvance_s::CreateInit() {
	m_id = (int32_t)0;
	m_soulId = (int32_t)0;
	m_advanceLv = (int32_t)0;
	m_advanceNum = (int32_t)0;
	return 0;
}

int E_SoulSouladvance_s::ResumeInit() {
	return 0;
}

void E_SoulSouladvance_s::write_to_pbmsg(::proto_ff::E_SoulSouladvance & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_soulid((int32_t)m_soulId);
	msg.set_m_advancelv((int32_t)m_advanceLv);
	msg.set_m_advancenum((int32_t)m_advanceNum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulSouladvanceAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulSouladvance_s::read_from_pbmsg(const ::proto_ff::E_SoulSouladvance & msg) {
	m_id = msg.m_id();
	m_soulId = msg.m_soulid();
	m_advanceLv = msg.m_advancelv();
	m_advanceNum = msg.m_advancenum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulSouladvanceAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulSouladvance_s::Sheet_SoulSouladvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulSouladvance_s::CreateInit() {
	return 0;
}

int Sheet_SoulSouladvance_s::ResumeInit() {
	return 0;
}

void Sheet_SoulSouladvance_s::write_to_pbmsg(::proto_ff::Sheet_SoulSouladvance & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulSouladvance_List.size(); ++i) {
		::proto_ff::E_SoulSouladvance* temp_e_soulsouladvance_list = msg.add_e_soulsouladvance_list();
		E_SoulSouladvance_List[i].write_to_pbmsg(*temp_e_soulsouladvance_list);
	}
}

void Sheet_SoulSouladvance_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulSouladvance & msg) {
	E_SoulSouladvance_List.resize((int)msg.e_soulsouladvance_list_size() > (int)E_SoulSouladvance_List.max_size() ? E_SoulSouladvance_List.max_size() : msg.e_soulsouladvance_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulSouladvance_List.size(); ++i) {
		const ::proto_ff::E_SoulSouladvance & temp_e_soulsouladvance_list = msg.e_soulsouladvance_list(i);
		E_SoulSouladvance_List[i].read_from_pbmsg(temp_e_soulsouladvance_list);
	}
}

E_SoulBless_s::E_SoulBless_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBless_s::CreateInit() {
	m_id = (int32_t)0;
	m_basic_exp = (int32_t)0;
	m_need_gold = (int32_t)0;
	m_open_lv = (int32_t)0;
	return 0;
}

int E_SoulBless_s::ResumeInit() {
	return 0;
}

void E_SoulBless_s::write_to_pbmsg(::proto_ff::E_SoulBless & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_basic_exp((int32_t)m_basic_exp);
	msg.set_m_need_gold((int32_t)m_need_gold);
	msg.set_m_open_lv((int32_t)m_open_lv);
}

void E_SoulBless_s::read_from_pbmsg(const ::proto_ff::E_SoulBless & msg) {
	m_id = msg.m_id();
	m_basic_exp = msg.m_basic_exp();
	m_need_gold = msg.m_need_gold();
	m_open_lv = msg.m_open_lv();
}

Sheet_SoulBless_s::Sheet_SoulBless_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBless_s::CreateInit() {
	return 0;
}

int Sheet_SoulBless_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBless_s::write_to_pbmsg(::proto_ff::Sheet_SoulBless & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBless_List.size(); ++i) {
		::proto_ff::E_SoulBless* temp_e_soulbless_list = msg.add_e_soulbless_list();
		E_SoulBless_List[i].write_to_pbmsg(*temp_e_soulbless_list);
	}
}

void Sheet_SoulBless_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBless & msg) {
	E_SoulBless_List.resize((int)msg.e_soulbless_list_size() > (int)E_SoulBless_List.max_size() ? E_SoulBless_List.max_size() : msg.e_soulbless_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBless_List.size(); ++i) {
		const ::proto_ff::E_SoulBless & temp_e_soulbless_list = msg.e_soulbless_list(i);
		E_SoulBless_List[i].read_from_pbmsg(temp_e_soulbless_list);
	}
}

E_SoulPrivilegeAttributeDesc_s::E_SoulPrivilegeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulPrivilegeAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulPrivilegeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulPrivilegeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulPrivilegeAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulPrivilegeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulPrivilegeAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulPrivilege_s::E_SoulPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulPrivilege_s::CreateInit() {
	m_id = (int32_t)0;
	m_poolUp = (int32_t)0;
	m_huoyuedu_to_exp = (int32_t)0;
	m_meditation_to_exp = (int32_t)0;
	return 0;
}

int E_SoulPrivilege_s::ResumeInit() {
	return 0;
}

void E_SoulPrivilege_s::write_to_pbmsg(::proto_ff::E_SoulPrivilege & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_activate(m_activate.data());
	msg.set_m_poolup((int32_t)m_poolUp);
	msg.set_m_huoyuedu_to_exp((int32_t)m_huoyuedu_to_exp);
	msg.set_m_meditation_to_exp((int32_t)m_meditation_to_exp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulPrivilegeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulPrivilege_s::read_from_pbmsg(const ::proto_ff::E_SoulPrivilege & msg) {
	m_id = msg.m_id();
	m_activate = msg.m_activate();
	m_poolUp = msg.m_poolup();
	m_huoyuedu_to_exp = msg.m_huoyuedu_to_exp();
	m_meditation_to_exp = msg.m_meditation_to_exp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulPrivilegeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulPrivilege_s::Sheet_SoulPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulPrivilege_s::CreateInit() {
	return 0;
}

int Sheet_SoulPrivilege_s::ResumeInit() {
	return 0;
}

void Sheet_SoulPrivilege_s::write_to_pbmsg(::proto_ff::Sheet_SoulPrivilege & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulPrivilege_List.size(); ++i) {
		::proto_ff::E_SoulPrivilege* temp_e_soulprivilege_list = msg.add_e_soulprivilege_list();
		E_SoulPrivilege_List[i].write_to_pbmsg(*temp_e_soulprivilege_list);
	}
}

void Sheet_SoulPrivilege_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulPrivilege & msg) {
	E_SoulPrivilege_List.resize((int)msg.e_soulprivilege_list_size() > (int)E_SoulPrivilege_List.max_size() ? E_SoulPrivilege_List.max_size() : msg.e_soulprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulPrivilege_List.size(); ++i) {
		const ::proto_ff::E_SoulPrivilege & temp_e_soulprivilege_list = msg.e_soulprivilege_list(i);
		E_SoulPrivilege_List[i].read_from_pbmsg(temp_e_soulprivilege_list);
	}
}

E_SoulCrystal_s::E_SoulCrystal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulCrystal_s::CreateInit() {
	m_equipId = (int32_t)0;
	m_crystalType = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_dismantleTime = (int32_t)0;
	m_dismantleNum = (int32_t)0;
	m_skill = (int32_t)0;
	m_skillLv = (int32_t)0;
	m_handbook = (int32_t)0;
	return 0;
}

int E_SoulCrystal_s::ResumeInit() {
	return 0;
}

void E_SoulCrystal_s::write_to_pbmsg(::proto_ff::E_SoulCrystal & msg) const {
	msg.set_m_equipid((int32_t)m_equipId);
	msg.set_m_name(m_name.data());
	msg.set_m_crystaltype((int32_t)m_crystalType);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_dismantletime((int32_t)m_dismantleTime);
	msg.set_m_dismantlenum((int32_t)m_dismantleNum);
	msg.set_m_skill((int32_t)m_skill);
	msg.set_m_skilllv((int32_t)m_skillLv);
	msg.set_m_handbook((int32_t)m_handbook);
}

void E_SoulCrystal_s::read_from_pbmsg(const ::proto_ff::E_SoulCrystal & msg) {
	m_equipId = msg.m_equipid();
	m_name = msg.m_name();
	m_crystalType = msg.m_crystaltype();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_dismantleTime = msg.m_dismantletime();
	m_dismantleNum = msg.m_dismantlenum();
	m_skill = msg.m_skill();
	m_skillLv = msg.m_skilllv();
	m_handbook = msg.m_handbook();
}

Sheet_SoulCrystal_s::Sheet_SoulCrystal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulCrystal_s::CreateInit() {
	return 0;
}

int Sheet_SoulCrystal_s::ResumeInit() {
	return 0;
}

void Sheet_SoulCrystal_s::write_to_pbmsg(::proto_ff::Sheet_SoulCrystal & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulCrystal_List.size(); ++i) {
		::proto_ff::E_SoulCrystal* temp_e_soulcrystal_list = msg.add_e_soulcrystal_list();
		E_SoulCrystal_List[i].write_to_pbmsg(*temp_e_soulcrystal_list);
	}
}

void Sheet_SoulCrystal_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystal & msg) {
	E_SoulCrystal_List.resize((int)msg.e_soulcrystal_list_size() > (int)E_SoulCrystal_List.max_size() ? E_SoulCrystal_List.max_size() : msg.e_soulcrystal_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulCrystal_List.size(); ++i) {
		const ::proto_ff::E_SoulCrystal & temp_e_soulcrystal_list = msg.e_soulcrystal_list(i);
		E_SoulCrystal_List[i].read_from_pbmsg(temp_e_soulcrystal_list);
	}
}

E_SoulCrystallv_s::E_SoulCrystallv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulCrystallv_s::CreateInit() {
	m_lv = (int32_t)0;
	m_wraithsItem = (int32_t)0;
	m_wraithsMun = (int32_t)0;
	return 0;
}

int E_SoulCrystallv_s::ResumeInit() {
	return 0;
}

void E_SoulCrystallv_s::write_to_pbmsg(::proto_ff::E_SoulCrystallv & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_wraithsitem((int32_t)m_wraithsItem);
	msg.set_m_wraithsmun((int32_t)m_wraithsMun);
}

void E_SoulCrystallv_s::read_from_pbmsg(const ::proto_ff::E_SoulCrystallv & msg) {
	m_lv = msg.m_lv();
	m_wraithsItem = msg.m_wraithsitem();
	m_wraithsMun = msg.m_wraithsmun();
}

Sheet_SoulCrystallv_s::Sheet_SoulCrystallv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulCrystallv_s::CreateInit() {
	return 0;
}

int Sheet_SoulCrystallv_s::ResumeInit() {
	return 0;
}

void Sheet_SoulCrystallv_s::write_to_pbmsg(::proto_ff::Sheet_SoulCrystallv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulCrystallv_List.size(); ++i) {
		::proto_ff::E_SoulCrystallv* temp_e_soulcrystallv_list = msg.add_e_soulcrystallv_list();
		E_SoulCrystallv_List[i].write_to_pbmsg(*temp_e_soulcrystallv_list);
	}
}

void Sheet_SoulCrystallv_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystallv & msg) {
	E_SoulCrystallv_List.resize((int)msg.e_soulcrystallv_list_size() > (int)E_SoulCrystallv_List.max_size() ? E_SoulCrystallv_List.max_size() : msg.e_soulcrystallv_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulCrystallv_List.size(); ++i) {
		const ::proto_ff::E_SoulCrystallv & temp_e_soulcrystallv_list = msg.e_soulcrystallv_list(i);
		E_SoulCrystallv_List[i].read_from_pbmsg(temp_e_soulcrystallv_list);
	}
}

E_SoulCrystaltopAttributeDesc_s::E_SoulCrystaltopAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulCrystaltopAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulCrystaltopAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulCrystaltopAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulCrystaltopAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulCrystaltopAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulCrystaltopAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulCrystaltop_s::E_SoulCrystaltop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulCrystaltop_s::CreateInit() {
	m_topLv = (int32_t)0;
	m_wraithsItem = (int32_t)0;
	m_wraithsMun = (int32_t)0;
	return 0;
}

int E_SoulCrystaltop_s::ResumeInit() {
	return 0;
}

void E_SoulCrystaltop_s::write_to_pbmsg(::proto_ff::E_SoulCrystaltop & msg) const {
	msg.set_m_toplv((int32_t)m_topLv);
	msg.set_m_wraithsitem((int32_t)m_wraithsItem);
	msg.set_m_wraithsmun((int32_t)m_wraithsMun);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulCrystaltopAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulCrystaltop_s::read_from_pbmsg(const ::proto_ff::E_SoulCrystaltop & msg) {
	m_topLv = msg.m_toplv();
	m_wraithsItem = msg.m_wraithsitem();
	m_wraithsMun = msg.m_wraithsmun();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulCrystaltopAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulCrystaltop_s::Sheet_SoulCrystaltop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulCrystaltop_s::CreateInit() {
	return 0;
}

int Sheet_SoulCrystaltop_s::ResumeInit() {
	return 0;
}

void Sheet_SoulCrystaltop_s::write_to_pbmsg(::proto_ff::Sheet_SoulCrystaltop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulCrystaltop_List.size(); ++i) {
		::proto_ff::E_SoulCrystaltop* temp_e_soulcrystaltop_list = msg.add_e_soulcrystaltop_list();
		E_SoulCrystaltop_List[i].write_to_pbmsg(*temp_e_soulcrystaltop_list);
	}
}

void Sheet_SoulCrystaltop_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystaltop & msg) {
	E_SoulCrystaltop_List.resize((int)msg.e_soulcrystaltop_list_size() > (int)E_SoulCrystaltop_List.max_size() ? E_SoulCrystaltop_List.max_size() : msg.e_soulcrystaltop_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulCrystaltop_List.size(); ++i) {
		const ::proto_ff::E_SoulCrystaltop & temp_e_soulcrystaltop_list = msg.e_soulcrystaltop_list(i);
		E_SoulCrystaltop_List[i].read_from_pbmsg(temp_e_soulcrystaltop_list);
	}
}

E_SoulCrystalhole_s::E_SoulCrystalhole_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulCrystalhole_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_SoulCrystalhole_s::ResumeInit() {
	return 0;
}

void E_SoulCrystalhole_s::write_to_pbmsg(::proto_ff::E_SoulCrystalhole & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_unlock(m_unlock.data());
}

void E_SoulCrystalhole_s::read_from_pbmsg(const ::proto_ff::E_SoulCrystalhole & msg) {
	m_id = msg.m_id();
	m_unlock = msg.m_unlock();
}

Sheet_SoulCrystalhole_s::Sheet_SoulCrystalhole_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulCrystalhole_s::CreateInit() {
	return 0;
}

int Sheet_SoulCrystalhole_s::ResumeInit() {
	return 0;
}

void Sheet_SoulCrystalhole_s::write_to_pbmsg(::proto_ff::Sheet_SoulCrystalhole & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulCrystalhole_List.size(); ++i) {
		::proto_ff::E_SoulCrystalhole* temp_e_soulcrystalhole_list = msg.add_e_soulcrystalhole_list();
		E_SoulCrystalhole_List[i].write_to_pbmsg(*temp_e_soulcrystalhole_list);
	}
}

void Sheet_SoulCrystalhole_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystalhole & msg) {
	E_SoulCrystalhole_List.resize((int)msg.e_soulcrystalhole_list_size() > (int)E_SoulCrystalhole_List.max_size() ? E_SoulCrystalhole_List.max_size() : msg.e_soulcrystalhole_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulCrystalhole_List.size(); ++i) {
		const ::proto_ff::E_SoulCrystalhole & temp_e_soulcrystalhole_list = msg.e_soulcrystalhole_list(i);
		E_SoulCrystalhole_List[i].read_from_pbmsg(temp_e_soulcrystalhole_list);
	}
}

E_SoulFusionFusionDesc_s::E_SoulFusionFusionDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulFusionFusionDesc_s::CreateInit() {
	m_star = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_SoulFusionFusionDesc_s::ResumeInit() {
	return 0;
}

void E_SoulFusionFusionDesc_s::write_to_pbmsg(::proto_ff::E_SoulFusionFusionDesc & msg) const {
	msg.set_m_star((int32_t)m_star);
	msg.set_m_quality((int32_t)m_quality);
}

void E_SoulFusionFusionDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulFusionFusionDesc & msg) {
	m_star = msg.m_star();
	m_quality = msg.m_quality();
}

E_SoulFusion_s::E_SoulFusion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulFusion_s::CreateInit() {
	m_id = (int32_t)0;
	m_fusionType = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_condition = (int32_t)0;
	m_qualityGet = (int32_t)0;
	m_starGet = (int32_t)0;
	m_attributeBer = (int32_t)0;
	return 0;
}

int E_SoulFusion_s::ResumeInit() {
	return 0;
}

void E_SoulFusion_s::write_to_pbmsg(::proto_ff::E_SoulFusion & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_fusiontype((int32_t)m_fusionType);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_condition((int32_t)m_condition);
	msg.set_m_qualityget((int32_t)m_qualityGet);
	msg.set_m_starget((int32_t)m_starGet);
	msg.set_m_attributeber((int32_t)m_attributeBer);
	for(int32_t i = 0; i < (int32_t)m_fusion.size(); ++i) {
		::proto_ff::E_SoulFusionFusionDesc* temp_m_fusion = msg.add_m_fusion();
		m_fusion[i].write_to_pbmsg(*temp_m_fusion);
	}
}

void E_SoulFusion_s::read_from_pbmsg(const ::proto_ff::E_SoulFusion & msg) {
	m_id = msg.m_id();
	m_fusionType = msg.m_fusiontype();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_condition = msg.m_condition();
	m_qualityGet = msg.m_qualityget();
	m_starGet = msg.m_starget();
	m_attributeBer = msg.m_attributeber();
	m_fusion.resize((int)msg.m_fusion_size() > (int)m_fusion.max_size() ? m_fusion.max_size() : msg.m_fusion_size());
	for(int32_t i = 0; i < (int32_t)m_fusion.size(); ++i) {
		const ::proto_ff::E_SoulFusionFusionDesc & temp_m_fusion = msg.m_fusion(i);
		m_fusion[i].read_from_pbmsg(temp_m_fusion);
	}
}

Sheet_SoulFusion_s::Sheet_SoulFusion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulFusion_s::CreateInit() {
	return 0;
}

int Sheet_SoulFusion_s::ResumeInit() {
	return 0;
}

void Sheet_SoulFusion_s::write_to_pbmsg(::proto_ff::Sheet_SoulFusion & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulFusion_List.size(); ++i) {
		::proto_ff::E_SoulFusion* temp_e_soulfusion_list = msg.add_e_soulfusion_list();
		E_SoulFusion_List[i].write_to_pbmsg(*temp_e_soulfusion_list);
	}
}

void Sheet_SoulFusion_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulFusion & msg) {
	E_SoulFusion_List.resize((int)msg.e_soulfusion_list_size() > (int)E_SoulFusion_List.max_size() ? E_SoulFusion_List.max_size() : msg.e_soulfusion_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulFusion_List.size(); ++i) {
		const ::proto_ff::E_SoulFusion & temp_e_soulfusion_list = msg.e_soulfusion_list(i);
		E_SoulFusion_List[i].read_from_pbmsg(temp_e_soulfusion_list);
	}
}

E_SoulBone_s::E_SoulBone_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBone_s::CreateInit() {
	m_id = (int32_t)0;
	m_position = (int32_t)0;
	m_type = (int32_t)0;
	m_awakening = (int32_t)0;
	m_awakeningTime = (int32_t)0;
	m_awakeningNum = (int32_t)0;
	m_modelId = (int32_t)0;
	return 0;
}

int E_SoulBone_s::ResumeInit() {
	return 0;
}

void E_SoulBone_s::write_to_pbmsg(::proto_ff::E_SoulBone & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_awakening((int32_t)m_awakening);
	msg.set_m_awakeningtime((int32_t)m_awakeningTime);
	msg.set_m_awakeningnum((int32_t)m_awakeningNum);
	msg.set_m_modelid((int32_t)m_modelId);
}

void E_SoulBone_s::read_from_pbmsg(const ::proto_ff::E_SoulBone & msg) {
	m_id = msg.m_id();
	m_position = msg.m_position();
	m_type = msg.m_type();
	m_awakening = msg.m_awakening();
	m_awakeningTime = msg.m_awakeningtime();
	m_awakeningNum = msg.m_awakeningnum();
	m_modelId = msg.m_modelid();
}

Sheet_SoulBone_s::Sheet_SoulBone_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBone_s::CreateInit() {
	return 0;
}

int Sheet_SoulBone_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBone_s::write_to_pbmsg(::proto_ff::Sheet_SoulBone & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBone_List.size(); ++i) {
		::proto_ff::E_SoulBone* temp_e_soulbone_list = msg.add_e_soulbone_list();
		E_SoulBone_List[i].write_to_pbmsg(*temp_e_soulbone_list);
	}
}

void Sheet_SoulBone_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBone & msg) {
	E_SoulBone_List.resize((int)msg.e_soulbone_list_size() > (int)E_SoulBone_List.max_size() ? E_SoulBone_List.max_size() : msg.e_soulbone_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBone_List.size(); ++i) {
		const ::proto_ff::E_SoulBone & temp_e_soulbone_list = msg.e_soulbone_list(i);
		E_SoulBone_List[i].read_from_pbmsg(temp_e_soulbone_list);
	}
}

E_SoulBoneskill_s::E_SoulBoneskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBoneskill_s::CreateInit() {
	m_id = (int32_t)0;
	m_boneId = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_ActiveSkill = (int32_t)0;
	m_ActiveSkillLv = (int32_t)0;
	return 0;
}

int E_SoulBoneskill_s::ResumeInit() {
	return 0;
}

void E_SoulBoneskill_s::write_to_pbmsg(::proto_ff::E_SoulBoneskill & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_boneid((int32_t)m_boneId);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_activeskill((int32_t)m_ActiveSkill);
	msg.set_m_activeskilllv((int32_t)m_ActiveSkillLv);
	for(int32_t i = 0; i < (int32_t)m_passive_Skill.size(); ++i) {
		msg.add_m_passive_skill((int32_t)m_passive_Skill[i]);
	}
}

void E_SoulBoneskill_s::read_from_pbmsg(const ::proto_ff::E_SoulBoneskill & msg) {
	m_id = msg.m_id();
	m_boneId = msg.m_boneid();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_ActiveSkill = msg.m_activeskill();
	m_ActiveSkillLv = msg.m_activeskilllv();
	m_passive_Skill.resize((int)msg.m_passive_skill_size() > (int)m_passive_Skill.max_size() ? m_passive_Skill.max_size() : msg.m_passive_skill_size());
	for(int32_t i = 0; i < (int32_t)m_passive_Skill.size(); ++i) {
		m_passive_Skill[i] = msg.m_passive_skill(i);
	}
}

Sheet_SoulBoneskill_s::Sheet_SoulBoneskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBoneskill_s::CreateInit() {
	return 0;
}

int Sheet_SoulBoneskill_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBoneskill_s::write_to_pbmsg(::proto_ff::Sheet_SoulBoneskill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBoneskill_List.size(); ++i) {
		::proto_ff::E_SoulBoneskill* temp_e_soulboneskill_list = msg.add_e_soulboneskill_list();
		E_SoulBoneskill_List[i].write_to_pbmsg(*temp_e_soulboneskill_list);
	}
}

void Sheet_SoulBoneskill_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBoneskill & msg) {
	E_SoulBoneskill_List.resize((int)msg.e_soulboneskill_list_size() > (int)E_SoulBoneskill_List.max_size() ? E_SoulBoneskill_List.max_size() : msg.e_soulboneskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBoneskill_List.size(); ++i) {
		const ::proto_ff::E_SoulBoneskill & temp_e_soulboneskill_list = msg.e_soulboneskill_list(i);
		E_SoulBoneskill_List[i].read_from_pbmsg(temp_e_soulboneskill_list);
	}
}

E_SoulBonekill_s::E_SoulBonekill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBonekill_s::CreateInit() {
	m_lv = (int32_t)0;
	m_killBoss = (int32_t)0;
	return 0;
}

int E_SoulBonekill_s::ResumeInit() {
	return 0;
}

void E_SoulBonekill_s::write_to_pbmsg(::proto_ff::E_SoulBonekill & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_killboss((int32_t)m_killBoss);
}

void E_SoulBonekill_s::read_from_pbmsg(const ::proto_ff::E_SoulBonekill & msg) {
	m_lv = msg.m_lv();
	m_killBoss = msg.m_killboss();
}

Sheet_SoulBonekill_s::Sheet_SoulBonekill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBonekill_s::CreateInit() {
	return 0;
}

int Sheet_SoulBonekill_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBonekill_s::write_to_pbmsg(::proto_ff::Sheet_SoulBonekill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBonekill_List.size(); ++i) {
		::proto_ff::E_SoulBonekill* temp_e_soulbonekill_list = msg.add_e_soulbonekill_list();
		E_SoulBonekill_List[i].write_to_pbmsg(*temp_e_soulbonekill_list);
	}
}

void Sheet_SoulBonekill_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBonekill & msg) {
	E_SoulBonekill_List.resize((int)msg.e_soulbonekill_list_size() > (int)E_SoulBonekill_List.max_size() ? E_SoulBonekill_List.max_size() : msg.e_soulbonekill_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBonekill_List.size(); ++i) {
		const ::proto_ff::E_SoulBonekill & temp_e_soulbonekill_list = msg.e_soulbonekill_list(i);
		E_SoulBonekill_List[i].read_from_pbmsg(temp_e_soulbonekill_list);
	}
}

E_SoulBonestrongTypeDesc_s::E_SoulBonestrongTypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBonestrongTypeDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_SoulBonestrongTypeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulBonestrongTypeDesc_s::write_to_pbmsg(::proto_ff::E_SoulBonestrongTypeDesc & msg) const {
	msg.set_m_num(m_num.data());
	msg.set_m_id((int32_t)m_id);
}

void E_SoulBonestrongTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulBonestrongTypeDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_SoulBonestrong_s::E_SoulBonestrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBonestrong_s::CreateInit() {
	m_id = (int32_t)0;
	m_position = (int32_t)0;
	m_srtongUp = (int32_t)0;
	return 0;
}

int E_SoulBonestrong_s::ResumeInit() {
	return 0;
}

void E_SoulBonestrong_s::write_to_pbmsg(::proto_ff::E_SoulBonestrong & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_srtongup((int32_t)m_srtongUp);
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_SoulBonestrongTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
}

void E_SoulBonestrong_s::read_from_pbmsg(const ::proto_ff::E_SoulBonestrong & msg) {
	m_id = msg.m_id();
	m_position = msg.m_position();
	m_srtongUp = msg.m_srtongup();
	m_type.resize((int)msg.m_type_size() > (int)m_type.max_size() ? m_type.max_size() : msg.m_type_size());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		const ::proto_ff::E_SoulBonestrongTypeDesc & temp_m_type = msg.m_type(i);
		m_type[i].read_from_pbmsg(temp_m_type);
	}
}

Sheet_SoulBonestrong_s::Sheet_SoulBonestrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBonestrong_s::CreateInit() {
	return 0;
}

int Sheet_SoulBonestrong_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBonestrong_s::write_to_pbmsg(::proto_ff::Sheet_SoulBonestrong & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBonestrong_List.size(); ++i) {
		::proto_ff::E_SoulBonestrong* temp_e_soulbonestrong_list = msg.add_e_soulbonestrong_list();
		E_SoulBonestrong_List[i].write_to_pbmsg(*temp_e_soulbonestrong_list);
	}
}

void Sheet_SoulBonestrong_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBonestrong & msg) {
	E_SoulBonestrong_List.resize((int)msg.e_soulbonestrong_list_size() > (int)E_SoulBonestrong_List.max_size() ? E_SoulBonestrong_List.max_size() : msg.e_soulbonestrong_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBonestrong_List.size(); ++i) {
		const ::proto_ff::E_SoulBonestrong & temp_e_soulbonestrong_list = msg.e_soulbonestrong_list(i);
		E_SoulBonestrong_List[i].read_from_pbmsg(temp_e_soulbonestrong_list);
	}
}

E_SoulGuwentype_s::E_SoulGuwentype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulGuwentype_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_SoulGuwentype_s::ResumeInit() {
	return 0;
}

void E_SoulGuwentype_s::write_to_pbmsg(::proto_ff::E_SoulGuwentype & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_quality((int32_t)m_quality);
}

void E_SoulGuwentype_s::read_from_pbmsg(const ::proto_ff::E_SoulGuwentype & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_quality = msg.m_quality();
}

Sheet_SoulGuwentype_s::Sheet_SoulGuwentype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulGuwentype_s::CreateInit() {
	return 0;
}

int Sheet_SoulGuwentype_s::ResumeInit() {
	return 0;
}

void Sheet_SoulGuwentype_s::write_to_pbmsg(::proto_ff::Sheet_SoulGuwentype & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulGuwentype_List.size(); ++i) {
		::proto_ff::E_SoulGuwentype* temp_e_soulguwentype_list = msg.add_e_soulguwentype_list();
		E_SoulGuwentype_List[i].write_to_pbmsg(*temp_e_soulguwentype_list);
	}
}

void Sheet_SoulGuwentype_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwentype & msg) {
	E_SoulGuwentype_List.resize((int)msg.e_soulguwentype_list_size() > (int)E_SoulGuwentype_List.max_size() ? E_SoulGuwentype_List.max_size() : msg.e_soulguwentype_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulGuwentype_List.size(); ++i) {
		const ::proto_ff::E_SoulGuwentype & temp_e_soulguwentype_list = msg.e_soulguwentype_list(i);
		E_SoulGuwentype_List[i].read_from_pbmsg(temp_e_soulguwentype_list);
	}
}

E_SoulGuwentypesuitAttributeDesc_s::E_SoulGuwentypesuitAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulGuwentypesuitAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulGuwentypesuitAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulGuwentypesuitAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulGuwentypesuitAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulGuwentypesuitAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulGuwentypesuitAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulGuwentypesuit_s::E_SoulGuwentypesuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulGuwentypesuit_s::CreateInit() {
	m_id = (int32_t)0;
	m_typeId = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_SoulGuwentypesuit_s::ResumeInit() {
	return 0;
}

void E_SoulGuwentypesuit_s::write_to_pbmsg(::proto_ff::E_SoulGuwentypesuit & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_typeid((int32_t)m_typeId);
	msg.set_m_num((int32_t)m_num);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulGuwentypesuitAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulGuwentypesuit_s::read_from_pbmsg(const ::proto_ff::E_SoulGuwentypesuit & msg) {
	m_id = msg.m_id();
	m_typeId = msg.m_typeid();
	m_num = msg.m_num();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulGuwentypesuitAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulGuwentypesuit_s::Sheet_SoulGuwentypesuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulGuwentypesuit_s::CreateInit() {
	return 0;
}

int Sheet_SoulGuwentypesuit_s::ResumeInit() {
	return 0;
}

void Sheet_SoulGuwentypesuit_s::write_to_pbmsg(::proto_ff::Sheet_SoulGuwentypesuit & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulGuwentypesuit_List.size(); ++i) {
		::proto_ff::E_SoulGuwentypesuit* temp_e_soulguwentypesuit_list = msg.add_e_soulguwentypesuit_list();
		E_SoulGuwentypesuit_List[i].write_to_pbmsg(*temp_e_soulguwentypesuit_list);
	}
}

void Sheet_SoulGuwentypesuit_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwentypesuit & msg) {
	E_SoulGuwentypesuit_List.resize((int)msg.e_soulguwentypesuit_list_size() > (int)E_SoulGuwentypesuit_List.max_size() ? E_SoulGuwentypesuit_List.max_size() : msg.e_soulguwentypesuit_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulGuwentypesuit_List.size(); ++i) {
		const ::proto_ff::E_SoulGuwentypesuit & temp_e_soulguwentypesuit_list = msg.e_soulguwentypesuit_list(i);
		E_SoulGuwentypesuit_List[i].read_from_pbmsg(temp_e_soulguwentypesuit_list);
	}
}

E_SoulGuwenskill_s::E_SoulGuwenskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulGuwenskill_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_skillId = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_SoulGuwenskill_s::ResumeInit() {
	return 0;
}

void E_SoulGuwenskill_s::write_to_pbmsg(::proto_ff::E_SoulGuwenskill & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_skillid((int32_t)m_skillId);
	msg.set_m_quality((int32_t)m_quality);
	for(int32_t i = 0; i < (int32_t)m_skillLevel.size(); ++i) {
		msg.add_m_skilllevel((int32_t)m_skillLevel[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_num.size(); ++i) {
		msg.add_m_num((int32_t)m_num[i]);
	}
}

void E_SoulGuwenskill_s::read_from_pbmsg(const ::proto_ff::E_SoulGuwenskill & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_skillId = msg.m_skillid();
	m_quality = msg.m_quality();
	m_skillLevel.resize((int)msg.m_skilllevel_size() > (int)m_skillLevel.max_size() ? m_skillLevel.max_size() : msg.m_skilllevel_size());
	for(int32_t i = 0; i < (int32_t)m_skillLevel.size(); ++i) {
		m_skillLevel[i] = msg.m_skilllevel(i);
	}
	m_num.resize((int)msg.m_num_size() > (int)m_num.max_size() ? m_num.max_size() : msg.m_num_size());
	for(int32_t i = 0; i < (int32_t)m_num.size(); ++i) {
		m_num[i] = msg.m_num(i);
	}
}

Sheet_SoulGuwenskill_s::Sheet_SoulGuwenskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulGuwenskill_s::CreateInit() {
	return 0;
}

int Sheet_SoulGuwenskill_s::ResumeInit() {
	return 0;
}

void Sheet_SoulGuwenskill_s::write_to_pbmsg(::proto_ff::Sheet_SoulGuwenskill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulGuwenskill_List.size(); ++i) {
		::proto_ff::E_SoulGuwenskill* temp_e_soulguwenskill_list = msg.add_e_soulguwenskill_list();
		E_SoulGuwenskill_List[i].write_to_pbmsg(*temp_e_soulguwenskill_list);
	}
}

void Sheet_SoulGuwenskill_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwenskill & msg) {
	E_SoulGuwenskill_List.resize((int)msg.e_soulguwenskill_list_size() > (int)E_SoulGuwenskill_List.max_size() ? E_SoulGuwenskill_List.max_size() : msg.e_soulguwenskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulGuwenskill_List.size(); ++i) {
		const ::proto_ff::E_SoulGuwenskill & temp_e_soulguwenskill_list = msg.e_soulguwenskill_list(i);
		E_SoulGuwenskill_List[i].read_from_pbmsg(temp_e_soulguwenskill_list);
	}
}

E_SoulGuwenslot_s::E_SoulGuwenslot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulGuwenslot_s::CreateInit() {
	m_id = (int32_t)0;
	m_position = (int32_t)0;
	return 0;
}

int E_SoulGuwenslot_s::ResumeInit() {
	return 0;
}

void E_SoulGuwenslot_s::write_to_pbmsg(::proto_ff::E_SoulGuwenslot & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_position((int32_t)m_position);
}

void E_SoulGuwenslot_s::read_from_pbmsg(const ::proto_ff::E_SoulGuwenslot & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_position = msg.m_position();
}

Sheet_SoulGuwenslot_s::Sheet_SoulGuwenslot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulGuwenslot_s::CreateInit() {
	return 0;
}

int Sheet_SoulGuwenslot_s::ResumeInit() {
	return 0;
}

void Sheet_SoulGuwenslot_s::write_to_pbmsg(::proto_ff::Sheet_SoulGuwenslot & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulGuwenslot_List.size(); ++i) {
		::proto_ff::E_SoulGuwenslot* temp_e_soulguwenslot_list = msg.add_e_soulguwenslot_list();
		E_SoulGuwenslot_List[i].write_to_pbmsg(*temp_e_soulguwenslot_list);
	}
}

void Sheet_SoulGuwenslot_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwenslot & msg) {
	E_SoulGuwenslot_List.resize((int)msg.e_soulguwenslot_list_size() > (int)E_SoulGuwenslot_List.max_size() ? E_SoulGuwenslot_List.max_size() : msg.e_soulguwenslot_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulGuwenslot_List.size(); ++i) {
		const ::proto_ff::E_SoulGuwenslot & temp_e_soulguwenslot_list = msg.e_soulguwenslot_list(i);
		E_SoulGuwenslot_List[i].read_from_pbmsg(temp_e_soulguwenslot_list);
	}
}

E_SoulGuwensuitAttributeDesc_s::E_SoulGuwensuitAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulGuwensuitAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulGuwensuitAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulGuwensuitAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulGuwensuitAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulGuwensuitAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulGuwensuitAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulGuwensuit_s::E_SoulGuwensuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulGuwensuit_s::CreateInit() {
	m_id = (int32_t)0;
	m_boneId = (int32_t)0;
	m_typeId = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_SoulGuwensuit_s::ResumeInit() {
	return 0;
}

void E_SoulGuwensuit_s::write_to_pbmsg(::proto_ff::E_SoulGuwensuit & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_boneid((int32_t)m_boneId);
	msg.set_m_typeid((int32_t)m_typeId);
	msg.set_m_num((int32_t)m_num);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulGuwensuitAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulGuwensuit_s::read_from_pbmsg(const ::proto_ff::E_SoulGuwensuit & msg) {
	m_id = msg.m_id();
	m_boneId = msg.m_boneid();
	m_typeId = msg.m_typeid();
	m_num = msg.m_num();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulGuwensuitAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulGuwensuit_s::Sheet_SoulGuwensuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulGuwensuit_s::CreateInit() {
	return 0;
}

int Sheet_SoulGuwensuit_s::ResumeInit() {
	return 0;
}

void Sheet_SoulGuwensuit_s::write_to_pbmsg(::proto_ff::Sheet_SoulGuwensuit & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulGuwensuit_List.size(); ++i) {
		::proto_ff::E_SoulGuwensuit* temp_e_soulguwensuit_list = msg.add_e_soulguwensuit_list();
		E_SoulGuwensuit_List[i].write_to_pbmsg(*temp_e_soulguwensuit_list);
	}
}

void Sheet_SoulGuwensuit_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwensuit & msg) {
	E_SoulGuwensuit_List.resize((int)msg.e_soulguwensuit_list_size() > (int)E_SoulGuwensuit_List.max_size() ? E_SoulGuwensuit_List.max_size() : msg.e_soulguwensuit_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulGuwensuit_List.size(); ++i) {
		const ::proto_ff::E_SoulGuwensuit & temp_e_soulguwensuit_list = msg.e_soulguwensuit_list(i);
		E_SoulGuwensuit_List[i].read_from_pbmsg(temp_e_soulguwensuit_list);
	}
}

E_SoulGuwenupstar_s::E_SoulGuwenupstar_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulGuwenupstar_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_targetQuality = (int32_t)0;
	m_targetStar = (int32_t)0;
	m_samePosNum = (int32_t)0;
	m_samePosQuality = (int32_t)0;
	m_samePosStar = (int32_t)0;
	return 0;
}

int E_SoulGuwenupstar_s::ResumeInit() {
	return 0;
}

void E_SoulGuwenupstar_s::write_to_pbmsg(::proto_ff::E_SoulGuwenupstar & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_targetquality((int32_t)m_targetQuality);
	msg.set_m_targetstar((int32_t)m_targetStar);
	msg.set_m_sameposnum((int32_t)m_samePosNum);
	msg.set_m_sameposquality((int32_t)m_samePosQuality);
	msg.set_m_sameposstar((int32_t)m_samePosStar);
}

void E_SoulGuwenupstar_s::read_from_pbmsg(const ::proto_ff::E_SoulGuwenupstar & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_targetQuality = msg.m_targetquality();
	m_targetStar = msg.m_targetstar();
	m_samePosNum = msg.m_sameposnum();
	m_samePosQuality = msg.m_sameposquality();
	m_samePosStar = msg.m_sameposstar();
}

Sheet_SoulGuwenupstar_s::Sheet_SoulGuwenupstar_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulGuwenupstar_s::CreateInit() {
	return 0;
}

int Sheet_SoulGuwenupstar_s::ResumeInit() {
	return 0;
}

void Sheet_SoulGuwenupstar_s::write_to_pbmsg(::proto_ff::Sheet_SoulGuwenupstar & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulGuwenupstar_List.size(); ++i) {
		::proto_ff::E_SoulGuwenupstar* temp_e_soulguwenupstar_list = msg.add_e_soulguwenupstar_list();
		E_SoulGuwenupstar_List[i].write_to_pbmsg(*temp_e_soulguwenupstar_list);
	}
}

void Sheet_SoulGuwenupstar_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwenupstar & msg) {
	E_SoulGuwenupstar_List.resize((int)msg.e_soulguwenupstar_list_size() > (int)E_SoulGuwenupstar_List.max_size() ? E_SoulGuwenupstar_List.max_size() : msg.e_soulguwenupstar_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulGuwenupstar_List.size(); ++i) {
		const ::proto_ff::E_SoulGuwenupstar & temp_e_soulguwenupstar_list = msg.e_soulguwenupstar_list(i);
		E_SoulGuwenupstar_List[i].read_from_pbmsg(temp_e_soulguwenupstar_list);
	}
}

E_SoulAffixesAttributeDesc_s::E_SoulAffixesAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulAffixesAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulAffixesAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulAffixesAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulAffixesAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulAffixesAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulAffixesAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulAffixes_s::E_SoulAffixes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulAffixes_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_SoulAffixes_s::ResumeInit() {
	return 0;
}

void E_SoulAffixes_s::write_to_pbmsg(::proto_ff::E_SoulAffixes & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_name(m_name.data());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulAffixesAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulAffixes_s::read_from_pbmsg(const ::proto_ff::E_SoulAffixes & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_quality = msg.m_quality();
	m_name = msg.m_name();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulAffixesAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulAffixes_s::Sheet_SoulAffixes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulAffixes_s::CreateInit() {
	return 0;
}

int Sheet_SoulAffixes_s::ResumeInit() {
	return 0;
}

void Sheet_SoulAffixes_s::write_to_pbmsg(::proto_ff::Sheet_SoulAffixes & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulAffixes_List.size(); ++i) {
		::proto_ff::E_SoulAffixes* temp_e_soulaffixes_list = msg.add_e_soulaffixes_list();
		E_SoulAffixes_List[i].write_to_pbmsg(*temp_e_soulaffixes_list);
	}
}

void Sheet_SoulAffixes_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulAffixes & msg) {
	E_SoulAffixes_List.resize((int)msg.e_soulaffixes_list_size() > (int)E_SoulAffixes_List.max_size() ? E_SoulAffixes_List.max_size() : msg.e_soulaffixes_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulAffixes_List.size(); ++i) {
		const ::proto_ff::E_SoulAffixes & temp_e_soulaffixes_list = msg.e_soulaffixes_list(i);
		E_SoulAffixes_List[i].read_from_pbmsg(temp_e_soulaffixes_list);
	}
}

E_SoulAffixessuitSkillDesc_s::E_SoulAffixessuitSkillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulAffixessuitSkillDesc_s::CreateInit() {
	m_level = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_SoulAffixessuitSkillDesc_s::ResumeInit() {
	return 0;
}

void E_SoulAffixessuitSkillDesc_s::write_to_pbmsg(::proto_ff::E_SoulAffixessuitSkillDesc & msg) const {
	msg.set_m_level((int32_t)m_level);
	msg.set_m_id((int32_t)m_id);
}

void E_SoulAffixessuitSkillDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulAffixessuitSkillDesc & msg) {
	m_level = msg.m_level();
	m_id = msg.m_id();
}

E_SoulAffixessuitAttributeDesc_s::E_SoulAffixessuitAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulAffixessuitAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulAffixessuitAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulAffixessuitAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulAffixessuitAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulAffixessuitAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulAffixessuitAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulAffixessuit_s::E_SoulAffixessuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulAffixessuit_s::CreateInit() {
	m_id = (int32_t)0;
	m_affixesId = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_SoulAffixessuit_s::ResumeInit() {
	return 0;
}

void E_SoulAffixessuit_s::write_to_pbmsg(::proto_ff::E_SoulAffixessuit & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_affixesid((int32_t)m_affixesId);
	msg.set_m_num((int32_t)m_num);
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		::proto_ff::E_SoulAffixessuitSkillDesc* temp_m_skill = msg.add_m_skill();
		m_skill[i].write_to_pbmsg(*temp_m_skill);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulAffixessuitAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulAffixessuit_s::read_from_pbmsg(const ::proto_ff::E_SoulAffixessuit & msg) {
	m_id = msg.m_id();
	m_affixesId = msg.m_affixesid();
	m_num = msg.m_num();
	m_skill.resize((int)msg.m_skill_size() > (int)m_skill.max_size() ? m_skill.max_size() : msg.m_skill_size());
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		const ::proto_ff::E_SoulAffixessuitSkillDesc & temp_m_skill = msg.m_skill(i);
		m_skill[i].read_from_pbmsg(temp_m_skill);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulAffixessuitAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulAffixessuit_s::Sheet_SoulAffixessuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulAffixessuit_s::CreateInit() {
	return 0;
}

int Sheet_SoulAffixessuit_s::ResumeInit() {
	return 0;
}

void Sheet_SoulAffixessuit_s::write_to_pbmsg(::proto_ff::Sheet_SoulAffixessuit & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulAffixessuit_List.size(); ++i) {
		::proto_ff::E_SoulAffixessuit* temp_e_soulaffixessuit_list = msg.add_e_soulaffixessuit_list();
		E_SoulAffixessuit_List[i].write_to_pbmsg(*temp_e_soulaffixessuit_list);
	}
}

void Sheet_SoulAffixessuit_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulAffixessuit & msg) {
	E_SoulAffixessuit_List.resize((int)msg.e_soulaffixessuit_list_size() > (int)E_SoulAffixessuit_List.max_size() ? E_SoulAffixessuit_List.max_size() : msg.e_soulaffixessuit_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulAffixessuit_List.size(); ++i) {
		const ::proto_ff::E_SoulAffixessuit & temp_e_soulaffixessuit_list = msg.e_soulaffixessuit_list(i);
		E_SoulAffixessuit_List[i].read_from_pbmsg(temp_e_soulaffixessuit_list);
	}
}

}