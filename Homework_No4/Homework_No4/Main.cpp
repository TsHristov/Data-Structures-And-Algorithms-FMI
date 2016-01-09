#include <iostream>
#include <string>
#include "Tree.h"

int main()
{
	char* str = "(5 {(9 {}) (1 {(C {}) (13 {}) (4 {})})})";
	char* str1 = "(5 {     (A {  }) (1 { (1 {}) (1 {}) (4 {})})})";

	std::cout << "Building first tree..." << '\n';
	Tree test;
	test.build(str);

	std::cout << "Building second tree..." << '\n';
	Tree test1;
	test1.build(str1);

	Tree::areIsomorphic(test, test1);

	return 0;
}