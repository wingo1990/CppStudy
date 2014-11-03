#include <iostream>
using namespace std;

#define sizeof_v(x)  ((char*)(&x+1) - (char*)&x )		//变量大小
#define sizeof_t(X)  (size_t)((X*)0 + 1 )				//类型大小
								
#define ALIGN(v, b)  ((v+b-1) & ~(b-1))				//对齐，对于内存池很有用 

int main(void)
{
	double d;
	int i;
	struct {int j; int k;} sttt;

	cout << sizeof_v(sttt) << endl;
	cout << sizeof_v(d) << endl;
	cout << sizeof_v(i) << endl;

	cout << sizeof_t(int) << endl;
	cout << sizeof_t(double) <<endl;

	cout << ALIGN(4,4096) << endl;


	return 0;
}