#pragma once
#include <string>
#include "DynamicArray.h"

class Node
{

public:
	bool wasSorted;
	std::string data;
	Node *parent;
	DynamicArray<Node*> children;

public:
	Node() :parent(NULL),wasSorted(false){}
	~Node();
	Node(const Node&);
	Node(std::string&);
	
public:
	std::string getData() const;
	bool isLeaf() const;
	void insertChild(Node*);
	void setParent(Node*);
	size_t countOfChildren() const;

public:
	//	Proxy to sort the children of the current node,
	//	based on this how many children they have.
	//	This step helps to check for isomorphism in both trees.
	void sort();

private:
	void swap(Node *&, Node *&);
	void SelectionSort();
};