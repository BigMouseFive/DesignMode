#pragma once
#include "RealSubject.h"
class Proxy : public Subject{
public:
	void PreRequest();
	virtual void Request();
	void AfterRequest();
	~Proxy(){
		if (_real_sub)
			delete _real_sub;
	}
private:
	Subject* _real_sub;
};