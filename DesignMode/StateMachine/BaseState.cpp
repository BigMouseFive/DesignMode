#include "BaseState.h"
BaseStateStand* BaseStateStand::instance = new BaseStateStand();
BaseStateStay* BaseStateStay::instance = new BaseStateStay();
BaseStateFlat* BaseStateFlat::instance = new BaseStateFlat();


void BaseStateStand::Stay(Player* player){
	player->Transmit("Stand->Stay");
	player->ChangeBaseState(BaseStateStay::Instance());
}
void BaseStateStand::Flat(Player* player){
	player->Transmit("Stand->Flat");
	player->ChangeBaseState(BaseStateFlat::Instance());
}
void BaseStateStand::Jump(Player* player){
	player->Transmit("Jumping");
}

void BaseStateStay::Stay(Player* player){
	player->Transmit("Stay->Stand");
	player->ChangeBaseState(BaseStateStand::Instance());
}
void BaseStateStay::Flat(Player* player){
	player->Transmit("Stay->Flat");
	player->ChangeBaseState(BaseStateFlat::Instance());
}
void BaseStateStay::Jump(Player* player){
	player->Transmit("Stay->Stand");
	player->ChangeBaseState(BaseStateStand::Instance());
} 

void BaseStateFlat::Stay(Player* player){
	player->Transmit("Flat->Stay");
	player->ChangeBaseState(BaseStateStay::Instance());
}
void BaseStateFlat::Flat(Player* player){
	player->Transmit("Flat->Stand");
	player->ChangeBaseState(BaseStateStand::Instance());
}
void BaseStateFlat::Jump(Player* player){
	player->Transmit("Flat->Stay");
	player->ChangeBaseState(BaseStateStay::Instance());
}