#pragma once
template<class T>
struct Node{
	T data;
	Node *pNext;

public:
	Node(const T& d, Node *next) :pNext(next), data(d){}
	~Node(){
		if (pNext)
		{
			delete pNext;
		}
	}
};