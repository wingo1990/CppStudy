#include <iostream>
#include <memory>
using namespace std;

class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if (!_Instance.get())
		{
			_Instance = auto_ptr<Singleton>(new Singleton);	//构造函数+赋值运算符(浅拷贝)
		}
		
		return _Instance.get();								//返回new Singleton 的指针
	}

	~Singleton()
	{
		cout << "~Singleton..."<< endl;
	}
private:
	//禁止拷贝
	Singleton(const Singleton &other){}
	Singleton& operator=(const Singleton&){}
	
	//默认构造函数私有，不能任意的实例对象
	Singleton()
	{
		cout << "Singleton..." << endl;
	}

static auto_ptr<Singleton> _Instance;
};

auto_ptr<Singleton> Singleton::_Instance;

int main(void)
{
	Singleton *t = Singleton::GetInstance();
	Singleton *t1 = Singleton::GetInstance();

	cout << t << endl;				// 实例地址相同
	cout << t1 << endl;

	//t2 = t;
}