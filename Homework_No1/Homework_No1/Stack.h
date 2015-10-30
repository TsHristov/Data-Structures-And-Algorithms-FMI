#include <iostream>
#include "DynamicArray.h"
#pragma once
//pop & top better be separate
class Stack
{
private:
	int top;
	DynamicArray<char> arr;

public:
	Stack();
	~Stack();

public:
	void push(const char&);
	char& pop(); //return and removes the top element
	int GetTop() const;
	bool IsEmpty() const;
	size_t GetArrSize() const;
	void print() const;
};