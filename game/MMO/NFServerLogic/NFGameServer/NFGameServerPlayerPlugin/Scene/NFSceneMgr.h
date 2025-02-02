// -------------------------------------------------------------------------
//    @FileName         :    NFSceneMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFSceneMgr
//
// -------------------------------------------------------------------------

#pragma once


#include <set>
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFGameCommon/NFPoint2.h"
#include "NFGameCommon/NFPoint3.h"
#include "ServerInternal2.pb.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

#define GAME_SERVER_MAX_BATTLE_SCENE_SIZE 100
#define MAX_LAYER 5  //搜索最大层数

class NFScene;
class NFSceneMgr : public NFShmObjTemplate<NFSceneMgr, EOT_GAME_SCENE_MGR_ID, NFShmObj>
{
public:
    typedef NFShmVector<NFPoint2<int32_t>, (1+(MAX_LAYER-1)*2)*(1+(MAX_LAYER-1)*2)> OneLayer;
    typedef NFShmVector<OneLayer, MAX_LAYER+1> NineGridLayer;
public:
    NFSceneMgr();

    virtual ~NFSceneMgr();

    int CreateInit();

    int ResumeInit();

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
public:
    /**
     * @brief
     * @param mapIds
     * @return
     */
    int InitScene(const std::unordered_set<uint64_t>& mapIds);

public:
    /**
     * @brief
     * @param mapId
     * @param sceneId
     * @return
     */
    NFScene* CreateScene(uint64_t mapId, uint64_t sceneId);

    /**
     * @brief
     * @param sceneId
     * @return
     */
    NFScene* GetScene(uint64_t sceneId);

    /**
     * @brief
     * @param pScene
     * @return
     */
    int DeleteScene(NFScene* pScene);
public:
    /**
     * @brief 是否关闭
     * @param sceneId
     * @return
     */
    bool IsClosed(uint64_t sceneId);

    /**
     * @brief 获取层数对应格子计算数组
     * @param nlayer
     * @return
     */
    const OneLayer* GetLayerPoint(uint32_t nlayer);
public:
    /**
     * @brief 进入场景
     * @param roleId
     * @param mapId
     * @param sceneId
     * @param pos
     * @param transParam
     * @return
     */
    int EnterScene(uint64_t roleId, uint64_t mapId, uint64_t sceneId, const NFPoint3<float>& pos, const proto_ff::SceneTransParam& transParam);
    
    /**
     * @brief 离开场景
     * @param roleId
     * @param mapId
     * @param sceneId
     * @return
     */
    int LeaveScene(uint64_t roleId, uint64_t mapId, uint64_t sceneId);
    
    /**
     * @brief 获取主城场景
     * @param mapid
     * @param zid
     * @return
     */
    NFScene* GetMainCity(uint64_t mapid, uint32_t zid) { return NULL; }
    
    /**
     * @brief 获取主城场景ID
     * @param mapid
     * @param zid
     * @return
     */
    uint64_t MainCitySceneId(uint64_t mapid, uint32_t zid) { return 0; }
private:
    /**
     * @brief 场景销毁缓存表 sceneid - tick
     */
    NFShmHashMap<uint64_t, uint64_t, 1000> m_delCacheMap;
    
    /**
     * @brief 每层映射搜索位置信息(最大5层)
     */
    NineGridLayer m_nineGridLayer;
};