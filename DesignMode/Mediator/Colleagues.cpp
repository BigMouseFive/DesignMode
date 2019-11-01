#include "Colleagues.h"
void Colleague1::SendMsg(int id){
	if (_mediator){
		char* msg = new char[30];
		strcpy_s(msg, 19, "Colleague1: Hello!");
		_mediator->Operation(id, msg);
		delete[] msg;
	}
}
void Colleague1::RecvMsg(void* msg){
	printf("Colleague1 Recv: %s\n", (char*)msg);
}

void Colleague2::SendMsg(int id){
	if (_mediator){
		char* msg = new char[30];
		strcpy_s(msg, 19, "Colleague2: Hello!");
		_mediator->Operation(id, msg);
		delete[] msg;
	}
}
void Colleague2::RecvMsg(void* msg){
	printf("Colleague2 Recv: %s\n", (char*)msg);
}

void Colleague3::SendMsg(int id){
	if (_mediator){
		char* msg = new char[30];
		strcpy_s(msg, 19, "Colleague3: Hello!");
		_mediator->Operation(id, msg);
		delete[] msg;
	}
}
void Colleague3::RecvMsg(void* msg){
	printf("Colleague3 Recv: %s\n", (char*)msg);
}