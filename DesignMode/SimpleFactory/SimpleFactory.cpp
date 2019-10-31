#include "SimpleFactory.h"
#include "Products.h"
Product* SimpleFactory::CreateProduct(PRODUCT_TYPE type){
	switch (type){
	case PRODUCT_A:
		return new ProductA();
	case PRODUCT_B:
		return new ProductB();
	case PRODUCT_C:
		return new ProductC();
	default:
		printf("Product Type doesn`t exist.\n");
		return nullptr;
	}
}
