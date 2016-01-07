#pragma once
#include <iostream>
#include "DynamicArray.h"

template<class T>
class Node
{
public:
	T data;
	Node<T> *parent;
	DynamicArray<Node<T>*> children;

public:
	Node():parent(NULL){}
	Node(const T data)
	{
		this->data = data;
	}
	int getData() const
	{
		return this->data;
	}
	bool isLeaf() const
	{
		if (this->children.IsEmpty())
			return true;
		else
			return false;
	}
	void insertChild(Node<T> *n)
	{
		this->children.insert(n);
	}

	void setParent(Node<T> *node)
	{
		this->parent = node;
	}
	
	/*Node nextChild()
	{
		return this->children.getNext();
	}*/

	/*int getParentIndex() const
	{
		return this->parentIndex;
	}*/

	/*bool isRoot() const
	{
		return this->getParentIndex() == -1;
	}*/

	int countOfChildren()
	{
		return this->children.GetSize();
	}
};