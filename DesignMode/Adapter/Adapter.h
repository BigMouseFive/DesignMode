#pragma once
#include "Target.h"
#include "Adapteree1.h"

class Adapter : public Target, public Adapteree1{
public:
	virtual void Interface1();
	virtual void Interface2();
};