#include <iostream>
#include "DynamicArray.h"
#pragma once

class Stack
{
private:
	int top_index;
	DynamicArray<char> arr;

public:
	Stack();
	~Stack();

public:
	void push(const char&);
	void pop();
	char  top();
	int GetTop() const;
	bool IsEmpty() const;
	size_t GetArrSize() const;
	void print() const;
};