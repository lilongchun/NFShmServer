// -------------------------------------------------------------------------
//    @FileName         :    NFShmObj.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFDynamicHead.h"
#include "NFShmObj.h"
#include "NFShmMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"

NFShmObj::NFShmObj() : NFObject(NFShmMgr::Instance()->m_pTempPluginManager)
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}


NFShmObj::~NFShmObj()
{
    if (m_iObjType > EOT_TYPE_EVENT_MGR)
    {
        UnSubscribeAll();
        DeleteAllTimer();
    }

#ifdef NF_DEBUG_MODE
    CheckMemMagicNum();

    //m_iMagicCheckNum = 0;
    if (m_iGlobalId != INVALID_ID)
    {
        //有globalid的对象删除没有使用CIDRuntimeClass::DestroyObj会发生这种问题，这是不允许的
        NFShmObj *pObj = FindModule<NFISharedMemModule>()->GetObjByGlobalIdWithNoCheck(m_iGlobalId);
        assert(pObj == NULL);
    }
#endif
    m_iGlobalId = INVALID_ID;
    m_iObjSeq = INVALID_ID;
    m_iObjId = INVALID_ID;
    m_iHashKey = INVALID_ID;
    m_iObjType = INVALID_ID;
}

int NFShmObj::CreateInit()
{
#if NF_DEBUG_MODE
    m_iMagicCheckNum = OBJECT_MAGIC_CHECK_NUMBER;
#endif

    m_iObjId = INVALID_ID;
    m_iGlobalId = INVALID_ID;
    m_iObjType = NFShmMgr::Instance()->m_iType;
    if (m_iObjId == INVALID_ID)
    {
        m_iObjId = FindModule<NFISharedMemModule>()->GetObjId(m_iObjType, this);
        NF_ASSERT(m_iObjId != INVALID_ID);
    }

    int iID = FindModule<NFISharedMemModule>()->GetGlobalId(m_iObjType, m_iObjId, this);
    if (iID >= 0)
    {
        m_iGlobalId = iID;
    }

    m_iHashKey = INVALID_ID;
    m_iObjSeq = FindModule<NFISharedMemModule>()->IncreaseObjSeqNum();

    m_bIsInRecycle = false;

    return 0;
}

std::string NFShmObj::GetClassName() const
{
    return FindModule<NFISharedMemModule>()->GetClassName(GetClassType());
}

int NFShmObj::GetItemCount() const
{
    return FindModule<NFISharedMemModule>()->GetItemCount(GetClassType());
}
int NFShmObj::GetUsedCount() const
{
    return FindModule<NFISharedMemModule>()->GetUsedCount(GetClassType());
}
int NFShmObj::GetFreeCount() const
{
    return FindModule<NFISharedMemModule>()->GetFreeCount(GetClassType());
}

int NFShmObj::OnTimer(int timeId, int callcount)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "shm obj type:{} no handle timer:{}", GetClassType(), timeId);
    return 0;
}

int NFShmObj::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "event not handle, shmobjType:{} serverType:{} nEventID:{} bySrcType:{} nSrcID:{}, message:{}", GetClassType(),
               serverType, nEventID, bySrcType, nSrcID, pMessage->DebugString());
    return 0;
}

//发送执行事件
int NFShmObj::FireExecute(uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message)
{
    int retCode = m_pObjPluginManager->FindModule<NFISharedMemModule>()->FireExecute(nServerType, nEventID, bySrcType, nSrcID, message);
    if (retCode != 0)
    {
        return retCode;
    }

    m_pObjPluginManager->FindModule<NFIEventModule>()->FireExecute(nServerType, nEventID, bySrcType, nSrcID, message);
    return retCode;
}

int NFShmObj::FireBroadcast(uint32_t nServerType, uint32_t nRecvServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message, bool self/* = false*/)
{
    m_pObjPluginManager->FindModule<NFIMessageModule>()->BroadcastEventToServer((NF_SERVER_TYPES)nServerType, (NF_SERVER_TYPES)nRecvServerType, nEventID, bySrcType, nSrcID, message);
    if (self)
    {
        FireExecute(nServerType, nEventID, bySrcType, nSrcID, message);
    }
    return 0;
}

int NFShmObj::FireBroadcast(uint32_t nServerType, uint32_t nRecvServerType, uint32_t busId, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message, bool self/* = false*/)
{
    m_pObjPluginManager->FindModule<NFIMessageModule>()->BroadcastEventToServer((NF_SERVER_TYPES)nServerType, (NF_SERVER_TYPES)nRecvServerType, busId, nEventID, bySrcType, nSrcID, message);
    if (self)
    {
        FireExecute(nServerType, nEventID, bySrcType, nSrcID, message);
    }
    return 0;
}

int NFShmObj::FireBroadcast(uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message, bool self/* = false*/)
{
    m_pObjPluginManager->FindModule<NFIMessageModule>()->BroadcastEventToServer((NF_SERVER_TYPES)nServerType, nEventID, bySrcType, nSrcID, message);
    if (self)
    {
        FireExecute(nServerType, nEventID, bySrcType, nSrcID, message);
    }
    return 0;
}

//订阅执行事件
int NFShmObj::Subscribe(uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string &desc)
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->Subscribe(this, nServerType, nEventID, bySrcType, nSrcID, desc);
}

//取消订阅执行事件
int NFShmObj::UnSubscribe(uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID)
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->UnSubscribe(this, nServerType, nEventID, bySrcType, nSrcID);
}

//取消所有执行事件的订阅
int NFShmObj::UnSubscribeAll()
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->UnSubscribeAll(this);
}

int NFShmObj::DeleteAllTimer()
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->DeleteAllTimer(this);
}

int NFShmObj::DeleteAllTimer(NFRawShmObj* pRawShmObj)
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->DeleteAllTimer(this, pRawShmObj);
}

int NFShmObj::DeleteTimer(int timeObjId)
{
    return FindModule<NFISharedMemModule>()->DeleteTimer(this, timeObjId);
}

//注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
int NFShmObj::SetTimer(int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj)
{
    return FindModule<NFISharedMemModule>()->SetTimer(this, hour, minutes, second, microSec, pRawShmObj);
}

//注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
int NFShmObj::SetCalender(int hour, int minutes, int second, NFRawShmObj* pRawShmObj)
{
    return FindModule<NFISharedMemModule>()->SetCalender(this, hour, minutes, second, pRawShmObj);
}

//注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
int NFShmObj::SetCalender(uint64_t timestamp, NFRawShmObj* pRawShmObj)
{
    return FindModule<NFISharedMemModule>()->SetCalender(this, timestamp, pRawShmObj);
}

//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
int NFShmObj::SetTimer(int interval, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj)
{
    return FindModule<NFISharedMemModule>()->SetTimer(this, interval, callcount, hour, minutes, second, microSec, pRawShmObj);
}

//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
int NFShmObj::SetDayTime(int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj)
{
    return FindModule<NFISharedMemModule>()->SetDayTime(this, callcount, hour, minutes, second, microSec, pRawShmObj);
}

//注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
int NFShmObj::SetDayCalender(int callcount, int hour, int minutes, int second, NFRawShmObj* pRawShmObj)
{
    return FindModule<NFISharedMemModule>()->SetDayCalender(this, callcount, hour, minutes, second, pRawShmObj);
}

//周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
int NFShmObj::SetWeekTime(int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj)
{
    return FindModule<NFISharedMemModule>()->SetWeekTime(this, callcount, hour, minutes, second, microSec, pRawShmObj);
}

//注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
int NFShmObj::SetWeekCalender(int callcount, int weekDay, int hour, int minutes, int second, NFRawShmObj* pRawShmObj)
{
    return FindModule<NFISharedMemModule>()->SetWeekCalender(this, callcount, weekDay, hour, minutes, second, pRawShmObj);
}

//月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
int NFShmObj::SetMonthTime(int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj)
{
    return FindModule<NFISharedMemModule>()->SetMonthTime(this, callcount, hour, minutes, second, microSec, pRawShmObj);
}

//注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
int NFShmObj::SetMonthCalender(int callcount, int day, int hour, int minutes, int second, NFRawShmObj* pRawShmObj)
{
    return FindModule<NFISharedMemModule>()->SetMonthCalender(this, callcount, day, hour, minutes, second, pRawShmObj);
}