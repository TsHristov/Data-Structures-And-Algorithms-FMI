#include <iostream>
#include "Queue.h"
#include "Cell.h"
#include "Field.h"

bool canPass(char m[][3], size_t row, size_t col, const Cell& cell){
	if (cell.row < 0 || cell.row >= row || cell.col < 0 || cell.col >= col){
		return false;
	}
	return m[cell.row][cell.col] == '.';
}

//TODO:
/*
	- create Cell class
	- create Field class
	- perform BFS to find the shortest path
*/

int main(){
	
	//create field 3x3
	Field field(3, 3);

	//set the starting point at position (1, 1)
	Cell start(1, 1);

	//start the BFS algorithm to find the shortest path
	Queue<Cell> q;

	return 0;
}