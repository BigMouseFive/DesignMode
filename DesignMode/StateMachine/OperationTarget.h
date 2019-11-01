#pragma once
class Player;
class OperationTarget{
public:
	virtual int KeyWPressed() = 0;		//ǰ��
	//virtual int KeyAPressed() = 0;	//����
	//virtual int KeySPressed() = 0;	//����
	//virtual int KeyDPressed() = 0;	//����
	virtual int KeyWReleased() = 0;
	//virtual int KeyAReleased() = 0;
	//virtual int KeySReleased() = 0;
	//virtual int KeyDReleased() = 0;
	virtual int KeyZ() = 0;				//ſ��/վ��
	virtual int KeyX() = 0;				//��ǹ
	virtual int KeyC() = 0;				//����/����/վ��
	virtual int KeyShiftPressed() = 0;	//+W ����
	virtual int KeyCtrlPressed() = 0;	
	virtual int KeyShiftReleased() = 0;	//+W ����
	virtual int KeyCtrlReleased() = 0;
	virtual int KeySpace() = 0;			//��/����/վ��
	virtual int KeyMouseLeftPressed() = 0;//ʹ��ǹ
	virtual int KeyMouseLeftReleased() = 0;
	virtual void SetPlayer(Player*) = 0;
	virtual ~OperationTarget(){}
};