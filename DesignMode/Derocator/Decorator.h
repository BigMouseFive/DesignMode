#pragma once
#include "DAbstract.h"
class Decorator : public DAbstract{
public:
	Decorator(DAbstract* da) :_da(da){}
	virtual ~Decorator(){
		if (_da)
			delete _da;
	}
	virtual void Operation() = 0;
protected:
	DAbstract* _da;
};