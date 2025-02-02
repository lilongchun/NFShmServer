// -------------------------------------------------------------------------
//    @FileName         :    NFMapMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapMgr
//
// -------------------------------------------------------------------------

#include "NFMapMgr.h"
#include "DescStore/MapMapDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFMap.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFGameConfig.h"
#include "NFGameCommon/NFMath.h"
#include "DescStoreEx/MapDescEx.h"
#include "NFCSceneModule.h"

NFMapMgr::NFMapMgr()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFMapMgr::~NFMapMgr()
{
}

int NFMapMgr::CreateInit()
{
    return 0;
}

int NFMapMgr::ResumeInit()
{
    return 0;
}

NFNavMeshInfo* NFMapMgr::AddNavMeshInfo(const std::string& navName)
{
    auto iter = m_mapNavMesh.emplace_hint(navName, NFNavMeshInfo());
    if (iter != m_mapNavMesh.end())
    {
        return &iter->second;
    }
    return nullptr;
}

NFNavMeshInfo* NFMapMgr::GetNavMeshInfo(const std::string& navName)
{
    auto iter = m_mapNavMesh.find(navName);
    if (iter != m_mapNavMesh.end())
    {
        return &iter->second;
    }
    return nullptr;
}

int NFMapMgr::LoadConfig()
{
    NFMap::ClearAllObj(m_pObjPluginManager);
    CreateInit();
    auto pGameConfig = FindModule<NFCSceneModule>()->GetGameConfig()->GetConfig();
    for (int i = 0; i < (int)pGameConfig->map.size(); i++)
    {
        uint32_t mapId = pGameConfig->map[i];
        NFMap* pMap = CreateMap(mapId);
        CHECK_EXPR_ASSERT(pMap, -1, "CreateMap Failed, mapId:{}", mapId);
    }
    return 0;
}

NFMap* NFMapMgr::GetMap(uint64_t mapId)
{
    return dynamic_cast<NFMap*>(FindModule<NFISharedMemModule>()->GetObjByHashKey(EOT_GAME_MAP_ID, mapId));
}

NFMap* NFMapMgr::CreateMap(uint64_t mapId)
{
    NFMap* pMap = GetMap(mapId);
    CHECK_EXPR(pMap == NULL, NULL, "CreateMap Failed, map exist, mapId:{}", mapId);
    
    pMap = dynamic_cast<NFMap*>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(EOT_GAME_MAP_ID, mapId));
    CHECK_EXPR(pMap, NULL, "Create Map Obj Failed, mapId:{}", mapId);
    
    int iRet = pMap->Init(mapId);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "NFMap Init Failed! mapId:{}", mapId);
        DeleteMap(pMap);
        return NULL;
    }
    
    NFLogInfo(NF_LOG_SYSTEMLOG, mapId, "Create Map Success, mapId:{} globalId:{}", mapId, pMap->GetGlobalId());
    return pMap;
}

int NFMapMgr::DeleteMap(NFMap* pMap)
{
    CHECK_NULL(pMap);
    
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Map Info, mapId:{}, gloablId:{}", pMap->GetMapId(),
              pMap->GetGlobalId());
    
    FindModule<NFISharedMemModule>()->DestroyObj(pMap);
    
    return 0;
}

int NFMapMgr::ClearAllMap()
{
    FindModule<NFISharedMemModule>()->ClearAllObj(EOT_GAME_MAP_ID);
    return 0;
}

NFPoint3<float> NFMapMgr::RandPosAroundPos(uint64_t mapId, const NFPoint3<float>& pos, uint32_t nRadius)
{
    NFMap* pMap = GetMap(mapId);
    if (pMap)
    {
        int32_t nDeltaX = NFRandInt((int32_t)0, (int32_t)nRadius) * (NFRandInt(0, 100) % 2 == 0 ? 1 : -1);
        int32_t nDeltaZ = NFRandInt((int32_t)0, (int32_t)nRadius) * (NFRandInt(0, 100) % 2 == 0 ? 1 : -1);
        NFPoint3<float> destPos = pos;
        destPos.x += nDeltaX;
        destPos.z += nDeltaZ;
        if (pMap->FindNearestPos(destPos.x, destPos.z, destPos.y, &destPos.x, &destPos.z, &destPos.y, nullptr))
        {
            return destPos;
        }
    }
    return pos;
}

NFPoint3<float> NFMapMgr::RandPosAroundCircle(uint64_t mapId, const NFPoint3<float>& pos, float fRadius)
{
    NFMap* pMap = GetMap(mapId);
    if (nullptr == pMap) { return pos; }
    int32_t rnd = NFRandInt(1, 360);
    float frad = NFMath::AngleToRadian(rnd);
    float z = fRadius * sin(frad);
    float x = fRadius * cos(frad);
    NFPoint3<float> destPos(pos.x + x, pos.y, pos.z + z);
    if (pMap->FindNearestPos(destPos.x, destPos.z, destPos.y, &destPos.x, &destPos.z, &destPos.y, nullptr))
    {
        return destPos;
    }
    return pos;
}

bool NFMapMgr::RandPosInPoint(int64_t pointid, NFPoint3<float>& outpos)
{
    auto pcfg = MapDescEx::Instance()->GetPointCfg(pointid);
    if (nullptr == pcfg) { return false; }
    uint32_t nsize = (uint32_t)pcfg->vecposcfg.size();
    if (nsize <= 0) { return false; }
    uint32_t idx = NFRandInt((uint32_t)0, nsize); //0 - (nsize-1)
    auto& area = pcfg->vecposcfg[idx];
    outpos = RandPosAroundPos(pcfg->mapid, area.m_pos, 3.5);
    return true;
}
