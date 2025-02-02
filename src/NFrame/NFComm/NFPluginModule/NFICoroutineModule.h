// -------------------------------------------------------------------------
//    @FileName         :    NFICoroutineModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFICoroutineModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFIRpcService.h"
#include "NFITimerEventModule.h"

class NFCoroutineTask;

#ifdef Yield
#undef Yield
#endif



class NFICoroutineModule : public NFITimerEventModule {
public:
    NFICoroutineModule(NFIPluginManager *p) : NFITimerEventModule(p) {

    }

    virtual ~NFICoroutineModule() {

    }

    virtual int64_t MakeCoroutine(const std::function<void()> &func, bool is_immediately = true) = 0;

    /// @brief 启动该协程任务, 执行Run方法
    /// @param is_immediately 是否立即执行
    /// @return 返回协程ID
    virtual int64_t Start(NFCoroutineTask *pTask, bool is_immediately = true) = 0;

    virtual int DeleteTask(NFCoroutineTask *pTask) = 0;

    virtual int AddTask(NFCoroutineTask *pTask) = 0;

    /// @brief 返回当前协程数量
    /// @return 当前的协程数量
    virtual int Size() const = 0;

    /// @brief 获取当前正在运行的协程任务
    /// @return 正在运行的协程任务对象的指针
    /// @note 此函数必须在协程中调用
    virtual NFCoroutineTask *CurrentTask() const = 0;

    /// @brief 获取当前正在运行的协程ID
    /// @reurn 正在运行的协程ID
    /// @note 此函数必须在协程中调用
    virtual int64_t CurrentTaskId() const = 0;

    /**
     * @brief 当前是否在携程中
     * @return
     */
    virtual bool IsInCoroutine() const = 0;

    /// @brief 挂起当前协程
    /// @param timeout_ms 超时时间，单位为毫秒，默认-1，<=0时表示不进行超时处理
    /// @return 处理结果，@see CoroutineErrorCode
    /// @note 此函数必须在协程中调用
    virtual int32_t Yield(int32_t timeout_ms = -1) = 0;

    /// @brief 激活指定ID的协程
    /// @param id 协程ID
    /// @param result resume时可传递结果，默认为0
    /// @return 处理结果，@see CoroutineErrorCode
    virtual int32_t Resume(int64_t id, int32_t result = 0) = 0;

    /// @brief 返回指定id协程的状态
    /// @param id 协程ID
    /// @return 协程状态
    virtual int Status(int64_t id) = 0;

    virtual google::protobuf::Message *GetUserData(int64_t id) = 0;
    virtual int SetUserData(google::protobuf::Message *pUserData) = 0;

    /**
     * @brief 添加玩家的协程ID
     * @param id
     * @return
     */
    virtual int AddUserCo(uint64_t userId) = 0;

    /**
     * @brief 减少玩家的协程ID
     * @param id
     * @return
     */
    virtual int DelUserCo(uint64_t userId) = 0;

    /**
     * @brief 玩家是否还有携程在运行
     * @param userId
     * @return
     */
    virtual bool IsExistUserCo(uint64_t userId) = 0;

    /**
     * @brief 协程是否存在，是否已经死亡
     * @return
     */
    virtual bool IsDead(int64_t id) = 0;

    /**
     * @brief 是否正在运行
     * @return
     */
    virtual bool IsRunning(int64_t id) = 0;

    /**
     * @brief 是否协程正在挂起
     * @return
     */
    virtual bool IsYielding(int64_t id) = 0;
};