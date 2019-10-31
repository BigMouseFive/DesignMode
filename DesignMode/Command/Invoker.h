#pragma once
#include "Command.h"

class Invoker{
public:
	Invoker(Command*);
	~Invoker();
	void SetCommand(Command*);
	void Call();
private:
	Command* _command;
};