#include "E_Mofa_s.h"

namespace proto_ff_s {

E_MofaSetupZfDesc_s::E_MofaSetupZfDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaSetupZfDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MofaSetupZfDesc_s::ResumeInit() {
	return 0;
}

void E_MofaSetupZfDesc_s::write_to_pbmsg(::proto_ff::E_MofaSetupZfDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MofaSetupZfDesc_s::read_from_pbmsg(const ::proto_ff::E_MofaSetupZfDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MofaSetup_s::E_MofaSetup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaSetup_s::CreateInit() {
	m_PositionID = (int32_t)0;
	m_Unlock = (int32_t)0;
	m_ZyAtt = (int32_t)0;
	m_Bless = (int32_t)0;
	m_BlessBonus = (int32_t)0;
	m_JxZyAtt = (int32_t)0;
	m_JxBlessBonus = (int32_t)0;
	m_JxBlessAtt = (int32_t)0;
	return 0;
}

int E_MofaSetup_s::ResumeInit() {
	return 0;
}

void E_MofaSetup_s::write_to_pbmsg(::proto_ff::E_MofaSetup & msg) const {
	msg.set_m_positionid((int32_t)m_PositionID);
	msg.set_m_unlock((int32_t)m_Unlock);
	msg.set_m_zyatt((int32_t)m_ZyAtt);
	msg.set_m_bless((int32_t)m_Bless);
	msg.set_m_blessbonus((int32_t)m_BlessBonus);
	msg.set_m_jxzyatt((int32_t)m_JxZyAtt);
	msg.set_m_jxblessbonus((int32_t)m_JxBlessBonus);
	msg.set_m_jxblessatt((int32_t)m_JxBlessAtt);
	for(int32_t i = 0; i < (int32_t)m_ZF.size(); ++i) {
		::proto_ff::E_MofaSetupZfDesc* temp_m_zf = msg.add_m_zf();
		m_ZF[i].write_to_pbmsg(*temp_m_zf);
	}
}

void E_MofaSetup_s::read_from_pbmsg(const ::proto_ff::E_MofaSetup & msg) {
	m_PositionID = msg.m_positionid();
	m_Unlock = msg.m_unlock();
	m_ZyAtt = msg.m_zyatt();
	m_Bless = msg.m_bless();
	m_BlessBonus = msg.m_blessbonus();
	m_JxZyAtt = msg.m_jxzyatt();
	m_JxBlessBonus = msg.m_jxblessbonus();
	m_JxBlessAtt = msg.m_jxblessatt();
	m_ZF.resize((int)msg.m_zf_size() > (int)m_ZF.max_size() ? m_ZF.max_size() : msg.m_zf_size());
	for(int32_t i = 0; i < (int32_t)m_ZF.size(); ++i) {
		const ::proto_ff::E_MofaSetupZfDesc & temp_m_zf = msg.m_zf(i);
		m_ZF[i].read_from_pbmsg(temp_m_zf);
	}
}

Sheet_MofaSetup_s::Sheet_MofaSetup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MofaSetup_s::CreateInit() {
	return 0;
}

int Sheet_MofaSetup_s::ResumeInit() {
	return 0;
}

void Sheet_MofaSetup_s::write_to_pbmsg(::proto_ff::Sheet_MofaSetup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MofaSetup_List.size(); ++i) {
		::proto_ff::E_MofaSetup* temp_e_mofasetup_list = msg.add_e_mofasetup_list();
		E_MofaSetup_List[i].write_to_pbmsg(*temp_e_mofasetup_list);
	}
}

void Sheet_MofaSetup_s::read_from_pbmsg(const ::proto_ff::Sheet_MofaSetup & msg) {
	E_MofaSetup_List.resize((int)msg.e_mofasetup_list_size() > (int)E_MofaSetup_List.max_size() ? E_MofaSetup_List.max_size() : msg.e_mofasetup_list_size());
	for(int32_t i = 0; i < (int32_t)E_MofaSetup_List.size(); ++i) {
		const ::proto_ff::E_MofaSetup & temp_e_mofasetup_list = msg.e_mofasetup_list(i);
		E_MofaSetup_List[i].read_from_pbmsg(temp_e_mofasetup_list);
	}
}

E_MofaYuansuAttributeDesc_s::E_MofaYuansuAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaYuansuAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MofaYuansuAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MofaYuansuAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MofaYuansuAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MofaYuansuAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MofaYuansuAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MofaYuansuAwakenDesc_s::E_MofaYuansuAwakenDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaYuansuAwakenDesc_s::CreateInit() {
	m_lvAddratio = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_MofaYuansuAwakenDesc_s::ResumeInit() {
	return 0;
}

void E_MofaYuansuAwakenDesc_s::write_to_pbmsg(::proto_ff::E_MofaYuansuAwakenDesc & msg) const {
	msg.set_m_lvaddratio((int32_t)m_lvAddratio);
	msg.set_m_num((int32_t)m_num);
}

void E_MofaYuansuAwakenDesc_s::read_from_pbmsg(const ::proto_ff::E_MofaYuansuAwakenDesc & msg) {
	m_lvAddratio = msg.m_lvaddratio();
	m_num = msg.m_num();
}

E_MofaYuansu_s::E_MofaYuansu_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaYuansu_s::CreateInit() {
	m_EquipID = (int32_t)0;
	m_AttriType = (int32_t)0;
	m_LvItem = (int32_t)0;
	m_awaken_can = (int32_t)0;
	m_awaken_Lvmax = (int32_t)0;
	m_awaken_item = (int32_t)0;
	return 0;
}

int E_MofaYuansu_s::ResumeInit() {
	return 0;
}

void E_MofaYuansu_s::write_to_pbmsg(::proto_ff::E_MofaYuansu & msg) const {
	msg.set_m_equipid((int32_t)m_EquipID);
	msg.set_m_attritype((int32_t)m_AttriType);
	msg.set_m_mosaic(m_mosaic.data());
	msg.set_m_lvitem((int32_t)m_LvItem);
	msg.set_m_awaken_can((int32_t)m_awaken_can);
	msg.set_m_awaken_lvmax((int32_t)m_awaken_Lvmax);
	msg.set_m_awaken_item((int32_t)m_awaken_item);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MofaYuansuAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_awaken.size(); ++i) {
		::proto_ff::E_MofaYuansuAwakenDesc* temp_m_awaken = msg.add_m_awaken();
		m_awaken[i].write_to_pbmsg(*temp_m_awaken);
	}
}

void E_MofaYuansu_s::read_from_pbmsg(const ::proto_ff::E_MofaYuansu & msg) {
	m_EquipID = msg.m_equipid();
	m_AttriType = msg.m_attritype();
	m_mosaic = msg.m_mosaic();
	m_LvItem = msg.m_lvitem();
	m_awaken_can = msg.m_awaken_can();
	m_awaken_Lvmax = msg.m_awaken_lvmax();
	m_awaken_item = msg.m_awaken_item();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MofaYuansuAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_awaken.resize((int)msg.m_awaken_size() > (int)m_awaken.max_size() ? m_awaken.max_size() : msg.m_awaken_size());
	for(int32_t i = 0; i < (int32_t)m_awaken.size(); ++i) {
		const ::proto_ff::E_MofaYuansuAwakenDesc & temp_m_awaken = msg.m_awaken(i);
		m_awaken[i].read_from_pbmsg(temp_m_awaken);
	}
}

Sheet_MofaYuansu_s::Sheet_MofaYuansu_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MofaYuansu_s::CreateInit() {
	return 0;
}

int Sheet_MofaYuansu_s::ResumeInit() {
	return 0;
}

void Sheet_MofaYuansu_s::write_to_pbmsg(::proto_ff::Sheet_MofaYuansu & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MofaYuansu_List.size(); ++i) {
		::proto_ff::E_MofaYuansu* temp_e_mofayuansu_list = msg.add_e_mofayuansu_list();
		E_MofaYuansu_List[i].write_to_pbmsg(*temp_e_mofayuansu_list);
	}
}

void Sheet_MofaYuansu_s::read_from_pbmsg(const ::proto_ff::Sheet_MofaYuansu & msg) {
	E_MofaYuansu_List.resize((int)msg.e_mofayuansu_list_size() > (int)E_MofaYuansu_List.max_size() ? E_MofaYuansu_List.max_size() : msg.e_mofayuansu_list_size());
	for(int32_t i = 0; i < (int32_t)E_MofaYuansu_List.size(); ++i) {
		const ::proto_ff::E_MofaYuansu & temp_e_mofayuansu_list = msg.e_mofayuansu_list(i);
		E_MofaYuansu_List[i].read_from_pbmsg(temp_e_mofayuansu_list);
	}
}

E_MofaDecompose_s::E_MofaDecompose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaDecompose_s::CreateInit() {
	m_DpQua = (int32_t)0;
	m_DpItem = (int32_t)0;
	m_DpEss = (int32_t)0;
	return 0;
}

int E_MofaDecompose_s::ResumeInit() {
	return 0;
}

void E_MofaDecompose_s::write_to_pbmsg(::proto_ff::E_MofaDecompose & msg) const {
	msg.set_m_dpqua((int32_t)m_DpQua);
	msg.set_m_dpitem((int32_t)m_DpItem);
	msg.set_m_dpess((int32_t)m_DpEss);
}

void E_MofaDecompose_s::read_from_pbmsg(const ::proto_ff::E_MofaDecompose & msg) {
	m_DpQua = msg.m_dpqua();
	m_DpItem = msg.m_dpitem();
	m_DpEss = msg.m_dpess();
}

Sheet_MofaDecompose_s::Sheet_MofaDecompose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MofaDecompose_s::CreateInit() {
	return 0;
}

int Sheet_MofaDecompose_s::ResumeInit() {
	return 0;
}

void Sheet_MofaDecompose_s::write_to_pbmsg(::proto_ff::Sheet_MofaDecompose & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MofaDecompose_List.size(); ++i) {
		::proto_ff::E_MofaDecompose* temp_e_mofadecompose_list = msg.add_e_mofadecompose_list();
		E_MofaDecompose_List[i].write_to_pbmsg(*temp_e_mofadecompose_list);
	}
}

void Sheet_MofaDecompose_s::read_from_pbmsg(const ::proto_ff::Sheet_MofaDecompose & msg) {
	E_MofaDecompose_List.resize((int)msg.e_mofadecompose_list_size() > (int)E_MofaDecompose_List.max_size() ? E_MofaDecompose_List.max_size() : msg.e_mofadecompose_list_size());
	for(int32_t i = 0; i < (int32_t)E_MofaDecompose_List.size(); ++i) {
		const ::proto_ff::E_MofaDecompose & temp_e_mofadecompose_list = msg.e_mofadecompose_list(i);
		E_MofaDecompose_List[i].read_from_pbmsg(temp_e_mofadecompose_list);
	}
}

E_MofaLvexp_s::E_MofaLvexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaLvexp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_MofaLvexp_s::ResumeInit() {
	return 0;
}

void E_MofaLvexp_s::write_to_pbmsg(::proto_ff::E_MofaLvexp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
}

void E_MofaLvexp_s::read_from_pbmsg(const ::proto_ff::E_MofaLvexp & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
}

Sheet_MofaLvexp_s::Sheet_MofaLvexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MofaLvexp_s::CreateInit() {
	return 0;
}

int Sheet_MofaLvexp_s::ResumeInit() {
	return 0;
}

void Sheet_MofaLvexp_s::write_to_pbmsg(::proto_ff::Sheet_MofaLvexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MofaLvexp_List.size(); ++i) {
		::proto_ff::E_MofaLvexp* temp_e_mofalvexp_list = msg.add_e_mofalvexp_list();
		E_MofaLvexp_List[i].write_to_pbmsg(*temp_e_mofalvexp_list);
	}
}

void Sheet_MofaLvexp_s::read_from_pbmsg(const ::proto_ff::Sheet_MofaLvexp & msg) {
	E_MofaLvexp_List.resize((int)msg.e_mofalvexp_list_size() > (int)E_MofaLvexp_List.max_size() ? E_MofaLvexp_List.max_size() : msg.e_mofalvexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_MofaLvexp_List.size(); ++i) {
		const ::proto_ff::E_MofaLvexp & temp_e_mofalvexp_list = msg.e_mofalvexp_list(i);
		E_MofaLvexp_List[i].read_from_pbmsg(temp_e_mofalvexp_list);
	}
}

E_MofaLvatt_s::E_MofaLvatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaLvatt_s::CreateInit() {
	m_attId = (int64_t)0;
	return 0;
}

int E_MofaLvatt_s::ResumeInit() {
	return 0;
}

void E_MofaLvatt_s::write_to_pbmsg(::proto_ff::E_MofaLvatt & msg) const {
	msg.set_m_attid((int64_t)m_attId);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		msg.add_m_att((int32_t)m_att[i]);
	}
}

void E_MofaLvatt_s::read_from_pbmsg(const ::proto_ff::E_MofaLvatt & msg) {
	m_attId = msg.m_attid();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		m_att[i] = msg.m_att(i);
	}
}

Sheet_MofaLvatt_s::Sheet_MofaLvatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MofaLvatt_s::CreateInit() {
	return 0;
}

int Sheet_MofaLvatt_s::ResumeInit() {
	return 0;
}

void Sheet_MofaLvatt_s::write_to_pbmsg(::proto_ff::Sheet_MofaLvatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MofaLvatt_List.size(); ++i) {
		::proto_ff::E_MofaLvatt* temp_e_mofalvatt_list = msg.add_e_mofalvatt_list();
		E_MofaLvatt_List[i].write_to_pbmsg(*temp_e_mofalvatt_list);
	}
}

void Sheet_MofaLvatt_s::read_from_pbmsg(const ::proto_ff::Sheet_MofaLvatt & msg) {
	E_MofaLvatt_List.resize((int)msg.e_mofalvatt_list_size() > (int)E_MofaLvatt_List.max_size() ? E_MofaLvatt_List.max_size() : msg.e_mofalvatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_MofaLvatt_List.size(); ++i) {
		const ::proto_ff::E_MofaLvatt & temp_e_mofalvatt_list = msg.e_mofalvatt_list(i);
		E_MofaLvatt_List[i].read_from_pbmsg(temp_e_mofalvatt_list);
	}
}

E_MofaZyattZyDesc_s::E_MofaZyattZyDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaZyattZyDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MofaZyattZyDesc_s::ResumeInit() {
	return 0;
}

void E_MofaZyattZyDesc_s::write_to_pbmsg(::proto_ff::E_MofaZyattZyDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MofaZyattZyDesc_s::read_from_pbmsg(const ::proto_ff::E_MofaZyattZyDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MofaZyatt_s::E_MofaZyatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaZyatt_s::CreateInit() {
	m_ID = (int32_t)0;
	m_AttID = (int64_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_MofaZyatt_s::ResumeInit() {
	return 0;
}

void E_MofaZyatt_s::write_to_pbmsg(::proto_ff::E_MofaZyatt & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_attid((int64_t)m_AttID);
	msg.set_m_quality((int32_t)m_quality);
	for(int32_t i = 0; i < (int32_t)m_ZY.size(); ++i) {
		::proto_ff::E_MofaZyattZyDesc* temp_m_zy = msg.add_m_zy();
		m_ZY[i].write_to_pbmsg(*temp_m_zy);
	}
}

void E_MofaZyatt_s::read_from_pbmsg(const ::proto_ff::E_MofaZyatt & msg) {
	m_ID = msg.m_id();
	m_AttID = msg.m_attid();
	m_quality = msg.m_quality();
	m_ZY.resize((int)msg.m_zy_size() > (int)m_ZY.max_size() ? m_ZY.max_size() : msg.m_zy_size());
	for(int32_t i = 0; i < (int32_t)m_ZY.size(); ++i) {
		const ::proto_ff::E_MofaZyattZyDesc & temp_m_zy = msg.m_zy(i);
		m_ZY[i].read_from_pbmsg(temp_m_zy);
	}
}

Sheet_MofaZyatt_s::Sheet_MofaZyatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MofaZyatt_s::CreateInit() {
	return 0;
}

int Sheet_MofaZyatt_s::ResumeInit() {
	return 0;
}

void Sheet_MofaZyatt_s::write_to_pbmsg(::proto_ff::Sheet_MofaZyatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MofaZyatt_List.size(); ++i) {
		::proto_ff::E_MofaZyatt* temp_e_mofazyatt_list = msg.add_e_mofazyatt_list();
		E_MofaZyatt_List[i].write_to_pbmsg(*temp_e_mofazyatt_list);
	}
}

void Sheet_MofaZyatt_s::read_from_pbmsg(const ::proto_ff::Sheet_MofaZyatt & msg) {
	E_MofaZyatt_List.resize((int)msg.e_mofazyatt_list_size() > (int)E_MofaZyatt_List.max_size() ? E_MofaZyatt_List.max_size() : msg.e_mofazyatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_MofaZyatt_List.size(); ++i) {
		const ::proto_ff::E_MofaZyatt & temp_e_mofazyatt_list = msg.e_mofazyatt_list(i);
		E_MofaZyatt_List[i].read_from_pbmsg(temp_e_mofazyatt_list);
	}
}

E_MofaZyjxattZyjxDesc_s::E_MofaZyjxattZyjxDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaZyjxattZyjxDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MofaZyjxattZyjxDesc_s::ResumeInit() {
	return 0;
}

void E_MofaZyjxattZyjxDesc_s::write_to_pbmsg(::proto_ff::E_MofaZyjxattZyjxDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MofaZyjxattZyjxDesc_s::read_from_pbmsg(const ::proto_ff::E_MofaZyjxattZyjxDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MofaZyjxatt_s::E_MofaZyjxatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaZyjxatt_s::CreateInit() {
	m_ID = (int32_t)0;
	m_AttID = (int64_t)0;
	m_JxLv = (int32_t)0;
	return 0;
}

int E_MofaZyjxatt_s::ResumeInit() {
	return 0;
}

void E_MofaZyjxatt_s::write_to_pbmsg(::proto_ff::E_MofaZyjxatt & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_attid((int64_t)m_AttID);
	msg.set_m_jxlv((int32_t)m_JxLv);
	for(int32_t i = 0; i < (int32_t)m_ZyJx.size(); ++i) {
		::proto_ff::E_MofaZyjxattZyjxDesc* temp_m_zyjx = msg.add_m_zyjx();
		m_ZyJx[i].write_to_pbmsg(*temp_m_zyjx);
	}
}

void E_MofaZyjxatt_s::read_from_pbmsg(const ::proto_ff::E_MofaZyjxatt & msg) {
	m_ID = msg.m_id();
	m_AttID = msg.m_attid();
	m_JxLv = msg.m_jxlv();
	m_ZyJx.resize((int)msg.m_zyjx_size() > (int)m_ZyJx.max_size() ? m_ZyJx.max_size() : msg.m_zyjx_size());
	for(int32_t i = 0; i < (int32_t)m_ZyJx.size(); ++i) {
		const ::proto_ff::E_MofaZyjxattZyjxDesc & temp_m_zyjx = msg.m_zyjx(i);
		m_ZyJx[i].read_from_pbmsg(temp_m_zyjx);
	}
}

Sheet_MofaZyjxatt_s::Sheet_MofaZyjxatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MofaZyjxatt_s::CreateInit() {
	return 0;
}

int Sheet_MofaZyjxatt_s::ResumeInit() {
	return 0;
}

void Sheet_MofaZyjxatt_s::write_to_pbmsg(::proto_ff::Sheet_MofaZyjxatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MofaZyjxatt_List.size(); ++i) {
		::proto_ff::E_MofaZyjxatt* temp_e_mofazyjxatt_list = msg.add_e_mofazyjxatt_list();
		E_MofaZyjxatt_List[i].write_to_pbmsg(*temp_e_mofazyjxatt_list);
	}
}

void Sheet_MofaZyjxatt_s::read_from_pbmsg(const ::proto_ff::Sheet_MofaZyjxatt & msg) {
	E_MofaZyjxatt_List.resize((int)msg.e_mofazyjxatt_list_size() > (int)E_MofaZyjxatt_List.max_size() ? E_MofaZyjxatt_List.max_size() : msg.e_mofazyjxatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_MofaZyjxatt_List.size(); ++i) {
		const ::proto_ff::E_MofaZyjxatt & temp_e_mofazyjxatt_list = msg.e_mofazyjxatt_list(i);
		E_MofaZyjxatt_List[i].read_from_pbmsg(temp_e_mofazyjxatt_list);
	}
}

E_MofaZyjxzfattZyjxzfDesc_s::E_MofaZyjxzfattZyjxzfDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaZyjxzfattZyjxzfDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MofaZyjxzfattZyjxzfDesc_s::ResumeInit() {
	return 0;
}

void E_MofaZyjxzfattZyjxzfDesc_s::write_to_pbmsg(::proto_ff::E_MofaZyjxzfattZyjxzfDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MofaZyjxzfattZyjxzfDesc_s::read_from_pbmsg(const ::proto_ff::E_MofaZyjxzfattZyjxzfDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MofaZyjxzfatt_s::E_MofaZyjxzfatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaZyjxzfatt_s::CreateInit() {
	m_ID = (int32_t)0;
	m_AttID = (int64_t)0;
	m_JxLv = (int32_t)0;
	return 0;
}

int E_MofaZyjxzfatt_s::ResumeInit() {
	return 0;
}

void E_MofaZyjxzfatt_s::write_to_pbmsg(::proto_ff::E_MofaZyjxzfatt & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_attid((int64_t)m_AttID);
	msg.set_m_jxlv((int32_t)m_JxLv);
	for(int32_t i = 0; i < (int32_t)m_ZyJxZf.size(); ++i) {
		::proto_ff::E_MofaZyjxzfattZyjxzfDesc* temp_m_zyjxzf = msg.add_m_zyjxzf();
		m_ZyJxZf[i].write_to_pbmsg(*temp_m_zyjxzf);
	}
}

void E_MofaZyjxzfatt_s::read_from_pbmsg(const ::proto_ff::E_MofaZyjxzfatt & msg) {
	m_ID = msg.m_id();
	m_AttID = msg.m_attid();
	m_JxLv = msg.m_jxlv();
	m_ZyJxZf.resize((int)msg.m_zyjxzf_size() > (int)m_ZyJxZf.max_size() ? m_ZyJxZf.max_size() : msg.m_zyjxzf_size());
	for(int32_t i = 0; i < (int32_t)m_ZyJxZf.size(); ++i) {
		const ::proto_ff::E_MofaZyjxzfattZyjxzfDesc & temp_m_zyjxzf = msg.m_zyjxzf(i);
		m_ZyJxZf[i].read_from_pbmsg(temp_m_zyjxzf);
	}
}

Sheet_MofaZyjxzfatt_s::Sheet_MofaZyjxzfatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MofaZyjxzfatt_s::CreateInit() {
	return 0;
}

int Sheet_MofaZyjxzfatt_s::ResumeInit() {
	return 0;
}

void Sheet_MofaZyjxzfatt_s::write_to_pbmsg(::proto_ff::Sheet_MofaZyjxzfatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MofaZyjxzfatt_List.size(); ++i) {
		::proto_ff::E_MofaZyjxzfatt* temp_e_mofazyjxzfatt_list = msg.add_e_mofazyjxzfatt_list();
		E_MofaZyjxzfatt_List[i].write_to_pbmsg(*temp_e_mofazyjxzfatt_list);
	}
}

void Sheet_MofaZyjxzfatt_s::read_from_pbmsg(const ::proto_ff::Sheet_MofaZyjxzfatt & msg) {
	E_MofaZyjxzfatt_List.resize((int)msg.e_mofazyjxzfatt_list_size() > (int)E_MofaZyjxzfatt_List.max_size() ? E_MofaZyjxzfatt_List.max_size() : msg.e_mofazyjxzfatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_MofaZyjxzfatt_List.size(); ++i) {
		const ::proto_ff::E_MofaZyjxzfatt & temp_e_mofazyjxzfatt_list = msg.e_mofazyjxzfatt_list(i);
		E_MofaZyjxzfatt_List[i].read_from_pbmsg(temp_e_mofazyjxzfatt_list);
	}
}

E_MofaExchange_s::E_MofaExchange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaExchange_s::CreateInit() {
	m_EquipID = (int32_t)0;
	m_EcItem = (int32_t)0;
	m_EcNum = (int32_t)0;
	return 0;
}

int E_MofaExchange_s::ResumeInit() {
	return 0;
}

void E_MofaExchange_s::write_to_pbmsg(::proto_ff::E_MofaExchange & msg) const {
	msg.set_m_equipid((int32_t)m_EquipID);
	msg.set_m_ecitem((int32_t)m_EcItem);
	msg.set_m_ecnum((int32_t)m_EcNum);
}

void E_MofaExchange_s::read_from_pbmsg(const ::proto_ff::E_MofaExchange & msg) {
	m_EquipID = msg.m_equipid();
	m_EcItem = msg.m_ecitem();
	m_EcNum = msg.m_ecnum();
}

Sheet_MofaExchange_s::Sheet_MofaExchange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MofaExchange_s::CreateInit() {
	return 0;
}

int Sheet_MofaExchange_s::ResumeInit() {
	return 0;
}

void Sheet_MofaExchange_s::write_to_pbmsg(::proto_ff::Sheet_MofaExchange & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MofaExchange_List.size(); ++i) {
		::proto_ff::E_MofaExchange* temp_e_mofaexchange_list = msg.add_e_mofaexchange_list();
		E_MofaExchange_List[i].write_to_pbmsg(*temp_e_mofaexchange_list);
	}
}

void Sheet_MofaExchange_s::read_from_pbmsg(const ::proto_ff::Sheet_MofaExchange & msg) {
	E_MofaExchange_List.resize((int)msg.e_mofaexchange_list_size() > (int)E_MofaExchange_List.max_size() ? E_MofaExchange_List.max_size() : msg.e_mofaexchange_list_size());
	for(int32_t i = 0; i < (int32_t)E_MofaExchange_List.size(); ++i) {
		const ::proto_ff::E_MofaExchange & temp_e_mofaexchange_list = msg.e_mofaexchange_list(i);
		E_MofaExchange_List[i].read_from_pbmsg(temp_e_mofaexchange_list);
	}
}

E_MofaName_s::E_MofaName_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MofaName_s::CreateInit() {
	m_id = (int32_t)0;
	m_functionid = (int32_t)0;
	return 0;
}

int E_MofaName_s::ResumeInit() {
	return 0;
}

void E_MofaName_s::write_to_pbmsg(::proto_ff::E_MofaName & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_functionid((int32_t)m_functionid);
}

void E_MofaName_s::read_from_pbmsg(const ::proto_ff::E_MofaName & msg) {
	m_id = msg.m_id();
	m_functionid = msg.m_functionid();
}

Sheet_MofaName_s::Sheet_MofaName_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MofaName_s::CreateInit() {
	return 0;
}

int Sheet_MofaName_s::ResumeInit() {
	return 0;
}

void Sheet_MofaName_s::write_to_pbmsg(::proto_ff::Sheet_MofaName & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MofaName_List.size(); ++i) {
		::proto_ff::E_MofaName* temp_e_mofaname_list = msg.add_e_mofaname_list();
		E_MofaName_List[i].write_to_pbmsg(*temp_e_mofaname_list);
	}
}

void Sheet_MofaName_s::read_from_pbmsg(const ::proto_ff::Sheet_MofaName & msg) {
	E_MofaName_List.resize((int)msg.e_mofaname_list_size() > (int)E_MofaName_List.max_size() ? E_MofaName_List.max_size() : msg.e_mofaname_list_size());
	for(int32_t i = 0; i < (int32_t)E_MofaName_List.size(); ++i) {
		const ::proto_ff::E_MofaName & temp_e_mofaname_list = msg.e_mofaname_list(i);
		E_MofaName_List[i].read_from_pbmsg(temp_e_mofaname_list);
	}
}

}
