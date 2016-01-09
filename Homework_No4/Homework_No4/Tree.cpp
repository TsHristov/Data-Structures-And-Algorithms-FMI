#include "Tree.h"
#include <iostream>

Tree::Tree(char *str)
{
	root = NULL;
	buildTree(root, str);
}


Tree::~Tree()
{
	if (root)
	{
		delete root;
	}
}


void Tree::buildTree(Node * node, char* str)
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
		std::string data;
		while (*str != '{')
		{
			if (*str == ' ')
			{
				++str;
				continue;
			}
			data.push_back(*str);
			++str;
		}

		Node *current = new Node(data);

		if (!root)
		{
			root = current;
			buildTree(root, ++str);
		}

		if (node)
		{
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


void Tree::areIsomorphic(Tree &first, Tree &second)
{

	if (Isomorphic(first.root, second.root))
	{
		std::cout << "YES" << '\n';
	}
	else
	{
		std::cout << "NO" << '\n';
	}
}


bool Tree::Isomorphic(Node *first, Node *second)
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