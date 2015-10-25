#include "DynamicArray.h"


DynamicArray::DynamicArray()
{
	size = 0;
	capacity = 3;
	phead = new int[capacity];
	std::cout << "constructing..." << '\n';
}


DynamicArray::~DynamicArray()
{
	free();
	std::cout << "destructing..." << this << '\n';
}

DynamicArray::DynamicArray(const DynamicArray& o){
	phead = new int[o.capacity];
	for (size_t i = 0; i <= o.size; ++i){
		phead[i] = o.phead[i];
	}
	size = o.size;
	capacity = o.capacity;
	std::cout << "Copy constructor..." << '\n';
}

const DynamicArray& DynamicArray::operator=(const DynamicArray& o){
	if (this == &o){
		return *this;
	}
	else{
		free();
		phead = new int[o.capacity];
		for (size_t i = 0; i < o.capacity; ++i){
			phead[i] = o.phead[i];
		}
		size = o.size;
		capacity = o.capacity;
	}
	std::cout << "operator=" << '\n';
	return *this;
}


int& DynamicArray::operator[](int index){
	/*if (index < 0 || index > capacity - 1){
		std::cout << "Index out of bounds!" << '\n';
		exit(1);
	}*/
	std::cout << "operator[]" << '\n';
	return phead[index];
}


void DynamicArray::insert(int element){
	if (size == capacity)
	{
		this->resize();
	}
	phead[size++] = element;
	std::cout << "insert.." << '\n';
}


void DynamicArray::resize(){
}

void DynamicArray::free(){
	if (phead){
		delete[] phead;
		phead = NULL;
	}
	size = 0;
	capacity = 0;
}

void DynamicArray::print() const{
	for (int i = 0; i < capacity; ++i){
		std::cout << "[" << i << "]:" <<  phead[i] << '\n';
	}
}