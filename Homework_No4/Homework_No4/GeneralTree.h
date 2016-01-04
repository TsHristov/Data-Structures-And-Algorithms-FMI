#pragma once
#include "GeneralTreeNode.h"
#include "DynamicArray.h"

class GeneralTree
{

	DynamicArray<GeneralTreeNode> tree;

public:
	GeneralTreeNode getRoot()
	{
		return tree[0];
	};

	//"(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})"
	//	 deffinetely reccursion!
	void buildTree(char* str)
	{
		// дъно на рекурсията
		if ((*str) == '\0')
		{
			return;
		}

		if ((*str) == '(')
		{
			++str;
			int val = (int)(*str) - '0';
			int parentIndex;
			if (tree.GetSize() == 0)
			{
				parentIndex = -1;
			}
			GeneralTreeNode node(val, parentIndex);
			//node = new GeneralTreeNode(val, 0);
			tree.insert(node);
		}
		else if ((*str) == '{')
		{

		}

		// each root will be NULL
		if (*str == '(')
		{
				++str;
				int val = (int)(*str) - '0';
				node = new GeneralTreeNode(val, NULL, NULL);
		}

		buildTree(++str);
	}

	//Preorder Traversal
	/*void printTree(DynamicArray<GeneralTreeNode> tree)
	{
		int index = 0;

		std::cout << tree[index].data;

		//	If node has no children return.
		if (tree[index].children.IsEmpty())
		{
			return;
		}
		//	If it has then print them,and search whether they have children or not
		else
		{

			while (1)
			{
				print(tree[index].children[0]);
				// foreach child print its children
				// then return;
				// display info for first child of root
				tree[index].children[0];

				// display info for second child of root
				tree[index].children[1];
			}
		}
	}

	void print()
	{
		printTree(this->tree);
	}*/
};