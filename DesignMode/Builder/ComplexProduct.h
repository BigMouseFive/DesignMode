#pragma once

class ComplexProduct{
public:
	char GetC();
	int GetI();
	short GetS();
	float GetF();
	double GetD();

	void SetC(char);
	void SetI(int);
	void SetS(short);
	void SetF(float);
	void SetD(double);

	void Show();
private:
	char _c;
	int _i;
	short _s;
	float _f;
	double _d;
};