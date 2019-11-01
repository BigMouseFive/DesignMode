#pragma once
#include "Colleague.h"
class Colleague1 : public Colleague{
public:
	virtual void SendMsg(int);
	virtual void RecvMsg(void*);
};

class Colleague2 : public Colleague{
public:
	virtual void SendMsg(int);
	virtual void RecvMsg(void*);
};

class Colleague3 : public Colleague{
public:
	virtual void SendMsg(int);
	virtual void RecvMsg(void*);
};