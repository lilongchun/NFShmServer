// -------------------------------------------------------------------------
//    @FileName         :    NFSnsTransSaveDetailDB.h
//    @Author           :    gaoyi
//    @Date             :    23-7-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsTransSaveDetailDB
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFTransBase.h"


class NFPlayerDetail;
class NFSnsTransSaveDetailDB : public NFTransBase {
public:
    NFSnsTransSaveDetailDB();

    virtual ~NFSnsTransSaveDetailDB();

    int CreateInit();

    int ResumeInit();

    virtual int HandleTransFinished(int iRunLogicRetCode);
public:
    int SaveDB(NFPlayerDetail* pPlayer);
private:
    uint32_t m_curSeq;
    uint32_t m_cid;
DECLARE_IDCREATE(NFSnsTransSaveDetailDB)
};