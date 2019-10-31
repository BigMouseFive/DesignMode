#pragma once
#include "Implement.h"

class Abstract{
public:
	Abstract(Implement* impl) :_impl(impl){}
	virtual void Operation() = 0;
	virtual ~Abstract(){
		if (_impl)
			delete _impl;
	}
protected:
	Implement* _impl;
};