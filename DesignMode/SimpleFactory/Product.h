#pragma once
#define PRODUCT_A 0x01
#define PRODUCT_B 0x02
#define PRODUCT_C 0x03
typedef int PRODUCT_TYPE;

class Product{
public:
	Product(PRODUCT_TYPE type) :_type(type){}
	PRODUCT_TYPE GetType(){
		return _type;
	}
	virtual void Introduce() = 0;
private:
	PRODUCT_TYPE _type;
};