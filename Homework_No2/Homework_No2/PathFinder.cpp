#include "PathFinder.h"

void PathFinder::BFS(){
	//LinkedList<Cell> result;
	int moveRows[] = { 0, -1, 0, 1 };
	int moveColumns[] = { -1, 0, 1, 0 };
	Queue<Cell> q;
	Cell currentPosition;
	q.Enqueue(start);
	//result.append(start);
	while (!q.IsEmpty){
		currentPosition = q.Peek();
		//result.append(currentPosition);
		q.Dequeue();
		for (size_t i = 0; i < 4;++i)
		{
			Cell nextPosition(currentPosition.GetRow() + moveRows[i], currentPosition.GetCol() + moveColumns[i]);
			if (canPass(board, nextPosition))
			{
				q.Enqueue(nextPosition);
			}

		}
	}
}

void PathFinder::DFS(){
	//...
}

void PathFinder::allPaths(){
	DFS();
	//sort();
}