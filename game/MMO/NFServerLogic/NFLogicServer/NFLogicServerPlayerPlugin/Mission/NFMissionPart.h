// -------------------------------------------------------------------------
//    @FileName         :    NFMissionPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMissionPart
//
// -------------------------------------------------------------------------

#pragma once

#include "DescStoreEx/TaskDescEx.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFMissionDefine.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFEventDefine.h"

#define PLAYER_TRACK_MISSION_MAX_MISSION_COUNT MISSION_MAX_ACCEPT_NUM * 2

class NFMissionPart : public NFShmObjTemplate<NFMissionPart, EOT_LOGIC_PART_ID + PART_MISSION, NFPart> {
public:
    // eventtype - level - dynamicid
    typedef NFShmHashMap<uint32_t, NFShmHashMap<int32_t, NFShmHashSet<uint64_t, PLAYER_TRACK_MISSION_MAX_MISSION_COUNT>, PLAYER_TRACK_MISSION_MAX_MISSION_COUNT>, 10> EventTabal;
    
    typedef NFShmHashMap<uint64_t, MissionTrack, PLAYER_TRACK_MISSION_MAX_MISSION_COUNT> PlayerTrackMissionMap;
    typedef NFShmHashMap<int32_t, DyMissionTrack, NF_MISSION_TYPE_MAX_COUNT> PlayerDyMissionTrackMap;
public:
    NFMissionPart();
    
    virtual ~NFMissionPart();
    
    int CreateInit();
    
    int ResumeInit();

public:
public:
    //******************part调用接口******************
    /**
     * @brief 初始化part
     * @param pMaster
     * @param partType
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);
    
    /**
     * @brief 释放part资源
     * @return
     */
    virtual int UnInit();
    
    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage);

public:
    /**
     * @brief 从数据库中加载数据
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBData &data);
    
    /**
     * @brief 从配置中初始化数据
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBData &data) { return 0; }
    
    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBData &dbData);
    
    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin();
    
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo) { return 0; }
    
    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout() { return 0; }
    
    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect() { return 0; }
    
    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect() { return 0; }
    
    ////////////////////////////////// 每日零点 每周一零点 刷新接口
    //////////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int DailyZeroUpdate();
    
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int WeekZeroUpdate();
    
    /**
     * @brief 每月刷新接口
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; };
    
    /**
     * 设置外观信息
     * @param outproto
     */
    virtual int FillFacadeProto(proto_ff::RoleFacadeProto &outproto) { return 0; }

public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }

public:
    /**
     * @brief 注册要处理的消息
     * @return
     */
    virtual int RegisterMessage();

public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet);

public:
    /**
     * @brief 检查主线任务
     * @param notify
     */
    void CheckTrunkMission(bool notify = true);
    
    /**
     * \brief 检查等级任务接取
     * \param notify
     */
    void CheckLevMission(bool notify = true);
    
    /**
     * \brief 检查工会任务
     * \param notify
     */
    void CheckGuildMission(bool notify = false);
    
    /**
     * \brief 检查任务重置
     * \param notify
     */
    void CheckMissionFresh(bool notify = false);
    
    /**
     * \brief 检查功能开放
     * \param functionid
     * \param notify
     */
    void CheckFunctionMisssion(uint64_t functionid, bool notify = true);

public:
    /**
     * @brief NPC接取任务
     * @param msgId
     * @param packet
     */
    int HandleNpcAcceptMission(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 提交任务
     * @param msgId
     * @param packet
     */
    int HandleSubmitMission(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief NPC对话,寻人接口
     * @param msgId
     * @param packet
     */
    int HandleTalkWithNpc(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 提交任务物品
     * @param msgId
     * @param packet
     */
    int HandleSubmitMissionGoods(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 一键完成任务
     * @param msgId
     * @param packet
     */
    int HandleOnekeyFinishMission(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 立即完成
     * @param msgId
     * @param packet
     */
    int HandleOnceFinishMission(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 领取特殊奖励
     * @param msgId
     * @param packet
     */
    int HandleMissionRecvSpecialReward(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 推送任务列表信息
     * @param msgId
     * @param packet
     */
    int SendMissionList(uint32_t msgId, NFDataPackage &packet);
    
    void SendMissionInfo();

public:
    /**
     * @brief 接取任务
     * @param missionId
     * @param notify
     * @return
     */
    int32_t AcceptMission(uint64_t missionId, bool notify);
    
    /**
     * @brief GM 接取任务
     * @param missionId
     * @param notify
     * @return
     */
    int32_t GMAcceptMission(uint64_t missionId, bool notify);
    
    /** 接取任务
     * @brief
     * @param missionId
     * @param kind
     */
    void OnAccept(uint64_t missionId, uint32_t kind);
    
    /**
     * @brief 获取可接任务列表(主支线)
     * @param missionId
     * @return
     */
    int32_t CanAccept(uint64_t missionId);
    
    /**
     * @brief 获取可接任务列表(主支线)
     * @param missionId
     * @return
     */
    int32_t CanAccept(MissionInfo *pMissionInfo);
    
    /**
     * @brief 是否匹配接取任务的条件
     * @param cond
     * @return
     */
    int32_t CanAccept(const AcceptInfo &cond);
    
    /**
     * @brief 该任务是否已经接收过了
     * @param missionId
     * @return
     */
    bool HaveAccept(uint64_t missionId);
    
    
    /**
     * \brief 通过任务类型接取任务
     * \param missionType
     * \param notify
     * \return
     */
    int32_t AcceptMissionByType(int32_t missionType, bool notify);

public:
    /**
     * @brief 接取动态任务
     * @param missionId
     * @param notify
     * @return
     */
    int32_t AcceptDyMission(uint64_t missionId, bool notify);
    
    /**
     * \brief 接取动态任务
     * \param missionId
     * \param track
     * \param notify
     * \return
     */
    int32_t AcceptDyMission(uint64_t missionId, proto_ff::CMissionTrack &track, bool notify);
    
    /**
     * @brief 接取任务(动态任务)
     * @param dymissionId
     * @param missionType
     */
    void OnAcceptDy(uint64_t dymissionId, int32_t missionType);
    
    /**
     * @brief 是否能接取动态任务 dyCfgId:动态任务的配置ID
     * @param dyCfgId
     * @return
     */
    int32_t CanAcceptDy(uint64_t dyCfgId);
    
    /**
     * @brief
     * @param pDyMissionInfo
     * @return
     */
    int32_t CanAcceptDy(const DyMissionInfo *pDyMissionInfo);
    
    /**
     * @brief 添加动态任务接取次数
     * @param missionType
     * @param count
     */
    void OnAddAcceptDyCount(int32_t missionType, uint32_t count);
    
    /**
     * @brief 根据任务类型获取动态任务已经接取次数
     * @param missionType
     * @return
     */
    uint32_t GetDyMissionAceeptCnt(int32_t missionType);

public:
    /**
     * @brief 通过任务类型接取动态任务
     * @param missionType
     * @param notify
     * @return
     */
    int32_t AcceptDyMissionByType(int32_t missionType, bool notify);
    
    /**
     * \brief 通过任务类型接取动态任务
     * \param missionType
     * \param missionId
     * \param missionProto
     * \param notify
     * \return
     */
    int32_t AcceptDyMissionByType(int32_t missionType, uint64_t missionId, proto_ff::CMissionTrack &missionProto, bool notify);
    
    
    /**
     * @brief 能否通过任务类型接取任务
     * @param missionType
     * @return
     */
    int32_t CanAcceptDyMissionByType(int32_t missionType);
    
    /**
     * @brief 通过任务类型清除任务,返回清除的任务数量
     * notify：是否需要通知客户端删除任务
     * @param missionType
     * @param notify
     * @return
     */
    int32_t ClearMissionByType(int32_t missionType, bool notify);
    
    /**
     * @brief 获取任务最大环数
     * @param missionType
     * @param level
     * @return
     */
    int32_t DyMaxCount(int32_t missionType, int32_t level);

public:
    /**
     * @brief 完成诺林冒险
     * @param count
     */
    void OnFinishLoopMission(int32_t count);
    
    /**
     * @brief 判断某个任务是否完成了
     * @param missionId
     * @return
     */
    bool HaveFinish(uint64_t missionId);
    
    /**
     * @brief 判断某个任务是否已接取并且没完成
     * @param missionId
     * @return
     */
    bool HaveNoFinish(uint64_t missionId);
    
    /**
     * @brief 完成任务(动态任务)
     * @param dymissionId
     * @param dymissionType
     */
    void OnFinishDy(uint64_t missionId, uint64_t dymissionId, uint32_t dymissionType);
    
    /**
     * @brief 完成任务
     * @param missionId
     * @param kind
     */
    void OnFinish(uint64_t missionId, uint32_t kind);
    
    /**
     * @brief 完成任务后，对特殊条件，进行处理
     * @param missionId
     * @param kind
     */
    void OnFinishCondProcess(const ItemInfo &cond);

public:
    /**
     * @brief 根据任务类型获取动态任务记录信息
     * @param missionType
     * @return
     */
    DyMissionTrack *GetDyMissionTrack(int32_t missionType);
    
    /**
     * @brief 动态任务奖励
     * @param missionType
     * @param missionId
     * @param missionReward
     * @return
     */
    int32_t OnAddDyMissionReward(int32_t missionType, uint64_t missionId, SMissionReward &missionReward);
    
    /**
     * @brief 更新动态任务接取次数
     * @param setMissionType
     */
    void NotifyDyAcceptCount(SET_UINT32 &setMissionType);
    
    /**
     * @brief 是否是有效的动态任务ID
     * @param dyMissionId
     * @return
     */
    bool ValidDyMissionId(uint64_t dyMissionId);
    
    /**
     * @brief 分配一个动态任务ID
     * @return
     */
    uint64_t AllocNewDyMisssionId();
    
    /**
     * @brief 回收一个动态任务ID
     * @param dyMissionId
     */
    void FreeDyMissionId(uint64_t dyMissionId);
    
    /**
     * @brief 根据任务类型随机一个任务ID
     * @param missionType
     * @return
     */
    uint64_t DyRandMissionId(int32_t missionType);

public:
    /** 最近提交列表里面是否有指定类型的任务
     * @brief
     * @param missionType
     * @return
     */
    bool HaveRecentSubmit(int32_t missionType);
    
    /**
     * @brief  根据任务类型获取当前任务列表中存在的数量
     * @param missionType
     * @return
     */
    int32_t MissionNumByType(int32_t missionType);
    
    
    /**
     * @brief 是否已经提交过的任务
     * @param missionId
     * @return
     */
    bool HaveSubmited(uint64_t missionId);
    
    /**
     * @brief 是否已经提交过的任务
     * @param missionId
     * @return
     */
    bool HaveSubmitedByType(int32_t missionType);
    
    /**
     * @brief 清理提交
     * @param missionType
     * @return
     */
    bool ClearSubmitedByType(int32_t missionType);

public:
    /**
     * @brief 提取任务条件
     * @param pMissionInfo
     * @param pMissionTrack
     * @return
     */
    int32_t OnExtractCond(MissionInfo *pMissionInfo, MissionTrack *pMissionTrack);
    
    /**
     * @brief 条件预判断(有些条件接取任务时就已经完成了)
     * @param cond
     */
    void OnPreUpdateProgress(ItemInfo &cond);
    
    /**
     * @brief 更新条件进度
     * @param data
     * @param cond
     * @param notify
     */
    void OnUpdateCondProcess(const ExecuteData &data, ItemInfo &cond,
                             bool &notify);
    
    /**
     * @brief 提取动态任务条件
     * @param pMissionInfo
     * @param pMissionTrack
     * @param preUpdate
     * @return
     */
    int32_t OnExtractDyCond(const DyMissionInfo *pMissionInfo, MissionTrack *pMissionTrack, bool preUpdate = true);
    
    /**
     * @brief 生成任务条件
     * @param pDyMissionInfo
     * @param pDyConditionInfo
     * @param cond
     * @param textId
     * @return
     */
    int32_t OnGeneralCond(const DyMissionInfo *pDyMissionInfo,
                          const DyConditionInfo *pDyConditionInfo, ItemInfo &cond,
                          uint64_t &textId);
    
    /**
     * @brief 提取动态任务属性奖励
     * @param pNewMissinTrack
     * @return
     */
    int32_t OnExtractDyAttrReward(MissionTrack *pNewMissinTrack);

public:
    /**
     * @brief 增加发任务时的物品奖励
     * @param pMissionTrack
     * @return
     */
    int32_t AddReward(uint64_t missionId, int32_t kind, const TASK_REWARD &reward, float ration = 1);
    
    /**
     * @brief 是否能增加任务奖励
     * @param pPlayer
     * @param reward
     * @param param
     * @param lstOutItem
     * @return
     */
    bool CanAddReward(uint64_t missionId, int32_t kind, const TASK_REWARD &reward, LIST_ITEM &lstOutItem);

public:
    /**
     * @brief 移除任务
     * @param pMissionInfo
     * @return
     */
    int32_t RemoveMission(MissionInfo *pMissionInfo);
    
    /**
     * @brief 移除任务
     * @param pMissinTrack
     * @param pMissionInfo
     * @return
     */
    int32_t RemoveMission(MissionTrack *pMissinTrack, MissionInfo *pMissionInfo);
    
    /**
     * @brief 移除动态任务
     * @param dymissionId
     * @param notify
     * @return
     */
    int32_t RemoveDyMission(uint64_t dymissionId, bool notify);

public:
    /**
     * @brief 更新进度
     * @param missionId
     * @param data
     * @return
     */
    int32_t OnUpdateProgress(uint64_t missionId, const ExecuteData &data);
    
    /**
     * @brief 更新任务进度
     * @param missionId
     */
    void UpdateMissionProgress(uint64_t missionId);
    
    /** 删除任务
     * @brief
     * @param dymissionId
     */
    void NotifyDelMission(uint64_t dymissionId);
    
    /**
     * @brief 移除任务物品
     * @param pMissionTrack
     * @return
     */
    int32_t OnDelMissionItem(MissionTrack *pMissionTrack);

public:
    /**
     * @brief 添加任务掉落
     * @param pMissionTrack
     * @param progressLev
     * @return
     */
    int32_t OnAddMissionDrop(MissionTrack *pMissionTrack, int32_t progressLev);
    
    /**
     * @brief 添加任务掉落
     * @param dymissionId
     * @param monsId
     * @param dropId
     * @param boxId
     * @param progressLev
     * @return
     */
    bool AddMissionDrop(uint64_t dymissionId, uint64_t monsId, uint64_t dropId, uint64_t boxId, int32_t progressLev);
    
    /**
     * @brief 删除任务掉落
     * @param dymissionId
     * @param monsId
     * @return
     */
    bool DelMissionDrop(uint64_t dymissionId, uint64_t monsId);
    
    /**
     * @brief 获取任务掉落
     * @param monsterId
     * @return
     */
    MissionDropMap *GetMissionDrop(uint64_t monsterId);
    
    /**
     * @brief 移除任务掉落
     * @param pMissionTrack
     * @return
     */
    int32_t OnDelMissionDrop(MissionTrack *pMissionTrack);

public:
    /**
     * @brief 移除任务中间物品
     * @param pMissionTrack
     */
    int RemoveReward(MissionTrack *pMissionTrack);
    
    /**
     * @brief 移除接取任务时发放的物品
     * @param pPlayer
     * @param missionId
     * @param reward
     * @return
     */
    int RemoveReward(uint64_t missionId, TASK_REWARD &reward);

public: // 任务事件处理接口
    /**
     * @brief 注册监听事件，接任务成功后注册
     * @param eventType
     * @param missionId
     * @param progressLev
     */
    void RegisterEvent(uint32_t eventType, uint64_t missionId,
                       int32_t progressLev);
    
    /**
     * @brief 移除这个任务注册的所有事件
     * @param missionId
     */
    void RemoveEvent(uint64_t missionId);
    
    /**
     * @brief 发送任务事件，阻塞
     * @param eventType
     * @param data
     * @param dynamicId
     */
    void OnEvent(uint32_t eventType, const ExecuteData &data,
                 uint64_t dynamicId = 0);

public:
    /**
     * @brief 提交任务
     * @param pPlayer
     * @param missionId
     * @param selidx
     * @return
     */
    int32_t SubmitMission(uint64_t missionId, uint32_t selidx);
    
    /**
     * @brief 提交任务
     * @param missionId
     * @param premissionId
     * @param kind
     */
    void OnSubmit(uint64_t missionId, uint64_t premissionId, uint32_t kind);
    
    /**
     * @brief 检查接取条件中前置任务完成之后的可接任务
     * @param missionId
     * @param notify
     */
    void CheckPreAcceptMission(uint64_t missionId, bool notify = true);

public:
    /**
     * @brief 提交动态任务
     * @param dymissionId
     * @return
     */
    int32_t SubmitDyMission(uint64_t dymissionId);
    
    /**
     * @brief 提交任务(动态任务)
     * @param dymissionId
     * @param missionType
     */
    void OnSubmitDy(uint64_t dymissionId, int32_t missionType);

public:
    MissionTrack *AllocMissionTrack(uint64_t missionId);
    
    MissionTrack *GetMissionTrack(uint64_t missionId);
    
    MissionTrack *GetMissionTrackByType(uint32_t missionType);

public:
    //游戏通用事件处理接口
    int OnDie();
    
    //角色升级
    int OnLevelUp();
    
    int OnPassDuplicate(const google::protobuf::Message *pMessage);
    
    int OnItemChange(const google::protobuf::Message *pMessage);
    
    int OnArenaJoin(const google::protobuf::Message *pMessage);
    
    int OnAddFriend();
    
    int OnSlotStren(const google::protobuf::Message *pMessage);
    
    int OnEblemInaly(const google::protobuf::Message *pMessage);
    
    int OnAptitude(const google::protobuf::Message *pMessage);
    
    int OnStoneInlay(const google::protobuf::Message *pMessage);
    
    int OnGuildChange(const google::protobuf::Message *pMessage);
    
    int OnConvoyCommit(const google::protobuf::Message *pMessage);
    
    //翅膀升级
    int OnWingLevup(const google::protobuf::Message *pMessage);
    
    //宝具升级
    int OnTreasureLevup(const google::protobuf::Message *pMessage);
    
    //契灵升级
    int OnPartnerLevup(const google::protobuf::Message *pMessage);
    
    //点亮龙魂
    int OnLightSoul(const google::protobuf::Message *pMessage);
    
    //
    int OnCollectEvent(const google::protobuf::Message *pMessage);
    
    //
    int OnEquipDress(const google::protobuf::Message *pMessage);
    
    //
    int OnEquipUnDress(const google::protobuf::Message *pMessage);
    
    //加入团队
    int OnJoinClan(const google::protobuf::Message *pMessage);
    
    //
    int OnGodRelicTaskGroup(const google::protobuf::Message *pMessage);

public:
    void OnAreaFreshMonster(uint64_t dymissionId, bool checkArea = true);
    
    void OnCheckAreaFreshMonster(SET_UINT64 &setDynamic); //检查区域杀怪任务
public:
    /////////////////////////////////////// 外部系统调用的接口  //////////////////////////////////////////////////
    bool AcceptMissionByOccupation(uint64_t missionId); //接取转职任务
    int32_t AcceptMissionByItemUse(int64_t itemId, uint64_t missionId); //使用物品接取任务
public:
    ///////////////////////////////////////GM接口///////////////////////////////////////////////////
    int32_t CheatAcceptMission(uint64_t missionId);
    
    int32_t CheatFastFinishMission(uint64_t beginMissionId, uint64_t endMissionId);
    
    int32_t CheatSubmitMission(uint64_t missionId);
    
    int32_t CheatFastFinishSigleMission(uint64_t missionId, bool notify = true);
    
    int32_t CheatRemoveSingleMissiion(uint64_t missionId, bool notify = true);
    
    int32_t CheatAcceptDyMission(int32_t missionType, bool notify = true);
    
    int32_t CheatFinishDyMission(int32_t missionType, bool notify = true);
    
    int32_t CheatSubmitDyMission(int32_t missionType, bool notify = true);
    
    int32_t CheatRemoveDyMission(int32_t missionType, bool notify = true);

public:
    /**
     * @brief 共享杀怪
     * @param dieEvent
     * @param pos
     */
    void ShareKillMons(DieEvent &dieEvent);
    
    /**
     * @brief 共享杀怪
     * @param dieEvent
     * @param pos
     */
    void KillBoss(DieEvent &dieEvent);
    
    /**
     * @brief 杀怪掉落
     * @param monsId
     * @param monsLev
     * @param pos
     */
    void MissionDropByKillMons(uint64_t monsId, int32_t monsLev);
private:
    PlayerTrackMissionMap m_playerTrackMissionMap;                                                                 //当前任务列表
    NFShmHashMap<int32_t, NFShmHashSet<uint64_t, MAX_TASK_TASK_NUM>, NF_MISSION_TYPE_MAX_COUNT> m_mapRecentSubmit; //最近提交的任务
    NFShmHashSet<uint64_t, NF_MISSION_TYPE_MAX_MISSION_COUNT> m_setAlreadySubmit;                                  //已经提交的任务
    //动态任务
    PlayerDyMissionTrackMap m_mapDyMissionTrack; //动态任务数据
    MissionAllDropMap m_mapMissionAllDrop;       //任务掉落
    //
    EventTabal m_eventTabal;                                         //任务事件表
    NFShmVector<bool, MISSION_MAX_DYNAMIC_ALLOC + 1> m_aryDyIdAlloc; //动态任务ID分配
};
