#include <iostream>
#include "Queue.h"
#include "Cell.h"
#include "Board.h"


#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


bool canPass(char m[][3], size_t row, size_t col, const Cell& cell){
	if (cell.row < 0 || cell.row >= row || cell.col < 0 || cell.col >= col){
		return false;
	}
	return m[cell.row][cell.col] == '.';
}

//TODO:
/*
	- create Board class - check
	- create Cell class - check
	- perform BFS to find the shortest path
*/

int main(){
	{
		int rows, cols;
		std::cout << "rows = ";
		std::cin >> rows;
		std::cout << "cols = ";
		std::cin >> cols;

		Board board(rows, cols);
		board.create();

		Cell start = board.getAt(0, 0);
		board.showCell(start);

	}
	_CrtDumpMemoryLeaks();

	return 0;
}