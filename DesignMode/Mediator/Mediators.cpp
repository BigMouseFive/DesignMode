#include "Mediators.h"
#include "Colleague.h"
#include <cstdio>
void Mediator1::Register(int id, Colleague* pc){
	auto iter = _map.find(id);
	if (iter != _map.end()){
		printf("Id Exists.\n");
	}
	else{
		_map[id] = pc;
		pc->SetMediator(this);
		printf("Register Successful.\n");
	}
}
void Mediator1::UnRegister(int id, Colleague* pc){
	auto iter = _map.find(id);
	if (iter == _map.end()){
		printf("Id Doesn`t Exists.\n");
	}
	else{
		_map.erase(iter);
		printf("UnRegisterRegister Successful.\n");
	}
}
void Mediator1::Operation(int id, void* msg){
	auto iter = _map.find(id);
	if (iter == _map.end()){
		printf("Id Doesn`t Exists.\n");
		return;
	}
	if (!iter->second){
		printf("Colleague is NULL. Ready to delete.\n");
		_map.erase(iter);
		return;
	}
	iter->second->RecvMsg(msg);
	printf("Operation Successful.\n");
}