#include "Observers.h"
#include "Subject.h"
#include <cstdio>
void Observer1::Update(OSubject* sub){
	printf("Observer1 Update: state->%d\n", sub->GetState());
}

