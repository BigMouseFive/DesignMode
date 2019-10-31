#pragma once
class Command{
public:
	virtual void Excute() = 0;
	virtual ~Command(){};
};