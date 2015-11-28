#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "PathFinder.h"
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(){
	{
		int rows, cols;
		std::cout << "rows = ";
		std::cin >> rows;
		std::cout << "cols = ";
		std::cin >> cols;

		Board board(rows, cols);
		board.create();

		Cell start = board.getAt(1, 1);

		PathFinder path(board, start);

		path.BFS();

	}
	_CrtDumpMemoryLeaks();

	return 0;
}