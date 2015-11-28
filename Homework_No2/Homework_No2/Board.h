#include <iostream>
#include "Cell.h"
#pragma once

class Board{

private:
	size_t rowsCount, columnsCount;
	size_t size;
	Cell** board;

public:
	Board() :board(nullptr), rowsCount(0), columnsCount(0){}
	Board(size_t n, size_t m){
		rowsCount = n;
		columnsCount = m;
		size = rowsCount*columnsCount;
		board = new Cell*[rowsCount];
	}
	~Board(){
		free();
	}
	Board(const Board&);
	Board& operator=(const Board&);
	void copyFrom(const Board&);
	void free(){
		for (size_t i = 0; i < columnsCount; ++i){
			delete board[i];
		}
		delete[] board;
	}

public:
	Cell getAt(size_t, size_t) const;
	Cell& getCell(const Cell& cell) const{
		return board[cell.GetRow()][cell.GetCol()];
	}
	void showCell(const Cell&) const;

public:
	bool canPass(const Cell& cell) const;
	bool wasVisited(const Cell& cell) const{
		return getCell(cell).wasVisited;
	}
	void markAsVisted(Cell& cell){
		Cell change = this->getCell(cell);
		getCell(cell).wasVisited = true;
	}

public:
	void create();
	void display() const;
};


