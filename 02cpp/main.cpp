#include "String.h"
#include <iostream>
using namespace std;

int main(void)
{
	String s1 = "abcd";		//调用构造函数
	String s2 = s1;			//调用拷贝构造函数
							//两者都为调用赋值=函数。
	return 0;
}