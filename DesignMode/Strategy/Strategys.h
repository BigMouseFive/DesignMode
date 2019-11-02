#pragma once
#include "Strategy.h"
class Strategy1 : public Strategy{
public:
	virtual void Sort(std::vector<int>*);
	static Strategy1* Instance();
private:
	static Strategy1* _instance;
};

class Strategy2 : public Strategy{
public:
	virtual void Sort(std::vector<int>*);
	static Strategy2* Instance();
private:
	static Strategy2* _instance;
};