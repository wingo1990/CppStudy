#include <stdio.h>

int main()
{
	//string str = "name = abc";
	//boost::regex reg(" ");

	//boost::sregex_token_iterator it(str.begin(), str.end(), reg, -1);
	//boost::sregex_token_iterator end;

	//while (it != end)
	//{
	//	string ss = *it++;
	//	cout << ss;
	//}
	//
	//return 0;
	//////////////////////////////////////////////////////////////////////////

	//string str = "name= abc";
	//regex reg("\\s*(.*)\\s?(>|<|=)\\s?(.*)\\s*");
	//smatch sm;

	//regex_match(str, sm, reg);
	////cout << sm.size();
	//for (int i=0; i<sm.size(); i++)
	//{
	//	cout << sm[i] << endl;
	//}
	//////////////////////////////////////////////////////////////////////////

	//string str = " host=124.6.6.5, db=afd, user=zhang, passwd=fjadlfaom";
	//regex reg("\\s?host=(.*),\\s?db=(.*),\\s?user=(.*),\\s?passwd=(.*)\\s?");
	//smatch sm;
	//regex_match(str, sm, reg);

	//cout << sm[0]<<endl;
	//cout << sm[1]<<endl;
	//cout << sm[2]<<endl;
	//cout << sm[3]<<endl;
	//cout << sm[4]<<endl;
	//////////////////////////////////////////////////////////////////////////

	//string str = " abc-wed zhang-int wang-double li-string  ";
	//regex reg(" ");
	//smatch sm;
	////regex_search(str, sm, reg);
	//sregex_token_iterator it(str.begin(), str.end(), reg, -1);
	//sregex_token_iterator end;
	//while (it != end)
	//{	
	//	if (it->str().size())
	//	{	
	//		cout << it->str() << endl;
	//		string temp = it->str();
	//		regex reg2("(.*?)-(.*)");
	//		smatch sm2;
	//		regex_match(temp, sm2, reg2);
	//		cout << sm2.size()<<endl;
	//		cout << sm2[0] << endl;
	//		cout << sm2[1] << endl;
	//		cout << sm2[2] << endl;
	//	}
	//	it++;
	//}

	//cout << str <<endl;
	//////////////////////////////////////////////////////////////////////////

	//string str = "abcdefghijklmnopqrstuvwxyz";
	//str.erase(str.size()-1);
	//cout << str << endl;
	//////////////////////////////////////////////////////////////////////////

	//vector<int> int_vec;
	//if (int_vec.begin() == int_vec.end())
	//{
	//	cout << "begin == end" << endl;
	//}

	//int_vec.insert(int_vec.begin()+2, 10);

	//cout << int_vec.size() << endl;
	//////////////////////////////////////////////////////////////////////////

	//string temp = " zhang - string ";
	//regex reg("\\s*([^\\s]*)\\s*-\\s*([^\\s]*)\\s*");
	//smatch sm;
	//regex_match(temp, sm, reg);

	//cout << sm.size() << endl;
	//cout << sm[0] << endl;
	//cout << sm[1] << endl;
	//cout << sm[2] << endl;
	//////////////////////////////////////////////////////////////////////////

	//void *str1 = new string;
	//void *str2 = new string;

	//*(string*)str1 = "Hello world!";
	//cout << *(string*)str1 <<endl;

	//*(string*)str2 = *(string*)str1;
	//cout << *(string*)str2 << endl;
	//////////////////////////////////////////////////////////////////////////

	//printf("\n\n\n\n\n\n\n\n\n\n"
	//	   "Hello World!");
	//////////////////////////////////////////////////////////////////////////

	unsigned short usLen = 0;
	unsigned char ucLen[2] = {0x12, 0x34};

	usLen = ucLen[0] + (ucLen[1]<<8);

	printf("%4x\n", usLen);
}