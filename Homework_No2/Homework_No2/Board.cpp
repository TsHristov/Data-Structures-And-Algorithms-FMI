#include "Board.h"

Cell Board::getAt(size_t row,size_t col) const{
	Cell returned(row, col);
	returned.setContent(board[row][col].getContent());
	return returned;
}

void Board::showCell(const Cell& cell) const{
	std::cout << board[cell.row][cell.col].getContent() << ' ';
}

void Board::create(){
	for (size_t row = 0; row < rowsCount; ++row)
	{
		board[row] = new Cell[columnsCount];
		size_t col;
		char symbol;
		for (col = 0; col < columnsCount; ++col)
		{
			std::cin >> symbol;
			board[row][col].setContent(symbol);
		}
	}
}


void Board::display() const{
	std::cout << "The board is: \n";
	for (size_t row = 0; row < rowsCount; ++row)
	{
		for (size_t col = 0; col < columnsCount; ++col)
		{
			std::cout << board[row][col].getContent() << ' ';
			//std::cout << board[row][col] << ' ';
		}
		std::cout << '\n';
	}
}