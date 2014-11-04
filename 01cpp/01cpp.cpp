#include <iostream>
using namespace std;

int main(void)
{
	volatile const int a = 100;				// 在没有volatile的时候，C++采用的优化，用到a替换成100

	int *p = const_cast<int*>(&a);

	*p = 500;

	cout << "&a = "<<(int*)&a<<endl;
	cout << "p = " <<p<<endl;

	cout <<"a1 = "<<a<<endl;				//a 用volatile 修饰打印的就一样了,可以保证a是存内存中读，不是从符号表中读取。
	cout <<"a2 = "<<*(int*)&a<<endl;
	cout <<"*p = "<<*p<<endl;

	//下面这个例子是合理的，而上面的则是不合理的，其具体原因是：
	//const_cast其要转换的对象时指针和引用才有意义。

	//指针
	const int *b = new int(100);
	int *q = const_cast<int*>(b);

	*q = 200;
	cout << "b= "<< b <<endl;
	cout << "q= "<< q <<endl;

	cout <<"*b="<<*b <<endl;
	cout <<"*q="<<*q <<endl;

	//引用
	volatile const int i = 100;
	int &j = const_cast<int &>(i);
	cout << "before &i = " << (int*)&i <<endl;
	cout << "befoer &j = " << &j <<endl;

	j = 200;

	cout << "after &i = " << (int*)&i <<endl;
	cout << "after &j = " << &j <<endl;

	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
 


	//自定义
	class MyClass
	{
	public:
		int a;
		double b;
		MyClass(int a1, double b1): a(a1), b(b1){}
	};

	const MyClass aa(1,2.5);
	MyClass &bb = const_cast<MyClass &>(aa);

	cout<< "before &aa = " << &aa << endl;
	cout<< "before &bb = " << &bb << endl;

	bb.a = 100;
	bb.b = 25.5;

	cout<< "after &aa = " << &aa << endl;
	cout<< "after &bb = " << &bb << endl;

	cout << "aa.a = " << aa.a << endl;
	cout << "aa.b = " << aa.b << endl;
	cout << "bb.a = " << bb.a << endl;
	cout << "bb.b = " << bb.b << endl;
	
	return 0;
}
