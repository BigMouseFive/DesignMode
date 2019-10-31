#pragma once
#include <boost/thread/mutex.hpp>

class LazySingleton{
public:
	static LazySingleton* GetInstance();
private:
	LazySingleton();
	static boost::mutex mutex_ins;
	static LazySingleton* instance;
};