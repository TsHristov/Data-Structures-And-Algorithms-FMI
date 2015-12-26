#include "RadixSort.h"

void RadixSort::radixSort()
{
	//	Finds the length of the longest word.
	int maxLength = getMaxLength();

	//	Do counting sort for every letter in the stings.
	//	step - on the first step look at the last letter
	//	,on the second - the letter before the last and so on...
	//	Example: "string"
	//	1st step: process 'g'
	//	2nd step: process 'n'
	//	. . .
	int step;
	for (step = 1; step <= maxLength; ++step)
		//	The strings are rearanged after each pass of countSort
		countSort(step);
}

// Get length of  word in the array of names
int RadixSort::getMaxLength()
{
	int maxLength = names[0].size();
	for (size_t i = 1; i < N; ++i)
	if (names[i].size() > maxLength)
		maxLength = names[i].size();
	return maxLength;
}


//	Perform Counting Sort on the names in the array
//	,based on the ASCII values of their letters.
void RadixSort::countSort(int step)
{
	std::cout << "Pass No: " << step << endl;
	
	//	string* - because the size of the output must be known in advance.
	string* output = new string[N];

	int i,count[26] = { 0 };

	//	Store the count of occurrences in count[]
	for (i = 0; i < N; ++i)
	{
		if (names[i].size() >= step)
		{
			count[getPosition(getLastChar(names[i], step))]++;

			//	Display the letters and the their position in the array.
			std::cout << " Name: " << names[i] << " | Letter: " << getLastChar(names[i], step) <<
				" | Position: " << getPosition(getLastChar(names[i], step)) << endl;
		}
		else if (names[i].size() < step) //	Case: step == maxLength,then put 0.
		{
			count[0]++;
		}

	}

	//	Change count[i] so that count[i] now contains actual
	//	position of this string in output[].

	for (i = 1; i < 26; ++i)
		count[i] = count[i - 1] + count[i];

	//	Builds the output array
	for (i = N - 1; i >= 0; --i)
	{
		if (names[i].size() >= step)
		{
			output[count[getPosition(getLastChar(names[i], step))] - 1] = names[i];
			count[getPosition(getLastChar(names[i], step))]--;
		}
		else if (names[i].size() < step) //	Case: step == maxLength,then put 0.
		{
			output[count[0] - 1] = names[i];
			count[0]--;
		}
	}

	//	Copy the output array to arr[], so that arr[] now
	//	contains sorted names according to current letter.
	DynamicArray<string> temp;
	for (i = 0; i < N; ++i)
	{
		temp.insert(output[i]);
	}
	names = temp;
	std::cout << " \n Result: ";
	print(names);
	std::cout << endl << endl;
	delete[] output;
}

//	Simple interface to sum up all the logic of the algorithm.
DynamicArray<string> RadixSort::sort()
{
	radixSort();
	return names;
}