#include "Stack.h"


Stack::Stack(){
	top = -1;
	//std::cout << "Stack Construction..." << '\n';
}


Stack::~Stack()
{
	//std::cout << "Stack Destruction...at adress:" << this << '\n';
}

void Stack::push(const char& item){
	arr.insert(item);
	top++;
}

char& Stack::pop(){
	arr.removeElement();
	return arr[top--];
}

int Stack::GetTop() const{
	return top;
}

bool Stack::IsEmpty() const{
	if (top == -1){
		return true;
	}
	else{
		return false;
	}
}

size_t Stack::GetArrSize() const{
	return arr.GetSize();
}

void Stack::print() const{
	arr.print();
}