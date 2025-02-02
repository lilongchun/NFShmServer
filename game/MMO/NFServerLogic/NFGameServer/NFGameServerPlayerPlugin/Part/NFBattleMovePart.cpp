// -------------------------------------------------------------------------
//    @FileName         :    NFMovePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-1
//    @Email			:    445267987@qq.com
//    @Module           :    NFMovePart
//
// -------------------------------------------------------------------------

#include "NFBattleMovePart.h"
#include "ClientServerCmd.pb.h"
#include "Move.pb.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "Creature/NFCreature.h"
#include "NFComm/NFCore/NFTime.h"
#include "Map/NFMap.h"
#include "Map/NFMapMgr.h"
#include "Scene/NFSceneMgr.h"
#include "Scene/NFScene.h"
#include "Scene.pb.h"
#include "DescStore/AreaAreaDesc.h"
#include "Creature/NFBattlePlayer.h"
#include "ClientServer.pb.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "NFGameCommon/NFMath.h"
#include "DescStore/MapMapDesc.h"
#include "DescStoreEx/MapDescEx.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFBattleBuffPart.h"
#include "ServerInternalCmd.pb.h"

NFBattleMovePart::NFBattleMovePart()
{
    m_partType = BATTLE_PART_MOVE;
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFBattleMovePart::~NFBattleMovePart()
{
}

int NFBattleMovePart::CreateInit()
{
    m_lastClientMoveTick = 0;
    m_moveTick = 0;
    m_waitLoadMapId = 0;
    m_timerIdMove = INVALID_ID;
    m_timerIdLoadMapTimeout = INVALID_ID;
    return 0;
}

int NFBattleMovePart::ResumeInit()
{
    return 0;
}

int NFBattleMovePart::Init(const proto_ff::RoleEnterSceneData& data)
{
    return 0;
}

int NFBattleMovePart::UnInit()
{
    return 0;
}

int OnReconnect()
{
    return 0;
}

int NFBattleMovePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_MOVE_REQ:
        {
            ClientMoveReq(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_LOAD_MAP_FINISH:
        {
            ClientLoadMapFinshReq(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_SCENE_TRANS_REQ:
        {
            ClientTransSceneReq(msgId, packet);
            break;
        }
        case proto_ff::MOVE_TELEPORT_REQ:
        {
            ClientTeleportReq(msgId, packet);
            break;
        }
            ////////////////////////////////////冥想数据///////////////////////////////////////
        case proto_ff::CLIENT_TO_LOGIC_PLAYER_SEAT_REQ:
        {
            ClientSeatReq(msgId, packet);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "msgId:{} Not Handle", msgId);
            break;
        }
    }
    return 0;
}

int NFBattleMovePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFBattlePart::OnHandleServerMessage(msgId, packet);
}

int NFBattleMovePart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_MOVE_REQ);
    RegisterClientMessage(proto_ff::CLIENT_LOAD_MAP_FINISH);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_PLAYER_SEAT_REQ);
    RegisterClientMessage(proto_ff::CLIENT_SCENE_TRANS_REQ);
    RegisterClientMessage(proto_ff::MOVE_TELEPORT_REQ);
    return 0;
}

int NFBattleMovePart::ClientMoveReq(uint32_t msgId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::MoveReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    //客户端当前位置
    NFPoint3<float> pos(req.pos().x(), req.pos().y(), req.pos().z());
    //校验客户端坐标
    NFPoint3<float> clientPos = pos;
    
    //客户端一帧的速度
    NFPoint3<float> speed(req.speed().x(), 0.0f, req.speed().y());
    
    //停止的速度,主要用来和客户端速度比较
    NFPoint3<float> zerospeed(0.0f, 0.0f, 0.0f);
    
    //客户端方向
    NFPoint3<float> dir(req.dir().x(), 0.0f, req.dir().y());
    
    //玩家速度
    float fspeed = m_pMaster->GetSpeed();
    
    //玩家当前坐标
    NFPoint3<float> curPos = m_pMaster->GetPos();
    
    //客户端是否停止移动
    bool stopMoveFlag = false;
    //客户端是否是原地跑动
    bool inplaceFlag = false;
    //
    uint64_t mapId = m_pMaster->GetMapId();
    //
    if (zerospeed == speed) //速度为0，表示停止移动
    {
        //停止移动
        stopMoveFlag = true;
    }
    else if (clientPos == m_lastClientPos)
    {
        /* 客户端坐标和最近一次发上来的客户端坐标一样，表示客户端在原地跑动
           这种情况是玩家在阻挡点原地跑动，其他客户端看到这个玩家 也是要原地跑动
        */
        inplaceFlag = true;
    }
    else
    {
        //启动模拟移动定时器
        if (m_timerIdMove == INVALID_ID)
        {
            m_timerIdMove = SetTimer(INTERVAL_MOVE_TIME, 0, 0, 0, 0, 0);
            if (m_timerIdMove != INVALID_ID)
            {
                //设置服务器最近一次移动的时间，定时器初次设置的时候需要设置这个时间
                m_moveTick = NFTime::Now().UnixMSec();
                
                //发送开始移动事件
                proto_ff::NFEventNoneData startEvent;
                FireExecute(NF_ST_GAME_SERVER, EVENT_START_MOVE, m_pMaster->Kind(), m_pMaster->Cid(), startEvent);
            }
            else
            {
                float lenspeed = speed.length();
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                           "SetTimer failed...cid:{}, pos:{},{},{},curPos:{},{},{}, fpeed:{},speed:{},{},{}, lenspeed:{}",
                           m_pMaster->Cid(), pos.x, pos.y, pos.z, curPos.x, curPos.y, curPos.z, fspeed, speed.x, speed.y, speed.z, lenspeed);
                return -1;
            }
        }
    }
    //
    m_lastClientMoveTick = NFTime::Now().UnixMSec();
    m_lastClientPos = clientPos;
    if (!stopMoveFlag) //非停止移动的时候，需要设置客户端速度
    {
        SetClientSpeed(speed);
    }
    else
    {
        //停止移动的时候校验一次坐标
        NFPoint3<float> nearpos = pos;
        NFPoint3<float> rightpos = m_lastRightPos;
        NFMap* pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
        if (nullptr != pMap)
        {
            NFPoint3<float> tempos;
            if (!pMap->FindNearestPos(nearpos.x, nearpos.z, nearpos.y, &tempos.x, &tempos.z, &tempos.y, nullptr))
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                           "[logic] MovePart::ClientMoveReq check move failed,reset pos...cid:{},stopMoveFlag:{},inplaceFlag:{},clientPos:{},{},{}, curpos:{},{},{},mapId:{}, rightpos:{},{},{}  ",
                           m_pMaster->Cid(), stopMoveFlag, inplaceFlag, clientPos.x, clientPos.y, clientPos.z, curPos.x, curPos.y, curPos.z, mapId,
                           rightpos.x, rightpos.y, rightpos.z);
                //客户端当前位置无效，取上一次正确的坐标
                pos = rightpos;
            }
            else
            {
                pos = tempos;
                rightpos = tempos;
                m_lastRightPos = tempos;
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                       "ClientMoveReq check move failed,reset pos...can not find map config,cid:{},stopMoveFlag:{},inplaceFlag:{}, clientPos:{},{},{}, curpos:{},{},{},mapId:{}, clpos:{},{},{}  ",
                       m_pMaster->Cid(), stopMoveFlag, inplaceFlag, clientPos.x, clientPos.y, clientPos.z, curPos.x, curPos.y, curPos.z, mapId,
                       rightpos.x, rightpos.y, rightpos.z);
            pos = rightpos;
        }
    }
    
    //设置坐标
    m_pMaster->SetPos(pos);
    //如果是停止移动，直接取消定时器就行，客户端发送停止移动消息期间，服务器有可能还在模拟移动
    if (stopMoveFlag && m_timerIdMove != INVALID_ID)
    {
        DeleteTimer(m_timerIdMove);
        m_timerIdMove = INVALID_ID;
    }
    
    //设置最近一次的方向
    m_lastDir = dir;
    //设置最近一次客户端发上来的坐标
    m_lastClientPos = clientPos;
    
    BroadcastMove(m_pMaster->Cid(), pos, speed, dir, true);
    //
    if (stopMoveFlag)
    {
        proto_ff::NFEventNoneData stopMoveEvent;
        FireExecute(NF_ST_GAME_SERVER, EVENT_END_MOVE, m_pMaster->Kind(), m_pMaster->Cid(), stopMoveEvent);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

void NFBattleMovePart::SetClientSpeed(const NFPoint3<float>& speed)
{
    m_clientSpeed = speed;
    float len = m_clientSpeed.length();
    if (len > EPS)
    {
        m_clientUnitVector = m_clientSpeed / len;
    }
}

int NFBattleMovePart::BroadcastMove(uint64_t cid, const NFPoint3<float>& pos, const NFPoint3<float>& speed, const NFPoint3<float>& dir,
                                    bool selfFlag/* = false*/)
{
    proto_ff::MoveBroadRsp rsp;
    rsp.set_cid(cid);
    
    proto_ff::Vector3PB* protoPos = rsp.mutable_pos();
    if (nullptr != protoPos)
    {
        protoPos->set_x(pos.x);
        protoPos->set_y(pos.y);
        protoPos->set_z(pos.z);
    }
    
    proto_ff::Vector2PB* protoSpeed = rsp.mutable_speed();
    if (nullptr != protoSpeed)
    {
        protoSpeed->set_x(speed.x);
        protoSpeed->set_y(speed.z);
    }
    
    proto_ff::Vector2PB* protoDir = rsp.mutable_dir();
    if (nullptr != protoDir)
    {
        protoDir->set_x(dir.x);
        protoDir->set_y(dir.z);
    }
    
    return m_pMaster->BroadCast(proto_ff::MOVE_BROAD_RSP, rsp, selfFlag);
}

int NFBattleMovePart::TransScene(uint64_t sceneId, const NFPoint3<float>& dstPos, uint64_t mapId, const proto_ff::SceneTransParam& transParam)
{
    int ret = proto_ff::RET_SUCCESS;
    proto_ff::SceneTransParam& trans_param = const_cast<proto_ff::SceneTransParam&>(transParam);
    trans_param.set_ret(ret);
    {
        uint64_t curSceneId = m_pMaster->GetSceneId();
        uint64_t curMapId = m_pMaster->GetMapId();
        if (m_pMaster->Kind() != CREATURE_PLAYER && m_pMaster->Kind() != CREATURE_REBOT)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "TransScene...creature kind can not trans scene, this creature cannt, type:{}, cid:{}",
                       m_pMaster->Kind(), m_pMaster->Cid());
            return proto_ff::RET_FAIL;
        }
        
        NFPoint3<float> outPos(0.0, 0.0, 0.0);
        
        //这里，如果在副本里用传送点，会从传送点配置中读一个地图ID，此时sceneid实际上是地图ID,这里加sceneId == m_pMaster->GetMapId() 只是为了在副本内可传送功能 add by wangxx
        //判断是否在同一个逻辑服里
        NFScene* pScene = NFSceneMgr::Instance(m_pObjPluginManager)->GetScene(sceneId);
        if (nullptr != pScene)
        {
            //同一逻辑服则直接进入场景
            if (m_pMaster->GetScene() && (curSceneId == sceneId || curMapId == sceneId))
            {
                //传送同一个场景，直接设置坐标
                //
                NFMap* pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(pScene->GetMapId());
                if (nullptr == pMap)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                               "[logic] MovePart::TransScene can not find map cfg  cid={},sceneid={},despos({},{},{}),map:{}", m_pMaster->Cid(),
                               sceneId, dstPos.x, dstPos.y, dstPos.z, pScene->GetMapId());
                    return proto_ff::RET_SCENE_CAN_NOT_TRAN;
                }
                
                if (!pMap->FindNearestPos(dstPos.x, dstPos.z, dstPos.y, &outPos.x, &outPos.z, &outPos.y, nullptr))
                {
                    //坐标无效
                    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                               "FindNearestPos failed..  cid={},sceneid={},despos={},outpos={}", m_pMaster->Cid(), sceneId,
                               dstPos.ToString(), outPos.ToString());
                    return proto_ff::RET_SCENE_INVALID_DST_POS;
                }
                
                //当前场景内，直接瞬移，上面已经校验过坐标，这里就不再校验了
                int32_t teleType = 0;
                ret = Teleporting(dstPos, teleType, false);
                if (ret != proto_ff::RET_SUCCESS)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "TransScene same scene failed  cid={},sceneid={},despos={},outpos={}",
                               m_pMaster->Cid(), sceneId, dstPos.ToString(), outPos.ToString());
                }
                else
                {
                    OnTransSceneSuccess(transParam);
                }
            }
            else
            {
                if (m_pMaster->Kind() != CREATURE_PLAYER)
                {
                    ret = proto_ff::RET_FAIL;
                    trans_param.set_ret(ret);
                    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "creature kind can not trans scene, this creature cannt, type:{}, cid:{}", m_pMaster->Kind(), m_pMaster->Cid());
                    return ret;
                }
                
                //检查玩家是否能从当前场景切换到其他场景去
                if (!transParam.has_forcetp())
                {
                    ret = m_pMaster->CanTrans(sceneId, mapId, dstPos, outPos, transParam);
                    //检查玩家是否能从当前场景切换到其他场景去
                    if (ret != proto_ff::RET_SUCCESS)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                                   "TransScene..... CanTrans() Fail....sceneid:{}, mapid:{}, curscene:{}, cid:{},ret:{},outpos:{},{},{} ",
                                   sceneId, mapId, curSceneId, m_pMaster->Cid(), ret, outPos.x, outPos.y, outPos.z);
                        return ret;
                    }
                }
                
                //传送不同场景，则需要走下面流程
                ret = TransSceneInLogic(pScene, dstPos, transParam);
                if (ret != proto_ff::RET_SUCCESS)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                               "TransScene..... TransSceneInLogic Fail....sceneid:{}, mapid:{}, curscene:{}, cid:{},ret:{},outpos:{},{},{} ",
                               sceneId, mapId, curSceneId, m_pMaster->Cid(), ret, outPos.x, outPos.y, outPos.z);
                }
                else
                {
                    OnTransSceneSuccess(transParam);
                }
            }
        }
        else
        {
            if (m_pMaster->Kind() != CREATURE_PLAYER)
            {
                ret = proto_ff::RET_FAIL;
                trans_param.set_ret(ret);
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] MovePart::TransScene...creature kind can not trans scene, this creature cannt, type:%d, cid:%lu", m_pMaster->Kind(), m_pMaster->Cid());
                return false;
            }
            //检查玩家是否能从当前场景切换到其他场景去
            if (!transParam.has_forcetp())
            {
                ret = m_pMaster->CanTrans(sceneId, mapId, dstPos, outPos, transParam);
                //检查玩家是否能从当前场景切换到其他场景去
                if (ret != proto_ff::RET_SUCCESS)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                               "TransScene..... CanTrans() Fail....sceneid:{}, mapid:{}, curscene:{}, cid:{},ret:{},outpos:{},{},{} ",
                               sceneId, mapId, curSceneId, m_pMaster->Cid(), ret, outPos.x, outPos.y, outPos.z);
                    return ret;
                }
            }
            
            NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
            NF_ASSERT(pConfig);
            
            //
            proto_ff::LogicCreatureTransSceneReq req;
            req.set_cursceneid(curSceneId);
            req.set_dstsceneid(sceneId);
            req.set_srclogicid(pConfig->GetBusId());
            proto_ff::CreatureTransParam* protoParam = req.mutable_param();
            if (nullptr == protoParam)
            {
                ret = proto_ff::RET_FAIL;
                trans_param.set_ret(ret);
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] MovePart::TransScene..... nullptr == protoParam....sceneid:%lu, mapid:%lu, curscene:%lu,curMapId:%lu, cid:%lu,ret:%d ", sceneId, mapId, curSceneId, curMapId, m_pMaster->Cid(), ret);
                return ret;
            }
            proto_ff::SceneTransParam* protoTypeParam = protoParam->mutable_trans_param();
            if (nullptr == protoTypeParam)
            {
                ret = proto_ff::RET_FAIL;
                trans_param.set_ret(ret);
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] MovePart::TransScene..... nullptr == protoParam....sceneid:%lu, mapid:%lu, curscene:%lu,curMapId:%lu, cid:%lu,ret:%d ", sceneId, mapId, curSceneId, curMapId, m_pMaster->Cid(), ret);
                return ret;
            }
            protoParam->set_kind(m_pMaster->Kind());
            protoParam->set_cid(m_pMaster->Cid());
            protoTypeParam->CopyFrom(transParam);
            ret = m_pMaster->ChangeLogic(sceneId, mapId, dstPos, *protoParam);
            if (ret != proto_ff::RET_SUCCESS)
            {
                ret = proto_ff::RET_FAIL;
                trans_param.set_ret(ret);
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] MovePart::TransScene..... m_pMaster->ChangeLogic failed....sceneid:%lu, mapid:%lu, curscene:%lu,curMapId:%lu, cid:%lu,ret:%d ", sceneId, mapId, curSceneId, curMapId, m_pMaster->Cid(), ret);
                return ret;
            }
            //非玩家，直接发送到中心服
            ret = m_pMaster->SendMsgToCenterServer(proto_ff::LOGIC_CREATURE_TRANS_SCENE_REQ_CENTER, req);
            if (ret != proto_ff::RET_SUCCESS)
            {
                ret = proto_ff::RET_FAIL;
                trans_param.set_ret(ret);
            }
            return ret;
        } // end of if (nullptr != pScene)
    } // end of ERetCode ret = RET_SUCCESS;
    //
    
    return ret;
}

int
NFBattleMovePart::Teleporting(const NFPoint3<float> dstPos, int32_t type /*= (int32_t) proto_ff::MoveTeleportRsp_Type_common*/, bool checkpos /*= true*/)
{
    //校验坐标的正确性
    NFPoint3<float> pos = dstPos;
    if (checkpos)
    {
        uint64_t mapId = m_pMaster->GetMapId();
        NFMap* pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
        if (nullptr != pMap)
        {
            if (!pMap->FindNearestPos(pos.x, pos.z, pos.y, &pos.x, &pos.z, &pos.y, nullptr))
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "Teleporting pMap->FindNearestPos failed...cid:{}, mapid:{}, type:{},pos:{} ",
                           m_pMaster->Cid(), mapId, (int32_t)type, pos.ToString());
                return proto_ff::RET_FAIL;
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "Teleporting can not find map cfg...cid:{}, mapid:{}, type:{},pos:{} ",
                       m_pMaster->Cid(), mapId, (int32_t)type, pos.ToString());
            return proto_ff::RET_FAIL;
        }
    }
    
    //正在模拟移动的，先停止模拟移动
    if (m_timerIdMove != INVALID_ID)
    {
        DeleteTimer(m_timerIdMove);
        m_timerIdMove = INVALID_ID;
        //清空路径
        m_curMovePath.Clear();
    }
    
    //设置坐标
    m_pMaster->SetPos(pos);
    
    //广播通知
    proto_ff::MoveTeleportRsp notify;
    notify.set_type(type);
    notify.set_cid(m_pMaster->Cid());
    proto_ff::Vector3PB* proto = notify.mutable_pos();
    if (nullptr != proto)
    {
        proto->set_x(pos.x);
        proto->set_y(pos.y);
        proto->set_z(pos.z);
    }
    
    m_pMaster->BroadCast(proto_ff::MOVE_TELEPORT_RSP, notify, true);
    //
    if (CREATURE_PLAYER == m_pMaster->Kind())
    {
        //发送瞬移事件, 目前只用到玩家的瞬移
        proto_ff::NFEventNoneData event;
        FireExecute(NF_ST_GAME_SERVER, EVENT_TELEPORT_MOVE, m_pMaster->Kind(), m_pMaster->Cid(), event);
    }
    
    return proto_ff::RET_SUCCESS;
}

int NFBattleMovePart::OnTransSceneSuccess(const proto_ff::SceneTransParam& transParam)
{
    if (CREATURE_PLAYER != m_pMaster->Kind())
    {
        return proto_ff::RET_FAIL;
    }
    
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "Trans Scene Success, roleId:{} mapId:{} sceneId:{}", m_pMaster->Cid(), m_pMaster->GetMapId(),
              m_pMaster->GetSceneId());
    
    if (ETransType_Dup == transParam.trans_type())
    {
        if (!MapDescEx::Instance()->IsDynamic(m_pMaster->GetMapId()))
        {
            //从副本回到静态地图，满血
            int64_t maxhp = m_pMaster->GetAttr(proto_ff::A_MAX_HP);
            if (m_pMaster->GetAttr(proto_ff::A_CUR_HP) < maxhp)
            {
                m_pMaster->SetAttr(proto_ff::A_CUR_HP, maxhp, nullptr, true);
            }
        }
    }
    else if (ETransType_Teleport == transParam.trans_type())
    {
        //瞬移-切地图
        proto_ff::MoveTeleportResultRsp rsp;
        rsp.set_ret(proto_ff::RET_SUCCESS);
        rsp.set_type(transParam.param1());
        rsp.set_param1(transParam.param2());
        rsp.set_param2(transParam.param3());
        m_pMaster->SendMsgToClient(proto_ff::MOVE_TELEPORT_RESULT_RSP, rsp);
    }
    
    m_pMaster->OnTransSceneSuccess(transParam);
    return 0;
}

int NFBattleMovePart::TransSceneInLogic(NFScene* pDstScene, const NFPoint3<float>& transPos, const proto_ff::SceneTransParam& transParam)
{
    CHECK_NULL(pDstScene);
    if (CREATURE_PLAYER == m_pMaster->Kind())
    {
        m_pMaster->SetCanBeSeenFlag(false);
    }
    
    //这里先通知客户端加载，再发送场景其它数据
    proto_ff::NotifyLoadMap notifyLoad;
    notifyLoad.set_mapid(pDstScene->GetMapId());
    proto_ff::Vector3PB* prtopos = notifyLoad.mutable_pos();
    prtopos->set_x(transPos.x);
    prtopos->set_y(transPos.y);
    prtopos->set_z(transPos.z);
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_CLIENT_LOAD_MAP, notifyLoad);
    //
    
    if (m_pMaster->EnterScene(pDstScene->GetSceneId(), transPos, transParam) != proto_ff::RET_SUCCESS)  //到这里是已经进场景了，如果进入失败，则说明玩家信息有误。
    {
        if (CREATURE_PLAYER == m_pMaster->Kind())
        {
            m_pMaster->SetCanBeSeenFlag(true);
        }
        
        //通知前端切场景失败
        proto_ff::TransSceneRsp transRsp;
        transRsp.set_retcode(proto_ff::RET_SCENE_DST_NOT_EXIST);
        transRsp.set_mapid(pDstScene->GetMapId());
        m_pMaster->SendMsgToClient(proto_ff::NOTIFY_CLIENT_TRANS_SCENE_RSP, notifyLoad);
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "TransSceneInLogic failed....cid:{} ,cursceneid:{}, curmapid:{}, dstsceneid:{} ,dstmapid:{} ",
                   m_pMaster->Cid(), m_pMaster->GetSceneId(), m_pMaster->GetMapId(), pDstScene->GetSceneId(), pDstScene->GetMapId());
        return proto_ff::RET_FAIL;
    }
    else
    {
        if (m_timerIdLoadMapTimeout != INVALID_ID)
        {
            DeleteTimer(m_timerIdLoadMapTimeout);
        }
        
        m_waitLoadMapId = pDstScene->GetMapId();
        m_timerIdLoadMapTimeout = SetTimer(INTERVAL_LOAD_MAP_TIMEOUT, 1, 0, 0, 0, 0);
    }
    
    return proto_ff::RET_SUCCESS;
}

int32_t NFBattleMovePart::CanTrans(const proto_ff_s::E_MapMap_s* pmapcfg, uint64_t& outsceneId, const NFPoint3<float>& pos, const proto_ff::SceneTransParam& transParam, bool checkpos)
{
    if (nullptr == pmapcfg) { return proto_ff::RET_CONFIG_ERROR; }
    int ret = proto_ff::RET_FAIL;
    NFPoint3<float> outpos;
    
    ret = m_pMaster->CanTrans(outsceneId, pmapcfg->m_mapId, pos, outpos, transParam, checkpos);
    if (ret != proto_ff::RET_SUCCESS)
    {
        return (int32_t)ret;
    }
    
    //动态地图不允许用这个接口
    if (MapDescEx::Instance()->IsDynamic(pmapcfg->m_mapId))
    {
        return proto_ff::RET_SCENE_CAN_NOT_TRAN;
    }
    
    //特殊的活动的静态地图只能通过活动那边进入
    if (MapDescEx::Instance()->IsActSpecMap(pmapcfg->m_mapId))
    {
        return proto_ff::RET_SCENE_CAN_NOT_TRAN;
    }
    //
    outsceneId = pmapcfg->m_mapId;
    if (MapDescEx::Instance()->IsMainCity(pmapcfg))
    {
        outsceneId = NFSceneMgr::Instance(m_pObjPluginManager)->MainCitySceneId(pmapcfg->m_mapId, m_pMaster->GetZid());
        if (outsceneId <= 0)
        {
            return proto_ff::RET_SCENE_DST_NOT_EXIST;
        }
    }
    return proto_ff::RET_SUCCESS;
}

int NFBattleMovePart::OnTimer(int timeId, int callcount)
{
    if (timeId == m_timerIdMove)
    {
        OnMoveTimer();
    }
    else if (timeId == m_timerIdLoadMapTimeout)
    {
        if (m_waitLoadMapId > 0)
        {
            m_waitLoadMapId = 0;
            m_timerIdLoadMapTimeout = INVALID_ID;
            if (!m_pMaster->GetCanBeSeenFlag())
            {
                m_pMaster->SetCanBeSeenFlag(true);
                m_pMaster->UpdateNineGridLst();
            }
        }
    }
    return 0;
}

int NFBattleMovePart::OnMoveTimer()
{
    uint64_t curTick = NFTime::Now().UnixMSec();
    int64_t interTick = curTick - m_moveTick;
    //
    if (CREATURE_PLAYER == m_pMaster->Kind())
    {
        bool stopFlag = false;
        uint64_t interMSec = curTick - m_lastClientMoveTick;
        //超过6秒还没收到的客户端移动的消息消息，自动停止
        //避免客户端没有发停止过来，服务器一直走下去
        if (interMSec >= INTERVAL_CLIENT_MOVE_TIMEOUT)
        {
            stopFlag = true;
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                       "MovePart::ClientMoveTimer...move timeout...auto stop move cid:{},m_clientMoveTime:{},tick:{},interMSec:{},intertick:{}",
                       m_pMaster->Cid(), m_lastClientMoveTick, curTick, interMSec, interTick);
        }
        //
        MoveBySimulate(interTick, stopFlag);
    }
    else
    {
        
        MoveByPath(interTick);
    }
    
    //设置服务器移动时间
    m_moveTick = curTick;
    //停止移动的话，需要发送事件
    if (m_timerIdMove == INVALID_ID)
    {
        //发送停止移动事件
        proto_ff::NFEventNoneData event;
        FireExecute(NF_ST_GAME_SERVER, EVENT_END_MOVE, m_pMaster->Kind(), m_pMaster->Cid(), event);
    }
    
    return 0;
}

//模拟客户端移动(玩家移动) intertick: 间隔时间，单位：毫秒,  stopFlag:是否停止移动
int NFBattleMovePart::MoveBySimulate(int64_t interTick, bool stopFlag /*= false*/)
{
    //间隔时间
    float fTick = interTick / 1000.0f;
    //坐标
    NFPoint3<float> curPos = m_pMaster->GetPos();
    NFPoint3<float> oldPos = curPos;
    //
    if (stopFlag)
    {
        DeleteTimer(m_timerIdMove);
        m_timerIdMove = INVALID_ID;
        m_curMovePath.Clear();
    }
    //
    if (interTick > 0)
    {
        curPos = curPos + m_clientUnitVector * fTick * m_pMaster->GetSpeed();
    }
    
    NFLogDebug(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "ftick:{}, stopFlag:{}, oldpos:{}, curpos:{}", fTick, stopFlag, oldPos.ToString(), curPos.ToString());
    //
    if (stopFlag) //如果是停止移动，服务器需要校验下最终的坐标
    {
        NFPoint3<float> zeroSpeed(0.0f, 0.0f, 0.0f);
        NFPoint3<float> newPos = curPos;
        uint64_t mapId = m_pMaster->GetMapId();
        NFMap* pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
        if (nullptr != pMap)
        {
            if (!pMap->FindNearestPos(curPos.x, curPos.z, curPos.y, &curPos.x, &curPos.z, &curPos.y, nullptr))
            {
                //找不到可行走的点，直接设置为上一次客户端正确的坐标
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                           "FindNearestPos failed cid:{}, interTick:{}, fTick:{}, oldPos:{}, newPos:{}, curPos:{}, m_clientUnitVector:{}, fSpeed:{}, rightPos:{}",
                           m_pMaster->Cid(), interTick, fTick, oldPos.ToString(), newPos.ToString(), curPos.ToString(),
                           m_clientUnitVector.ToString(), m_pMaster->GetSpeed(), m_lastRightPos.ToString());
                curPos = m_lastRightPos;
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                       "not find map cfg cid failed cid:{}, interTick:{}, fTick:{}, oldPos:{}, newPos:{}, curPos:{}, m_clientUnitVector:{}, fSpeed:{}, rightPos:{}",
                       m_pMaster->Cid(), interTick, fTick, oldPos.ToString(), newPos.ToString(), curPos.ToString(),
                       m_clientUnitVector.ToString(), m_pMaster->GetSpeed(), m_lastRightPos.ToString());
            curPos = m_lastClientPos;
        }
        
        if (interTick > 0) //有移动间隔才会计算朝向
        {
            //计算朝向
            m_lastDir = CalDir(curPos, oldPos);
        }
        
        //广播通知停止移动
        BroadcastMove(m_pMaster->Cid(), curPos, zeroSpeed, m_lastDir, true);
        //停止移动时的坐标是校验过的，肯定是正确的，把上一次客户端正确的坐标设置为当前坐标
        m_lastRightPos = curPos;
        //设置坐标
        m_pMaster->SetPos(curPos);
    }
    else if (interTick > 0) //有移动间隔才会设置当前坐标
    {
        m_pMaster->SetPos(curPos);
    }
    
    return 0;
}

//计算朝向
NFPoint3<float> NFBattleMovePart::CalDir(const NFPoint3<float>& dstPos, const NFPoint3<float>& srcPos)
{
    NFPoint3<float> dir = dstPos - srcPos;
    dir.y = 0;
    return dir;
}

//通过路径移动 intertick: 间隔时间，单位：毫秒
int NFBattleMovePart::MoveByPath(int64_t interTick, bool stopFlag)
{
    NFPoint3<float> oldPos = m_pMaster->GetPos();
    
    //通过移动距离确定路径上的坐标
    if (interTick > 0)
    {
        //间隔时间
        float fSec = interTick / 1000.0f;
        //间隔时间内移动的距离
        float fDis = fSec * m_pMaster->GetSpeed();
        NFPoint3<float> retPos;
        //
        bool reachFlag = m_curMovePath.MapPathDistanceToPoint(fDis, retPos);
        
        //新的朝向和朝向点
        NFPoint3<float> newDir = CalDir(retPos, oldPos);
        NFPoint3<float> newDot = CalDotByDir(newDir);
        bool broadFlag = false;//是否需要广播客户端
        //这里是计算生物朝向是否有改变，具体的计算方式保持和客户端一致
        float fdiff = newDot.x * m_lastDirDot.x + newDot.z * m_lastDirDot.z;
        if (fdiff < 1.0f)
        {
            //朝向有改变，需要广播通知给客户端
            broadFlag = true;
        }
        //计算新的速度
        NFPoint3<float> newSpeed(0.0f, 0.0f, 0.0f);
        if (reachFlag || stopFlag)
        {
            broadFlag = true; //停止移动或者已达到目标点，需要广播
            DeleteTimer(m_timerIdMove);
            m_timerIdMove = INVALID_ID;
            //清空路径
            m_curMovePath.Clear();
        }
        else
        {
            //新速度
            newSpeed = CalSpeedByDot(newDot, 1.0f, m_pMaster->GetSpeed());
        }
        
        //广播通知
        if (broadFlag)
        {
            BroadcastMove(m_pMaster->Cid(), retPos, newSpeed, newDir, true);
        }
        
        //设置新的朝向
        m_lastDir = newDir;
        //设置新的朝向点
        m_lastDirDot = newDot;
        //设置新的速度
        SetClientSpeed(newSpeed);
        //设置坐标
        m_pMaster->SetPos(retPos);
        m_pMaster->SetDir(newDot);
    }
    else if (stopFlag)
    {
        DeleteTimer(m_timerIdMove);
        m_timerIdMove = INVALID_ID;
        //清空路径
        m_curMovePath.Clear();
        
        //间隔时间为0，表示没有移动，直接广播停止即可
        NFPoint3<float> zerospeed(0.0f, 0.0f, 0.0f);
        BroadcastMove(m_pMaster->Cid(), oldPos, zerospeed, m_lastDir, true);
    }
    
    return 0;
}

//根据计算单位朝向
NFPoint3<float> NFBattleMovePart::CalDotByDir(const NFPoint3<float>& dir)
{
    float flen = NFMath::CarmackSqrt((dir.x * dir.x + dir.z * dir.z));
    NFPoint3<float> dot; //新的朝向点
    if (flen > EPS)
    {
        dot = dir / flen;
    }
    return dot;
}

//根据朝向点计算速度  dot:朝向点， fsec:间隔时间，单位：秒，  fspeed：速度，单位：m/s
NFPoint3<float> NFBattleMovePart::CalSpeedByDot(const NFPoint3<float>& dot, float fsec, float fspeed)
{
    return (dot * fsec * fspeed);
}

int NFBattleMovePart::ClientLoadMapFinshReq(uint32_t msgId, NFDataPackage& packet)
{
    if (m_waitLoadMapId <= 0)
    {
        if (m_timerIdLoadMapTimeout != INVALID_ID)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                       "m_waitLoadMapId <= 0....cid:{},m_waitLoadMapId:{},curmap:{},curscene:{},beensee:{} ",
                       m_pMaster->Cid(),
                       m_waitLoadMapId, m_pMaster->GetMapId(), m_pMaster->GetSceneId(), m_pMaster->GetCanBeSeenFlag());
            return -1;
        }
        
        return 0;
    }
    
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "cid:{}, m_waitLoadMapId:{}, curmap:{}, curscene:{}, beensee:{} ",
              m_pMaster->Cid(), m_waitLoadMapId, m_pMaster->GetMapId(), m_pMaster->GetSceneId(), m_pMaster->GetCanBeSeenFlag());
    //
    m_waitLoadMapId = 0;
    if (m_timerIdLoadMapTimeout != INVALID_ID)
    {
        DeleteTimer(m_timerIdLoadMapTimeout);
        m_timerIdLoadMapTimeout = INVALID_ID;
    }
    
    if (!m_pMaster->GetCanBeSeenFlag())
    {
        m_pMaster->SetCanBeSeenFlag(true);
        m_pMaster->UpdateNineGridLst();
    }
    
    return 0;
}

int NFBattleMovePart::ClientSeatReq(uint32_t msgId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::PlayerSeatReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    int32_t opt = req.opt();
    
    proto_ff::PlayerSeatRsp rsp;
    rsp.set_opt(opt);
    
    if (opt == 1 && !m_pMaster->BState(proto_ff::state_normal))
    {
        rsp.set_ret(proto_ff::RET_PLAYER_SEAT_STATE_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
        return -1;
    }
    
    if (opt != 1 && !m_pMaster->BState(proto_ff::state_seat))
    {
        rsp.set_ret(proto_ff::RET_PLAYER_SEAT_STATE_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
        return -1;
    }
    
    NFScene* pScene = m_pMaster->GetScene();
    if (nullptr == pScene)
    {
        rsp.set_ret(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
        return -1;
    }
    
    uint64_t map_id = pScene->GetMapId();
    auto pMapCfg = MapMapDesc::Instance()->GetDesc(map_id);
    if (!pMapCfg)
    {
        rsp.set_ret(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
        return -1;
    }
    
    if (opt == 1 && pMapCfg->m_mapType != 1)
    {
        rsp.set_ret(proto_ff::RET_PLAYER_SEAT_MAP_NOT_SEAT);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
        return -1;
    }
    
    bool bOpt = true;
    if (opt == 1)
    {
        bOpt = m_pMaster->EnterSeatState();
    }
    else
    {
        bOpt = m_pMaster->LeaveSeatState();
    }
    
    int32_t ret = bOpt ? proto_ff::RET_SUCCESS : proto_ff::RET_FAIL;
    rsp.set_ret(ret);
    
    rsp.set_exp(0);
    rsp.set_online_hangup_time(0);
    rsp.set_online_all_exp(0);
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFBattleMovePart::ClientTransSceneReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::TransSceneReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    uint64_t cid = m_pMaster->Cid();
    int32_t transType = req.type(); //传送类型
    uint64_t transId = req.id();    //传送ID，针对路径点传送和区域传送
    uint64_t dstMapId = 0; //目标地图ID
    NFPoint3<float> dstPos; //目标传送点
    //
    proto_ff::SceneTransParam transParam;
    transParam.set_src_map(m_pMaster->GetMapId());
    transParam.set_trans_type(ETransType_Scene);
    int32_t ret = proto_ff::RET_SCENE_TRANS_PARAM_ERROR;
    //
    if (ETransMapType_None == transType) //出生点传送
    {
        dstMapId = req.dst_mapid();
        //随机出生点
        const NFPoint3<float>* pBornCfg = MapDescEx::Instance()->RandBornPoint(dstMapId);
        if (nullptr == pBornCfg)
        {
            ret = proto_ff::RET_SCENE_CAN_NOT_TRAN;
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "RandBornPoint failed...cid:%lu, mapid:%lu ", cid, dstMapId);
        }
        else
        {
            dstPos.x = pBornCfg->x;
            dstPos.y = pBornCfg->y;
            dstPos.z = pBornCfg->z;
            dstPos = NFMapMgr::Instance(m_pObjPluginManager)->RandPosAroundPos(dstMapId, dstPos, 5);
            ret = proto_ff::RET_SUCCESS;
        }
    }
    else if (ETransMapType_Point == transType)
    {
        auto pPointLoc = MapDescEx::Instance()->GetPointCfg(transId);
        if (nullptr == pPointLoc)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] MovePart::ClientTransSceneReq...nullptr == pPointLoc..cid:%lu, transId:%lu ", cid, transId);
        }
        else if (pPointLoc->vecposcfg.size() <= 0)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] MovePart::ClientTransSceneReq...pPathLoc->vecposcfg.size() <= 0..cid:%lu,m_mapId:%lu, transId:%lu ", cid, pPointLoc->mapid, transId);
        }
        else
        {
            uint32_t isize = (uint32_t)pPointLoc->vecposcfg.size();
            uint32_t idx = NFRandInt((uint32_t)0, isize);
            dstPos = pPointLoc->vecposcfg[idx].m_pos;
            dstMapId = pPointLoc->mapid;
            ret = proto_ff::RET_SUCCESS;
        }
    }
    else if (ETransMapType_Area == transType)
    {
        auto pAreaCfg = AreaAreaDesc::Instance()->GetDesc(transId);
        if (nullptr == pAreaCfg)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[nullptr == pAreaCfg..cid:%lu,transId:%lu ", cid, transId);
        }
        else if (!MapDescEx::Instance()->RandPosInArea(transId, dstPos)) //区域内随机一个坐标
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "RandPosInArea failed..cid:%lu, mapid:%lu, transId:%lu ", cid, dstMapId, transId);
        }
        else
        {
            dstMapId = pAreaCfg->m_belongToSceneID;
            ret = proto_ff::RET_SUCCESS;
        }
    }
    uint64_t dstSceneId = dstMapId;
    if (proto_ff::RET_SUCCESS == ret)
    {
        auto pmapcfg = MapMapDesc::Instance()->GetDesc(dstMapId);
        if (nullptr == pmapcfg)
        {
            ret = proto_ff::RET_CONFIG_ERROR;
        }
        else
        {
            ret = CanTrans(pmapcfg, dstSceneId, dstPos, transParam);
        }
    }
    if (proto_ff::RET_SUCCESS == ret)
    {
        ret = TransScene(dstSceneId, dstPos, dstMapId, transParam);
    }
    if (proto_ff::RET_SUCCESS != ret)
    {
        //通知前端切场景失败
        proto_ff::TransSceneRsp transRsp;
        transRsp.set_retcode(ret);
        transRsp.set_mapid(dstMapId);
        m_pMaster->SendMsgToClient(proto_ff::NOTIFY_CLIENT_TRANS_SCENE_RSP, transRsp);
    }
    return 0;
}

int NFBattleMovePart::ClientTeleportReq(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

//能否移动
int NFBattleMovePart::CanMove()
{
    uint64_t cid = m_pMaster->Cid();
    //是否死亡
    if (m_pMaster->IsDead())
    {
        NFLogError(NF_LOG_SYSTEMLOG, cid, "MovePart::CanMove  cid={}, already dead ", cid);
        return proto_ff::RET_FAIL;
    }
    
    //检查是否有禁止移动的buff
    NFBattleBuffPart* pBuff = dynamic_cast<NFBattleBuffPart*>(m_pMaster->GetPart(PART_MOVE));
    if (nullptr != pBuff && !pBuff->CanMove())
    {
        return proto_ff::RET_FAIL;
    }
    
    //正在传送，不接收移动消息，主要是为了处理传送过种中，客户端还会发移动消息，此时，客户端在加载，会跑到不合法点上
    if (!m_pMaster->GetCanBeSeenFlag())
    {
        return proto_ff::RET_FAIL;
    }
    
    //移动速度为0，也不需移动
    float fspeed = m_pMaster->GetSpeed();
    if (fspeed <= EPS)
    {
        return proto_ff::RET_FAIL;
    }
    
    return proto_ff::RET_SUCCESS;
}

//移动到目标坐标，注意：这个接口只允许人物以外的生物调用，人物的移动是前端驱动的
int NFBattleMovePart::MoveTo(const NFPoint3<float>& dstPos)
{
    uint64_t cid = m_pMaster->Cid();
    NFPoint3<float> startPos = m_pMaster->GetPos();
    NFPoint3<float> srcPos(startPos.x, startPos.y, startPos.z);
    //
    if (srcPos == dstPos)
    {
        //当前坐标已经在目标点了
        NFLogError(NF_LOG_SYSTEMLOG, cid,
                   "MovePart::MoveTo already in position cid={}, kind:{}, cfgid:{}, scene:{}, map:{}, speed={},distance={}", cid, m_pMaster->Kind(),
                   m_pMaster->GetCfgId(), m_pMaster->GetSceneId(), m_pMaster->GetMapId(), m_pMaster->GetSpeed(), NFMath::NFPoint3Length(srcPos, dstPos));
        return 0;
    }
    //
    if (!CanMove())
    {
        NFLogError(NF_LOG_SYSTEMLOG, cid, "MovePart::MoveTo can not move cid={}, kind:{}, cfgid:{}, scene:{}, map:{}, speed={},distance={}", cid,
                   m_pMaster->Kind(), m_pMaster->GetCfgId(), m_pMaster->GetSceneId(), m_pMaster->GetMapId(), m_pMaster->GetSpeed(),
                   NFMath::NFPoint3Length(srcPos, dstPos));
        return proto_ff::RET_FAIL;
    }
    
    //
    NFMap* map = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(m_pMaster->GetMapId());
    if (!map)
    {
        NFLogError(NF_LOG_SYSTEMLOG, cid, "MovePart::MoveTo can not find map cfg cid={}, kind:{}, cfgid:{}, scene:{}, map:{}", cid,
                   m_pMaster->Kind(), m_pMaster->GetCfgId(), m_pMaster->GetSceneId(), m_pMaster->GetMapId());
        return proto_ff::RET_FAIL;
    }
    
    VEC_FLAGS flgs;
    flgs.clear();
    VEC_POINT3 path;
    path.clear();
    float vSrcPos[] = {srcPos.x, srcPos.y, srcPos.z};
    float vDstPos[] = {dstPos.x, dstPos.y, dstPos.z};
    if (!map->GetNavPath(vSrcPos, vDstPos, path, flgs))
    {
        NFLogError(NF_LOG_SYSTEMLOG, cid,
                   "MovePart::MoveTo GetNavPath failed...cid={},mapid-={},sceneid={},cid={},cfgid:{}, speed={},distance={},startpos:{},{},{}  dstpos:{},{},{} ",
                   cid, m_pMaster->GetMapId(), m_pMaster->GetSceneId(), m_pMaster->Cid(), m_pMaster->GetCfgId(), m_pMaster->GetSpeed(),
                   NFMath::NFPoint3Length(startPos, dstPos), startPos.x, startPos.y, startPos.z, dstPos.x, dstPos.y, dstPos.z);
        return proto_ff::RET_FAIL;
    }
    
    //找路点的方法好像有问题，会找出来一个和起点一样的点，然后返回true,暂时在这里作个处理，后续再验证todo.
    if (1 == path.size() && path[0] == startPos)
    {
        NFLogError(NF_LOG_SYSTEMLOG, cid,
                   "MovePart::MoveTo  path.size() <= 1 && path[0] == startPos... cid={},cfgid:{}, scene:{}, map:{}, srcpos:[{},{},{}], dstpos:[{},{},{}],path[0]:[{},{},{}] ",
                   cid, m_pMaster->GetCfgId(), m_pMaster->GetSceneId(), m_pMaster->GetMapId(), srcPos.x, srcPos.y, srcPos.z, dstPos.x, dstPos.y,
                   dstPos.z, path[0].x, path[0].y, path[0].z);
        //return false;
        //由于起始点和目标点比较进的时候，会出现寻路插件寻找到的目标路径和起始点一样
        //这里做一个兼容处理，如果寻路插件寻找到的目标路径和起始点一样，在目标坐标附近找一个可行走的坐标点 放到目标路径中
        path[0].x = srcPos.x;
        path[0].y = srcPos.y;
        path[0].z = srcPos.z;
        //
        NFPoint3<float> tmpDstPos = dstPos;
        if (!map->FindNearestPos(dstPos.x, dstPos.z, dstPos.y, &tmpDstPos.x, &tmpDstPos.z, &tmpDstPos.y, nullptr))
        {
            NFLogError(NF_LOG_SYSTEMLOG, cid,
                       "MovePart::MoveTo path.size() <= 1 && path[0] == startPos, FindNearestPos failed... cid={},cfgid:{}, scene:{}, map:{}, srcpos:[{},{},{}], dstpos:[{},{},{}],path[0]:[{},{},{}] ",
                       cid, m_pMaster->GetCfgId(), m_pMaster->GetSceneId(), m_pMaster->GetMapId(), srcPos.x, srcPos.y, srcPos.z, dstPos.x, dstPos.y,
                       dstPos.z, path[0].x, path[0].y, path[0].z);
            //
            path.push_back(srcPos);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, cid,
                       "MovePart::MoveTo path.size() <= 1 && path[0] == startPos, FindNearestPos success... cid={},cfgid:{}, scene:{}, map:{}, srcpos:[{},{},{}], dstpos:[{},{},{}],path[0]:[{},{},{}],tmpDstPos:[{},{},{}] ",
                       cid, m_pMaster->GetCfgId(), m_pMaster->GetSceneId(), m_pMaster->GetMapId(), srcPos.x, srcPos.y, srcPos.z, dstPos.x, dstPos.y,
                       dstPos.z, path[0].x, path[0].y, path[0].z, tmpDstPos.x, tmpDstPos.y, tmpDstPos.z);
            path.push_back(tmpDstPos);
        }
    }
    
    if (m_curMovePath.Init(path, startPos))
    {
        if (m_timerIdMove == INVALID_ID)
        {
            m_timerIdMove = SetTimer(INTERVAL_MOVE_TIME, 0, 0, 0, 0, 0);
            if (m_timerIdMove == INVALID_ID)
            {
                m_curMovePath.Clear();
                NFLogError(NF_LOG_SYSTEMLOG, cid,
                           "MovePart::MoveTo g_GetTimerAxis()->SetTimer failed... cid={},cfgid:{}, scene:{}, map:{}, srcpos:[{},{},{}], dstpos:[{},{},{}] ",
                           cid, m_pMaster->GetCfgId(), m_pMaster->GetSceneId(), m_pMaster->GetMapId(), srcPos.x, srcPos.y, srcPos.z, dstPos.x, dstPos.y,
                           dstPos.z);
                return proto_ff::RET_FAIL;
            }
            //
            m_moveTick = NFTime::Now().UnixMSec();
            //
            m_lastDir = CalDir(dstPos, srcPos);
            m_lastDirDot = CalDotByDir(m_lastDir);
            NFPoint3<float> speed = CalSpeedByDot(m_lastDirDot, 1.0f, m_pMaster->GetSpeed());
            SetClientSpeed(speed);
            //开始移动广播
            BroadcastMove(m_pMaster->Cid(), srcPos/*pos*/, m_clientSpeed, m_lastDir, true);
        }
        
        return 0;
    }
    //
    m_curMovePath.Clear();
    NFLogError(NF_LOG_SYSTEMLOG, cid,
               "MovePart::MoveTo m_curMovePath.Init failed... cid={},cfgid:{}, scene:{}, map:{}, pathsize:{}, srcpos:[{},{},{}], dstpos:[{},{},{}] ",
               cid, m_pMaster->GetCfgId(), m_pMaster->GetSceneId(), m_pMaster->GetMapId(), (int32_t)path.size(), srcPos.x, srcPos.y, srcPos.z, dstPos.x,
               dstPos.y, dstPos.z);
    
    return proto_ff::RET_FAIL;
}

//是否正在移动
int NFBattleMovePart::IsMoving() const
{
    if (m_timerIdMove != INVALID_ID) { return 0; }
    return proto_ff::RET_FAIL;
}

//停止移动
int NFBattleMovePart::StopMove()
{
    if (m_timerIdMove == INVALID_ID)
    {
        return 0;
    }
    //
    uint64_t intertick = NFTime::Now().UnixMSec() - m_moveTick;
    if (CREATURE_PLAYER == m_pMaster->Kind())
    {
        MoveBySimulate(intertick, true);
    }
    else
    {
        MoveByPath(intertick, true);
    }
    
    return 0;
}