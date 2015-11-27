#include <iostream>
/*#include "Queue.h"
#include "Cell.h"
#include "Board.h"
#include "PathFinder.h"*/
#include "Iterator.h"
#include "LinkedList.h"
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


/*bool canPass(Board board, size_t row, size_t col, const Cell& cell){
	if (cell.GetRow() < 0 || cell.GetRow()>= row || cell.GetCol() < 0 || cell.GetCol() >= col){
		return false;
	}
	return board[cell.GetRow()][cell.GetCol()] == '.';
}*/


//TODO:
/*
	- perform BFS to find the shortest path - 
*/

int main(){
	{
		LinkedList<int> list;
		list.add(1);
		list.add(2);
		list.add(3);
		list.add(4);
		list.add(5);
		list.add(6);
		for (Iterator<int> it = list.GetIterator(); !it.EndReached(); it.MoveNext())
		{
			std::cout << it.GetCurrent() << '\n';
		}
		/*int rows, cols;
		std::cout << "rows = ";
		std::cin >> rows;
		std::cout << "cols = ";
		std::cin >> cols;

		Board board(rows, cols);
		board.create();

		Cell start = board.getAt(1, 1);

		PathFinder path(board, start);

		path.shortestPath();*/

		/*Cell start = board.getAt(0, 0);
		board.showCell(start);*/

	}
	_CrtDumpMemoryLeaks();

	return 0;
}