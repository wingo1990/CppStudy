#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <cstdlib>

template <typename T>
class Singleton
{
public:
	static T &GetInstance()
	{
		if (_instance == NULL)
		{
			_instance = new T;
			atexit(Destroy);
		}
		return *_instance;
	}

	static void Destroy()
	{
		if (NULL != _instance)
		{
			delete _instance;
		}
	}

private:
	Singleton<T>();
	~Singleton<T>();

	Singleton<T>(const Singleton<T> &other);
	Singleton<T> &operator=(const Singleton<T> &other);

	static T *_instance;
};

template <typename T>
T* Singleton<T>::_instance = 0;

#endif // _SINGLETON_H_


