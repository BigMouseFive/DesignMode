#pragma once
#include "Product.h"
class SimpleFactory{
public:
	static Product* CreateProduct(PRODUCT_TYPE);
};