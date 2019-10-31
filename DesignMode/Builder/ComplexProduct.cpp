#include "ComplexProduct.h"
#include <cstdio>

char ComplexProduct::GetC(){
	return _c;
}
int ComplexProduct::GetI(){
	return _i;
}
short ComplexProduct::GetS(){
	return _s;
}
float ComplexProduct::GetF(){
	return _f;
}
double ComplexProduct::GetD(){
	return _d;
}

void ComplexProduct::SetC(char c){
	_c = c;
}
void ComplexProduct::SetI(int i){
	_i = i;
}
void ComplexProduct::SetS(short s){
	_s = s;
}
void ComplexProduct::SetF(float f){
	_f = f;
}
void ComplexProduct::SetD(double d){
	_d = d;
}

void ComplexProduct::Show(){
	printf("ComplexProduct\tc:%c, s:%d, i:%d, f:%f, d:%lf\n", _c, _s, _i, _f, _d);
}
