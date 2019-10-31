#pragma once
#include "Decorator.h"

class Decorator1 : public Decorator{
public:
	Decorator1(DAbstract*);
	void AddOperation();
	void Operation();
};