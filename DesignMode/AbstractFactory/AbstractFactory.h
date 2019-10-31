#pragma once
#include "AProduct.h"
#include "BProduct.h"

class AbstractFactory{
public:
	virtual AProduct* CrateaAProduct() = 0;
	virtual BProduct* CrateaBProduct() = 0;
	virtual ~AbstractFactory(){};
};