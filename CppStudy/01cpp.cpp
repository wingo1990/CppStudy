#include <iostream>
using namespace std;

int main(void)
{
	const volatile int a = 100;

	int *p = const_cast<int*>(&a);

	*p = 200;

//	cout << "&a = "<<&a<<endl;
//	cout << "p = " <<p<<endl;

	cout <<"a1 = "<<a<<endl;				//a 用volatile 修饰打印的就一样了？
	cout <<"a2 = "<<*(int*)&a<<endl;
	cout <<"*p = "<<*p<<endl;

	//下面这个例子是合理的，而上面的则是不合理的，其具体原因是：
	//const_cast其要转换的对象时指针和引用才有意义。

	const int *b = new int(100);
	int *q = const_cast<int*>(b);

	*q = 200;
	cout << b << q <<endl;
	cout <<*b <<*q <<endl;


	return 0;
}