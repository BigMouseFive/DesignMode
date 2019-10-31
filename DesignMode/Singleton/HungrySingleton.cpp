#include "HungrySingleton.h"
#include<cstdio>

HungrySingleton* HungrySingleton::instance = new HungrySingleton();

HungrySingleton::HungrySingleton(){
	printf("HungrySingleton: Created.\n");
}
HungrySingleton* HungrySingleton::GetInstance(){
	return instance;
}
