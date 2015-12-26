#include "DynamicArray.h"
#include <string>
using namespace std;
#pragma once

class RadixSort
{
	DynamicArray<string> names;
	size_t N;

public:
	RadixSort(DynamicArray<string> names)
	{
		this->names = names;
		this->N = names.GetSize();
	}

public:
	// Main methods for the Radix Sort algortihm.
	void radixSort();
	void countSort(int step);
	int getMaxLength();
	DynamicArray<string> sort();

public:
	//	Transforms the ASCII code of the character into index of an array
	//	,which will be used to perform the sorting.
	int getPosition(char arg)
	{
		return (int)arg - 97;
	}

	// Returns the last character of a string.
	char getLastChar(string arg, int step)
	{
		if (arg.length())
		{
			return	arg.at(arg.size() - step);
		}
	}

public:
	void print(DynamicArray<string> arr)
	{
		for (size_t i = 0; i < N; ++i)
			cout << arr[i] << " ";
	}

};