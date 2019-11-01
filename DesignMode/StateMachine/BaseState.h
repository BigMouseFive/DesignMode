#pragma once
#include "Player.h"
class BaseState{
public:
	virtual void Stay(Player* player){}
	virtual void Flat(Player* player){}
	virtual void Jump(Player* player){}
	virtual ~BaseState(){}
};
class BaseStateStand : public BaseState{
public:
	virtual void Stay(Player* player);
	virtual void Flat(Player* player);
	virtual void Jump(Player* player);
	static BaseStateStand* Instance(){
		return instance;
	}
private:
	static BaseStateStand* instance;
};
class BaseStateStay : public BaseState{
public:
	virtual void Stay(Player* player);
	virtual void Flat(Player* player);
	virtual void Jump(Player* player);
	static BaseStateStay* Instance(){
		return instance;
	}
private:
	static BaseStateStay* instance;
};
class BaseStateFlat : public BaseState{
public:
	virtual void Stay(Player* player);
	virtual void Flat(Player* player);
	virtual void Jump(Player* player);
	static BaseStateFlat* Instance(){
		return instance;
	}
private:
	static BaseStateFlat* instance;
};
