#include "AchievementAchievementrewardDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(AchievementAchievementrewardDesc, EOT_CONST_ACHIEVEMENT_ACHIEVEMENTREWARD_DESC_ID, NFShmObj)

AchievementAchievementrewardDesc::AchievementAchievementrewardDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AchievementAchievementrewardDesc::~AchievementAchievementrewardDesc()
{
}

int AchievementAchievementrewardDesc::CreateInit()
{
	Initialize();
	return 0;
}

int AchievementAchievementrewardDesc::ResumeInit()
{
	return 0;
}

int AchievementAchievementrewardDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_achievementachievementreward table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.achievementachievementreward_list_size() < 0) || (table.achievementachievementreward_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.achievementachievementreward_list_size());
		return -2;
	}

	for (int i = 0; i < table.achievementachievementreward_list_size(); i++)
	{
		const proto_ff::achievementachievementreward& desc = table.achievementachievementreward_list(i);
		if (desc.has_achievementprizeid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		auto pDesc = m_astDesc.Insert(desc.achievementprizeid());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.achievementprizeid());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.achievementachievementreward_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int AchievementAchievementrewardDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::achievementachievementreward_s * AchievementAchievementrewardDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::achievementachievementreward_s * AchievementAchievementrewardDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}
