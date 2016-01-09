#pragma once
#include "Node.h"
#include "DynamicArray.h"

class Tree
{
private:
	Node *root;

public:
	Tree() : root(NULL){}
	Tree(char*);
	~Tree();

public:
	static void areIsomorphic(Tree &, Tree &);

private:
	//	Builds the tree recursively.
	void buildTree(Node*, char*);

	//	This function first checks whether the current two nodes of the two trees
	//	have different number of children, if so then the trees are not isomorphic.
	//
	//	If the nodes are leaves it goes back to the theit parent.
	//
	//	Next if the number of children are the same and there are
	//	still children unchecked then first sorts them
	//	based on how many children they have and recursively eneters each of the child with
	//	the above steps.
	static bool Isomorphic(Node *, Node *);
};