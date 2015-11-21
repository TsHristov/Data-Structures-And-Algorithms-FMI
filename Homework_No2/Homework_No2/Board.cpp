#include "Board.h"

void Board::create(){
	for (size_t row = 0; row < rowsCount; ++row)
	{
		board[row] = new char[columnsCount + 1];
		size_t col;
		for (col = 0; col < columnsCount; ++col)
		{
			std::cin >> board[row][col];
		}
		board[row][col] = '\0';
	}
}

void Board::display() const{
	std::cout << "The board is: \n";
	for (size_t row = 0; row < rowsCount; ++row)
	{
		for (size_t col = 0; col < columnsCount; ++col)
		{
			std::cout << board[row][col] << ' ';
		}
		std::cout << '\n';
	}
}