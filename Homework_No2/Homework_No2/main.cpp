#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "PathFinder.h"

int main(){
	int rows, cols;
	std::cout << "rows = ";
	std::cin >> rows;
	std::cout << "cols = ";
	std::cin >> cols;

	std::cout << "Set starting point:" << '\n';
	int x, y;
	std::cout << "row = ";
	std::cin >> x; 
	std::cout << "col = ";
	std::cin >> y;

	Board board(rows, cols);
	board.create();

	Cell start = board.getAt(x, y);

	PathFinder path(board, start);

	std::cout << "Shortest path: " << '\n';
	path.BFS();

	std::cout << "\nAll paths: " << '\n';
	path.DFS();

	return 0;
}