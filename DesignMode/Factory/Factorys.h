#pragma once
#include "Factory.h"

class FactoryA : public Factory{
	virtual Product* CreateProduct();
};



class FactoryB : public Factory{
	virtual Product* CreateProduct();
};



class FactoryC : public Factory{
	virtual Product* CreateProduct();
};

