#include <iostream>
#pragma once
class Board{

private:
	size_t rowsCount, columnsCount;
	size_t size;
	char** board;

public:
	Board() :board(nullptr), rowsCount(0), columnsCount(0){}
	Board(size_t n, size_t m){
		rowsCount = n;
		columnsCount = m;
		size = rowsCount*columnsCount;
		board = new char*[rowsCount];
	}
	~Board(){
		for (size_t i = 0; i < columnsCount; ++i){
			delete board[i];
		}
		delete[] board;
	}

public:
	void create();
	void display() const;
};