#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		istringstream iss(str);		//输入流绑定了字符长str
		string word;

		iss >> word;
		cout << word;
		while(iss>>word)			//当读到流结束时，EOF, 跳出。
			cout << "#" << word; 
	}

	return 0;
}