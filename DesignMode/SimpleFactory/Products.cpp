#include "Products.h"


ProductA::ProductA() 
	: Product(PRODUCT_A){
}
void ProductA::Introduce(){
	printf("I am Product A.\n");
}



ProductB::ProductB()
	: Product(PRODUCT_B){
}
void ProductB::Introduce(){
	printf("I am Product B.\n");
}



ProductC::ProductC() 
	: Product(PRODUCT_C){
}
void ProductC::Introduce(){
	printf("I am Product C.\n");
}