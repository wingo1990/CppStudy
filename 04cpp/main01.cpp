#include <iostream>
using namespace std;

struct E{};

class A
{
public:
	A()
	{
				throw E();
	}
};

class Test
{
public:
	Test(int n=100):_n(n)
	{
		cout << "Test ..." <<endl;
	}
	~Test()
	{
		cout << "~Test ..." <<endl;
	}

	int _n;
};

void *operator new(size_t size)						// operator new origin function
{
	cout << "operator new(size_t size)" << endl;
	return malloc(size);
}

void operator delete(void *p)
{
	cout << "operator delete(void *p)" << endl;
	free(p);
}

void *operator new[](size_t size)						// operator new origin function
{
	cout << "operator new[](size_t size)" << endl;
	return malloc(size);
}

void operator delete[](void *p)
{
	cout << "operator delete[](void *p)" << endl;
	free(p);
}

//void *operator new(size_t size, void *p)			//placement new：无需分配空间，返回指着即可， 但是有调用构造函数
//{
//	cout << "operator new(size_t size)" << endl;
//	return p;
//}
//
//void operator delete(void *p, void *q)			//placement delet：无需释放空间，但是应该调用析构函数，才对称啊，但是这个函数无法调用(这是个严重的问题，不能理解)
//{
//	cout << "operator delete(void *p)" << endl;
//}


void *operator new(size_t size, const char *file, long line)
{
	cout << "[NEW] "<< file << ":" << line <<endl;
	return malloc(size);
}

void operator delete(void *p, const char *file, long line)
{
	cout << "[DELETE] "<< file << ":" << line <<endl;
	free(p);
}



int main(void)
{
	Test *t = new Test();		// new operator = operator new(成员变量的内存空间) + 构造函数的调用
	delete t;

	Test *t4 = new Test[10];	// 数组操作。
	delete[] t4;

	//placement new 调用情况，这个new关键字辈识别为placement new + 构造函数。
	char chunk[10];
	Test *t2 = new (chunk) Test(200);
	t2->~Test();				//显示调用析构
	//delete t2;

	// operator new 与operator delete配套使用的情况。
	try{
		A *t3 = new(__FILE__, __LINE__) A();			//从这里可以看出，配套的operator delete 函数在delete操作符时
	}catch(...) {cout << "exception cautch..." << endl;}	//是不被调用的，而是在使用相应new出现异常时才会调用。		

	return 0;
}