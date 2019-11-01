#pragma once
#include "Observer.h"
class Observer1 : public Observer{
public:
	virtual void Update(OSubject*);
};