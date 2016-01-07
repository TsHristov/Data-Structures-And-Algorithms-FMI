#include <iostream>
#include <string>
#include "Tree.h"
//#include "DynamicArray.h"
//#include "Node.h"
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

int main()
{
	{
		char* str = "(A {(B {}) (C {(D {}) (E {}) (F {})})})";
		char* str1 = "(A {(B {(D {})}) (C {})})";

		
		std::cout << "Building first tree..." << endl;
		Tree<char> test;
		test.build(str);

		std::cout << "Building second tree..." << endl;
		Tree<char> test1;
		test1.build(str1);

		test.areIsomorphic(test, test1);
		/*DynamicArray<int> arr;
		arr.insert(1);
		arr.insert(2);
		arr.insert(3);

		std::cout << arr.getNext() << endl;
		std::cout << arr.getNext() << endl;
		std::cout << arr.getNext() << endl;
		*/
	}
	_CrtDumpMemoryLeaks();

	return 0;
}