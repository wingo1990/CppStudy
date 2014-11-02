#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <memory>

template <typename T>
class Singleton
{
public:
	static T &GetInstance()
	{
		if (_instance.get() == NULL)
		{
			_instance.reset(new T);
		}

		return *_instance.get();
	}

private:
	Singleton<T>();
	~Singleton<T>();

	Singleton<T>(const Singleton<T> &other);
	Singleton<T> &operator=(const Singleton<T> &other);

	static std::auto_ptr<T> _instance;
};

template<typename T>
std::auto_ptr<T> Singleton<T>::_instance;
#endif // _SINGLETON_H_


