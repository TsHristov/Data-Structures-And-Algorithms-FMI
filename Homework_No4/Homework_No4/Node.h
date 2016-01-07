#pragma once
#include <iostream>
#include "DynamicArray.h"

template<class T>
class Node
{
public:
	bool sorted;
	T data;
	Node<T> *parent;
	DynamicArray<Node<T>*> children;

public:
	Node() :parent(NULL),sorted(false){}
	~Node();
	Node(const Node<T>&);
	Node(const T);
	

public:
	T getData() const;
	bool isLeaf() const;
	void insertChild(Node<T>*);
	void setParent(Node<T>*);
	size_t countOfChildren();
	void printChildren();

public:
	void sort();

private:
	void swapif(Node<T> *&, Node<T> *&);
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
	sorted = o.sorted;
	data = o.data;
	parent = o.parent;
	children = o.children;
}

template<class T>
Node<T>::Node(const T data)
{
	this->sorted = false;
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
size_t Node<T>::countOfChildren()
{
	return this->children.GetSize();
}


template<class T>
void Node<T>::printChildren()
{
	for (size_t i = 0; i < children.GetSize(); ++i)
	{
		std::cout << (char)children[i]->getData() << '\n';
	}
}


template<class T>
void Node<T>::swapif(Node<T> *&a, Node<T> *&b)
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
	if (this->children.GetSize() == 0)
		return;

	for (size_t i = 0; i < this->children.GetSize() - 1; i++)
	{
		size_t min = i;

		for (size_t j = i + 1; j < this->children.GetSize(); j++)
		{
			std::cout << "Node " << (char)children[j]->getData()
				<< " has " << children[j]->countOfChildren() << " children" << '\n';

			std::cout << "Node " << (char)children[min]->getData()
				<< " has " << children[min]->countOfChildren() << " children" << '\n';
			if (children[j]->countOfChildren() < children[min]->countOfChildren())
				min = j;
		}

		std::cout << "Before:" << (char)children[i]->getData() << (char)children[min]->getData() << '\n';
		swapif(children[i], children[min]);
		std::cout << "After:" << (char)children[i]->getData() << (char)children[min]->getData() << '\n';

	}
}


template<class T>
void Node<T>::sort()
{
	SelectionSort();
	this->sorted = true;
}