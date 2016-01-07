#include <iostream>
#include <string>
#include "Tree.h"
#include "DynamicArray.h"
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

int main()
{
	{
		char* str = "(A {(B {}) (C {(D {}) (E {}) (F {})})})";
		//char *str = "(7{(15 {(7 {}) (10 {})}) (3 {})})";
		Tree<char> test;
		test.build(str);
	}
	_CrtDumpMemoryLeaks();

	return 0;
}