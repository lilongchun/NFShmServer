#include "EquipGemDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(EquipGemDesc, EOT_CONST_EQUIP_GEM_DESC_ID, NFShmObj)

EquipGemDesc::EquipGemDesc():NFIDescStore()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EquipGemDesc::~EquipGemDesc()
{
}

int EquipGemDesc::CreateInit()
{
	return 0;
}

int EquipGemDesc::ResumeInit()
{
	return 0;
}

int EquipGemDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "EquipGemDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_EquipGem table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_equipgem_list_size() < 0) || (table.e_equipgem_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_equipgem_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_equipgem_list_size(); i++)
	{
		const proto_ff::E_EquipGem& desc = table.e_equipgem_list(i);
		if (desc.has_m_position() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_position()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_position());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_position());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_position());
			}
			continue;
		}
		m_astDesc.push_back();
		auto pDesc = &m_astDesc.back();
		int curIndex = m_astDesc.size() - 1;
		CHECK_EXPR(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_position());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_position(), curIndex);
		CHECK_EXPR(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_position());
		uint64_t hashKey = desc.m_position();
		if (hashKey < NF_MAX_DESC_STORE_INDEX_SIZE)
		{
			if (m_astDescIndex[hashKey] != -1)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc store:{} exist repeated key:{}", GetFileName(), hashKey);
				m_astDescIndex[hashKey] = -1;
			}
			else
			{
				m_astDescIndex[hashKey] = curIndex;
			}
		}
		else
		{
			//NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc store:{} exist key:{} than the max index:{}", GetFileName(), hashKey, NF_MAX_DESC_STORE_INDEX_SIZE);
		}
		CHECK_EXPR_ASSERT(GetDesc(hashKey) == pDesc, -1, "GetDesc != pDesc, id:{}", hashKey);
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_equipgem_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int EquipGemDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::E_EquipGem_s * EquipGemDesc::GetDesc(int64_t id) const
{
	if (id >= 0 && id < NF_MAX_DESC_STORE_INDEX_SIZE)
	{
		int index = m_astDescIndex[id];
		if (index >= 0)
		{
			CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} of the id:{} exist error, than the m_astDesc max index:{}", index, id, m_astDesc.size());
			return &m_astDesc[index];
		}
	}

	auto iter = m_astDescMap.find(id);
	if (iter != m_astDescMap.end())
	{
		int index = iter->second;
		CHECK_EXPR_ASSERT(index >= 0 && index < (int)m_astDesc.size(), NULL, "the index:{} of the id:{} exist error, than the m_astDesc max index:{}", index, id, m_astDesc.size());
		return &m_astDesc[index];
	}

	return NULL;
}

proto_ff_s::E_EquipGem_s * EquipGemDesc::GetDesc(int64_t id)
{
	return const_cast<proto_ff_s::E_EquipGem_s *>((static_cast<const EquipGemDesc*>(this))->GetDesc(id));
}

int EquipGemDesc::GetDescIndex(int id) const
{
	auto iter = m_astDescMap.find(id);
	if (iter != m_astDescMap.end())
	{
		return iter->second;
	}

	return -1;
}

const proto_ff_s::E_EquipGem_s * EquipGemDesc::GetDescByIndex(int index) const
{
	CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
	return &m_astDesc[index];
}

proto_ff_s::E_EquipGem_s * EquipGemDesc::GetDescByIndex(int index)
{
	CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
	return &m_astDesc[index];
}
