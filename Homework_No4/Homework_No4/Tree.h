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

	void build(char *str)
	{
		buildTree(root, str);
	}
};