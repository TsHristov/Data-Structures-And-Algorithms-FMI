#include "Stack.h"

Stack::Stack(){
	top_index = -1;
	for (int i = 0; i < 10; ++i){
		arr[i] = 0;
	}
}
Stack::~Stack()
{
	std::cout << "Destructing..." << '\n';
}


void Stack::push(const int& item){
	top_index++;
	arr[top_index] = item;
}

int& Stack::pop(){
	return arr[top_index--];
}

bool Stack::IsEmpty() const{
	if (top_index == -1){
		return true;
	}
	else{
		return false;
	}
}

void Stack::print() const{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "stack[" << i << "]:" << arr[i] << '\n';
	}
}