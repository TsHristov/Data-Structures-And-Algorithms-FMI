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
			//	If the array of children for the node has been sorted don`t sort it again.
			if (!first->sorted)
			{
				first->sort();
			}
			if (!second->sorted)
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

		std::cout << "Create node " << data << '\n';
		Node<T> *current = new Node<T>(data);

		if (!root)
		{
			root = current;
			buildTree(root, ++str);
		}

		if (node)
		{
			std::cout << "Insert " << current->data << " in node " << node->data << '\n';

			node->children.insert(current);
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