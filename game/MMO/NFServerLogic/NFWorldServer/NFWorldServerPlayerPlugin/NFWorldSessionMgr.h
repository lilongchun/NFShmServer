// -------------------------------------------------------------------------
//    @FileName         :    NFWorldSessionMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldSessionMgr
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFWorldSession;
class NFWorldSessionMgr : public NFShmObjTemplate<NFWorldSessionMgr, EOT_WORLD_SESSION_MGR_ID, NFShmObj>
{
public:
    NFWorldSessionMgr();

    virtual ~NFWorldSessionMgr();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnTimer(int timeId, int callcount);
    int Tick();
public:
    /**
     * @brief 通过clientId获取Seesion数据
     * @param clientId
     * @return
     */
    NFWorldSession *GetSession(uint64_t clientId);

    /**
     * @brief 通过clientId创建Session数据, 如果玩家存在，返回NULL
     * @param ClientId
     * @return
     */
    NFWorldSession *CreateSession(uint64_t clientId);

    /**
     * @brief 删除Session数据
     * @param pSession
     * @return
     */
    int DeleteSession(NFWorldSession *pSession);

    int DeleteSession(uint64_t ClientId);
};