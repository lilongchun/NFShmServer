#include "AvatarDisplayDesc.h"
#include "AvatarFragmentDesc.h"
#include "ItemItemDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

AvatarDisplayDesc::AvatarDisplayDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AvatarDisplayDesc::~AvatarDisplayDesc()
{
}

int AvatarDisplayDesc::CreateInit()
{
	return 0;
}

int AvatarDisplayDesc::ResumeInit()
{
	return 0;
}

int AvatarDisplayDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "AvatarDisplayDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_AvatarDisplay table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_avatardisplay_list_size() < 0) || (table.e_avatardisplay_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_avatardisplay_list_size());
		return -2;
	}

	m_minId = INVALID_ID;
	for (int i = 0; i < (int)table.e_avatardisplay_list_size(); i++)
	{
		const proto_ff::E_AvatarDisplay& desc = table.e_avatardisplay_list(i);
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

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_avatardisplay_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int AvatarDisplayDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		for(int j = 0; j < (int)pDesc->m_fragmentID.size(); j++)
		{
			CHECK_EXPR_MSG_RESULT((pDesc->m_fragmentID[j] <= 0 || AvatarFragmentDesc::Instance()->GetDesc(pDesc->m_fragmentID[j])), result, "can't find the fragmentID:{} in the  excel:avatar sheet:fragment", pDesc->m_fragmentID[j]);
		}
		for(int j = 0; j < (int)pDesc->m_material.size(); j++)
		{
			CHECK_EXPR_MSG_RESULT((pDesc->m_material[j].m_id <= 0 || ItemItemDesc::Instance()->GetDesc(pDesc->m_material[j].m_id)), result, "can't find the material:{} in the  excel:item sheet:item", pDesc->m_material[j].m_id);
		}
	}
	return result;
}

