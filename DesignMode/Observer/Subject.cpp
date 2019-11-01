#include "Subject.h"

void OSubject::Attach(Observer* obj){
	if (obj)
		_objs.insert(obj);
}
void OSubject::Detach(Observer* obj){
	auto iter = _objs.find(obj);
	if (iter != _objs.end())
		_objs.erase(iter);
}
void OSubject::Notify(){
	for (auto iter = _objs.begin(); iter != _objs.end(); ++iter){
		(*iter)->Update(this);
	}
}