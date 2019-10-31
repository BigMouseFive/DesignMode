#include "Builders.h"


void Builder1::BuildC(){
	_product->SetC('1');
}
void Builder1::BuildS(){
	_product->SetS(1);
}
void Builder1::BuildI(){
	_product->SetI(1);
}
void Builder1::BuildF(){
	_product->SetF(1);
}
void Builder1::BuildD(){
	_product->SetD(1);
}

void Builder2::BuildC(){
	_product->SetC('2');
}
void Builder2::BuildS(){
	_product->SetS(2);
}
void Builder2::BuildI(){
	_product->SetI(2);
}
void Builder2::BuildF(){
	_product->SetF(2);
}
void Builder2::BuildD(){
	_product->SetD(2);
}