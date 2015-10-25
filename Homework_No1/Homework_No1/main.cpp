#include<iostream>
#include "DynamicArray.h"
int main(){
	DynamicArray<int> obj;
	obj.insert(1);
	obj.insert(2);
	obj.insert(3);
	obj.insert(4);
	obj.insert(5);
	obj.insert(6);
	obj.insert(7);
	obj.print();

	DynamicArray<int> other(obj);
	other.print();
	other.insert(9);
	other.print();

	return 0;
}