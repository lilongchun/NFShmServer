//
// https://github.com/SteveKChiu/lua-intf
//
// Copyright 2014, Steve K. Chiu <steve.k.chiu@gmail.com>
//
// The MIT License (http://www.opensource.org/licenses/mit-license.php)
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

#ifndef LUACONTEXT_H
#define LUACONTEXT_H

//---------------------------------------------------------------------------

#include "LuaRef.h"
#include <string>
#include <map>
#include <list>

namespace LuaIntf
{

//---------------------------------------------------------------------------

/**
 * Lua state context
 *
 * Object representing an instance of Lua.
 */
class LuaContext
{
public:
    /**
     * Create a new Lua state
     *
     * @param needImportLibs - true if need to import the standard libraries.
     */
    explicit LuaContext(bool needImportLibs = true)
        : L(nullptr)
        , m_own(true)
    {
        L = luaL_newstate();
        if (!L) throw LuaException("can not allocate new lua state");

#if LUAINTF_LINK_LUA_COMPILED_IN_CXX
        lua_atpanic(L, panic);
#endif

        if (needImportLibs) {
            importLibs();
        }
    }

    /**
     * Create a new wrapper for an existing state
     *
     * Wraps an existing lua_State. The underlying state will not be closed when this object is destroyed.
     * This constructor is useful if your lua_State is not managed by your code.
     *
     * @param state lua_State object to wrap
     */
    explicit LuaContext(lua_State* state)
        : L(state)
        , m_own(false)
        {}

    /**
     * Lua state is closed if it is not wrapper for an existing state
     */
    ~LuaContext()
    {
        if (m_own) {
            lua_close(L);
        }
    }

    /**
     * Copy is not allowed
     */
    LuaContext(const LuaContext&) = delete;

    /**
     * Copy assignment is not allowed
     */
    LuaContext& operator = (const LuaContext&) = delete;

    /**
     * Implicit conversion for lua_State*
     */
    operator lua_State* () const
    {
        return L;
    }

    /**
     * get underlying lua_State
     */
    lua_State* state() const
    {
        return L;
    }

    /**
     * Import standard Lua libraries
     *
     * The standard Lua library is not available until this function is called.
     */
    void importLibs()
    {
        luaL_openlibs(L);
    }

    /**
     * Run a string of Lua
     *
     * @param code Lua code to execute
     * @throw LuaException for syntax errors and uncaught runtime errors
     */
    void doString(const char* code)
    {
        int err = luaL_dostring(L, code);
        if (err) throw LuaException(L);
    }

    /**
     * Run a Lua script, the path is probably not unicode friendly
     *
     * @param path Path to script file to execute
     * @throw LuaException for syntax errors and uncaught runtime errors
     */
    void doFile(const char* path)
    {
		std::string errString;
		for (auto str_ : filePath)
		{
			std::string tmp = str_;
			tmp += path;
			if (!luaL_dofile(L, tmp.c_str()))
			{
				return;
			}
			if (lua_gettop(L) > 0)
			{
				errString += lua_tostring(L, -1);
				errString += "/n";
				lua_pop(L, 1);
			}
		}

		if (!luaL_dofile(L, path))
		{
			return;
		}

		if (lua_gettop(L) > 0)
		{
			errString += lua_tostring(L, -1);
			lua_pop(L, 1);
		}

        throw LuaException(errString);
    }

    /**
     * Get global table (_G)
     */
    LuaRef globals() const
    {
        return LuaRef::globals(L);
    }

    /**
     * Get value from global variable
     */
    template <typename V = LuaRef>
    V getGlobal(const char* name) const
    {
        return Lua::getGlobal<V>(L, name);
    }

    /**
     * Set value of global variable
     */
    template <typename V>
    void setGlobal(const char* name, const V& v)
    {
        Lua::setGlobal(L, name, v);
    }

    /**
     * Get registry table
     */
    LuaRef registry() const
    {
        return LuaRef::registry(L);
    }

    /**
     * Access Lua garbage collection.
     * Defaults to collecting all garbage.
     */
    int gc(int what = LUA_GCCOLLECT, int data = 0)
    {
        return lua_gc(L, what, data);
    }
	/**
	* AddTrans the lua PackagePath
	*/
	bool addPackagePath(const std::string& str_)
	{
		std::string new_path = "package.path = package.path .. \"";
		std::string tmp = str_;
		if (str_.empty())
		{
			return false;
		}

		if (str_[0] != ';')
		{
			new_path += ";";
		}

		new_path += str_;

		if (str_[str_.length() - 1] != '/')
		{
			new_path += "/";
			tmp += "/";
		}

		new_path += "?.lua\" ";

		doString(new_path.c_str());
		filePath.push_back(tmp);
		return true;
	}

#if LUAINTF_LINK_LUA_COMPILED_IN_CXX
private:
    static int panic(lua_State* L)
    {
        throw LuaException(L);
    }
#endif

private:
	std::list<std::string> filePath;
    lua_State* L;
    bool m_own;
};

//---------------------------------------------------------------------------

}

#endif
