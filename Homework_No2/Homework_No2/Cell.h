#pragma once
/**
* - represents coordinates as tuples
*/
class Cell{

	/**
	* - canPass(...) - helper function to determine whether the position
	*	on the board is passable
	*/
	//friend bool canPass(const Board& board, size_t row, size_t col, const Cell& cell);
	friend class Board;

private:
	char symbol;
	bool wasVisited;
	size_t row, col;

public:
	Cell():symbol('\0'), wasVisited(false), row(0), col(0){}
	Cell(size_t r, size_t c) : row(r), col(c){}

public:
	void setContent(char symbol){
		this->symbol = symbol;
	}

	char getContent() const{
		return symbol;
	}

	size_t GetRow() const{
		return row;
	}

	size_t GetCol() const{
		return col;
	}

public:
	/**
	*	these functions are used to navigate the positions in the board
	*
	*/
	Cell goUp() const{
		return Cell(row - 1, col);
	}
	Cell goDown() const{
		return Cell(row + 1, col);
	}
	Cell goRight() const{
		return Cell(row, col + 1);
	}
	Cell goLeft() const{
		return Cell(row, col - 1);
	}

public:
	void markAsVisited(){
		wasVisited = true;
	}
};