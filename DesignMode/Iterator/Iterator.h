#pragma once
template<class _T>
class ListNode{
public:
	_T value;
	ListNode<_T>* pre;
	ListNode<_T>* next;
	ListNode(){
		pre = nullptr;
		next = nullptr;
	}
	ListNode(_T v){
		value = v;
		ListNode<_T>();
	}
};

template<class _T>
class Container;

template<class _T>
class Iterator{
public:
	Iterator(ListNode<_T>* node, Container<_T>& con){
		_ptr = node;
		_con = &con;
	}
	virtual _T& operator*() = 0;
	virtual Iterator<_T>& operator++ () = 0;
	virtual Iterator<_T>& operator++ (int) = 0;
	virtual Iterator<_T>& operator-- () = 0;
	virtual Iterator<_T>& operator-- (int) = 0;
	virtual bool operator== (Iterator*) = 0;
	virtual bool operator!= (Iterator*) = 0;
	virtual ~Iterator(){}
	ListNode<_T>* GetPtr(){ return _ptr; }
	ListNode<_T>* GetCon(){ return _con; }
protected:
	ListNode<_T>* _ptr;
	Container<_T>* _con;
private:
	Iterator(){}
};