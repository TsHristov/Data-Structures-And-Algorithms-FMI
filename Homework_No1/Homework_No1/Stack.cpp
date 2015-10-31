#include "Stack.h"


Stack::Stack(){
	top_index = -1;
	//std::cout << "Stack Construction..." << '\n';
}


Stack::~Stack()
{
	//std::cout << "Stack Destruction...at adress:" << this << '\n';
}

void Stack::push(const char& item){
	arr.insert(item);
	top_index++;
}

void Stack::pop(){
	arr.removeElement();
	--top_index;
}

char Stack::top(){
	return arr[top_index];
}

int Stack::GetTop() const{
	return top_index;
}

bool Stack::IsEmpty() const{
	if (top_index == -1){
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