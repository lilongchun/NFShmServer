// -------------------------------------------------------------------------
//    @FileName         :    NFShmTimerManager.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmTimerManager.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFShmTimer.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmCore/NFShmNodeList.h"
#include <list>

#define SLOT_COUNT 600
#define SLOT_TICK_TIME 32
//#define ALL_TIMER_COUNT 300000
#define ALL_TIMER_COUNT 30000
#define CUR_SLOT_TICK_MAX 500

struct STimerIDData
{
    int preIndex;
    int nextIndex;
    int curIndex;
    int objID;            // timer的objectid
    int slotID;            // slot的m_index
    bool isValid;        // 是否非法，做简单判断用
};

class NFShmTimerManager;
class Slot
{
public:
    int CreateInit();
    
    int ResumeInit();
    
    void SetIndex(int i) { m_index = i; }
    
    int AddTimer(NFShmTimer *timer, STimerIDData *idData, STimerIDData *allIDData);
    
    bool OnTick(NFShmTimerManager *pTimerManager, int64_t tick, std::list<NFShmTimer *> &timeoutList, uint32_t seq, STimerIDData *allIDData);
    
    bool DeleteTimer(NFShmTimerManager *pTimerManager, NFShmTimer *timer, STimerIDData *allIDData);
    
    STimerIDData *UnBindListTimer(NFShmTimerManager *pTimerManager, NFShmTimer *timer, STimerIDData *tmpData, STimerIDData *allIDData);
    
    void ClearRunStatus(uint32_t seq);
    
    int GetCount() { return m_count; }

private:

//	map<uint32_t, Timer* > m_mapTimer;
//	TIMER_SLOT_LIST m_mapTimer;
    STimerIDData m_headData;
    int m_index;
    uint32_t m_slotSeq;        // 每次tick的seq
    int m_curRunIndex;    // 当前运行到的链表的序号
    int m_count;            // 定时器的个数
};

class NFShmTimerManager : public NFShmObjTemplate<NFShmTimerManager, EOT_TYPE_TIMER_MNG, NFShmObj>
{
public:
    NFShmTimerManager();
    
    ~NFShmTimerManager();
    
    int CreateInit();
    
    int ResumeInit();
    
    void OnTick(int64_t tick);
    
    // 删除此定时器
    int Delete(int objectId);
    
    NFShmTimer *GetTimer(int objectId);
    
    void ReleaseTimerIDData(int index);
    
    //注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
    int SetTimer(NFShmObj *pObj, int hour, int minutes, int second, int microSec, NFRawShmObj *pRawShmObj = NULL);
    
    //注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
    int SetCalender(NFShmObj *pObj, int hour, int minutes, int second, NFRawShmObj *pRawShmObj = NULL);
    
    //注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
    int SetCalender(NFShmObj *pObj, uint64_t timestamp, NFRawShmObj *pRawShmObj = NULL);
    
    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
    int SetTimer(NFShmObj *pObj, int interval, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj *pRawShmObj = NULL);
    
    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    int SetDayTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj *pRawShmObj = NULL);
    
    //注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
    int SetDayCalender(NFShmObj *pObj, int callcount, int hour, int minutes, int second, NFRawShmObj *pRawShmObj = NULL);
    
    //周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    int SetWeekTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj *pRawShmObj = NULL);
    
    //注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
    int SetWeekCalender(NFShmObj *pObj, int callcount, int weekDay, int hour, int minutes, int second, NFRawShmObj *pRawShmObj = NULL);
    
    //月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
    int SetMonthTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj *pRawShmObj = NULL);
    
    //注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
    int SetMonthCalender(NFShmObj *pObj, int callcount, int day, int hour, int minutes, int second, NFRawShmObj *pRawShmObj = NULL);
public:
    int AddShmObjTimer(NFShmObj *pObj, NFShmTimer *pTimer);
    int ClearShmObjTimer(NFShmTimer *pTimer);
    int ClearAllTimer(NFShmObj *pObj);
    int ClearAllTimer(NFShmObj *pObj, NFRawShmObj *pRawShmObj);
private:
    bool AttachTimer(NFShmTimer *timer, int64_t tick, bool isNewTimer);
    
    int AddTimer(NFShmTimer *timer, int64_t tick, bool isNewTimer = true);
    
    int AddTimer(NFShmTimer *timer, int slot);
    
    bool SetDistanceTime(NFShmTimer *stime, int hour, int minutes, int second, int microSec, int interval = 0, int callCount = 1);
    
    bool SetDayTime(NFShmTimer *stime, int hour, int minutes, int second, int interval = 0, int callCount = 1);
    
    bool SetDayTime(NFShmTimer *stime, uint64_t timestamp, int interval = 0, int callCount = 1);
    
    bool SetWeekTime(NFShmTimer *stime, int weekDay, int hour, int minutes, int second, int callCount = 1);
    
    bool SetMonthTime(NFShmTimer *stime, int day, int hour, int minutes, int second, int callCount = 1);
    
    // 获取空闲的链表结构
    STimerIDData *GetFreeTimerIDData();
    
    bool CheckFull();

private:
    
    Slot m_slots[SLOT_COUNT];
    uint32_t m_currSlot;
    int64_t m_beforeTick; //上一次执行的tick数
    
    STimerIDData m_timerIDData[ALL_TIMER_COUNT + 1];
    int m_iFreeIndex;
    uint32_t m_timerSeq;                    // 每次tick的seq,只有当前m_currSlot已经遍历完了，才会++
    
    NFShmHashMap<int, NFShmNodeObjList<NFShmTimer>, ALL_TIMER_COUNT> m_shmObjTimer;
};
