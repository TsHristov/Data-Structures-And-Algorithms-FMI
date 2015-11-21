#pragma once
class Cell{

	friend bool canPass(char m[][3], size_t row, size_t col, const Cell& cell);
private:
	size_t row, col;

public:
	Cell() :row(0), col(0){}
	Cell(size_t r, size_t c) : row(r), col(c){}

public:
	// take the new position by copy,so we don`t modify the current object cell
	Cell* goUp() const{
		return &Cell(row - 1, col);
	}
	Cell* goDown() const{
		return &Cell(row + 1, col);
	}
	Cell* goRight() const{
		return &Cell(row, col + 1);
	}
	Cell* goLeft() const{
		return &Cell(row, col - 1);
	}
};