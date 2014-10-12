#include <iostream>

using namespace std;

template <typename T>
class MyClass
{
public:
	MyClass(const T& v): _val(v) {}

	//非成员模板
	//void Assign(const MyClass<T>& other)
	//{
	//	_val = other._val;
	//}

	//成员模板, 非const版本
	//template<typename X>
	//void Assign(MyClass<X>& other)
	//{
	//	_val = other.GetValue();
	//}

	//T& GetValue() {return _val;}

	//成员模板, const版本
	template<typename X>
	void Assign(const MyClass<X>& other)		// 参数定义成了const对象，所以它只能调用const函数。
	{
		_val = other.GetValue();
	}

	const T& GetValue() const {return _val;}	// 函数定义成了const函数，实际上将this指针所指向的内容const化，对象属性不可改变。
												// 所以_val const了，那么它的引用一定要const，所以函数返回值为const &
private:							
	T _val;
};

int main()
{
	MyClass<int> m1(10);
	MyClass<int> m3(20);
	MyClass<double> m2(1.1);

	//m1.Assign(m2);
	m1.Assign(m3);
	return 0;
}