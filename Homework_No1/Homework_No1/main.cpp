#include<iostream>
#include "Stack.h"
int main(){
	Stack obj;
	obj.push('a');
	//std::cout << obj.IsEmpty() << '\n';
	obj.print();
	obj.pop();
	obj.print();
	obj.push('b');
	obj.print();
	return 0;
}