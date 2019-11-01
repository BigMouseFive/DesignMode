#include "PlayerEquipState.h"
PlayerEquipPack* PlayerEquipPack::instance = new PlayerEquipPack();
PlayerEquipHandle* PlayerEquipHandle::instance = new PlayerEquipHandle();
PlayerEquipUse* PlayerEquipUse::instance = new PlayerEquipUse();

void PlayerEquipPack::CutGun(Player* player){
	player->Transmit("Pack->Handle");
	player->ChangePlayerEquipState(PlayerEquipHandle::Instance());
}

void PlayerEquipHandle::CutGun(Player* player){
	player->Transmit("Handle->Pack");
	player->ChangePlayerEquipState(PlayerEquipPack::Instance());
}
void PlayerEquipHandle::UseGun(Player* player){
	player->Transmit("Handle->Use");
	player->ChangePlayerEquipState(PlayerEquipUse::Instance());
}

void PlayerEquipUse::UnuseGun(Player* player){
	player->Transmit("Use->Handle");
	player->ChangePlayerEquipState(PlayerEquipHandle::Instance());
}