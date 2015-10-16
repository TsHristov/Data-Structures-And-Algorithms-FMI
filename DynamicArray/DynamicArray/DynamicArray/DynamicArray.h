#pragma once

class DArray{
	int* pData;
	size_t capacity;
	size_t size;
public:
	DArray(){
		pData = new int[5];
		capacity = 10;
		size = 0;
	}
	~DArray(){
		delete[] pData;
		std::cout << pData << "~DArray()" << '\n';
	}
	DArray(const DArray&);
	DArray& operator=(const DArray&);
	DArray& Resize();
	void Add(int value);
};