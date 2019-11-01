#pragma once
#include "Player.h"
class SeniorState{
public:
	virtual void Walk(Player* player){}
	virtual void StopWalk(Player* player);
	virtual void Run(Player* player){}
	virtual void SlowWalk(Player* player){}
	virtual ~SeniorState(){}
};
class SeniorStateWalk : public SeniorState{
public:
	virtual void Run(Player* player);
	virtual void SlowWalk(Player* player);
	static SeniorStateWalk* Instance(){
		return instance;
	}
private:
	static SeniorStateWalk* instance;
};
class SeniorStateRun : public SeniorState{
public:
	virtual void Walk(Player* player);
	virtual void SlowWalk(Player* player);
	static SeniorStateRun* Instance(){
		return instance;
	}
private:
	static SeniorStateRun* instance;
};
class SeniorStateSlowWalk : public SeniorState{
public:
	virtual void Walk(Player* player);
	virtual void Run(Player* player);
	static SeniorStateSlowWalk* Instance(){
		return instance;
	}
private:
	static SeniorStateSlowWalk* instance;
};
class SeniorStateStop : public SeniorState{
public:
	virtual void Walk(Player* player);
	virtual void Run(Player* player);
	virtual void SlowWalk(Player* player);
	static SeniorStateStop* Instance(){
		return instance;
	}
private:
	static SeniorStateStop* instance;
};
