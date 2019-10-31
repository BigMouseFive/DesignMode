#include "Decorators.h"
#include <cstdio>

Decorator1::Decorator1(DAbstract* da) 
	:Decorator(da){
}

void Decorator1::AddOperation(){
	printf("Decorator1 AddOperation.\n");
}
void Decorator1::Operation(){
	AddOperation();
	_da->Operation();
}
