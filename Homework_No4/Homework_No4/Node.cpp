#include "Node.h"

Node::~Node()
{
	for (size_t i = 0; i < children.GetSize(); ++i)
	{
		if (children[i])
		{
			delete children[i];
		}
	}
};

Node::Node(const Node& o)
{
	wasSorted = o.wasSorted;
	data = o.data;
	parent = o.parent;
	children = o.children;
}

Node::Node(std::string &data)
{
	this->wasSorted = false;
	this->data = data;
	this->parent = NULL;
}

std::string Node::getData() const
{
	return this->data;
}

bool Node::isLeaf() const
{
	if (this->children.IsEmpty() && this->parent != NULL)
		return true;
	else
		return false;
}


void Node::insertChild(Node *n)
{
	this->children.insert(n);
}


void Node::setParent(Node *node)
{
	this->parent = node;
}


size_t Node::countOfChildren() const
{
	return this->children.GetSize();
}


void Node::swap(Node *&a, Node *&b)
{
	if (b->countOfChildren() < a->countOfChildren())
	{
		Node *temp = a;
		a = b;
		b = temp;
	}
}


void Node::SelectionSort()
{
	if (children.GetSize() == 0)
		return;

	for (size_t i = 0; i < children.GetSize() - 1; i++)
	{

		size_t min = i;

		for (size_t j = i + 1; j < children.GetSize(); j++)
		{
			if (children[j]->countOfChildren() < children[min]->countOfChildren())
				min = j;
		}

		swap(children[i], children[min]);
	}
}


void Node::sort()
{
	SelectionSort();
	this->wasSorted = true;
}