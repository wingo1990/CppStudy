#include<iostream>
#include<iomanip>

using namespace std;


//实现操作子方式和成员函数两种方式。
//宽度控制
//对齐控制
//填充控制
//精度控制
//进制控制

int main()
{
	int n = 65;
	double d = 123.45;
	double d2 = 0.0123;

	cout << "====================宽度控制===================" << endl;
	cout << setw(10) << n << "#" << endl;								//不影响后续的操作。
	cout << n << "#" << endl;

	cout.width(10);														//只影响后续一次的操作
	cout << n << "#" << endl;
	cout << n << "#" << endl;

	cout << "====================对齐控制===================" << endl;
	cout << setw(10) << setiosflags(ios::left) << n << "#" << endl;		//影响下一次操作
	cout << setw(10) << n << "#" << endl;
	cout << setw(10) << resetiosflags(ios::left) << n << "#" << endl;

	cout.setf(ios::left);												//影响下一次操作
	cout << setw(10) << n << "#" << endl;
	cout << setw(10) << n << "#" << endl;
	cout.unsetf(ios::left);
	cout << setw(10) << n << "#" << endl;

	cout << "====================填充控制===================" << endl;
	cout << setw(10) << setfill('?') << n << "#" << endl;		//影响下一次操作
	cout << setw(10) << n << "#" << endl;
	cout << setw(10) << setfill(' ') << n << "#" << endl;

	cout.fill('?');  											//影响下一次操作
	cout << setw(10) << n << "#" << endl;
	cout << setw(10) << n << "#" << endl;
	cout.fill(' ');
	cout << setw(10) << n << "#" << endl;

	cout << "====================精度控制===================" << endl;
	cout << setprecision(4) << setiosflags(ios::fixed) << d << endl; //影响下一次操作
	cout << setprecision(0) << resetiosflags(ios::fixed)<< d << endl;

	cout.precision(6);
	cout.setf(ios::fixed);
	cout << d2 << endl;
	cout << d2 << endl;
	cout.precision(0);
	cout.unsetf(ios::fixed);

	cout << "====================进制控制===================" << endl;
	cout << n << endl;
	cout << hex << setiosflags(ios::showbase) << n << endl;	//对后续有影响,同时设置多个进制方式是有问题的，必须将前面的还原成10进制的。
	cout << oct << n << endl;
	cout << resetiosflags(ios::showbase) << n << endl;

	cout.unsetf(ios::oct);									//使用之前一定得把前面的进制给unset掉才行。
	cout.setf(ios::hex);
	cout.setf(ios::showbase);
	cout << n << endl;
	
	cout.unsetf(ios::hex);
	cout.setf(ios::oct);
	cout << n << endl;

}