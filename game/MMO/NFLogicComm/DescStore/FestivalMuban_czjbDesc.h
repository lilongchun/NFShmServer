#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_CZJB_NUM 20

class FestivalMuban_czjbDesc : public NFIDescStore
{
public:
	FestivalMuban_czjbDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_czjbDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalmuban_czjb_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_czjb_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_czjb_s, MAX_FESTIVAL_MUBAN_CZJB_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_czjb_s, MAX_FESTIVAL_MUBAN_CZJB_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_czjb_s, festivalmuban_czjb, MAX_FESTIVAL_MUBAN_CZJB_NUM);
DECLARE_IDCREATE(FestivalMuban_czjbDesc);
};