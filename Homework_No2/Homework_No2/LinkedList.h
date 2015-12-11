#pragma once
#include "Node.h"
template<class T>
class LinkedList
{
private:
	Node<T> *pHead, *pTail;
	size_t size;

public:
	LinkedList() :pHead(nullptr), pTail(nullptr), size(0){}
	~LinkedList(){
		if (pHead)
		{
			delete pHead;
		}
	}

public:
	bool IsEmpty() const{
		return size == 0;
	}
	void add(const T&);
	Iterator<T> GetIterator() const;
};

template<class T>
void LinkedList<T>::add(const T& val)
{
	if (this->IsEmpty())
	{
		pHead = new Node<T>(val,pHead);
		pTail = pHead;
		++size;
	}
	else
	{
		Node<T> *newNode = new Node<T>(val, nullptr);
		pTail->pNext = newNode;
		pTail = newNode;
		++size;
	}

}

template <class T>
Iterator<T> LinkedList<T>::GetIterator() const
{
	return Iterator<T>(this->pHead);
}