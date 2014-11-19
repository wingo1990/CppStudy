#include<iostream>
#include<sstream>

using namespace std;

//double StrToDouble(string &str)
//{
//	double temp;
//	istringstream iss(str);
//	iss >> temp;
//	return temp;
//}

template <typename T>
T StrTo(string& str)
{
	T temp;
	istringstream iss(str);
	iss >> temp;
	return temp;
}

string DoubleToStr(double dn)
{
	ostringstream oss;
	oss << dn;
	return oss.str();
}

int main()
{
	double val = 5.55;
	string str;
	str = DoubleToStr(val);
	cout << str << endl;

	double valt = StrTo<int>(str);
	cout << valt << endl;

	double i = StrTo<double>(str);
	cout << i << endl;

	return 0;
}