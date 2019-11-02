#include "Context.h"

Context::Context()
	:_strategy(nullptr){
	_vec = new std::vector<int>();
}
Context::~Context(){
	if (_vec){
		_vec->clear();
		delete _vec;
	}
}
void Context::SetStrategy(Strategy* strategy){
	_strategy = strategy;
}
void Context::Sort(){
	if (_strategy){
		_strategy->Sort(_vec);
	}
}