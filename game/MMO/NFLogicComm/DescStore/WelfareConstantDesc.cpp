#include "WelfareConstantDesc.h"
#include "BoxBoxDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

WelfareConstantDesc::WelfareConstantDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

WelfareConstantDesc::~WelfareConstantDesc()
{
}

int WelfareConstantDesc::CreateInit()
{
	return 0;
}

int WelfareConstantDesc::ResumeInit()
{
	return 0;
}

int WelfareConstantDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "WelfareConstantDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_WelfareConstant table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_welfareconstant_list_size() < 0) || (table.e_welfareconstant_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_welfareconstant_list_size());
		return -2;
	}

	m_minId = INVALID_ID;
	for (int i = 0; i < (int)table.e_welfareconstant_list_size(); i++)
	{
		const proto_ff::E_WelfareConstant& desc = table.e_welfareconstant_list(i);
		if (desc.has_m_id() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}

		if (m_minId == INVALID_ID)
		{
			m_minId = desc.m_id();
		}
		else
		{
			if (desc.m_id() < m_minId)
			{
				m_minId = desc.m_id();
			}
		}

		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_id()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_id());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_id());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_id());
			}
			continue;
		}
		CHECK_EXPR_ASSERT(m_astDescMap.size() < m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_id()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_id());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_id()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_id());
	}

	for(int i = 0; i < (int)m_astDescIndex.size(); i++)
	{
		m_astDescIndex[i] = INVALID_ID;
	}

	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		int64_t index = (int64_t)iter->first - (int64_t)m_minId;
		if (index >= 0 && index < (int64_t)m_astDescIndex.size())
		{
			m_astDescIndex[index] = iter.m_curNode->m_self;
			CHECK_EXPR_ASSERT(iter == m_astDescMap.get_iterator(m_astDescIndex[index]), -1, "index error");
			CHECK_EXPR_ASSERT(GetDesc(iter->first) == &iter->second, -1, "GetDesc != iter->second, id:{}", iter->first);
		}
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_welfareconstant_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int WelfareConstantDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		CHECK_EXPR_MSG_RESULT((pDesc->m_fraudReward <= 0 || BoxBoxDesc::Instance()->GetDesc(pDesc->m_fraudReward)), result, "can't find the fraudReward:{} in the  excel:box sheet:box", pDesc->m_fraudReward);
		CHECK_EXPR_MSG_RESULT((pDesc->m_keyRebate <= 0 || BoxBoxDesc::Instance()->GetDesc(pDesc->m_keyRebate)), result, "can't find the keyRebate:{} in the  excel:box sheet:box", pDesc->m_keyRebate);
		CHECK_EXPR_MSG_RESULT((pDesc->m_noticeReward <= 0 || BoxBoxDesc::Instance()->GetDesc(pDesc->m_noticeReward)), result, "can't find the noticeReward:{} in the  excel:box sheet:box", pDesc->m_noticeReward);
	}
	return result;
}

