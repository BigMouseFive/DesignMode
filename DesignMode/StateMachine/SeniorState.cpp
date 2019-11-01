#include "SeniorState.h"
SeniorStateWalk* SeniorStateWalk::instance = new SeniorStateWalk();
SeniorStateRun* SeniorStateRun::instance = new SeniorStateRun();
SeniorStateSlowWalk* SeniorStateSlowWalk::instance = new SeniorStateSlowWalk();
SeniorStateStop* SeniorStateStop::instance = new SeniorStateStop();

void SeniorState::StopWalk(Player* player){
	player->Transmit("SlowWalk->Stop");
	player->ChangeSeniorState(SeniorStateWalk::Instance());
}

void SeniorStateWalk::Run(Player* player){
	player->Transmit("Walk->Run");
	player->ChangeSeniorState(SeniorStateRun::Instance());
}
void SeniorStateWalk::SlowWalk(Player* player){
	player->Transmit("Walk->SlowWalk");
	player->ChangeSeniorState(SeniorStateSlowWalk::Instance());
}

void SeniorStateRun::Walk(Player* player){
	player->Transmit("Run->Walk");
	player->ChangeSeniorState(SeniorStateWalk::Instance());
}
void SeniorStateRun::SlowWalk(Player* player){
	player->Transmit("Run->SlowWalk");
	player->ChangeSeniorState(SeniorStateSlowWalk::Instance());
}

void SeniorStateSlowWalk::Walk(Player* player){
	player->Transmit("SlowWalk->Walk");
	player->ChangeSeniorState(SeniorStateWalk::Instance());
}
void SeniorStateSlowWalk::Run(Player* player){
	player->Transmit("SlowWalk->Run");
	player->ChangeSeniorState(SeniorStateRun::Instance());
}

void SeniorStateStop::Walk(Player* player){
	player->Transmit("Stop->Walk");
	player->ChangeSeniorState(SeniorStateWalk::Instance());
}
void SeniorStateStop::Run(Player* player){
	player->Transmit("Stop->Run");
	player->ChangeSeniorState(SeniorStateRun::Instance());
}
void SeniorStateStop::SlowWalk(Player* player){
	player->Transmit("Stop->SlowWalk");
	player->ChangeSeniorState(SeniorStateSlowWalk::Instance());
}
