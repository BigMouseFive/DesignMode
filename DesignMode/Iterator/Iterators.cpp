#include "Iterators.h"
#include "Container.h"

template<class _T>
Iterator1<_T>::Iterator1(ListNode<_T>* node, Container<_T>& con)
	:Iterator<_T>(node, con){
}

template<class _T>
_T& Iterator1<_T>::operator*(){
	if (_ptr != _con->GetTail()){
		return _ptr->value;
	}
	else
		throw 1;
}

template<class _T>
_T* Iterator1<_T>::operator->(){
	if (_ptr != _con->GetTail()){
		return _ptr->value;
	}
	else
		throw 1;
}

template<class _T>
Iterator<_T>& Iterator1<_T>::operator++(){
	if (_ptr != _con->GetTail()){
		_ptr = _ptr->next;
	}
	return *this; 
}

template<class _T>
Iterator<_T>& Iterator1<_T>::operator++(int){
	Iterator1<_T> *iter = this;
	if (_ptr != _con->GetTail()){
		_ptr = _ptr->next;
	}
	return *iter;
}

template<class _T>
Iterator<_T>& Iterator1<_T>::operator--(){
	if (_ptr != _con->GetHead()){
		_ptr = _ptr->pre;
	}
	return *this;
}

template<class _T>
Iterator<_T>& Iterator1<_T>::operator--(int){
	Iterator1<_T> *iter = this;
	if (_ptr != _con->GetHead()){
		_ptr = _ptr->pre;
	}
	return *iter;
}

template<class _T>
bool Iterator1<_T>::operator==(const Iterator<_T>& iter){
	return (iter->GetPtr() == _ptr);
}

template<class _T>
bool Iterator1<_T>::operator!=(const Iterator<_T>& iter){
	return (iter->GetPtr() != _ptr);
}
