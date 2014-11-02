#include <iostream>
using namespace std;

#include "DynBase.h"

int main()
{
	string s = "int";
	double *a = (double *)DynBase::CreateObject(s);
	*a = 100.1;
	cout << *a << endl; 
}

REGISTER_CLASS(int);
REGISTER_CLASS(double);