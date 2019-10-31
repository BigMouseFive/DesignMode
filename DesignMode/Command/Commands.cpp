#include "Commands.h"


Command1::Command1(Receiver* recv){
	_recv = recv;
}
void Command1::SetReceiver(Receiver* recv){
	_recv = recv;
}
void Command1::Excute(){
	printf("Command1.\n");
	_recv->Notice();

}



Command2::Command2(Receiver* recv){
	_recv = recv;
}
void Command2::SetReceiver(Receiver* recv){
	_recv = recv;
}
void Command2::Excute(){
	printf("Command2.\n");
	_recv->Notice();
}
