#include <iostream>
//#include <exception>
#include "DynamicArray.h"


DArray::DArray(const DArray& other) //other is the old one
{
	size = other.size;
	for (size_t i = 0; i < other.size; ++i)
	{
		pData[i] = other.pData[i];
	};
	std::cout << "Copy constructor!" << __LINE__ << '\n';
}

/*
*	Copy other into the current
*	and delete it`s content.
*
*/
DArray& DArray::operator=(const DArray& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] pData;
	pData = new int[capacity * 2];
	size = other.size;
	for (size_t i = 0; i < other.size; ++i)
	{
		pData[i] = other.pData[i];
	}
	std::cout << "Operator=" << '\n';
	return *this;
}

/*
IF old one filled:
Copy the content of the current filled array into
the newly created one,which have bigger capacity.
ELSE:
Continue filling the old one.
*/
DArray& DArray::Resize(){
	DArray NewArr;
	NewArr.pData = new int[capacity * 2];
	*this = NewArr;
	std::cout << "Resize()" << "\n";
	return *this;
}

void DArray::Add(int value)
{
	if (pData == NULL)
	{
		pData = new int[capacity];
	} //OK
	/*else if (size == capacity)
	{
	//if there are size elements in the array
	this->Resize();
	//should return the same object but resized
	}*/
	//start to add values in the structure
	pData[size] = value;
	++size;
	std::cout << (*pData) << "\n";
	std::cout << pData << '\n';
	++pData;
}