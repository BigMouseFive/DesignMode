#pragma once
#include "AbstractFactory.h"


class AbstractFactroy1 : public AbstractFactory{
	virtual AProduct* CrateaAProduct();
	virtual BProduct* CrateaBProduct();
};


class AbstractFactroy2 : public AbstractFactory{
	virtual AProduct* CrateaAProduct();
	virtual BProduct* CrateaBProduct();
};