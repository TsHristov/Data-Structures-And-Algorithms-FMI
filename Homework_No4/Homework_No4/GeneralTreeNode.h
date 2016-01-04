#pragma once
#include <iostream>
#include "DynamicArray.h"

class GeneralTreeNode
{

public:
	int data;
	int parentIndex;
	DynamicArray<GeneralTreeNode> children;

public:
	GeneralTreeNode(const int data, int parentIndex)
	{
		this->data = data;
		this->parentIndex = parentIndex;
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
	void insertChild(GeneralTreeNode &n)
	{
		this->children.insert(n);
	}

	int getParentIndex() const
	{
		return this->parentIndex;
	}

	bool isRoot() const
	{
		return this->getParentIndex() == -1;
	}

	int countOfChildren()
	{
		return this->children.GetSize();
	}
};