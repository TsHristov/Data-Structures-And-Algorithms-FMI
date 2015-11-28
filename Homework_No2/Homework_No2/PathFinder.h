#pragma once
#include "Queue.h"
#include "Board.h"
#include "Iterator.h"
#include "LinkedList.h"

class PathFinder
{
private:
	Board board;
	Cell start;

public:
	PathFinder();
	PathFinder(const Board& board, const Cell& cell){
		this->board = board;
		this->start = cell;
	}

public:
	void BFS();
};