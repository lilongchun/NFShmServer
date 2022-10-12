#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_EQUIP_NUM 4000

class EquipEquipDesc : public NFIDescStore
{
public:
	EquipEquipDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipEquipDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::equipequip_s* GetDesc(int id) const;
	proto_ff_s::equipequip_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipequip_s, MAX_EQUIP_EQUIP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipequip_s, MAX_EQUIP_EQUIP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipequip_s, equipequip, MAX_EQUIP_EQUIP_NUM);
DECLARE_IDCREATE(EquipEquipDesc);
};