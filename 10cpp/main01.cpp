#include <iostream>

using namespace std;

template <typename T>
const T& Max(const T& a, const T& b)
{
	return a<b?b:a;
}

class MyClass
{
public:
	//bool operator<(const MyClass& other) 
	//{
	//	return true;
	//}
	// 这种成员函数的定义不可，需要用有友元函数才可。
	friend bool operator<(const MyClass& c1, const MyClass& c2);
};

bool operator<(const MyClass& c1, const MyClass& c2)
{
	return true;
}
int main()
{
	cout << Max(5.55, 6.66) << endl;
	cout << Max('a', 'z') << endl;
	
	MyClass m1;
	MyClass m2;
	Max(m1, m2);
	return 0;
}
