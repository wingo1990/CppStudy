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

	ofstream f("test.txt", ios::binary);		
	assert(f);
	f.write((char*)&t.a, sizeof(int));	
	int len = t.b.length();
	f.write((char*)&len, sizeof(int));
	f.write((char*)(t.b.data()), t.b.length());
	len = t.c.length();
	f.write((char*)&len, sizeof(int));
	f.write((char*)(t.c.data()), t.c.size());
	f.close();

	ifstream f1("test.txt", ios::binary);
	assert(f1);
	Test t1;
	f1.read((char*)(&t1.a), sizeof(int));
	f1.read((char*)&len, sizeof(int));
	cout << len << endl;
	t1.b.resize(len);
	f1.read(&t1.b[0], len);
	f1.read((char*)&len, sizeof(int));
	cout << len << endl;
	t1.c.resize(len);
	f1.read(&t1.c[0], len);
	f1.close();

	cout << t1.a << endl;
	cout << t1.b << endl;
	cout << t1.c << endl;

	return 0;
}
