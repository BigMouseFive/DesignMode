#include "Decorators.h"
#include <cstdio>

void Decorator1::AddOperation(){
	printf("Decorator1 AddOperation.\n");
}
void Decorator1::Operation(){
	AddOperation();
	_da->Operation();
}
