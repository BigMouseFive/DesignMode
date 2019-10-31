#pragma once
#include "../SimpleFactory/Product.h"
class Factory{
public:
	virtual Product* CreateProduct() = 0;
	virtual ~Factory(){}
};