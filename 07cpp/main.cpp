#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//ofstream fo("test.txt"); //Ĭ��������ı���ʽ��
	//assert(fo);
	//fo << "hello\r\n";		 //д�뵽�ı��У��ı��Ĵ�СΪ8�ֽ�
	//fo.close();

	ofstream fo("test.txt", ios::binary); //�Զ����Ƹ�ʽ��
	assert(fo);
	fo << "hello\r\n";					  //д�뵽�ı��У��ı��Ĵ�СΪ7�ֽ�
	fo.close();
}