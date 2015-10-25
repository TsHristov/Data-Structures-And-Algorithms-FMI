#include <iostream>
#include "DynamicArray.h"
#pragma once
class Stack
{
private:
	int top;
	DynamicArray<char> arr;

public:
	Stack();
	~Stack();
	//Stack(const Stack&);
	//const Stack& operator=(const Stack&);
	//TODO write copy construcor and operator=

public:
	void push(const char&);
	char& pop(); //return and removes the top element
	bool IsEmpty() const;
	void print() const;
};