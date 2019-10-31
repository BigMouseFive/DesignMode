#pragma once
class Target {
public:
	virtual void Interface1() = 0;
	virtual void Interface2() = 0;
	virtual ~Target(){}
};