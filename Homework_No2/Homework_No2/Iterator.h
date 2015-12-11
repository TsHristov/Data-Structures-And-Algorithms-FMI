#pragma once
#include "Node.h"
template<class T>
class Iterator
{
private:
	Node<T> *pStart;
	Node<T> *pCurrent;
public:
	Iterator(Node<T> *pStart)
	{
		this->pStart = this->pCurrent = pStart;
	}

public:
	T const & GetCurrent() const
	{
		return this->pCurrent->data;
	}
	void SetCurrent(T const & Value)
	{
		this->pCurrent->data = Value;
	}
	void MoveNext()
	{
		if (this->pCurrent)
		{
			this->pCurrent = this->pCurrent->pNext;
		}
	}
	bool End() const
	{
		return this->pCurrent == NULL;
	}
};