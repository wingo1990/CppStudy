#include "String.h"
#include <iostream>
using namespace std;

int main(void)
{
	String s1;
	String s2("aaa");
	String s3="aaa";
	String s4="bbbb";
	s2 = "cccc";
	s1 = "cccc";
	cout << (!s1) <<endl;

	s4 = "abc" + s3 + s2;

	cout << s1 << s2 << s3 << endl;

	cout << s2[3] << endl;
	s2[3] = 'C';
	cout << s2[3] << endl;

	const String s5 = "abcdefghijklmnopqrstuvwxyz";
	cout << s5 << endl;
	cout << s5[8];
	//s5[8] = 'A';

	cin >> s1;

	cout << s1 << endl;

	return 0;
}