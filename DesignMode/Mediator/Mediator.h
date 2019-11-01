#pragma once
#include <unordered_map>
class Colleague;
class Mediator{
public:
	virtual void Register(int, Colleague*) = 0;
	virtual void UnRegister(int, Colleague*) = 0;
	virtual void Operation(int, void*) = 0;
	virtual ~Mediator(){}
protected:
	std::unordered_map<int, Colleague*> _map;
};