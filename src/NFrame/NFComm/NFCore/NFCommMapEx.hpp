// -------------------------------------------------------------------------
//    @FileName         :    NFMapEx.h
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//
// -------------------------------------------------------------------------

#pragma once

#include <map>
#include <list>
#include <string>
#include <iostream>
#include <typeinfo>
#include <memory>
#include "NFPlatform.h"
#include "NFConsistentHash.hpp"

template <typename T, typename TD>
class NFCommMapEx
{
public:
	typedef std::map<T, NF_SHARE_PTR<TD> > NFMapOBJECT;

	NFCommMapEx()
	{
	};
	virtual ~NFCommMapEx()
	{
	};

	virtual bool ExistElement(const T& name)
	{
		typename NFMapOBJECT::iterator itr = mObjectList.find(name);
		if (itr != mObjectList.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	/*
	virtual NF_SHARE_PTR<TD> AddElement(const T& name)
	{
	typename NFMapOBJECT::iterator itr = mObjectList.find(name);
	if (itr == mObjectList.end())
	{
	NF_SHARE_PTR<TD> data(NF_NEW TD());
	mObjectList.insert(typename NFMapOBJECT::value_type(name, data));
	return data;
	}

	return NF_SHARE_PTR<TD>();
	}
	*/
	virtual bool AddElement(const T& name, const NF_SHARE_PTR<TD> data)
	{
		if (data == nullptr)
		{
			std::cout << "AddElement failed : " << std::endl;
			return false;
		}

		typename NFMapOBJECT::iterator itr = mObjectList.find(name);
		if (itr == mObjectList.end())
		{
			mObjectList.insert(typename NFMapOBJECT::value_type(name, data));

			return true;
		}

		return false;
	}

	virtual bool RemoveElement(const T& name)
	{
		typename NFMapOBJECT::iterator itr = mObjectList.find(name);
		if (itr != mObjectList.end())
		{
			mObjectList.erase(itr);

			return true;
		}

		return false;
	}

	virtual TD* GetElementNude(const T& name)
	{
		typename NFMapOBJECT::iterator itr = mObjectList.find(name);
		if (itr != mObjectList.end())
		{
			return itr->second.get();
		}
		else
		{
			return NULL;
		}
	}

	virtual NF_SHARE_PTR<TD> GetElement(const T& name)
	{
		typename NFMapOBJECT::iterator itr = mObjectList.find(name);
		if (itr != mObjectList.end())
		{
			return itr->second;
		}
		else
		{
			return nullptr;
		}
	}

	virtual TD* FirstNude(T& name)
	{
		if (mObjectList.size() <= 0)
		{
			return NULL;
		}

		mObjectCurIter = mObjectList.begin();
		if (mObjectCurIter != mObjectList.end())
		{
			name = mObjectCurIter->first;
			return mObjectCurIter->second.get();
		}
		else
		{
			return NULL;
		}
	}

	virtual TD* NextNude(T& name)
	{
		if (mObjectCurIter == mObjectList.end())
		{
			return NULL;
		}

		mObjectCurIter++;
		if (mObjectCurIter != mObjectList.end())
		{
			name = mObjectCurIter->first;
			return mObjectCurIter->second.get();
		}
		else
		{
			return NULL;
		}
	}
	virtual TD* FirstNude()
	{
		if (mObjectList.size() <= 0)
		{
			return NULL;
		}

		mObjectCurIter = mObjectList.begin();
		if (mObjectCurIter != mObjectList.end())
		{
			return mObjectCurIter->second.get();
		}
		else
		{
			return NULL;
		}
	}
	virtual TD* NextNude()
	{
		if (mObjectCurIter == mObjectList.end())
		{
			return NULL;
		}

		mObjectCurIter++;
		if (mObjectCurIter != mObjectList.end())
		{
			return mObjectCurIter->second.get();
		}
		else
		{
			return NULL;
		}
	}

	virtual NF_SHARE_PTR<TD> First()
	{
		if (mObjectList.size() <= 0)
		{
			return nullptr;
		}

		mObjectCurIter = mObjectList.begin();
		if (mObjectCurIter != mObjectList.end())
		{
			return mObjectCurIter->second;
		}
		else
		{
			return nullptr;
		}
	}

	virtual NF_SHARE_PTR<TD> Next()
	{
		if (mObjectCurIter == mObjectList.end())
		{
			return nullptr;
		}

		++mObjectCurIter;
		if (mObjectCurIter != mObjectList.end())
		{
			return mObjectCurIter->second;
		}
		else
		{
			return nullptr;
		}
	}

	virtual NF_SHARE_PTR<TD> First(T& name)
	{
		if (mObjectList.size() <= 0)
		{
			return nullptr;
		}

		mObjectCurIter = mObjectList.begin();
		if (mObjectCurIter != mObjectList.end())
		{
			name = mObjectCurIter->first;
			return mObjectCurIter->second;
		}
		else
		{
			return nullptr;
		}
	}

	virtual NF_SHARE_PTR<TD> Next(T& name)
	{
		if (mObjectCurIter == mObjectList.end())
		{
			return nullptr;
		}

		mObjectCurIter++;
		if (mObjectCurIter != mObjectList.end())
		{
			name = mObjectCurIter->first;
			return mObjectCurIter->second;
		}
		else
		{
			return nullptr;
		}
	}

	virtual bool ClearAll()
	{
		mObjectList.clear();
		return true;
	}

	int Count()
	{
		return (int)mObjectList.size();
	}

    typename NFMapOBJECT::iterator Begin()
    {
	    return mObjectList.begin();
    }

    typename NFMapOBJECT::iterator End()
    {
        return mObjectList.end();
    }
protected:
	NFMapOBJECT     mObjectList;
	typename NFMapOBJECT::iterator mObjectCurIter;
};

template <typename T, typename TD>
class NFConsistentCommMapEx : public NFCommMapEx<T, TD>
{
public:
	virtual NF_SHARE_PTR<TD> GetElementBySuitRandom()
	{
		NFVirtualNode<T> vNode;
		if (mxConsistentHash.GetSuitNodeRandom(vNode))
		{
			typename NFCommMapEx<T, TD>::NFMapOBJECT::iterator itr = NFCommMapEx<T, TD>::mObjectList.find(vNode.mxData);
			if (itr != NFCommMapEx<T, TD>::mObjectList.end())
			{
				return itr->second;
			}
		}

		return NULL;
	}

	virtual NF_SHARE_PTR<TD> GetElementBySuitConsistent()
	{
		NFVirtualNode<T> vNode;
		if (mxConsistentHash.GetSuitNodeConsistent(vNode))
		{
			typename NFCommMapEx<T, TD>::NFMapOBJECT::iterator itr = NFCommMapEx<T, TD>::mObjectList.find(vNode.mxData);
			if (itr != NFCommMapEx<T, TD>::mObjectList.end())
			{
				return itr->second;
			}
		}

		return NULL;
	}

	virtual NF_SHARE_PTR<TD> GetElementBySuit(const T& name)
	{
		NFVirtualNode<T> vNode;
		if (mxConsistentHash.GetSuitNode(name, vNode))
		{
			typename NFCommMapEx<T, TD>::NFMapOBJECT::iterator itr = NFCommMapEx<T, TD>::mObjectList.find(vNode.mxData);
			if (itr != NFCommMapEx<T, TD>::mObjectList.end())
			{
				return itr->second;
			}
		}

		return NULL;
	}

	template<typename TX>
    NF_SHARE_PTR<TD> GetElementBySuit(const TX& name)
    {
        NFVirtualNode<T> vNode;
        if (mxConsistentHash.GetSuitNode(name, vNode))
        {
            typename NFCommMapEx<T, TD>::NFMapOBJECT::iterator itr = NFCommMapEx<T, TD>::mObjectList.find(vNode.mxData);
            if (itr != NFCommMapEx<T, TD>::mObjectList.end())
            {
                return itr->second;
            }
        }

        return NULL;
    }

	virtual bool AddElement(const T& name, const NF_SHARE_PTR<TD> data) override
	{
		if (data == nullptr)
		{
			return false;
		}

		typename NFCommMapEx<T, TD>::NFMapOBJECT::iterator itr = NFCommMapEx<T, TD>::mObjectList.find(name);
		if (itr == NFCommMapEx<T, TD>::mObjectList.end())
		{
			NFCommMapEx<T, TD>::mObjectList.insert(typename NFCommMapEx<T, TD>::NFMapOBJECT::value_type(name, data));

			mxConsistentHash.Insert(name);

			return true;
		}

		return false;
	}

	virtual bool RemoveElement(const T& name) override
	{
		typename NFCommMapEx<T, TD>::NFMapOBJECT::iterator itr = NFCommMapEx<T, TD>::mObjectList.find(name);
		if (itr != NFCommMapEx<T, TD>::mObjectList.end())
		{
			NFCommMapEx<T, TD>::mObjectList.erase(itr);
			mxConsistentHash.Erase(name);

			return true;
		}

		return false;
	}

	virtual bool ClearAll() override
	{
		NFCommMapEx<T, TD>::mObjectList.clear();
		mxConsistentHash.ClearAll();
		return true;
	}

private:
	NFConsistentHash<T> mxConsistentHash;
};
