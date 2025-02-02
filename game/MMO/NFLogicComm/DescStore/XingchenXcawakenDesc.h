#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCAWAKEN_NUM 32

#define MAX_COM_INDEX_XINGCHEN_XCAWAKEN_POSITIONID_NUM 4

#define UNIQUE_KEY_MAX_COM_INDEX_XINGCHEN_XCAWAKEN_POSITIONID_NUM 16

#define MAX_COM_INDEX_XINGCHEN_XCAWAKEN_AWAKEN_QUALITY_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_XINGCHEN_XCAWAKEN_AWAKEN_QUALITY_NUM 4

struct XingchenXcawakenPositionidAwaken_quality
{
	XingchenXcawakenPositionidAwaken_quality()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		}
		else {
			ResumeInit();
		}
	}
	int CreateInit()
	{
		m_PositionID=0;
		m_awaken_quality=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_PositionID;
	int64_t m_awaken_quality;
	bool operator==(const XingchenXcawakenPositionidAwaken_quality& data) const
	{
		 return m_PositionID==data.m_PositionID && m_awaken_quality==data.m_awaken_quality;
	}
};

namespace std
{
	template<>
	struct hash<XingchenXcawakenPositionidAwaken_quality>
	{
		size_t operator()(const XingchenXcawakenPositionidAwaken_quality& data) const
		{
			return NFHash::hash_combine(data.m_PositionID,data.m_awaken_quality);
		}
	};
}


class XingchenXcawakenDesc : public NFIDescTemplate<XingchenXcawakenDesc, proto_ff_s::E_XingchenXcawaken_s, EOT_CONST_XINGCHEN_XCAWAKEN_DESC_ID, MAX_XINGCHEN_XCAWAKEN_NUM>
{
public:
	XingchenXcawakenDesc();
	virtual ~XingchenXcawakenDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	const proto_ff_s::E_XingchenXcawaken_s* GetDescByPositionidAwaken_quality(int64_t Positionid, int64_t Awaken_quality);
private:
	NFShmHashMap<XingchenXcawakenPositionidAwaken_quality ,uint64_t, UNIQUE_KEY_MAX_COM_INDEX_XINGCHEN_XCAWAKEN_POSITIONID_NUM*UNIQUE_KEY_MAX_COM_INDEX_XINGCHEN_XCAWAKEN_AWAKEN_QUALITY_NUM> m_PositionidAwaken_qualityComIndexMap;
};
