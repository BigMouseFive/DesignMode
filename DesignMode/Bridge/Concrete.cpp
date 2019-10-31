#include "Concrete.h"
#include <cstdio>
void Concrete1::Operation(){
	printf("Concrete1 Operation.\n");
	_impl->OperationImpl();
}

void Concrete2::Operation(){
	printf("Concrete2 Operation.\n");
	_impl->OperationImpl();
}