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