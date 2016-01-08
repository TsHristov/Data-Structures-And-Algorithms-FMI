#pragma once
#include <iostream>
#include "DynamicArray.h"

template<class T>
class Node
{

public:
	bool wasSorted;
	T data;
	Node<T> *parent;
	DynamicArray<Node<T>*> children;

public:
	Node() :parent(NULL),wasSorted(false){}
	~Node();
	Node(const Node<T>&);
	Node(const T);
	
public:
	T getData() const;
	bool isLeaf() const;
	void insertChild(Node<T>*);
	void setParent(Node<T>*);
	size_t countOfChildren() const;
	void printChildren() const;

public:
	//	Proxy to sort the children of the current node,
	//	based on this how many children they have.
	void sort();

private:
	void swap(Node<T> *&, Node<T> *&);
	void SelectionSort();
};


template<class T>
Node<T>::~Node()
{
	for (size_t i = 0; i < children.GetSize(); ++i)
	{
		if (children[i])
		{
			delete children[i];
		}
	}
};

template<class T>
Node<T>::Node(const Node<T>& o)
{
	wasSorted = o.wasSorted;
	data = o.data;
	parent = o.parent;
	children = o.children;
}

template<class T>
Node<T>::Node(const T data)
{
	this->wasSorted = false;
	this->data = data;
	this->parent = NULL;
}

template<class T>
T Node<T>::getData() const
{
	return this->data;
}

template<class T>
bool Node<T>::isLeaf() const
{
	if (this->children.IsEmpty() && this->parent != NULL)
		return true;
	else
		return false;
}


template<class T>
void Node<T>::insertChild(Node<T> *n)
{
	this->children.insert(n);
}


template<class T>
void Node<T>::setParent(Node<T> *node)
{
	this->parent = node;
}


template<class T>
size_t Node<T>::countOfChildren() const
{
	return this->children.GetSize();
}


template<class T>
void Node<T>::printChildren() const
{
	for (size_t i = 0; i < children.GetSize(); ++i)
	{
		std::cout << (char)children[i]->getData() << '\n';
	}
}


template<class T>
void Node<T>::swap(Node<T> *&a, Node<T> *&b)
{
	if (b->countOfChildren() < a->countOfChildren())
	{
		Node<T> *temp = a;
		a = b;
		b = temp;
	}
}


template<class T>
void Node<T>::SelectionSort()
{
	if (children.GetSize() == 0)
		return;

	for (size_t i = 0; i < children.GetSize() - 1; i++)
	{

		size_t min = i;

		for (size_t j = i + 1; j < children.GetSize(); j++)
		{
			if (children[j]->countOfChildren() < children[min]->countOfChildren())
				min = j;
		}

		swap(children[i], children[min]);
	}
}


template<class T>
void Node<T>::sort()
{
	SelectionSort();
	this->wasSorted = true;
}