#pragma once
class Cell{
	friend class Board;
private:
	char symbol;
	bool wasVisited;
	size_t row, col;

public:
	Cell() :symbol('\0'), wasVisited(false), row(-1), col(-1){}
	Cell(size_t r, size_t c) : row(r), col(c), wasVisited(false){}

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
	void showCell() const{
		std::cout << "(" << row << "," << col << ")" << '\n';
	}
public:
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
};