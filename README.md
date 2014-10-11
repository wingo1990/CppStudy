01cpp:
C++优化方案：常量折叠

const_cast：主要是针对指针和引用，去掉他们原有的const属性

使用const_cast去除const限定的目的不是为了修改它的内容
使用const_cast去除const限定，通常是为了函数能够接受这个实际参数：即是形参不带const属性，实参带const属性。

02cpp:

主要实现String类，目的是运算符的重载。
	String s1 = "abcd";		//调用构造函数，如果构造函数添加explicit就不可以隐式转换了。
	String s2 = s1;			//调用拷贝构造函数
							//两者都为调用赋值=函数。
	依次实现了下面运算符的重载：
	=、==、+、+=、[]、！、<<、>>。

03cpp:

禁止拷贝：将拷贝构造函数和赋值函数设为私有。

Singleton模式：
	main1.cpp：实现了单例，但是对于单例的资源释放问题解决的不是很好，在具体的工程中，在多个地方用此单例，不知何时才能释放资源，所以要解决让其自动释放资源的问题。
	main2.cpp：解决自动释放单例资源，定义了一个内嵌类，根据此类对象的析构确定型将其释放。
	main3.cpp：定义了局部static 单例对象，可以解决资源自动释放的问题，但不是线程安全的。

04cpp：
主要学习了new(关键字)、 operator new(函数) 以及 operator new的重载。
http://www.cnblogs.com/luxiaoxun/archive/2012/08/10/2631812.html

void *operator new(size_t size);						//operator new 的原型
void delete (void *p);
void delete (void *p, size_t);

void *operator new[](size_t size);						//operator new 数组原型
void delete[](void *p);

void *operator new(size_t size, void *p);				// placement new 是operator new 的重载
void delete(void *p, void *q);

void *operator new(size_t size, char *file, long line);	//重载的情况
void delete(void *p, char *file, long line);

以上是配套情况，重载是new和delete必须同时进行定义，但是在使用的时候不是配套的。
这种配套机制是解决在new遇到异常时，调用配套的delete而用的。
一般只调用delete即是普通的delete，不会找到那个相应的。

new operator = operator new + 构造函数。

05cpp：
工厂模式的实现

注意看你面的注释。

06cpp :
main：单例模式 auto_ptr(模板)
main1：
#define sizeof_v(x)  ((char*)(&x+1) - (char*)&x )		//变量大小
#define sizeof_t(X)  (size_t)((X*)0 + 1)				//类型大小
								
#define ALIGN(v, b)  ((v+b-1) & ~(b-1))				//对齐，对于内存池很有用

07cpp：
学习简单的io操作
io分为三种：
标准io：对标准的输入输出设备的输入输出
	cin cout cerr clog
文件io：对外部存储中的文件的输入输出操作
	ifstream ofstream fstream
	filebuf
串io：  对内存中的一块字符串的输入输出操作。
	istringstream ostringstream stringstream
	stringbuf

main: 文本格式打开与二进制格式打开的区别。
		windows： 写入'\n'会转换成'\r\n'
		linux :   '\n'不变，也就说在linux环境中文本格式打开和二进制格式打开时一样的。
		mac ：     '\n' 会转换成'\r'。
		'\r'无论在哪个系统中都不会转换的。

main1： 错误的读写字符串方式。
main2： 正确方式之一。

08cpp:
主要学习了 stringstream 串io
istringstream: 输入字符串流，一般需要绑定一个字符串，便于从中读取。
ostringstream: 输出字符串流，一般不需要绑定字符串，传入到其中的信息会存在它自己分配的字符串里，可以用::str()函数取出。

main01:
	循环读取，输出
main02:
	double与字符串之间的转换。

09cpp：
	实现操作子方式和成员函数两种方式。
	宽度控制
	对齐控制
	填充控制
	精度控制
	进制控制


