#ifndef _SINGLETON_H_
#define _SINGLETON_H_

template <typename T>
class Singleton
{
public:
	static T &GetInstance()
	{
		static T _instance;
		return _instance;
	}

private:
	Singleton<T>();
	~Singleton<T>();

	Singleton<T>(const Singleton<T> &other);
	Singleton<T> &operator=(const Singleton<T> &other);
};

#endif // _SINGLETON_H_


