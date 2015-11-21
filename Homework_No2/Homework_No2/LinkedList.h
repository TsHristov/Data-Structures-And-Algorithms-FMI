#pragma once
//TODO - finish LinkedList this evening
template<class T>
class LinkedList{
private:
	struct Node{
		T data;
		Node *next;
		Node(const T& v, Node *n) :next(n), data(v){}
		~Node(){
			if (!next){
				delete next;
			}
		}
	};

private:
	Node *head, *tail;
	size_t size;

public:
	LinkedList()
	~LinkedList();
};