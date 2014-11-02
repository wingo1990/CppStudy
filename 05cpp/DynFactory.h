#ifndef _DYNFACTORY_H_
#define _DYNFACTORY_H_

#include "Shape.h"
#include <map>
#include <string>
using namespace std;

typedef void* (*FUNC)();

class DynFactory
{
public:
	static void *CreateObject(const string &name)
	{
		map<string, FUNC>::const_iterator it;
		it = _mf.find(name);
		if (it == _mf.end())
			return 0;
		return it->second();
	}

	static void Register(const string &name, FUNC func)
	{
		_mf[name] = func;
	}

	//添加此代码实现资源的自动回收，似乎可以实现。
	//static void Destroy()
	//{
	//	map<string, FUNC>::const_iterator it;
	//	for (it = _mf.begin(), it != _mf.end(), ++it)
	//	{
	//		delete 
	//	}
	//	_mf.clear();
	//}
private:
	static map<string, FUNC> _mf;
};

map<string, FUNC> DynFactory::_mf;


//下面的实现方案有个严重的问题：
//在程序的执行顺序上有要求，按照顺序流程：必须是要求先注册，才能调用CreateObject函数。
//还可以更加灵活，让注册代码出现在任意地方都可以的。

//#define REGISTER_CLASS(ClassName) \
//class ClassName##Register{	\
//public: \
//	static void *NewInstance() \
//	{ \
//		return new ClassName; \
//	} \
//}; \
//DynFactory::Regist(#ClassName, ClassName##Register::NewInstance);

class RegisterMap
{
public:
	RegisterMap(const string &name, FUNC func)
	{
		DynFactory::Register(name, func);
	}
	~RegisterMap()
	{
		//在这里添加代码，似乎可以实现资源的自动回收。
	}
};

#define REGISTER_CLASS(ClassName)	\
class ClassName##Register{	\
public:	\
	static void *NewInstance()	\
	{	\
		return new ClassName;	\
	}	\
private:	\
static RegisterMap _reg;	\
};	\
RegisterMap ClassName##Register::_reg(#ClassName, ClassName##Register::NewInstance);

#endif //_DYNFACTORY_H_