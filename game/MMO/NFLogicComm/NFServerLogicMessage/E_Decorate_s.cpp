#include "E_Decorate_s.h"

namespace proto_ff_s {

E_DecorateDecorateAttributeDesc_s::E_DecorateDecorateAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DecorateDecorateAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_DecorateDecorateAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_DecorateDecorateAttributeDesc_s::write_to_pbmsg(::proto_ff::E_DecorateDecorateAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_DecorateDecorateAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_DecorateDecorateAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_DecorateDecorateActiveattributeDesc_s::E_DecorateDecorateActiveattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DecorateDecorateActiveattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_DecorateDecorateActiveattributeDesc_s::ResumeInit() {
	return 0;
}

void E_DecorateDecorateActiveattributeDesc_s::write_to_pbmsg(::proto_ff::E_DecorateDecorateActiveattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_DecorateDecorateActiveattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_DecorateDecorateActiveattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_DecorateDecorate_s::E_DecorateDecorate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DecorateDecorate_s::CreateInit() {
	m_ID = (int64_t)0;
	m_type = (int32_t)0;
	m_quality = (int32_t)0;
	m_activationItem = (int64_t)0;
	m_activationNum = (int32_t)0;
	m_starId = (int64_t)0;
	m_starUp = (int32_t)0;
	m_starBer = (int32_t)0;
	return 0;
}

int E_DecorateDecorate_s::ResumeInit() {
	return 0;
}

void E_DecorateDecorate_s::write_to_pbmsg(::proto_ff::E_DecorateDecorate & msg) const {
	msg.set_m_id((int64_t)m_ID);
	msg.set_m_name(m_name.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_professionlimit(m_professionLimit.data());
	msg.set_m_activationitem((int64_t)m_activationItem);
	msg.set_m_activationnum((int32_t)m_activationNum);
	msg.set_m_starid((int64_t)m_starId);
	msg.set_m_starnum(m_starNum.data());
	msg.set_m_starup((int32_t)m_starUp);
	msg.set_m_starber((int32_t)m_starBer);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_DecorateDecorateAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_ActiveAttribute.size(); ++i) {
		::proto_ff::E_DecorateDecorateActiveattributeDesc* temp_m_activeattribute = msg.add_m_activeattribute();
		m_ActiveAttribute[i].write_to_pbmsg(*temp_m_activeattribute);
	}
}

void E_DecorateDecorate_s::read_from_pbmsg(const ::proto_ff::E_DecorateDecorate & msg) {
	m_ID = msg.m_id();
	m_name = msg.m_name();
	m_type = msg.m_type();
	m_quality = msg.m_quality();
	m_professionLimit = msg.m_professionlimit();
	m_activationItem = msg.m_activationitem();
	m_activationNum = msg.m_activationnum();
	m_starId = msg.m_starid();
	m_starNum = msg.m_starnum();
	m_starUp = msg.m_starup();
	m_starBer = msg.m_starber();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_DecorateDecorateAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_ActiveAttribute.resize((int)msg.m_activeattribute_size() > (int)m_ActiveAttribute.max_size() ? m_ActiveAttribute.max_size() : msg.m_activeattribute_size());
	for(int32_t i = 0; i < (int32_t)m_ActiveAttribute.size(); ++i) {
		const ::proto_ff::E_DecorateDecorateActiveattributeDesc & temp_m_activeattribute = msg.m_activeattribute(i);
		m_ActiveAttribute[i].read_from_pbmsg(temp_m_activeattribute);
	}
}

Sheet_DecorateDecorate_s::Sheet_DecorateDecorate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DecorateDecorate_s::CreateInit() {
	return 0;
}

int Sheet_DecorateDecorate_s::ResumeInit() {
	return 0;
}

void Sheet_DecorateDecorate_s::write_to_pbmsg(::proto_ff::Sheet_DecorateDecorate & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DecorateDecorate_List.size(); ++i) {
		::proto_ff::E_DecorateDecorate* temp_e_decoratedecorate_list = msg.add_e_decoratedecorate_list();
		E_DecorateDecorate_List[i].write_to_pbmsg(*temp_e_decoratedecorate_list);
	}
}

void Sheet_DecorateDecorate_s::read_from_pbmsg(const ::proto_ff::Sheet_DecorateDecorate & msg) {
	E_DecorateDecorate_List.resize((int)msg.e_decoratedecorate_list_size() > (int)E_DecorateDecorate_List.max_size() ? E_DecorateDecorate_List.max_size() : msg.e_decoratedecorate_list_size());
	for(int32_t i = 0; i < (int32_t)E_DecorateDecorate_List.size(); ++i) {
		const ::proto_ff::E_DecorateDecorate & temp_e_decoratedecorate_list = msg.e_decoratedecorate_list(i);
		E_DecorateDecorate_List[i].read_from_pbmsg(temp_e_decoratedecorate_list);
	}
}

}
