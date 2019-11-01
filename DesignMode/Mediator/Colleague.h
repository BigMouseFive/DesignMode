#pragma once
#include "Mediator.h"

class Colleague{	
public:
	Colleague():_mediator(nullptr){}
	virtual ~Colleague(){}
	void SetMediator(Mediator* mediator){
		_mediator = mediator;
	}
	virtual void SendMsg(int) = 0;
	virtual void RecvMsg(void*) = 0;
protected:
	Mediator* _mediator;
};