// -------------------------------------------------------------------------
//    @FileName         :    NFILuaModule.h
//    @Author           :    GaoYi
//    @Date             :    2018/05/25
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#define LUAINTF_LINK_LUA_COMPILED_IN_CXX 0
#include "LuaBind/luaintf/LuaIntf.h"
#include "NFComm/NFCore/NFPlatform.h"
#include <iostream>
#include <vector>
#include <map>

namespace LuaIntf
{
	LUA_USING_SHARED_PTR_TYPE(std::shared_ptr);
	LUA_USING_LIST_TYPE(std::vector);
	LUA_USING_MAP_TYPE(std::map);
}

typedef LuaIntf::LuaRef NFLuaRef;
typedef LuaIntf::LuaTableRef NFLuaTableRef;

class NFILuaLoader
{
public:
	NFILuaLoader()
	{
		m_pLuaContext = nullptr;
		CreateLuaContext();
	}

	virtual ~NFILuaLoader()
	{
		if (m_pLuaContext)
		{
			NF_SAFE_DELETE(m_pLuaContext);
		}
	}

	void CreateLuaContext()
	{
		if (m_pLuaContext)
		{
			NF_SAFE_DELETE(m_pLuaContext);
		}
		m_pLuaContext = NF_NEW LuaIntf::LuaContext();
	}

	lua_State* GetLuaState() const
	{
		return m_pLuaContext->state();
	}

	LuaIntf::LuaContext* GetLuaContext()
	{
		return m_pLuaContext;
	}
public:
	template <typename V = LuaIntf::LuaRef>
	V GetGlobal(const std::string& keyName) const
	{
		return  m_pLuaContext->getGlobal(keyName.c_str());
	}

	template <typename T>
	bool GetValue(const std::string& keyName, T& value) const
	{
		LuaIntf::LuaRef ref = GetGlobal(keyName);
		if (ref == nullptr)
		{
			return false;
		}

		try
		{
			value = ref.toValue<T>();
			return true;
		}
		catch (LuaIntf::LuaException& e)
		{
			std::cout << e.what() << std::endl;
		}

		return true;
	}

public:
	bool TryLoadScriptString(const std::string& strScript)
	{
		try
		{
			m_pLuaContext->doString(strScript.c_str());
			return true;
		}
		catch (LuaIntf::LuaException& e)
		{
			std::cout << e.what() << std::endl;
		}
		return false;
	}

	bool TryLoadScriptFile(const std::string& strFileName)
	{
		try
		{
			m_pLuaContext->doFile(strFileName.c_str());
			return true;
		}
		catch (LuaIntf::LuaException& e)
		{
			std::cout << e.what() << std::endl;
		}
		return false;
	}

	bool TryAddPackagePath(const std::string& strFilePath)
	{
		try
		{
			m_pLuaContext->addPackagePath(strFilePath);
			return true;
		}
		catch (LuaIntf::LuaException& e)
		{
			std::cout << e.what() << std::endl;
		}
		return false;
	}

public:
	template <typename... Arg>
    LuaIntf::LuaRef TryRunGlobalScriptFunc(const std::string& strFuncName, Arg&&... args)
	{
		try
		{
			LuaIntf::LuaRef func(*m_pLuaContext, strFuncName.c_str());
            LuaIntf::LuaRef result = func.call<LuaIntf::LuaRef>(std::forward<Arg>(args)...);
			return result;
		}
		catch (LuaIntf::LuaException& e)
		{
			std::cout << e.what() << std::endl;
		}
		return LuaIntf::LuaRef();
	}

public:
	template <typename KEY, typename VALUE>
	static bool GetLuaTableValue(const LuaIntf::LuaRef& table, const KEY& keyName, VALUE& value)
	{
		try
		{
			LuaIntf::LuaRef valueRef = table[keyName];
			if (valueRef == nullptr)
			{
				//std::cout << "load lua table " << keyName << " failed!" << std::endl;
				return false;
			}

			value = valueRef.toValue<VALUE>();
			return true;
		}
		catch (LuaIntf::LuaException& e)
		{
			std::cout << e.what() << std::endl;
		}
		return false;
	}
protected:
	LuaIntf::LuaContext* m_pLuaContext;
};

