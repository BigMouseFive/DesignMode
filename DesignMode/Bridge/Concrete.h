#pragma once
#include "Abstract.h"

class Concrete1 : public Abstract{
public:
	Concrete1(Implement* impl) :Abstract(impl){}
	virtual void Operation();
};

class Concrete2 : public Abstract{
public:
	Concrete2(Implement* impl) :Abstract(impl){}
	virtual void Operation();
};