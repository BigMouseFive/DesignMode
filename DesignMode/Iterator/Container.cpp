#include "Container.h"
#include "Iterators.h"
template<class _T>
Container<_T>::Container(){
	_head = new ListNode<_T>();
	_tail = new ListNode<_T>();
	_head->next = _tail;
	_tail->pre = _head;
}


template<class _T>
Container<_T>::~Container(){
	Clear();
}

template<class _T>
Iterator<_T>* Container<_T>::Begin(){
	Iterator<_T>* iter = new Iterator<_T>(_head->next, this);
	return iter;
}

template<class _T>
Iterator<_T>* Container<_T>::End(){
	Iterator<_T>* iter = new Iterator<_T>(_tail->pre, this);
	return iter;
}

template<class _T>
void Container<_T>::PushBack(_T& a){
	ListNode<_T>* new_node = new ListNode<_T>(a);
	new_node->pre = _tail->pre;
	_tail->pre->next = new_node;
	new_node->next = _tail;
	_tail->pre = new_node;
}

template<class _T>
Iterator<_T>& Container<_T>::Insert(Iterator<_T>& iter, _T& a){
	ListNode<_T>* p = _head->next;
	ListNode<_T>* ip = iter.GetPtr();

	while (p != _tail){
		if (p == ip) {
			break;
		}
		p = p->next;
	}
	if (p == ip){
		ListNode<_T>* new_node = new ListNode<_T>(a);
		new_node->pre = p->pre;
		p->pre->next = new_node;
		new_node->next = p;
		p->pre = new_node;
		iter--;
	}
	return iter;
}

template<class _T>
void Container<_T>::PopBack(){
	ListNode<_T>* p = _tail->pre;
	p->pre->next = _tail;
	_tail->pre = p->pre;
	delete p;
}

template<class _T>
Iterator<_T>& Container<_T>::Erase(Iterator<_T>& iter){
	ListNode<_T>* p = _head->next;
	ListNode<_T>* ip = iter.GetPtr();

	while (p != _tail){
		if (p == ip) {
			break;
		}
		p = p->next;
	}
	if (p == ip){
		iter++;
		p->pre->next = p->next;
		p->next->pre = p->pre;
		delete p;
	}
	return iter;
}

template<class _T>
_T& Container<_T>::Value(int a){
	ListNode<_T>* p = _head->next;
	while (a-- > 0 && p != _tail){
		p = p->next;
	}
	if (p != _tail)
		return p->value;
	else
		throw 1;  //ugly code
}

template<class _T>
_T& Container<_T>::operator[](int a){
	return Value(int a);
}

template<class _T>
bool Container<_T>::Empty(){
	return (_head->next == _tail);
}

template<class _T>
void Container<_T>::Clear(){
	ListNode<_T>* p = _head->next;
	while (p != _tail){
		p = p->next;
		delete p->pre;
		_head->next = p;
	}
	_tail->pre = _head;
}