#pragma once
#include "Player.h"
class PlayerEquipState{
public:
	virtual void CutGun(Player* player){}
	virtual void UseGun(Player* player){}
	virtual void UnuseGun(Player* player){}
	virtual ~PlayerEquipState(){}
};
class PlayerEquipPack : public PlayerEquipState{
public:
	virtual void CutGun(Player* player);
	static PlayerEquipPack* Instance(){
		return instance;
	}
private:
	static PlayerEquipPack* instance;
};
class PlayerEquipHandle : public PlayerEquipState{
public:
	virtual void CutGun(Player* player);
	virtual void UseGun(Player* player);
	static PlayerEquipHandle* Instance(){
		return instance;
	}
private:
	static PlayerEquipHandle* instance;
};
class PlayerEquipUse : public PlayerEquipState{
public:
	virtual void UnuseGun(Player* player);
	static PlayerEquipUse* Instance(){
		return instance;
	}
private:
	static PlayerEquipUse* instance;
};
