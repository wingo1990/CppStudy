#include <iostream>

using namespace std;

template <typename T>
class MyClass
{
public:
	void Dispalay()
	{
		cout << ss << endl;
	}

	typename T::SubType ss;			// 定义类下面的类型时，需要加typename关键字。
};

class Test
{
public:
	typedef int SubType;

};

int main()
{
	MyClass<Test> tt;
	tt.ss = 100;
	tt.Dispalay();
}