#include "AbstractFactorys.h"
#include "AProducts.h"
#include "BProducts.h"

AProduct* AbstractFactroy1::CrateaAProduct(){
	return new AProduct1();
}

BProduct* AbstractFactroy1::CrateaBProduct(){
	return new BProduct1();
}


AProduct* AbstractFactroy2::CrateaAProduct(){
	return new AProduct2();
}

BProduct* AbstractFactroy2::CrateaBProduct(){
	return new BProduct2();
}