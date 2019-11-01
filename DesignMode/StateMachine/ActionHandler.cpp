#include "ActionHandler.h"
#include "Player.h"
#include "BaseState.h"
#include "SeniorState.h"
#include "PlayerEquipState.h"	
ActionHandler::ActionHandler(){
	_isWalk = false;
	_isShitf = false;
	_isCtrl = false;
}
int ActionHandler::SetPlayer(Player* player){
	_player = player;
	return 0;
}
int ActionHandler::Walk(){
	_isWalk = true;
	if (_isShitf) 
		Run();
	else if (_isCtrl) 
		SlowWalk();
	else{
		_player->GetSeniorState()->Walk(_player);
	}
	return 0;
}
int ActionHandler::StopWalk(){
	_isWalk = false;
	_player->GetSeniorState()->StopWalk(_player);
	return 0;
}
int ActionHandler::Stay(){
	_player->GetBastState()->Stay(_player);
	return 0;
}
int ActionHandler::Flat(){
	_player->GetBastState()->Flat(_player);
	return 0;
}
int ActionHandler::CutGun(){
	_player->GetPlayerEquipState()->CutGun(_player);
	return 0;
}
int ActionHandler::Run(){
	_isShitf = true;
	if (_isWalk){
		_player->GetSeniorState()->Run(_player);
	}
	return 0;
}
int ActionHandler::StopRun(){
	_isShitf = false;
	if (_isWalk)
		Walk();
	return 0;
}
int ActionHandler::SlowWalk(){
	_isCtrl = true;
	if (_isWalk){
		_player->GetSeniorState()->SlowWalk(_player);
	}
	return 0;
}
int ActionHandler::StopSlowWalk(){
	_isCtrl = false;
	if (_isWalk)
		Walk();
	return 0;
}
int ActionHandler::Jump(){
	_player->GetBastState()->Jump(_player);
	return 0;
}
int ActionHandler::UseGun(){
	_player->GetPlayerEquipState()->UseGun(_player);
	return 0;
}
int ActionHandler::UnuseGun(){
	_player->GetPlayerEquipState()->UnuseGun(_player);
	return 0;
}