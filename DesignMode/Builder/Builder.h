#pragma once
#include "ComplexProduct.h"
class Builder{
public:
	Builder(){
		_product = new ComplexProduct();
	}
	virtual ~Builder(){
		if (_product)
			delete _product;
	}

	ComplexProduct* GetProduct(){
		return _product;
	}
	virtual void BuildC() = 0;
	virtual void BuildS() = 0;
	virtual void BuildI() = 0;
	virtual void BuildF() = 0;
	virtual void BuildD() = 0;
protected:
	ComplexProduct* _product;
};