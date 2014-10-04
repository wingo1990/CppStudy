01cpp:

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