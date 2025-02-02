// -------------------------------------------------------------------------
//    @FileName         :    NFCreatureMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFCreatureMgr
//
// -------------------------------------------------------------------------

#include "NFCreatureMgr.h"
#include "NFCreature.h"
#include "NFBattlePlayer.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFLogicCommon/NFCharactorDefine.h"

NFCreatureMgr::NFCreatureMgr()
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

NFCreatureMgr::~NFCreatureMgr()
{
}

int NFCreatureMgr::CreateInit()
{
    m_creatureTickTimer = SetTimer(100, 0, 0, 0, 0, 0);
    return 0;
}

int NFCreatureMgr::ResumeInit()
{
    return 0;
}

NFCreature *NFCreatureMgr::GetCreature(uint64_t cid)
{
    NFCreature* pCreature = GetBattlePlayer(cid);
    if (pCreature == NULL)
    {
        /**
         * @brief iStrongType = 0 的时候， 需要查找NFShmObj之间继承关系， 只有NFCreature的子类才能获得对象
         */
        pCreature = dynamic_cast<NFCreature *>(FindModule<NFISharedMemModule>()->GetObjByGlobalId(EOT_GAME_CREATURE_ID, cid, true));
    }

    return pCreature;
}

NFCreature* NFCreatureMgr::CreateCreature(uint32_t kindType, uint64_t cid)
{
    NFCreature *pCreature = NULL;
    switch (kindType)
    {
        case CREATURE_PLAYER:
        {
            pCreature = FindModule<NFISharedMemModule>()->CreateObjByHashKey<NFBattlePlayer>(cid);
            if (pCreature == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, cid, "Create NFBattlePlayer failed! id:{} NFBattlePlayer: FreeCount:{} UseCount:{} ItemCount:{}", cid,
                           NFBattlePlayer::GetStaticFreeCount(m_pObjPluginManager), NFBattlePlayer::GetStaticUsedCount(m_pObjPluginManager),
                           NFBattlePlayer::GetStaticItemCount(m_pObjPluginManager))
            }

            NFCreature* pGetCreature = GetBattlePlayer(cid);
            NF_ASSERT_MSG(pGetCreature == pCreature, "pGetCreature != pCreature, id:{}", cid);

            pCreature->Init();
            break;
        }
        default:
            break;
    }

    return pCreature;
}

int NFCreatureMgr::DestroyCreature(NFCreature* pCreature)
{
    CHECK_NULL(pCreature);
    pCreature->UnInit();
    NFLogInfo(NF_LOG_SYSTEMLOG, pCreature->Cid(), "Destroy Creature, kind:{} cid:{} roleId:{} uid:{} ", pCreature->Kind(), pCreature->Cid(), pCreature->GetRoleId(), pCreature->GetUid());
    FindModule<NFISharedMemModule>()->DestroyObj(pCreature);
    return 0;
}

NFBattlePlayer* NFCreatureMgr::GetBattlePlayer(uint64_t cid)
{
    return FindModule<NFISharedMemModule>()->GetObjByHashKey<NFBattlePlayer>(cid);
}

int NFCreatureMgr::OnTimer(int timeId, int callcount)
{
    if (m_creatureTickTimer == timeId)
    {
        Update();
    }

    return 0;
}

int NFCreatureMgr::Update()
{
    uint64_t tick = NFTime::Now().UnixMSec();
    const std::unordered_set<int>& setKind = FindModule<NFISharedMemModule>()->GetChildrenType(EOT_GAME_CREATURE_ID);

    std::vector<uint64_t> willRemove;
    for(auto iter = setKind.begin(); iter != setKind.end(); iter++)
    {
        int type = *iter;
        NFCreature* pCreature = dynamic_cast<NFCreature *>(FindModule<NFISharedMemModule>()->GetHeadObj(type));
        while (pCreature)
        {
            pCreature->Update(tick);
            if (pCreature->Kind() == CREATURE_PLAYER)
            {
                NFBattlePlayer* pPlayer = dynamic_cast<NFBattlePlayer*>(pCreature);
                if (pPlayer)
                {
                    if (pPlayer->GetPlayerStatus() == proto_ff::PLAYER_STATUS_DEAD)
                    {
                        willRemove.push_back(pPlayer->Cid());
                    }
                }
            }
            pCreature = dynamic_cast<NFBattlePlayer *>(FindModule<NFISharedMemModule>()->GetNextObj(type, pCreature));
        }
    }

    for(int i = 0; i < (int)willRemove.size(); i++)
    {
        NFCreature* pCreature = GetCreature(willRemove[i]);
        if (pCreature)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, pCreature->Cid(), "Creature Cid:{} ClassName:{} be erase from memory", pCreature->Cid(), pCreature->GetClassName());
            DestroyCreature(pCreature);
        }
    }

    return 0;
}