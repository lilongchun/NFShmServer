// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleRimple.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleRimple
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/NFLogicShmTypeDefines.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "storesvr_sqldata.pb.h"

class NFTransGetPlayerSimple : public NFShmObjTemplate<NFTransGetPlayerSimple, EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID, NFTransBase>
{
public:
	NFTransGetPlayerSimple();

	virtual ~NFTransGetPlayerSimple();

	int CreateInit();

	int ResumeInit();
public:
	int QueryRole(uint64_t playerId);

	int OnTransFinished(int iRunLogicRetCode);
private:
	uint64_t m_playerId;
};
