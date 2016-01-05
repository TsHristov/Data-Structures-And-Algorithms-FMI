#pragma once
#include <iostream>
#include "DynamicArray.h"

class Node
{

public:
	int data;
	//int parentIndex;
	DynamicArray<Node> children;

public:
	Node():data(-1){}
	Node(const int data)
	{
		this->data = data;
		//this->parentIndex = parentIndex;
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
	void insertChild(Node &n)
	{
		this->children.insert(n);
	}
	
	Node nextChild()
	{
		return this->children.getNext();
	}

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