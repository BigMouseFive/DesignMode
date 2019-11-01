#pragma once
#include <string>
class BaseState;
class SeniorState;
class PlayerEquipState;
class Player{
public:
	Player();
	void Transmit(std::string);
	void ChangeBaseState(BaseState*);
	void ChangeSeniorState(SeniorState*);
	void ChangePlayerEquipState(PlayerEquipState*);
	BaseState* GetBastState(){ return _bstate; }
	SeniorState* GetSeniorState(){ return _sstate; }
	PlayerEquipState* GetPlayerEquipState(){ return _pstate; }
private:
	BaseState* _bstate;
	SeniorState* _sstate;
	PlayerEquipState* _pstate;
};