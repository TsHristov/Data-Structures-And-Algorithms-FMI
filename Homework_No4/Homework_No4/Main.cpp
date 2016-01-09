#include <iostream>
#include <string>
#include "Tree.h"
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char *argv[])
{
	std::cout << "First tree : " << argv[1] << '\n';
	std::cout << "Second tree : " << argv[2] << '\n';
	
	Tree test(argv[1]);

	Tree test1(argv[2]);

	Tree::areIsomorphic(test, test1);

	return 0;
}