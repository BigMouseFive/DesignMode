#pragma once
#include "Subsystems.h"
class Facade{
public:
	Facade();
	~Facade();

	void WrapOperation();
private:
	Subsystem1* _s1;
	Subsystem2* _s2;
	Subsystem3* _s3;
};