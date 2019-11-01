#pragma once
class Player;
class OperationTarget{
public:
	virtual int KeyWPressed() = 0;		//前走
	//virtual int KeyAPressed() = 0;	//左走
	//virtual int KeySPressed() = 0;	//后走
	//virtual int KeyDPressed() = 0;	//右走
	virtual int KeyWReleased() = 0;
	//virtual int KeyAReleased() = 0;
	//virtual int KeySReleased() = 0;
	//virtual int KeyDReleased() = 0;
	virtual int KeyZ() = 0;				//趴下/站起
	virtual int KeyX() = 0;				//切枪
	virtual int KeyC() = 0;				//蹲下/蹲起/站起
	virtual int KeyShiftPressed() = 0;	//+W 奔跑
	virtual int KeyCtrlPressed() = 0;	
	virtual int KeyShiftReleased() = 0;	//+W 慢走
	virtual int KeyCtrlReleased() = 0;
	virtual int KeySpace() = 0;			//跳/蹲起/站起
	virtual int KeyMouseLeftPressed() = 0;//使用枪
	virtual int KeyMouseLeftReleased() = 0;
	virtual void SetPlayer(Player*) = 0;
	virtual ~OperationTarget(){}
};