#pragma once
class Player;
class ActionHandler{
public:
	ActionHandler();
	int SetPlayer(Player*);
	int Jump();
	int Stay();
	int Flat();
	int Walk();
	int StopWalk();
	int Run();
	int StopRun();
	int SlowWalk();
	int StopSlowWalk();
	int CutGun();
	int UseGun();
	int UnuseGun();
private:
	bool _isWalk;
	bool _isShitf;
	bool _isCtrl;
	Player* _player;
};