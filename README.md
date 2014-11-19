01cpp:
C++优化方案：常量折叠

const_cast：主要是针对指针和引用，去掉他们原有的const属性

使用const_cast去除const限定的目的不是为了修改它的内容
使用const_cast去除const限定，通常是为了函数能够接受这个实际参数：即是形参不带const属性，实参带const属性。
*******

02cpp:

主要实现String类，目的是运算符的重载。
	String s1 = "abcd";		//调用构造函数，如果构造函数添加explicit就不可以隐式转换了。
	String s2 = s1;			//调用拷贝构造函数
							//两者都为调用赋值=函数。
	依次实现了下面运算符的重载：
	=、==、+、+=、[]、！、<<、>>。
*******

03cpp:

禁止拷贝：将拷贝构造函数和赋值函数设为私有。

Singleton模式：
	main1.cpp：实现了单例，但是对于单例的资源释放问题解决的不是很好，在具体的工程中，在多个地方用此单例，不知何时才能释放资源，所以要解决让其自动释放资源的问题。
	main2.cpp：解决自动释放单例资源，定义了一个内嵌类，根据此类对象的析构确定型将其释放。
	main3.cpp：定义了局部static 单例对象，可以解决资源自动释放的问题，但不是线程安全的。
*******

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
*******

05cpp：
工厂模式的实现

什么事工厂模式：

注意看你面的注释。
*******

06cpp :
main：单例模式 auto_ptr(模板)
main1：
	1.	#define sizeof_v(x)  ((char*)(&x+1) - (char*)&x )		//变量大小
	2.	#define sizeof_t(X)  (size_t)((X*)0 + 1)				//类型大小						
	3.	#define ALIGN(v, b)  ((v+b-1) & ~(b-1))					//对齐，对于内存池很有用
*******

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
*******

08cpp:
主要学习了 stringstream 串io
istringstream: 输入字符串流，一般需要绑定一个字符串，便于从中读取。
ostringstream: 输出字符串流，一般不需要绑定字符串，传入到其中的信息会存在它自己分配的字符串里，可以用::str()函数取出。

main01:
	循环读取，输出
main02:
	double与字符串之间的转换。
	模板函数训练
*******

09cpp：
	实现操作子方式和成员函数两种方式。
	宽度控制
	对齐控制
	填充控制
	精度控制
	进制控制
*******

10cpp:
	模板的学习
	对于具有相同逻辑的代码处理，目前有以下方法：
	1 宏： 不够灵活，对于不同类型不适用。
	2 重载： 对于每个类型都要重写重载函数。
	3 模板： 比较好的方法

main01： 函数模板， 友元函数 < 的定义。
概念：	模板函数			可以为逻辑操作一致而数据类型不一致的各种程序提供一种的代码共享机制。
		模板函数特化		依然是模板函数，只不过有是具体的实例。 template<>,坚括号里为空接口，函数中的类型都是指明的。
		非模板函数重载 	是全局函数，函数调用优先考虑，没有的话，才会考虑模板函数。

main02：缺省模板参数

main03：成员模板函数，类是模板了，在类中在还可以引入新的类型，定义模板函数。
		对于const函数有了明确的了解：函数()后面加const的意思是将this指针所指向的内容const化，也就说对象的属性const化了，不可更改。
		具体的推倒见代码。

main04：typename的用法，对于类型参数使用有着重要的意思。
*******

代码重用方式：
函数，内联函数，宏定义。
继承(追求编程效率) MFC就是用的这种方式；	组合方式。
模板(追求运行效率，过多的事情让编译器做了。) 类类型参数的使用 构成了适配器的概念，如stack适配了deque，这种效率要比继承的方式高。

面向对象与泛型都依赖于某种形式的多态。
面向对象： 动态多态  虚函数		运行时决定函数入口地址
泛型编程： 静态多态  模板			编译后决定了函数入口地址
*******

11cpp:
	模板的单例模式学习
	线程安全的单例模式类：普通锁、double check lock、pthread_once(linux)
*******

12cpp:
	Mysql　Ｃ++ Connector example.
	1. mysql-workbench-community-6.0.9-win32
	2. mysql-connector-c1.0.5-winx64（没用啊）
	3. mysql-5.5.40-winx64

	source code： 
	mysql-connector-c++-1.1.4
	boost_1_54_0
	MySQL Server 5.5[含有include和lib文件夹] 换位置，并更名为 MySQL_Server_5.5
	使用cmake-3.0.2转换成Visual Studio 2012版工程，编译成dll文件。
	过程：  1. set MYSQL_DIR=/path/to/Mysql_Server_5.5
		2. set BOOST_ROOT=/path/to/boost_1_34_0
			 注意中间不要有空格。
		3. cmake -G "Visual Studio 11 Win64"
		最后生成sln文件使用VS-2012打开。
*******

13cpp:
	mysql example。
*******

14cpp:
	regex使用相关例子， 主要是针对字符串相关操作。
*******

