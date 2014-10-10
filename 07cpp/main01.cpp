#include <cassert>
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

typedef struct
{
	int a;
	string b;
	string c;
}Test;


int main()
{
	Test t;
	t.a = 100;
	t.b = "aaa";
	t.c = "ccc";

	ofstream f("test.txt");
	assert(f);
	f.write(reinterpret_cast<char*>(&t),sizeof t);				//这种读写是错误的，“aaa”与string类没有太过直接的关系，只是指针的值在string中保存着。
	f.close();

	ifstream f1("test.txt");
	assert(f1);
	Test t1;
	f1.read(reinterpret_cast<char*>(&t1), sizeof t1);
	f1.close();
	cout << sizeof string << endl;
	cout << t1.a << endl;
	cout << t1.b << endl;
	cout << t1.c << endl;

	return 0;
}
