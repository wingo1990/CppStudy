#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//ofstream fo("test.txt"); //默认情况是文本格式打开
	//assert(fo);
	//fo << "hello\r\n";		 //写入到文本中，文本的大小为8字节
	//fo.close();

	ofstream fo("test.txt", ios::binary); //以二进制格式打开
	assert(fo);
	fo << "hello\r\n";					  //写入到文本中，文本的大小为7字节
	fo.close();
}