#pragma once
#include "Command.h"
#include "Receiver.h"
#include <list>

class Command1 : public Command{
public:
	Command1(Receiver*);
	void SetReceiver(Receiver*);
	virtual void Excute();
private:
	Receiver* _recv;
};

class Command2 : public Command{
public:
	Command2(Receiver*);
	void SetReceiver(Receiver*);
	virtual void Excute();
private:
	Receiver* _recv;
};