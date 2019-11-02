#include "Strategys.h"
Strategy1* Strategy1::_instance = new Strategy1();
Strategy2* Strategy2::_instance = new Strategy2();

void Strategy1::Sort(std::vector<int>* vec){
	printf("Strategy1::Sort.\n");
}
Strategy1* Strategy1::Instance(){
	return _instance;
}

void Strategy2::Sort(std::vector<int>* vec){
	printf("Strategy2::Sort.\n");
}
Strategy2* Strategy2::Instance(){
	return _instance;
}