#include "Product.h"
#include <cstdio>

class ProductA : public Product{
public:
	ProductA();
	virtual void Introduce();
};



class ProductB : public Product{
public:
	ProductB();
	virtual void Introduce();
};



class ProductC : public Product{
public:
	ProductC();
	virtual void Introduce();
};
