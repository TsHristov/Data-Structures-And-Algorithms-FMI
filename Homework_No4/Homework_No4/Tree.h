#pragma once
#include "Node.h"
#include "DynamicArray.h"

class Tree
{
	Node root;
public:
	Tree(){}
	void buildTree(Node node, char* str)
	{
		if (*str == '\0')
		{
			return;
		}
		Node current;
		if (*str == '(')
		{
			++str;
			int data = (int)(*str) - '0';
			
			current.data = data;

			if (root.data == -1)
			{
				root = current;
			}
			else
			{
				root.children.insert(current);
			}
		}
		else if (*str == '{')
		{
			//	Here the children of the current node should be inserted.
			buildTree(current,++str);
		}
		else if (*str == '}')
		{
			//	Return to the main node and continue . . .
			buildTree(root, ++str);
		}
	}

	void build(char *str)
	{
		buildTree(root, str);
	}
};