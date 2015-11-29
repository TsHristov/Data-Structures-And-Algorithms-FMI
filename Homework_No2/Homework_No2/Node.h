#pragma once
template<class T>
struct Node{
	T data;
	Node *pNext;

public:
	Node(const T& d, Node *next = nullptr) :data(d), pNext(next){}
	~Node(){
		delete pNext;
	}
	void showNode() const{
		std::cout << data << '\n';
	}
};