#include "Proxy.h"
#include <cstdio>
void Proxy::PreRequest(){
	printf("Proxy PreRequest.\n");
}
void Proxy::Request(){
	if (_real_sub == nullptr)
		_real_sub = new RealSubject();
	PreRequest();
	_real_sub->Request();
	AfterRequest();
}
void Proxy::AfterRequest(){
	printf("Proxy AfterRequest.\n");
}