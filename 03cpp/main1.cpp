#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if (NULL == _instance)
		{
			_instance = new Singleton;
		}

		return _instance;
	}

	static void Free()
	{
		if (NULL != _instance)
		{
			delete _instance;
		}
		_instance = 0;
	}

private:
	Singleton()
	{
		cout << "Singleton() ..." << endl;
	}

	~Singleton()
	{
		cout << "~Singleton() ..." << endl;
	}

	Singleton(const Singleton &other);
	Singleton &operator=(const Singleton &other);

	static Singleton *_instance;
};

Singleton *Singleton::_instance = 0;

int main(void)
{
	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();
	//Singleton s3(*s1);

	Singleton::Free();

	return 0;
}