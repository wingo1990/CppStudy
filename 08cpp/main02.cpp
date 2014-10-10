#include<iostream>
#include<sstream>

using namespace std;

double StrToDouble(string &str)
{
	double temp;
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

	double valt = StrToDouble(str);
	cout << valt << endl;

	return 0;
}