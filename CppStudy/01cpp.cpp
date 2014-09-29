#include <iostream>
using namespace std;

int main(void)
{
	const int a = 100;

	int *p = const_cast<int*>(&a);

	*p = 200;

	cout << "&a = "<<&a<<endl;
	cout << "p = " <<p<<endl;

	cout <<"a = "<<a<<endl;
	cout <<"*p = "<<*p<<endl;

	return 0;
}