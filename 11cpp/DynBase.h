#ifndef _DYNBASE_H_
#define _DYNBASE_H_

#include <map>
#include <string>

#include "ElementType.h"

typedef void* (*CREATE_FUNC)();

class DynBase
{
public:
	static void *CreateObject(const std::string &name)
	{
		std::map<std::string, CREATE_FUNC>::const_iterator it;
		it = _mf.find(name);
		if (it == _mf.end())
			return NULL;
		return it->second();
	}

	static void Regist(const std::string &name, CREATE_FUNC func)
	{
		_mf[name] = func;
	}

private:
	static std::map<std::string, CREATE_FUNC> _mf;
};

std::map<std::string, CREATE_FUNC> DynBase::_mf;

template <typename T>
class Delegator
{
public:
	Delegator(const std::string& classname)
	{
		DynBase::Regist(classname, &Delegator::NewInstance);
	}

	static void *NewInstance()
	{
		return new T;
	}
};

#define  REGISTER_CLASS(classname) Delegator<classname> class##classname(#classname)

#endif //_DYNBASE_H_