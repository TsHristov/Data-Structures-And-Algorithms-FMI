#include <iostream>
#include <string>
using namespace std;

int getPosition(char arg)
{
	return (int)arg - 97;
}

char getLastChar(string arg,int step)
{
	if (arg.length())
	{
		return	arg.at(arg.size() - step);
	}
}

// A utility function to print an array
void print(string arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// A utility function to get maximum length of word  in names[]
int getMax(string names[], int n)
{
	int mx = names[0].size();
	for (int i = 1; i < n; i++)
	if (names[i].size() > mx)
		mx = names[i].size();
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(string names[], int n, int step)
{
	std::cout << "Pass No: " << step << endl;
	print(names, 5);
	std::cout << endl;
	string output[5]; // output array
	int i, count[26] = { 0 };
	
	// Store count of occurrences in count[]
	//1st for loop
	for (i = 0; i < 5; i++)
	{
		if (names[i].size() >= step)
		{
			count[getPosition(getLastChar(names[i], step))]++;
			std::cout << " Name: " << names[i] << " | Letter: " << getLastChar(names[i], step) <<
				" | Position: " << getPosition(getLastChar(names[i], step)) << endl;
		}

	}

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]

	//2nd for loop
	for (i = 1; i < 26; i++)
		count[i] = count[i - 1] + count[i];

	// Build the output array
	//3rd for loop
	for (i = n - 1; i >= 0; i--)
	{
		if (names[i].size() >= step)
		{
			output[count[getPosition(getLastChar(names[i], step))] - 1] = names[i];
			count[getPosition(getLastChar(names[i], step))]--;
		}
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted names according to current letter
	for (i = 0; i < n; i++)
		names[i] = output[i];
}

// The main function to that sorts arr[] of size n using 
// Radix Sort
void radixsort(string names[], int n)
{
	// Find the maximum length of word to know number of letters
	int maxLength = getMax(names, 5);
	// Do counting sort for every letter. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	int step;
	for (step = 1; step <= maxLength; ++step)
		countSort(names, 5, step);
}



// Driver program to test above functions
int main()
{
	string names[] = { "ivan", "mitko" , "joro", "peshe" ,"tobi" };
	radixsort(names, 5);
	print(names, 5);
	/*int maxLength = getMax(names, 5);
	int step;
	for (int i = 0; i < 5; ++i)
	{
		for (step = 1; step <= maxLength; ++step)
		{
			if (names[i].size()>=step)
			std::cout << getLastChar(names[i], step) << endl;
		}

		std::cout << "-----" << endl;
	}*/
	/*string ivan = "ivan";
	unsigned sz = ivan.size();
	while (sz)
	{
		std::cout << getLastChar(ivan) << endl;
		std::cout << getPosition(getLastChar(ivan)) << endl;
		ivan.resize(sz - 1);
		--sz;
	}*/
	return 0;
}