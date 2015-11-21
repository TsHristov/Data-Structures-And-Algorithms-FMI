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
	- create Cell class
	- perform BFS to find the shortest path
*/

int main(){
	
	//create board
	{
		int rows, cols;
		std::cout << "rows = ";
		std::cin >> rows;
		std::cout << "cols = ";
		std::cin >> cols;

		Board field(rows, cols);
		field.create();
		field.display();


	}
	_CrtDumpMemoryLeaks();
	//set the starting point at position (1, 1)
	//Cell start(1, 1);

	//start the BFS algorithm to find the shortest path
	//Queue<Cell> q;

	return 0;
}