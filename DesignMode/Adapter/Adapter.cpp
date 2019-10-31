#include "Adapter.h"
#include <cstdio>
void Adapter::Interface1(){
	printf("This Interface1.[START]\n");
	this->Method1();
	this->Method2();
	printf("This Interface1.[END]\n");
}
void Adapter::Interface2(){
	printf("This Interface2.[START]\n");
	this->Method2();
	this->Method3();
	printf("This Interface2.[END]\n");
}