#include <iostream>
//#include "DynamicArray.h"

#pragma once
class Stack
{
private:
	//int size;
	int top_index; // when the stack is empty top equals -1
	//Here there`s should be a DynnamicArray
	int arr[10];

public:
	Stack();
	~Stack();
	//Stack(const Stack&);
	//const Stack& operator=(const Stack&);

public:
	void push(const int&);
	int& pop();
	//int& top_element() const;
	bool IsEmpty() const;
	//Stack& resize();
	void print() const;
};

