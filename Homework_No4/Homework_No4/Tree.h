#pragma once
#include "Node.h"
#include "DynamicArray.h"

class Tree
{
private:
	Node *root;

public:
	Tree(): root(NULL){}
	~Tree()
	{
		if (root)
		{
			delete root;
		}
	}
	void buildTree(Node *& node, char* str)
	{
		if (*str == '\0')
		{
			return;
		}

		Node *current = NULL;

		if (*str == '(')
		{
			++str;
			int data = (int)(*str) - '0';
			
			std::cout << "Create node " << data << '\n';
			current = new Node(data);

			if (!root)
			{
				root = current;
				buildTree(root, ++str);
			}
			
			std::cout << "Insert " << current->data << " in node " << node->data << '\n';
			
			node->children.insert(current);
			buildTree(current, ++str);
		}
		else if (*str == '{')
		{
			//	Here the children of the current node should be inserted.
			buildTree(node,++str);
		}
		else if (*str == '}')
		{
			//	Return to the main node and continue . . .
			buildTree(root, ++str);
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