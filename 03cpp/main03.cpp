#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton &GetInstance()
	{
	    static Singleton _instance;
		return _instance;
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
};

int main(void)
{
	Singleton& s1 = Singleton::GetInstance();
	Singleton& s2 = Singleton::GetInstance();
	//Singleton s3(*s1);

	//Singleton::Free();

	return 0;
}