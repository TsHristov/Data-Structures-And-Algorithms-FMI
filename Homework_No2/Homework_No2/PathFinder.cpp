#include "PathFinder.h"

void PathFinder::BFS(){
	int moveRows[] = { 0, -1, 0, 1 };
	int moveColumns[] = { -1, 0, 1, 0 };
	
	Queue<Cell> q;
	LinkedList<Cell> result;
	
	q.Enqueue(start);
	board.markAsVisted(start);

	while (!q.IsEmpty()){
		Cell currentPosition = q.Peek();
		result.add(currentPosition);
		q.Dequeue();
		for (size_t i = 0; i < 4;++i)
		{
			Cell nextPosition = board.getAt(currentPosition.GetRow() + moveRows[i], currentPosition.GetCol() + moveColumns[i]);
			if (board.canPass(nextPosition) && !board.wasVisited(nextPosition))
			{
				q.Enqueue(nextPosition);
				board.markAsVisted(nextPosition);
			}

		}
	}

	for (Iterator<Cell> it = result.GetIterator(); !it.EndReached(); it.MoveNext())
	{
		it.GetCurrent().showCell();
	}
}