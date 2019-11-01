#include "Player.h"
#include <cstdio>
#include "BaseState.h"
#include "SeniorState.h"
#include "PlayerEquipState.h"	
Player::Player(){
	_bstate = BaseStateStand::Instance();
	_sstate = SeniorStateStop::Instance();
	_pstate = PlayerEquipPack::Instance();
}
void Player::Transmit(std::string msg){
	printf("Transmit: %s\n", msg.c_str());
}
void Player::ChangeBaseState(BaseState* bstate){
	_bstate = bstate;
}
void Player::ChangeSeniorState(SeniorState* sstate){
	_sstate = sstate;
}
void Player::ChangePlayerEquipState(PlayerEquipState* estate){
	_pstate = estate;
}