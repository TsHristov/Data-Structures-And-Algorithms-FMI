#pragma once
class Cell{
	friend class Board;
private:
	//TODO add levels
	char symbol;
	bool wasVisited;
	size_t row, col;

public:
	//should think about whether default construcor is needed
	Cell() :symbol('\0'), wasVisited(false), row(0), col(0){}
	Cell(size_t r, size_t c) : row(r), col(c), wasVisited(false){}
	bool operator!=(const Cell& other)
	{
		return row != other.row && col != other.col && symbol != other.symbol;
	}
	bool operator==(const Cell& other)
	{
		return row == other.row && col == other.col && symbol == other.symbol;
	}

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
	//Don`t need these anymore,because the algorithm uses moveRows and moveColumns
	/*
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
	*/
};