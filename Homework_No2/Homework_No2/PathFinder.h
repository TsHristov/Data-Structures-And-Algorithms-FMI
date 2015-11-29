#pragma once
#include "Queue.h"
#include "Board.h"
#include "Iterator.h"
#include "LinkedList.h"
#include "Stack.h"

class PathFinder
{
private:
	Board board;
	Cell start;

public:
	PathFinder(const Board& board, const Cell& cell){
		this->board = board;
		this->start = cell;
	}

public:
	void BFS();
	void DFS();
	void DFS(Cell& start, Cell& end);
};