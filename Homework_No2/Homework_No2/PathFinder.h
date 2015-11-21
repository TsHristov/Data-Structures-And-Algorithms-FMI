#pragma once
#include "Queue.h"
#include "Board.h"
class PathFinder{
private:
	Board pBoard;
	Cell start;

public:
	PathFinder();
	PathFinder(const Board& board,const Cell& cell){
		pBoard = board;
		start = cell;
	}
	~PathFinder();

public:
	void BFS();
	void DFS();
	void allPaths();
};