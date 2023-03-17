#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/title_s.h"

#define MAX_TITLE_TITLE_NUM 40

class TitleTitleDesc : public NFIDescStore
{
public:
	TitleTitleDesc();
	virtual ~TitleTitleDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_TitleTitle_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TitleTitle_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TitleTitle_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TitleTitle_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(TitleTitleDesc, proto_ff_s::E_TitleTitle_s, E_TitleTitle, MAX_TITLE_TITLE_NUM);
DECLARE_IDCREATE(TitleTitleDesc);
};