#include <iostream>
#include "DynamicArray.h"
#pragma once

template<class T>
class Stack
{
private:
	int top_index;
	DynamicArray<T> arr;

public:
	Stack();
	//~Stack();

public:
	void push(const T&);
	void pop();
	T  top();
	int GetTop() const;
	bool IsEmpty() const;
	size_t GetArrSize() const;
	void print() const;
};

template<class T>
Stack<T>::Stack(){
	top_index = -1;
}

template<class T>
void Stack<T>::push(const T& item){
	arr.insert(item);
	top_index++;
}

template<class T>
void Stack<T>::pop(){
	arr.removeElement();
	--top_index;
}

template<class T>
T Stack<T>::top(){
	return arr[top_index];
}

template<class T>
int Stack<T>::GetTop() const{
	return top_index;
}

template<class T>
bool Stack<T>::IsEmpty() const{
	if (top_index == -1){
		return true;
	}
	else{
		return false;
	}
}

template<class T>
size_t Stack<T>::GetArrSize() const{
	return arr.GetSize();
}

template<class T>
void Stack<T>::print() const{
	arr.print();
}