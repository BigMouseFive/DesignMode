#pragma once
class OSubject;
class Observer{
public:
	virtual void Update(OSubject*) = 0;
	virtual ~Observer(){}
};