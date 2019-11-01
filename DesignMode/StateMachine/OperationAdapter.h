#pragma once
#include "OperationTarget.h"
#include "ActionHandler.h"
class OperationAdapter : public OperationTarget{
public:
	OperationAdapter();
	~OperationAdapter();
	virtual int KeyWPressed();		//前走
	virtual int KeyWReleased();
	virtual int KeyZ();				//趴下/站起
	virtual int KeyX();				//切枪
	virtual int KeyC();				//蹲下/蹲起/站起
	virtual int KeyShiftPressed();	//+W 奔跑
	virtual int KeyCtrlPressed();
	virtual int KeyShiftReleased();	//+W 慢走
	virtual int KeyCtrlReleased();
	virtual int KeySpace();			//跳/蹲起/站起
	virtual int KeyMouseLeftPressed();//使用枪
	virtual int KeyMouseLeftReleased();
	virtual void SetPlayer(Player*);
private:
	ActionHandler* _handler;
};