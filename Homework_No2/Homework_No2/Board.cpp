#include "Board.h"

void Board::copyFrom(const Board& other)
{
	board = new Cell*[other.rowsCount];
	rowsCount = other.rowsCount;
	columnsCount = other.columnsCount;
	size = rowsCount * columnsCount;
	for (size_t rows = 0; rows < rowsCount; ++rows){
		board[rows] = new Cell[columnsCount];
		for (size_t cols = 0; cols < columnsCount; ++cols){
			board[rows][cols] = other.board[rows][cols];
		}
	}
}


Board::Board(const Board& other)
{
	copyFrom(other);
}


Board& Board::operator=(const Board& other){
	if (this == &other){
		return *this;
	}
	free();
	copyFrom(other);
	return *this;
}


Cell Board::getAt(size_t row,size_t col) const{
	Cell returned(row, col);
	returned.setContent(board[row][col].getContent());
	return returned;
}


void Board::showCell(const Cell& cell) const{
	std::cout << board[cell.row][cell.col].getContent() << ' ';
}


void Board::create(){
	std::cout << "Enter the board: \n";
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