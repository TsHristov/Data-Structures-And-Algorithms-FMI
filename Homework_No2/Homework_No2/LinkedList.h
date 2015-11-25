#pragma once
//TODO - finish LinkedList this evening
template<class T>
class LinkedList
{
private:
	struct Node{
		T data;
		Node *pNext;

	public:
		Node(const T& d, Node *next = NULL) :data(d), pNext(next){}
		~Node(){
			delete pNext;
		}
	};

	Node *pHead, *pTail;
	size_t size;

public:
	LinkedList() :pHead(nullptr), pTail(nullptr), size(0){}
	~LinkedList(){
		delete pHead;
	}

public:
	bool IsEmpty() const{
		return size == 0;
	}
	void add(const T&);
};

template<class T>
void LinkedList<T>::add(const T& val)
{
	if (this->IsEmpty())
	{
		pHead = new Node(val, nullptr);
		pTail = pHead;
		++size;
	}
	else
	{
		Node *newNode = new Node(val, nullptr);
		pTail->pNext = newNode;
		pTail = newNode;
		++size;
	}

}