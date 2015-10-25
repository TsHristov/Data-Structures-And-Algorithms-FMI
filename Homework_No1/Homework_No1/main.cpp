#include<iostream>
#include "DynamicArray.h"
int main(){
	DynamicArray obj;
	obj.insert(3);
	obj.print();
	std::cout << obj[0] << '\n';
	DynamicArray other(obj);
	other.print();
	return 0;
}