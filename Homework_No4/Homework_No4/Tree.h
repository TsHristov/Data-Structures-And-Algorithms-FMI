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
	~Tree()
	{
		if (root)
		{
			delete root;
		}
	}
	void buildTree(Node<T> * node, char* str)
	{
		if (*str == '\0')
		{
			return;
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

			std::cout << "Insert " << current->data << " in node " << node->data << '\n';

			node->children.insert(current);
			current->setParent(node);
			buildTree(current, ++str);
		}
		else if (*str == '{')
		{
			//	Here the children of the current node should be inserted.
			buildTree(node, ++str);
		}
		else if (*str == '}')
		{
			//	return to the parent of the node
			buildTree(node->parent, ++str);
		}
		else if (*str == ' ' || *str == ')')
		{
			buildTree(node, ++str);
		}
	}

	void build(char *str)
	{
		buildTree(root, str);
	}
};