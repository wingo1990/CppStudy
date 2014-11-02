#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	//ofstream fo("test.txt"); //默认情况是文本格式打开
	//assert(fo);
	//fo << "hello\r\n";		 //写入到文本中，文本的大小为8字节
	//fo.close();

	//ofstream fo("test.txt", ios::binary); //以二进制格式打开
	//assert(fo);
	//fo << "FTCN:6 ";					  //写入到文本中，文本的大小为7字节
	//fo.close();

	//string ss;
	//ifstream fi("test.txt", ios::binary);
	//fi >> ss;
	//cout << ss << endl;;
	//
	//size_t i,j;
	//i = ss.rfind("FTCN:");
	//ss.erase(i,5);
	//cout << ss << endl;
	//istringstream iss(ss);
	//iss >> j;
	//cout << "j: " << j << endl;
	//cout << "i: " << i << endl;

	//string s;
	//string s1 = "stringtestfal;kdjflksdjfl;afjksdjf;lasdfjlkd";
	//s.assign(s1, 0, 4);
	//string::size_type a = -1;
	//cout << a << endl;

	// Error
	//string s("abc-ced");
	//ifstream iss(s);
	//string a, b;
	//iss >> a >> "-" >> b;

	//string str("st ri ng \n test\ndfja;lfdj");
	//istringstream iss(str);

	//string s;
	//iss >> str;
	//cout << str <<endl;;
	//iss >> str;
	//cout << str << endl;
	//iss >> str;
	//cout << str << endl;;
	//iss >> str;
	//cout << str << endl;

	/*vector<string> vs(3);
	for (int i=0; i<3; i++)
		vs[i] = "stringtest";

	for (int i=0; i<3; i++)
		cout << vs[i] << endl;
	cout << endl;

	vector<string> vs1 = vs;
	for (int i=0; i<3; i++)
		cout << vs1[i] << endl;
	cout << endl;

	for (int i=0; i<3; i++)
		vs[i] = "string";

	for (int i=0; i<3; i++)
		cout << vs1[i] << endl;
	cout << endl;

	for (int i=0; i<3; i++)
		cout << vs[i] << endl;
	cout << endl;*/
	
	//int i = 3;
	//B b;
	//b.Display(i);

	int a, b, c;
	cin >> a >> b >> c;
	cout << a << b << c <<endl;
}