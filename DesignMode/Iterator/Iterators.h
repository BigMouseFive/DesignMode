#pragma once
#include "Iterator.h"
#include "Container.h"
template<class _T>
class Iterator1 : public Iterator<_T>{
public:
	Iterator1(ListNode<_T>* node, Container<_T>& con)
		:Iterator<_T>(node, con){
	}
	virtual _T& operator*(){
		if (_ptr != _con->GetTail()){
			return _ptr->value;
		}
		else
			throw 1;
	}
	virtual Iterator<_T>& operator++ (){
		if (_ptr != _con->GetTail()){
			_ptr = _ptr->next;
		}
		return *this;
	}
	virtual Iterator<_T>& operator++ (int a){
		Iterator1<_T> *iter = this;
		if (_ptr != _con->GetTail()){
			_ptr = _ptr->next;
		}
		return *iter;
	}
	virtual Iterator<_T>& operator-- (){
		if (_ptr != _con->GetHead()){
			_ptr = _ptr->pre;
		}
		return *this;
	}
	virtual Iterator<_T>& operator-- (int a){
		Iterator1<_T> *iter = this;
		if (_ptr != _con->GetHead()){
			_ptr = _ptr->pre;
		}
		return *iter;
	}
	virtual bool operator== (Iterator<_T>* iter){
		return (_ptr == iter->GetPtr());
	}
	virtual bool operator!= (Iterator<_T>* iter){
		return (_ptr != iter->GetPtr());
	}
};