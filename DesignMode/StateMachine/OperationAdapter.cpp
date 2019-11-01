#include "OperationAdapter.h"

OperationAdapter::OperationAdapter(){
	_handler = new ActionHandler();
}
OperationAdapter::~OperationAdapter(){
	if (_handler)
		delete _handler;
}
int OperationAdapter::KeyWPressed(){
	_handler->Walk();
	return 0;
}
int OperationAdapter::KeyWReleased(){
	_handler->StopWalk();
	return 0;
}
int OperationAdapter::KeyZ(){
	_handler->Flat();
	return 0;
}
int OperationAdapter::KeyX(){
	_handler->CutGun();
	return 0;
}
int OperationAdapter::KeyC(){
	_handler->Stay();
	return 0;
}
int OperationAdapter::KeyShiftPressed(){
	_handler->Run();
	return 0;
}
int OperationAdapter::KeyCtrlPressed(){
	_handler->SlowWalk();
	return 0;
}
int OperationAdapter::KeyShiftReleased(){
	_handler->StopRun();
	return 0;
}
int OperationAdapter::KeyCtrlReleased(){
	_handler->StopSlowWalk();
	return 0;
}
int OperationAdapter::KeySpace(){
	_handler->Jump();
	return 0;
}
int OperationAdapter::KeyMouseLeftPressed(){
	_handler->UseGun();
	return 0;
}
int OperationAdapter::KeyMouseLeftReleased(){
	_handler->UnuseGun();
	return 0;
}

void OperationAdapter::SetPlayer(Player* player){
	_handler->SetPlayer(player);
}
