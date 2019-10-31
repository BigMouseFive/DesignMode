#pragma once
#include "Builder.h"
class Director{
public:
	Director() :_builder(nullptr){}
	void SetBuilder(Builder*);
	ComplexProduct* Construct();
	~Director();
private:
	Builder* _builder;
};