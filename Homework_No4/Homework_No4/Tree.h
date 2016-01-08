#pragma once
#include "Node.h"
#include "DynamicArray.h"

template<class T>
class Tree
{
private:
	Node<T> *root;

public:
	Tree() : root(NULL){}
	~Tree();

public:
	void build(char *str)
	{
		buildTree(root, str);
	}

	//	This function first checks whether the current two nodes of the two trees
	//	have different number of children, if so then the trees are not isomorphic.
	//
	//	If the nodes are leaves it goes back to the theit parent.
	//
	//	Next if the number of children are the same and there are
	//	still children unchecked then first sorts them
	//	based on how many children they have and recursively eneters each of the child with
	//	the above steps.
	bool Isomorphic(Node<T> *first, Node<T> *second)
	{
		if (first->countOfChildren() != second->countOfChildren())
		{
			return false;
		}
		else if (first->isLeaf() && second->isLeaf())
		{
			Isomorphic(first->parent, second->parent);
		}
		else if (first->children.hasNext() && second->children.hasNext())
		{
			//	If the children of the nodes have been sorted skip this step.
			if (!first->wasSorted)
			{
				first->sort();
			}
			if (!second->wasSorted)
			{
				second->sort();
			}
			Isomorphic(first->children.getNext(), second->children.getNext());
		}
		else
		{
			return true;
		}
	}

	void areIsomorphic(Tree &first, Tree &second)
	{
	
		if (Isomorphic(first.root, second.root))
		{
			std::cout << "YES" << endl;
		}
		else
		{
			std::cout << "NO" << endl;
		}
	}

private:
	//	Builds the tree recursively.
	void buildTree(Node<T>*, char*);
};


template<class T>
Tree<T>::~Tree()
{
	if (root)
	{
		delete root;
	}
}

template<class T>
void Tree<T>::buildTree(Node<T> * node, char* str)
{
	//	Bottom of the recursion.
	if (*str == '\0')
	{
		return;
	}

	while (*str == ' ' || *str == ')')
	{
		++str;
	}

	if (*str == '(')
	{
		++str;
		T data = *str;

		//std::cout << "Create node " << data << '\n';
		Node<T> *current = new Node<T>(data);

		if (!root)
		{
			root = current;
			buildTree(root, ++str);
		}

		if (node)
		{
			//std::cout << "Insert " << current->data << " in node " << node->data << '\n';

			node->insertChild(current);
			current->setParent(node);
			buildTree(current, ++str);
		}
	}
	else if (*str == '{')
	{
		buildTree(node, ++str);
	}
	else if (*str == '}')
	{
		buildTree(node->parent, ++str);
	}
}