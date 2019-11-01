#pragma once
#include "Iterator.h"
template<class _T>
class Container{
public:
	Container(){
		_head = new ListNode<_T>();
		_tail = new ListNode<_T>();
		_head->next = _tail;
		_tail->pre = _head;
	}
	~Container(){
		Clear();
	}
	Iterator<_T>* Begin(){
		Iterator<_T>* iter = new Iterator1<_T>(_head->next, *this);
		return iter;
	}
	Iterator<_T>* End(){
		Iterator<_T>* iter = new Iterator1<_T>(_tail, *this);
		return iter;
	}
	void PushBack(_T a){
		ListNode<_T>* new_node = new ListNode<_T>(a);
		new_node->pre = _tail->pre;
		_tail->pre->next = new_node;
		new_node->next = _tail;
		_tail->pre = new_node;
	}

	Iterator<_T>& Insert(Iterator<_T>& iter, _T a){
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
	void PopBack(){
		ListNode<_T>* p = _tail->pre;
		p->pre->next = _tail;
		_tail->pre = p->pre;
		delete p;
	}
	Iterator<_T>& Erase(Iterator<_T>& iter){
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
	_T& Value(int a){
		ListNode<_T>* p = _head->next;
		while (a-- > 0 && p != _tail){
			p = p->next;
		}
		if (p != _tail)
			return p->value;
		else
			throw 1;  //ugly code
	}
	_T& operator[](int){
		return Value(int a);
	}
	bool Empty(){
		return (_head->next == _tail);
	}
	void Clear(){
		ListNode<_T>* p = _head->next;
		while (p != _tail){
			p = p->next;
			delete p->pre;
			_head->next = p;
		}
		_tail->pre = _head;
	}
	ListNode<_T>* GetHead(){ return _head; }
	ListNode<_T>* GetTail(){ return _tail; }
private:
	ListNode<_T>* _head;
	ListNode<_T>* _tail;
};