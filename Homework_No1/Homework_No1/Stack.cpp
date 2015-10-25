#include "Stack.h"


Stack::Stack(){
	top = -1;
	std::cout << "Stack Construction..." << '\n';
}


Stack::~Stack()
{
	std::cout << "Stack Destruction...at adress:" << this << '\n';
}


void Stack::push(const char& item){
	arr[++top] = item;
}

char& Stack::pop(){
	return arr[top--];
}

bool Stack::IsEmpty() const{
	if (top == -1){
		return true;
	}
	else{
		return false;
	}
}

void Stack::print() const{
	arr.print();
}