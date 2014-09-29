#include <iostream>
using namespace std;

int main(void)
{
	const volatile int a = 100;				// ��û��volatile��ʱ��C++���õ��Ż����õ�a�滻��100

	int *p = const_cast<int*>(&a);

	*p = 200;

	cout << "&a = "<<&a<<endl;
	cout << "p = " <<p<<endl;

	cout <<"a1 = "<<a<<endl;				//a ��volatile ���δ�ӡ�ľ�һ���ˣ�
	cout <<"a2 = "<<*(int*)&a<<endl;
	cout <<"*p = "<<*p<<endl;

	//������������Ǻ���ģ�����������ǲ�����ģ������ԭ���ǣ�
	//const_cast��Ҫת���Ķ���ʱָ������ò������塣

	const int *b = new int(100);
	int *q = const_cast<int*>(b);

	*q = 200;
	cout << "b= "<< b <<endl;
	cout << "q= "<< q <<endl;

	cout <<"*b="<<*b <<endl;
	cout <<"*q="<<*q <<endl;

	return 0;
}