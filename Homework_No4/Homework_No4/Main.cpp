#include <iostream>
#include <string>
#include "GeneralTree.h"
using namespace std;

int toNumber(char c)
{
	return (int)c - 97;
}
int main()
{
	char* test = "(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})";
	GeneralTree first;
	first.buildTree(first.getRoot(),test);
	first.print();
	return 0;
}