// -------------------------------------------------------------------------
//    @FileName         :    NFAttr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFAttr
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Com.pb.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include <unordered_map>

#pragma pack(push)
#pragma pack(1)

//通用 战斗属性结束ID
const uint32_t COMMON_FIGHT_ATTR_END = 73;
//通用 战斗属性组结束ID
const uint32_t COMMON_FIGHT_ATTR_GROUP_END = 4;

//通用 普通属性结束ID
const uint32_t COMMON_ATTR_END = 20;

//角色 战斗属性结束ID
const uint32_t ROLE_FIGHT_ATTR_END = 131;
//角色 战斗属性 结束组ID
const uint32_t ROLE_FIGHT_ATTR_GROUP_END = (uint32_t) proto_ff::EAttrGroup_ARRAYSIZE;

//角色 普通属性结束ID
const uint32_t ROLE_ATTR_END = 200;

//属性类型
enum class EAttrType
{
    none = 0,        //无
    common = 1,        //通用属性
    role = 2,        //角色属性
};

class IFightAttr : public NFShmObj
{
public:
    virtual ~IFightAttr() {}
    
    virtual EAttrType GetType() { return EAttrType::none; }
    
    //是否有效的战斗属性ID
    virtual bool ValidAttr(uint32_t ANum) = 0;
    
    //是否是有效的属性数组索引
    virtual bool ValidIndex(uint8_t index) = 0;
    
    //是否是有效的战斗属性组ID
    virtual bool ValidAttrGroup(uint32_t groupid) = 0;
    
    //获取总属性值
    virtual int64_t GetAttr(uint32_t ANum) = 0;
    
    //获取所有的总属性
    virtual void GetAttr(MAP_UINT32_INT64 &mapattr) = 0;
    
    //获取属性组的总属性(所有属性组属性之和)
    virtual void GetAttrGroupTotal(MAP_UINT32_INT64 &mapattr) = 0;
    
    //计算总属性值
    virtual void CalcAttr(MAP_UINT32_INT64 &mapchg) = 0;
    
    //计算指定ID的总属性值
    virtual bool CalcAttr(uint32_t ANum, MAP_UINT32_INT64 &mapchg) = 0;
    
    //获取指定属性组中指定ID的属性值
    virtual int64_t GetAttrGroup(uint32_t groupid, uint32_t ANum) = 0;
    
    //获取指定属性组中所有的属性值
    virtual bool GetAttrGroup(uint32_t groupid, MAP_UINT32_INT64 &mapattr) = 0;
    
    //增加指定属性组中指定ID的属性值
    virtual bool AddAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag = nullptr) = 0;
    
    //设置指定属性组中指定ID的属性值
    virtual bool SetAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag = nullptr) = 0;
    
    //设置指定属性组中所有ID的属性值
    virtual bool SetAttrGroup(uint32_t groupid, const MAP_UINT32_INT64 &mapnew, MAP_UINT32_INT64 *pold = nullptr) = 0;
    
    //清空指定属性组的属性值
    virtual bool ClearAttrGroup(uint32_t groupid, MAP_UINT32_INT64 *pold = nullptr) = 0;
    
    //获取计算战力的属性值
    virtual void GetFightAttr(MAP_UINT32_INT64 &mapattr) = 0;
    
    //获取计算战力的标记
    virtual bool GetFightChg() = 0;
    
    //清除计算战力的标记
    virtual void ClearFightChg() = 0;
    
    //总属性是否锁定
    virtual bool IsLock() = 0;
    //锁定总属性
    virtual bool Lock(const MAP_UINT32_INT64 &mapattr, MAP_UINT32_INT64 &mapchg) = 0;
    //解锁总属性
    virtual bool UnLock(MAP_UINT32_INT64 &mapchg) = 0;
};

//通用战斗属性
class ComFightAttr : public NFShmObjTemplate<ComFightAttr, EOT_SERVER_COMMON_COMFIGHT_ATTR_ID, IFightAttr>
{
public:
    ComFightAttr();
    
    virtual ~ComFightAttr();
    
    int CreateInit();
    
    int ResumeInit();

public:
    virtual EAttrType GetType() { return EAttrType::common; }
    
    virtual bool ValidAttr(uint32_t ANum) override;
    
    virtual bool ValidAttrGroup(uint32_t groupid) override;
    
    virtual bool ValidIndex(uint8_t index) override;
    
    virtual int64_t GetAttr(uint32_t ANum) override;
    
    virtual void GetAttr(MAP_UINT32_INT64 &mapattr) override;
    
    virtual void GetAttrGroupTotal(MAP_UINT32_INT64 &mapattr) override;
    
    virtual void CalcAttr(MAP_UINT32_INT64 &mapchg) override;
    
    virtual bool CalcAttr(uint32_t ANum, MAP_UINT32_INT64 &mapchg) override;
    
    virtual int64_t GetAttrGroup(uint32_t groupid, uint32_t ANum) override;
    
    virtual bool GetAttrGroup(uint32_t groupid, MAP_UINT32_INT64 &mapattr) override;
    
    virtual bool AddAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag = nullptr) override;
    
    virtual bool SetAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag = nullptr) override;
    
    virtual bool SetAttrGroup(uint32_t groupid, const MAP_UINT32_INT64 &mapnew, MAP_UINT32_INT64 *pold = nullptr) override;
    
    virtual bool ClearAttrGroup(uint32_t groupid, MAP_UINT32_INT64 *pold = nullptr) override;
    
    virtual void GetFightAttr(MAP_UINT32_INT64 &mapattr) {}
    
    virtual bool GetFightChg() { return false; }
    
    virtual void ClearFightChg() {};
    
    //
    virtual bool IsLock() { return false; }
    virtual bool Lock(const MAP_UINT32_INT64 &mapattr, MAP_UINT32_INT64 &mapchg) { return false; }
    virtual bool UnLock(MAP_UINT32_INT64 &mapchg) { return false; }
private:
    //战斗属性, ID为0的属性组表示总属性
    int64_t m_attr[COMMON_FIGHT_ATTR_GROUP_END][COMMON_FIGHT_ATTR_END];
};

//角色战斗属性
class RoleFightAttr : public NFShmObjTemplate<RoleFightAttr, EOT_SERVER_COMMON_ROLEFIGHT_ATTR_ID, IFightAttr>
{
public:
    RoleFightAttr();
    
    virtual ~RoleFightAttr();
    
    int CreateInit();
    
    int ResumeInit();
    
    virtual EAttrType GetType() { return EAttrType::role; }
    
    virtual bool ValidAttr(uint32_t ANum) override;
    
    virtual bool ValidIndex(uint8_t index) override;
    
    virtual bool ValidAttrGroup(uint32_t groupid) override;
    
    virtual int64_t GetAttr(uint32_t ANum) override;
    
    virtual void GetAttr(std::unordered_map<uint32_t, int64_t> &mapattr) override;
    
    virtual void CalcAttr(MAP_UINT32_INT64 &mapchg) override;
    
    virtual void GetAttrGroupTotal(MAP_UINT32_INT64 &mapattr) override;
    
    virtual bool CalcAttr(uint32_t ANum, MAP_UINT32_INT64 &mapchg) override;
    
    virtual int64_t GetAttrGroup(uint32_t groupid, uint32_t ANum) override;
    
    virtual bool GetAttrGroup(uint32_t groupid, MAP_UINT32_INT64 &mapattr) override;;
    
    virtual bool AddAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag = nullptr) override;
    
    virtual bool SetAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag = nullptr) override;
    
    virtual bool SetAttrGroup(uint32_t groupid, const MAP_UINT32_INT64 &mapnew, MAP_UINT32_INT64 *pold = nullptr) override;
    
    virtual bool ClearAttrGroup(uint32_t groupid, MAP_UINT32_INT64 *pold = nullptr) override;
    
    virtual void GetFightAttr(MAP_UINT32_INT64 &mapattr) override;
    
    virtual bool GetFightChg() { return m_fightchg; }
    
    virtual void ClearFightChg() { m_fightchg = false; }
    
    virtual bool IsLock() { return m_lock; }
    virtual bool Lock(const MAP_UINT32_INT64 &mapattr, MAP_UINT32_INT64 &mapchg);
    virtual bool UnLock(MAP_UINT32_INT64 &mapchg);
private:
    bool IsFightAttrGroup(uint32_t groupid);
    int64_t GetAttrGroupTotal(uint32_t ANum);
    int64_t GetCalcFightAttrGroupTotal(uint32_t ANum);
    void GetAttrGroupTotal(uint32_t ANum, int64_t &attrval, int64_t &fightval);
private:
    //战斗属性, ID为0的属性组表示总属性
    int64_t m_attr[ROLE_FIGHT_ATTR_GROUP_END][ROLE_FIGHT_ATTR_END];
    //用于计算战力的属性
    int64_t m_fightattr[ROLE_FIGHT_ATTR_END];
    //计算战力属性是否有改变
    bool m_fightchg;
    //是否锁定总属性
    bool m_lock = false;
};

class IAttr : public NFShmObj
{
public:
    virtual ~IAttr() {};
    
    virtual EAttrType GetType() { return EAttrType::none; }
    
    //是否有效的属性ID
    virtual bool ValidAttr(uint32_t ANum) = 0;
    
    //是否是有效的属性数组索引
    virtual bool ValidIndex(uint16_t index) = 0;
    
    //获取属性值
    virtual int64_t GetAttr(uint32_t ANum) = 0;
    
    //增加属性值
    virtual bool AddAttr(uint32_t ANum, int64_t val, bool *chgflag = nullptr) = 0;
    
    //设置属性值
    virtual bool SetAttr(uint32_t ANum, int64_t val, bool *chgflag = nullptr) = 0;
};

//通用属性
class ComAttr : public NFShmObjTemplate<ComAttr, EOT_SERVER_COMMON_COM_ATTR_ID, IAttr>
{
public:
    ComAttr();
    
    virtual ~ComAttr();
    
    int CreateInit();
    
    int ResumeInit();
    
    virtual EAttrType GetType() { return EAttrType::common; }
    
    virtual bool ValidAttr(uint32_t ANum);
    
    virtual bool ValidIndex(uint16_t index);
    
    virtual int64_t GetAttr(uint32_t ANum);
    
    virtual bool AddAttr(uint32_t ANum, int64_t val, bool *chgflag = nullptr);
    
    virtual bool SetAttr(uint32_t ANum, int64_t val, bool *chgflag = nullptr);

private:
    int64_t m_attr[COMMON_ATTR_END];
};

//角色属性
class RoleAttr : public NFShmObjTemplate<RoleAttr, EOT_SERVER_COMMON_ROLE_ATTR_ID, IAttr>
{
public:
    RoleAttr();
    
    virtual ~RoleAttr();
    
    int CreateInit();
    
    int ResumeInit();
    
    virtual EAttrType GetType() { return EAttrType::role; }
    
    virtual bool ValidAttr(uint32_t ANum);
    
    virtual bool ValidIndex(uint16_t index);
    
    virtual int64_t GetAttr(uint32_t ANum);
    
    virtual bool AddAttr(uint32_t ANum, int64_t val, bool *chgflag = nullptr);
    
    virtual bool SetAttr(uint32_t ANum, int64_t val, bool *chgflag = nullptr);

private:
    int64_t m_attr[ROLE_ATTR_END];
};

#pragma pack(pop)