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

	for (Iterator<Cell> it = result.GetIterator(); !it.End(); it.MoveNext())
	{
		it.GetCurrent().showCell();
	}
}


/** 
* For each cell that is in the ouput of the DFS algorithm
* perfrom another DFS from the starting point to itself
* in order to find all paths to all cells.
*/
void PathFinder::DFS(){

	int moveRows[] = { 0, -1, 0, 1 };
	int moveColumns[] = { -1, 0, 1, 0 };
	
	Board board = this->board;
	Stack<Cell>  stack;
	LinkedList<Cell> output;

	stack.push(start);
	output.add(start);
	board.markAsVisted(start);

	// Corner case: find all paths to start
	/*std::cout << "All paths to position: " << start.GetRow() << "," << start.GetCol() << '\n';
	PathFinder allpaths(board, start);
	allpaths.allPaths(start, start);*/
	//

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

				// finds all paths to nextPosition
				/*std::cout << "\nAll paths to position: " << nextPosition.GetRow() << "," << nextPosition.GetCol() << '\n';
				PathFinder allpaths(this->board, nextPosition);
				allpaths.allPaths(start, nextPosition);*/
				//

				++neighboursCount;
				break;
			}
		}
		if (!neighboursCount)
		{
			stack.pop();
		}
	}

	/**
	* Shows the result of the basic DFS performed.
	* All paths for all cells not included.
	*/
	for (Iterator<Cell> it = output.GetIterator(); !it.End(); it.MoveNext())
	{
		it.GetCurrent().showCell();
	}
}

/** 
* For each cell perform DFS from the starting point to itself.
* The algorithm stops when it reaches the point itself.
* Then it starts again with a board that has already marked cells
* from the previous step.
* This way all paths for a cell are found.
*/
void PathFinder::allPaths(Cell& start, Cell& end)
{
	/**
	* Copy of  the original board is needed
	* ,because otherwise the Cells will be already marked as visited.
	*/
	Board board = this->board;
	int moveRows[] = { 0, -1, 0, 1 };
	int moveColumns[] = { -1, 0, 1, 0 };

	Stack<Cell>  stack;
	LinkedList<Cell> path;

	/**
	* allpaths consists of LinkedList of paths(outputs) for a Cell
	*/
	LinkedList<LinkedList<Cell>> allpaths;

	stack.push(start);
	path.add(start);
	//copyBoard.markAsVisted(start);
	Cell currentPosition;

	while (currentPosition != end || !stack.IsEmpty())
	{
		currentPosition = stack.top();

		/**
		* When end cell is reached,the algorithm starts again with the already 
		* marked cells from the path.In the next go, the path will include other cells to the end.
		* Each of these iterations is one path,which is one element of LinkedList<LinkedList<Cell>> allpaths.
		*/
		if (currentPosition == end)
		{
			allpaths.add(path);
			// - clear the current LinkedList<Cell> path
			// - make recursive call to allPaths this time with the marked board
			break;
		}
		int neighboursCount = 0;
		for (size_t i = 0; i < 4; ++i)
		{
			Cell nextPosition = board.getAt(currentPosition.GetRow() + moveRows[i], currentPosition.GetCol() + moveColumns[i]);
			if (board.canPass(nextPosition) && !board.wasVisited(nextPosition))
			{
				stack.push(nextPosition);
				path.add(nextPosition);
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

	/**
	* Iterates over the resulting list of available paths for the Cell
	*/
	for (Iterator<LinkedList<Cell>> pathIterator = allpaths.GetIterator(); !pathIterator.End(); pathIterator.MoveNext())
	{
		for (Iterator<Cell> cellIterator = pathIterator.GetCurrent().GetIterator(); !cellIterator.End(); cellIterator.MoveNext())
		{
			cellIterator.GetCurrent().showCell();
		}
	}
	/**
	* Problem with the destructor.
	*/
}