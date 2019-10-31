#include "LazySingleton.h"
#include <cstdio>
boost::mutex LazySingleton::mutex_ins;
LazySingleton* LazySingleton::instance = nullptr;

LazySingleton::LazySingleton(){
	printf("LazySingleton: Created.\n");
}

LazySingleton* LazySingleton::GetInstance(){
	if (instance == NULL){
		//get mutex
		mutex_ins.lock();
		if (instance == NULL){
			instance = new LazySingleton();
		}
		//release mutex
		mutex_ins.unlock();
	}
	return instance;
}