#include <iostream>
#include <string>
#include "Tree.h"
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

int main()
{
	{
		char* str = "(A {(E {}) (F {})})";
		char* str1 = "(A {(C {})(D {})})";

		std::cout << "Building first tree..." << endl;
		Tree<char> test;
		test.build(str);

		std::cout << "Building second tree..." << endl;
		Tree<char> test1;
		test1.build(str1);

		test.areIsomorphic(test, test1);
	}
	_CrtDumpMemoryLeaks();

	return 0;
}