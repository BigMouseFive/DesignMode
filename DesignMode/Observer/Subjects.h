#pragma once
#include "Subject.h"

class OSubject1 : public OSubject{
public:
	virtual int GetState();
	virtual void SetState(int state);
private:
	int _state;
};