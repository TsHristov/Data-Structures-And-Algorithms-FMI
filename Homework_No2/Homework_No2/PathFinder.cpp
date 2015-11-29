#include "PathFinder.h"

void PathFinder::BFS(){
	int moveRows[] = { 0, -1, 0, 1 };
	int moveColumns[] = { -1, 0, 1, 0 };
	
	Queue<Cell> q;
	LinkedList<Cell> result;
	Board board = this->board;
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

// for each position perform DFS 
// from the start on a new board (unmarked)
// untill it reaches itself
void PathFinder::DFS(){

	int moveRows[] = { 0, -1, 0, 1 };
	int moveColumns[] = { -1, 0, 1, 0 };
	
	Board board = this->board;
	Stack<Cell>  stack;
	LinkedList<Cell> output;

	stack.push(start);
	output.add(start);
	board.markAsVisted(start);

	while (!stack.IsEmpty())
	{
		Cell currentPosition = stack.top();

		//must print all the paths  from the start to the currentPosition
		//PathFinder allpaths(board, currentPosition);
		//allpaths.DFS(start, currentPosition);
	
		int neighboursCount = 0;
		for (size_t i = 0; i < 4; ++i)
		{
			Cell nextPosition = board.getAt(currentPosition.GetRow() + moveRows[i], currentPosition.GetCol() + moveColumns[i]);
			if (board.canPass(nextPosition) && !board.wasVisited(nextPosition))
			{
				stack.push(nextPosition);
				output.add(nextPosition);
				board.markAsVisted(nextPosition);
				++neighboursCount;
				break;
			}
		}
		if (!neighboursCount)
		{
			stack.pop();
		}
	}

	for (Iterator<Cell> it = output.GetIterator(); !it.EndReached(); it.MoveNext())
	{
		it.GetCurrent().showCell();
	}
}


// For each cell of the matrix perform DFS with start and end(the cell itself)
// in order to find all paths from the start to itself.
// 
// The paths represent LinkedLists of Cells.
// There might be a couple of them.
//
void PathFinder::DFS(Cell& start, Cell& end)
{
	//For each element in the labyrinth perform this
	//Copy of the original board
	std::cout << "Enters" << '\n';
	Board copyBoard = board;
	int moveRows[] = { 0, -1, 0, 1 };
	int moveColumns[] = { -1, 0, 1, 0 };

	Stack<Cell>  stack;
	LinkedList<Cell> output;

	stack.push(start);
	copyBoard.markAsVisted(start);
	Cell currentPosition;
	while (currentPosition != end || !stack.IsEmpty())
	{
		currentPosition = stack.top();
		output.add(currentPosition);

		if (currentPosition == end)
		{
			break;
		}
		stack.pop();
		for (size_t i = 0; i < 4; ++i)
		{
			Cell nextPosition = board.getAt(currentPosition.GetRow() + moveRows[i], currentPosition.GetCol() + moveColumns[i]);
			if (board.canPass(nextPosition) && !board.wasVisited(nextPosition))
			{
				stack.push(nextPosition);
				board.markAsVisted(nextPosition);
			}

		}

	}

	for (Iterator<Cell> it = output.GetIterator(); !it.EndReached(); it.MoveNext())
	{
		it.GetCurrent().showCell();
	}
}