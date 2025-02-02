// -------------------------------------------------------------------------
//    @FileName         :    NFTransMng.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransMng.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFTickByRunIndexOP.h"
//#define MAX_TOTAL_TRANS_NUM 500000
#define MAX_TOTAL_TRANS_NUM 10000

class NFTransBase;
class NFTransMng : public NFShmObjTemplate<NFTransMng, EOT_TRANS_MNG, NFShmObj>, public NFTickByRunIndexOP
{
public:
    NFTransMng();
    virtual ~NFTransMng();

    int CreateInit();
    int ResumeInit();

    NFTransBase* CreateTrans(uint32_t bTransObjType);
    NFTransBase* GetTransBase(uint64_t ullTransID);

    virtual int CheckAllTransFinished(bool &bAllTransFinished);
    virtual int DoTick(uint32_t dwCurRunIndex, bool bIsTickAll = false);

    int RebuildTransObjPointerListForResume();

    int GetTotalTransNum() const { return m_iTotalTransNum; }
protected:
    virtual NFTransBase* CreateTrans_i(uint32_t bTransObjType);
    void InnerRebuildList();
protected:
    int m_iTotalTransNum;
    int m_aiTransObjIDList[MAX_TOTAL_TRANS_NUM];
    NFTransBase* m_apTransObjList[MAX_TOTAL_TRANS_NUM];
};


