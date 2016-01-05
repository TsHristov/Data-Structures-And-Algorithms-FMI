#include <iostream>
#include <string>
//#include "GeneralTree.h"
#include "DynamicArray.h"
using namespace std;

int main()
{
	//char* str = "(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})";
	//GeneralTree test;
	//test.buildTree(str);
	//test.print();
	
	DynamicArray<int> arr;
	arr.insert(1);
	arr.insert(2);
	arr.insert(3);
	arr.print();

	std::cout << endl;
	std::cout << arr.getNext() << endl;
	std::cout << arr.getNext() << endl;
	std::cout << arr.getNext() << endl;

	return 0;
}