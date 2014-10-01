#pragma warning(disable:4996)
#include "String.h"
#include <cstring>
#include <iostream>
using namespace std;

String::String(const char *str)
{
	int len = strlen(str) + 1;
	_str = new char[len];
	memset(_str, 0 , len);
	strcpy(_str, str);
}

String::String(const String& other)
{
	AllocAndCpy(_str, other._str);
}

String::~String()
{
	delete[] _str;
}

String& String::operator=(const String& other)
{
	if (*this == other)
		return *this;

	delete[] _str;
	AllocAndCpy(_str, other._str);	
	return *this;
}
String& String::operator=(const char* s)
{
	delete[] _str;
	AllocAndCpy(_str, s);
	return *this;
}

bool String::operator==(const String& other) const
{
	return (0 == strcmp(_str, other._str));
}

bool String::operator!() const
{
	return 0 != strlen(_str);
}

String& String::operator+=(const String &other)
{
	int len = strlen(_str) + strlen(other._str) + 1;
	char *newstr = new char[len];
	memset(newstr, 0 , len);
	strcpy(newstr,  _str);
	strcat(newstr, other._str);

	delete[] _str;

	_str = newstr;
	return *this;
}
String operator+(const String &str1, const String &str2)
{
	String tmp = str1;
	tmp += str2;

	return tmp;
}

char& String::operator[](const int i)
{
	return const_cast<char &>(static_cast<const String &>(*this)[i]);
}

const char& String::operator[](const int i) const
{
	return _str[i];
}

ostream &operator<<(ostream &os, const String &str)
{
	os << str._str;
	return os;
}
istream &operator>>(istream &is, String &str)
{
	char tmp[1024];
	is >> tmp;
	str = tmp;
	return is;
}

void String::AllocAndCpy(char* &d, const char *s)
{
	int len = strlen(s) + 1;
	d = new char[len];
	memset(d, 0, len);
	strcpy(d, s);
}