#include "Invoker.h"

Invoker::Invoker(Command* command) :_command(command){

}

Invoker::~Invoker(){
}
void Invoker::SetCommand(Command* command){
	_command = command;
}

void Invoker::Call(){
	if (_command)
		_command->Excute();
}
