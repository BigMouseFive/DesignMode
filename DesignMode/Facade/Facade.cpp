#include "Facade.h"

Facade::Facade(){
	_s1 = new Subsystem1();
	_s2 = new Subsystem2();
	_s3 = new Subsystem3();
}

Facade::~Facade(){
	if (_s1) delete _s1;
	if (_s2) delete _s2;
	if (_s3) delete _s3;
}

void Facade::WrapOperation(){
	_s1->Method();
	_s2->Method();
	_s3->Method();
}