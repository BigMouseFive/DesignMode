#include "Factorys.h"
#include "../SimpleFactory/Products.h"

Product* FactoryA::CreateProduct(){
	return new ProductA;
}

Product* FactoryB::CreateProduct(){
	return new ProductB;
}

Product* FactoryC::CreateProduct(){
	return new ProductC;
}