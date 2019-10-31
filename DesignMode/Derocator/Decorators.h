#pragma once
#include "Decorator.h"

class Decorator1 : public Decorator{
public:
	Decorator1(DAbstract* da) :Decorator(da){}
	void AddOperation();
	virtual void Operation();
};