#include <iostream>
#include <deque>
#include <vector>
using namespace std;

template <typename T, typename CONT = deque<T> >	//缺省模板参数
class Stack
{
public:
	Stack():_c()
	{

	}
	~Stack()
	{

	}

	void push(const T& ele)
	{
		_c.push_back(ele);
	}

	void pop()
	{
		_c.pop_back();
	}

	T& top()
	{
		return _c.back();
	}
private:
	CONT _c;
};

int main()
{
	//Stack<int> s; 
	Stack<int, vector<int>> s;
	s.push(10);
	s.push(20);
	s.push(30);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

}