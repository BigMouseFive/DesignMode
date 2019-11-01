#include "Subjects.h"

int OSubject1::GetState(){
	return _state;
}
void OSubject1::SetState(int state){
	_state = state;
	Notify();
}