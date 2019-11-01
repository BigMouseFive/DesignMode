#pragma once
#include "OperationTarget.h"
#include "ActionHandler.h"
class OperationAdapter : public OperationTarget{
public:
	OperationAdapter();
	~OperationAdapter();
	virtual int KeyWPressed();		//ǰ��
	virtual int KeyWReleased();
	virtual int KeyZ();				//ſ��/վ��
	virtual int KeyX();				//��ǹ
	virtual int KeyC();				//����/����/վ��
	virtual int KeyShiftPressed();	//+W ����
	virtual int KeyCtrlPressed();
	virtual int KeyShiftReleased();	//+W ����
	virtual int KeyCtrlReleased();
	virtual int KeySpace();			//��/����/վ��
	virtual int KeyMouseLeftPressed();//ʹ��ǹ
	virtual int KeyMouseLeftReleased();
	virtual void SetPlayer(Player*);
private:
	ActionHandler* _handler;
};