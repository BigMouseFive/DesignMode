#pragma once
#include "Mediator.h"
class Mediator1 : public Mediator{
public:
	virtual void Register(int, Colleague*);
	virtual void UnRegister(int, Colleague*);
	virtual void Operation(int, void*);
protected:
	std::unordered_map<int, Colleague*> _map;
};