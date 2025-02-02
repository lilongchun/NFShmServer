#include "DBProto_s.h"

namespace proto_ff_s {

tbFishAccountTable_s::tbFishAccountTable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbFishAccountTable_s::CreateInit() {
	player_id = (uint64_t)0;
	account_type = (uint32_t)0;
	phonenum = (uint64_t)0;
	return 0;
}

int tbFishAccountTable_s::ResumeInit() {
	return 0;
}

void tbFishAccountTable_s::write_to_pbmsg(::proto_ff::tbFishAccountTable & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_account(account.data());
	msg.set_password(password.data());
	msg.set_account_type((uint32_t)account_type);
	msg.set_device_id(device_id.data());
	msg.set_phonenum((uint64_t)phonenum);
}

void tbFishAccountTable_s::read_from_pbmsg(const ::proto_ff::tbFishAccountTable & msg) {
	player_id = msg.player_id();
	account = msg.account();
	password = msg.password();
	account_type = msg.account_type();
	device_id = msg.device_id();
	phonenum = msg.phonenum();
}

tbFishPlayerData_s::tbFishPlayerData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbFishPlayerData_s::CreateInit() {
	player_id = (uint64_t)0;
	faceid = (uint32_t)0;
	regdate = (uint64_t)0;
	gender = (uint32_t)0;
	age = (uint32_t)0;
	phonenum = (uint64_t)0;
	jetton = (uint64_t)0;
	last_login_time = (uint64_t)0;
	last_logout_time = (uint64_t)0;
	return 0;
}

int tbFishPlayerData_s::ResumeInit() {
	return 0;
}

void tbFishPlayerData_s::write_to_pbmsg(::proto_ff::tbFishPlayerData & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_nickname(nickname.data());
	msg.set_faceid((uint32_t)faceid);
	msg.set_regdate((uint64_t)regdate);
	msg.set_gender((uint32_t)gender);
	msg.set_age((uint32_t)age);
	msg.set_phonenum((uint64_t)phonenum);
	msg.set_jetton((uint64_t)jetton);
	msg.set_ip(ip.data());
	msg.set_last_login_time((uint64_t)last_login_time);
	msg.set_last_logout_time((uint64_t)last_logout_time);
}

void tbFishPlayerData_s::read_from_pbmsg(const ::proto_ff::tbFishPlayerData & msg) {
	player_id = msg.player_id();
	nickname = msg.nickname();
	faceid = msg.faceid();
	regdate = msg.regdate();
	gender = msg.gender();
	age = msg.age();
	phonenum = msg.phonenum();
	jetton = msg.jetton();
	ip = msg.ip();
	last_login_time = msg.last_login_time();
	last_logout_time = msg.last_logout_time();
}

tbFishSnsPlayerSimpleData_s::tbFishSnsPlayerSimpleData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbFishSnsPlayerSimpleData_s::CreateInit() {
	player_id = (uint64_t)0;
	faceid = (uint32_t)0;
	last_login_time = (uint64_t)0;
	last_logout_time = (uint64_t)0;
	agent = (uint64_t)0;
	return 0;
}

int tbFishSnsPlayerSimpleData_s::ResumeInit() {
	return 0;
}

void tbFishSnsPlayerSimpleData_s::write_to_pbmsg(::proto_ff::tbFishSnsPlayerSimpleData & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_nickname(nickname.data());
	msg.set_faceid((uint32_t)faceid);
	msg.set_last_login_time((uint64_t)last_login_time);
	msg.set_last_logout_time((uint64_t)last_logout_time);
	msg.set_agent((uint64_t)agent);
}

void tbFishSnsPlayerSimpleData_s::read_from_pbmsg(const ::proto_ff::tbFishSnsPlayerSimpleData & msg) {
	player_id = msg.player_id();
	nickname = msg.nickname();
	faceid = msg.faceid();
	last_login_time = msg.last_login_time();
	last_logout_time = msg.last_logout_time();
	agent = msg.agent();
}

GiveBankRecordDBData_s::GiveBankRecordDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GiveBankRecordDBData_s::CreateInit() {
	return 0;
}

int GiveBankRecordDBData_s::ResumeInit() {
	return 0;
}

void GiveBankRecordDBData_s::write_to_pbmsg(::proto_ff::GiveBankRecordDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		::proto_ff::tbGiveBankJetton* temp_record = msg.add_record();
		record[i].write_to_pbmsg(*temp_record);
	}
}

void GiveBankRecordDBData_s::read_from_pbmsg(const ::proto_ff::GiveBankRecordDBData & msg) {
	record.resize((int)msg.record_size() > (int)record.max_size() ? record.max_size() : msg.record_size());
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		const ::proto_ff::tbGiveBankJetton & temp_record = msg.record(i);
		record[i].read_from_pbmsg(temp_record);
	}
}

tbFishSnsPlayerDetailData_s::tbFishSnsPlayerDetailData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbFishSnsPlayerDetailData_s::CreateInit() {
	player_id = (uint64_t)0;
	bank_jetton = (uint64_t)0;
	return 0;
}

int tbFishSnsPlayerDetailData_s::ResumeInit() {
	return 0;
}

void tbFishSnsPlayerDetailData_s::write_to_pbmsg(::proto_ff::tbFishSnsPlayerDetailData & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_bank_jetton((uint64_t)bank_jetton);
	msg.set_bank_password(bank_password.data());
	::proto_ff::GiveBankRecordDBData* temp_record = msg.mutable_record();
	record.write_to_pbmsg(*temp_record);
}

void tbFishSnsPlayerDetailData_s::read_from_pbmsg(const ::proto_ff::tbFishSnsPlayerDetailData & msg) {
	player_id = msg.player_id();
	bank_jetton = msg.bank_jetton();
	bank_password = msg.bank_password();
	const ::proto_ff::GiveBankRecordDBData & temp_record = msg.record();
	record.read_from_pbmsg(temp_record);
}

}
