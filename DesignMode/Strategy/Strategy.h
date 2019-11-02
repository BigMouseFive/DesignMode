#pragma once
#include <vector>
class Strategy{
public:
	virtual void Sort(std::vector<int>*) = 0;
	virtual ~Strategy(){}
};
