#include "E_Occupation_s.h"

namespace proto_ff_s {

E_OccupationOccupation_s::E_OccupationOccupation_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationOccupation_s::CreateInit() {
	m_id = (int64_t)0;
	m_professionID = (int32_t)0;
	m_grade = (int32_t)0;
	m_level = (int32_t)0;
	m_skill_id = (int64_t)0;
	return 0;
}

int E_OccupationOccupation_s::ResumeInit() {
	return 0;
}

void E_OccupationOccupation_s::write_to_pbmsg(::proto_ff::E_OccupationOccupation & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_professionid((int32_t)m_professionID);
	msg.set_m_grade((int32_t)m_grade);
	msg.set_m_equip(m_equip.data());
	msg.set_m_modelid(m_modelID.data());
	msg.set_m_activedesc(m_activeDesc.data());
	msg.set_m_level((int32_t)m_level);
	msg.set_m_skill_id((int64_t)m_skill_id);
	msg.set_m_itemids(m_itemIDs.data());
}

void E_OccupationOccupation_s::read_from_pbmsg(const ::proto_ff::E_OccupationOccupation & msg) {
	m_id = msg.m_id();
	m_professionID = msg.m_professionid();
	m_grade = msg.m_grade();
	m_equip = msg.m_equip();
	m_modelID = msg.m_modelid();
	m_activeDesc = msg.m_activedesc();
	m_level = msg.m_level();
	m_skill_id = msg.m_skill_id();
	m_itemIDs = msg.m_itemids();
}

Sheet_OccupationOccupation_s::Sheet_OccupationOccupation_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_OccupationOccupation_s::CreateInit() {
	return 0;
}

int Sheet_OccupationOccupation_s::ResumeInit() {
	return 0;
}

void Sheet_OccupationOccupation_s::write_to_pbmsg(::proto_ff::Sheet_OccupationOccupation & msg) const {
	for(int32_t i = 0; i < (int32_t)E_OccupationOccupation_List.size(); ++i) {
		::proto_ff::E_OccupationOccupation* temp_e_occupationoccupation_list = msg.add_e_occupationoccupation_list();
		E_OccupationOccupation_List[i].write_to_pbmsg(*temp_e_occupationoccupation_list);
	}
}

void Sheet_OccupationOccupation_s::read_from_pbmsg(const ::proto_ff::Sheet_OccupationOccupation & msg) {
	E_OccupationOccupation_List.resize((int)msg.e_occupationoccupation_list_size() > (int)E_OccupationOccupation_List.max_size() ? E_OccupationOccupation_List.max_size() : msg.e_occupationoccupation_list_size());
	for(int32_t i = 0; i < (int32_t)E_OccupationOccupation_List.size(); ++i) {
		const ::proto_ff::E_OccupationOccupation & temp_e_occupationoccupation_list = msg.e_occupationoccupation_list(i);
		E_OccupationOccupation_List[i].read_from_pbmsg(temp_e_occupationoccupation_list);
	}
}

E_OccupationStage_s::E_OccupationStage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationStage_s::CreateInit() {
	m_id = (int32_t)0;
	m_grade = (int32_t)0;
	m_lv = (int32_t)0;
	m_stgaeAttShow = (int32_t)0;
	m_stgaeAtt = (int32_t)0;
	m_taskId = (int32_t)0;
	m_battle = (int32_t)0;
	m_skillID = (int32_t)0;
	m_soulTpye = (int32_t)0;
	m_itemID = (int32_t)0;
	return 0;
}

int E_OccupationStage_s::ResumeInit() {
	return 0;
}

void E_OccupationStage_s::write_to_pbmsg(::proto_ff::E_OccupationStage & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_grade((int32_t)m_grade);
	msg.set_m_stgae(m_stgae.data());
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_stgaeattshow((int32_t)m_stgaeAttShow);
	msg.set_m_stgaeatt((int32_t)m_stgaeAtt);
	msg.set_m_taskid((int32_t)m_taskId);
	msg.set_m_battle((int32_t)m_battle);
	msg.set_m_skillid((int32_t)m_skillID);
	msg.set_m_lightsoul(m_lightSoul.data());
	msg.set_m_soultpye((int32_t)m_soulTpye);
	msg.set_m_itemid((int32_t)m_itemID);
}

void E_OccupationStage_s::read_from_pbmsg(const ::proto_ff::E_OccupationStage & msg) {
	m_id = msg.m_id();
	m_grade = msg.m_grade();
	m_stgae = msg.m_stgae();
	m_lv = msg.m_lv();
	m_stgaeAttShow = msg.m_stgaeattshow();
	m_stgaeAtt = msg.m_stgaeatt();
	m_taskId = msg.m_taskid();
	m_battle = msg.m_battle();
	m_skillID = msg.m_skillid();
	m_lightSoul = msg.m_lightsoul();
	m_soulTpye = msg.m_soultpye();
	m_itemID = msg.m_itemid();
}

Sheet_OccupationStage_s::Sheet_OccupationStage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_OccupationStage_s::CreateInit() {
	return 0;
}

int Sheet_OccupationStage_s::ResumeInit() {
	return 0;
}

void Sheet_OccupationStage_s::write_to_pbmsg(::proto_ff::Sheet_OccupationStage & msg) const {
	for(int32_t i = 0; i < (int32_t)E_OccupationStage_List.size(); ++i) {
		::proto_ff::E_OccupationStage* temp_e_occupationstage_list = msg.add_e_occupationstage_list();
		E_OccupationStage_List[i].write_to_pbmsg(*temp_e_occupationstage_list);
	}
}

void Sheet_OccupationStage_s::read_from_pbmsg(const ::proto_ff::Sheet_OccupationStage & msg) {
	E_OccupationStage_List.resize((int)msg.e_occupationstage_list_size() > (int)E_OccupationStage_List.max_size() ? E_OccupationStage_List.max_size() : msg.e_occupationstage_list_size());
	for(int32_t i = 0; i < (int32_t)E_OccupationStage_List.size(); ++i) {
		const ::proto_ff::E_OccupationStage & temp_e_occupationstage_list = msg.e_occupationstage_list(i);
		E_OccupationStage_List[i].read_from_pbmsg(temp_e_occupationstage_list);
	}
}

E_OccupationAttributeAttributeDesc_s::E_OccupationAttributeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationAttributeAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_OccupationAttributeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_OccupationAttributeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_OccupationAttributeAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_item((int32_t)m_item);
}

void E_OccupationAttributeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_OccupationAttributeAttributeDesc & msg) {
	m_value = msg.m_value();
	m_item = msg.m_item();
}

E_OccupationAttribute_s::E_OccupationAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationAttribute_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_OccupationAttribute_s::ResumeInit() {
	return 0;
}

void E_OccupationAttribute_s::write_to_pbmsg(::proto_ff::E_OccupationAttribute & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_OccupationAttributeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_OccupationAttribute_s::read_from_pbmsg(const ::proto_ff::E_OccupationAttribute & msg) {
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_OccupationAttributeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_OccupationAttribute_s::Sheet_OccupationAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_OccupationAttribute_s::CreateInit() {
	return 0;
}

int Sheet_OccupationAttribute_s::ResumeInit() {
	return 0;
}

void Sheet_OccupationAttribute_s::write_to_pbmsg(::proto_ff::Sheet_OccupationAttribute & msg) const {
	for(int32_t i = 0; i < (int32_t)E_OccupationAttribute_List.size(); ++i) {
		::proto_ff::E_OccupationAttribute* temp_e_occupationattribute_list = msg.add_e_occupationattribute_list();
		E_OccupationAttribute_List[i].write_to_pbmsg(*temp_e_occupationattribute_list);
	}
}

void Sheet_OccupationAttribute_s::read_from_pbmsg(const ::proto_ff::Sheet_OccupationAttribute & msg) {
	E_OccupationAttribute_List.resize((int)msg.e_occupationattribute_list_size() > (int)E_OccupationAttribute_List.max_size() ? E_OccupationAttribute_List.max_size() : msg.e_occupationattribute_list_size());
	for(int32_t i = 0; i < (int32_t)E_OccupationAttribute_List.size(); ++i) {
		const ::proto_ff::E_OccupationAttribute & temp_e_occupationattribute_list = msg.e_occupationattribute_list(i);
		E_OccupationAttribute_List[i].read_from_pbmsg(temp_e_occupationattribute_list);
	}
}

E_OccupationSoulAttributeDesc_s::E_OccupationSoulAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationSoulAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_OccupationSoulAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_OccupationSoulAttributeDesc_s::write_to_pbmsg(::proto_ff::E_OccupationSoulAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_OccupationSoulAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_OccupationSoulAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_OccupationSoul_s::E_OccupationSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationSoul_s::CreateInit() {
	m_id = (int32_t)0;
	m_soulTpye = (int32_t)0;
	m_position = (int32_t)0;
	return 0;
}

int E_OccupationSoul_s::ResumeInit() {
	return 0;
}

void E_OccupationSoul_s::write_to_pbmsg(::proto_ff::E_OccupationSoul & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_soultpye((int32_t)m_soulTpye);
	msg.set_m_position((int32_t)m_position);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_OccupationSoulAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_OccupationSoul_s::read_from_pbmsg(const ::proto_ff::E_OccupationSoul & msg) {
	m_id = msg.m_id();
	m_soulTpye = msg.m_soultpye();
	m_position = msg.m_position();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_OccupationSoulAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_OccupationSoul_s::Sheet_OccupationSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_OccupationSoul_s::CreateInit() {
	return 0;
}

int Sheet_OccupationSoul_s::ResumeInit() {
	return 0;
}

void Sheet_OccupationSoul_s::write_to_pbmsg(::proto_ff::Sheet_OccupationSoul & msg) const {
	for(int32_t i = 0; i < (int32_t)E_OccupationSoul_List.size(); ++i) {
		::proto_ff::E_OccupationSoul* temp_e_occupationsoul_list = msg.add_e_occupationsoul_list();
		E_OccupationSoul_List[i].write_to_pbmsg(*temp_e_occupationsoul_list);
	}
}

void Sheet_OccupationSoul_s::read_from_pbmsg(const ::proto_ff::Sheet_OccupationSoul & msg) {
	E_OccupationSoul_List.resize((int)msg.e_occupationsoul_list_size() > (int)E_OccupationSoul_List.max_size() ? E_OccupationSoul_List.max_size() : msg.e_occupationsoul_list_size());
	for(int32_t i = 0; i < (int32_t)E_OccupationSoul_List.size(); ++i) {
		const ::proto_ff::E_OccupationSoul & temp_e_occupationsoul_list = msg.e_occupationsoul_list(i);
		E_OccupationSoul_List[i].read_from_pbmsg(temp_e_occupationsoul_list);
	}
}

}
