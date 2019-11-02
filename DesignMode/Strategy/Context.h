#pragma once
#include "Strategy.h"

class Context{
public:
	Context();
	~Context();
	void SetStrategy(Strategy*);
	void Sort();
private:
	std::vector<int>* _vec;
	Strategy* _strategy;
};