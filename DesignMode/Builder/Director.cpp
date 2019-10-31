#include "Director.h"
#include "ComplexProduct.h"

void Director::SetBuilder(Builder* builder){
	if (_builder)
		delete _builder;
	_builder = builder;
}
ComplexProduct* Director::Construct(){
	_builder->BuildC();
	_builder->BuildS();
	_builder->BuildI();
	_builder->BuildF();
	_builder->BuildD();
	return _builder->GetProduct();
}

Director::~Director(){
	if (_builder)
		delete _builder;
}
