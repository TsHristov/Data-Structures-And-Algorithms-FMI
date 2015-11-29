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
	std::cout << "All paths to position: " << start.GetRow() << "," << start.GetCol() << '\n';
	PathFinder allpaths(board, start);
	allpaths.DFS(start, start);
	while (!stack.IsEmpty())
	{
		Cell currentPosition = stack.top();

		
	
		int neighboursCount = 0;
		for (size_t i = 0; i < 4; ++i)
		{
			Cell nextPosition = board.getAt(currentPosition.GetRow() + moveRows[i], currentPosition.GetCol() + moveColumns[i]);
			if (board.canPass(nextPosition) && !board.wasVisited(nextPosition))
			{
				stack.push(nextPosition);
				output.add(nextPosition);
				board.markAsVisted(nextPosition);
				std::cout << '\n';
				std::cout << "All paths to position: " << nextPosition.GetRow() << "," << nextPosition.GetCol() << '\n';
				PathFinder allpaths(this->board, nextPosition);
				allpaths.DFS(start, nextPosition);
				++neighboursCount;
				break;
			}
		}
		if (!neighboursCount)
		{
			stack.pop();
		}
	}

	/*for (Iterator<Cell> it = output.GetIterator(); !it.EndReached(); it.MoveNext())
	{
		it.GetCurrent().showCell();
	}*/
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
	Board board = this->board;
	int moveRows[] = { 0, -1, 0, 1 };
	int moveColumns[] = { -1, 0, 1, 0 };

	Stack<Cell>  stack;
	LinkedList<Cell> output;
	LinkedList<LinkedList<Cell>> allpaths;

	stack.push(start);
	output.add(start);
	//copyBoard.markAsVisted(start);
	Cell currentPosition;

	while (currentPosition != end || !stack.IsEmpty())
	{
		currentPosition = stack.top();

		if (currentPosition == end)
		{
			allpaths.add(output);
			//output.removeAll();
			//take the already marked matrix and perform DFS on the unmarked cells PathFinder all(copyBoard, start); all.DFS(start, end)
			break;
		}
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

	// Iterates over the list of paths for the cell
	for (Iterator<LinkedList<Cell>> pathIterator = allpaths.GetIterator(); !pathIterator.EndReached(); pathIterator.MoveNext())
	{
		for (Iterator<Cell> cellIterator = pathIterator.GetCurrent().GetIterator(); !cellIterator.EndReached(); cellIterator.MoveNext())
		{
			cellIterator.GetCurrent().showCell();
		}
	}
}