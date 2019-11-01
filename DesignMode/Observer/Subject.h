#pragma once
#include "Observer.h"
#include <unordered_set>
class OSubject{
public:
	void Attach(Observer* obj);
	void Detach(Observer* obj);
	void Notify();
	virtual int GetState() = 0;
	virtual void SetState(int) = 0;
	virtual ~OSubject(){}
private:
	std::unordered_set<Observer*> _objs;
};