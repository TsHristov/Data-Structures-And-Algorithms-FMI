#pragma once
class Cell
{
	//Cell has setters and getters so Board doesn`t need to be friend
	friend class Board;
private:
	char symbol;
	bool wasVisited;
	size_t row, col;

public:
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
	void setContent(char symbol)
	{
		this->symbol = symbol;
	}

	char getContent() const
	{
		return symbol;
	}

	size_t GetRow() const
	{
		return row;
	}

	size_t GetCol() const
	{
		return col;
	}
public:
	void showCell() const{
		std::cout << "(" << row << "," << col << ")";
	}
};