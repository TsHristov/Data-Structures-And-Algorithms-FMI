#include <iostream>
#include <string>
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "DynamicArray.h"
using namespace std;

//Get position of the letter in the array as index of it
int getPosition(char arg)
{
	return (int)arg - 97;
}

//Extracts the last letter of a string
char getLastChar(string arg,int step)
{
	if (arg.length())
	{
		return	arg.at(arg.size() - step);
	}
}

void print(string arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void print(DynamicArray<string> arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Get maximum length of word  in the array of names
int getMax(string names[], int n)
{
	int mx = names[0].size();
	for (int i = 1; i < n; i++)
	if (names[i].size() > mx)
		mx = names[i].size();
	return mx;
}

// A function to perform counting sort on the names based on the letter
void countSort(string names[], int N, int step)
{
	std::cout << "Pass No: " << step << endl;
	
	string* output = new string[N];
	int i, count[26] = { 0 };
	
	// Store count of occurrences in count[]

	for (i = 0; i < N; i++)
	{
		if (names[i].size() >= step)
		{
			count[getPosition(getLastChar(names[i], step))]++;
			std::cout << " Name: " << names[i] << " | Letter: " << getLastChar(names[i], step) <<
				" | Position: " << getPosition(getLastChar(names[i], step)) << endl;
		}
		else if (names[i].size() < step) // case step == maxLength
		{
			count[0]++;
		}

	}

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]

	for (i = 1; i < 26; i++)
		count[i] = count[i - 1] + count[i];

	// Build the output array
	for (i = N - 1; i >= 0; i--)
	{
		if (names[i].size() >= step)
		{
			output[count[getPosition(getLastChar(names[i], step))] - 1] = names[i];
			count[getPosition(getLastChar(names[i], step))]--;
		}
		else if (names[i].size() < step) // case step == maxLength
		{
			output[count[0] - 1] = names[i];
			count[0]--;
		}
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted names according to current letter
	DynamicArray<string> temp;
	for (i = 0; i < N; i++)
	{
		if (output[i] != "")
			//temp.insert(output[i]);
			names[i] = output[i];
	}
	//names = temp;
	std::cout << " \n Result: ";
	print(names, N);
	std::cout << endl << endl;
	delete []output;
}


void radixsort(string names[], int N)
{
	// Find the maximum length of  word to know number of letters
	int maxLength = getMax(names, N);
	// Do counting sort for every letter.
	// step - on the first step look at the last letter,on the second the letter before the last and so on...
	int step;
	for (step = 1; step <= maxLength; ++step)
		countSort(names, N, step);
}

DynamicArray<string> ENTER(DynamicArray<string> arg)
{
	int min, max;
	std::cin >> min >> max;
	int size = (max - min) + 1;
	
	DynamicArray<string> result;
	for (int i = min; i <= max; ++i)
	{
		result.insert(arg[i]);
	}
	print(result, size);
	return result;
}

void QUERY(DynamicArray<string> names)
{
	string query;
	std::cin >> query;
	int count = 0;

	for (size_t i = 0; i <= names.GetSize(); ++i)
	{
		if (names[i].find(query) != string::npos)
		{
			++count;
		}
	}
	std::cout << count << endl;
}

int main()
{
	{
		int T;
		cout << "T=";
		cin >> T;
		for (int i = 0; i < T; ++i)
		{
			int N, Q;
			cout << "N=";
			cin >> N;
			cout << "Q=";
			cin >> Q;
			string *names = new string[N];
			for (int i = 0; i < N; ++i)
			{
				std::cout << "[" << i << "]=";
				std::cin >> names[i];
			}
			radixsort(names, N);
			print(names, N);
			std::cout << endl;

			
			DynamicArray<string> NAMES;
			for (int i = 0; i < N; ++i)
			{
				NAMES.insert(names[i]);
			}
			

			DynamicArray<string> copy;
			for (int i = 0; i < N; ++i)
			{
				copy.insert(names[i]);
			}

			for (int i = 0; i < Q; ++i)
			{
				string str;
				std::cin >> str;
				string enter = "ENTER";
				string query = "QUERY";
				if (!strcmp(str.c_str(), query.c_str()))
				{
					QUERY(copy);
				}
				else if (!strcmp(str.c_str(), enter.c_str()))
				{
					copy = ENTER(NAMES);
				}
			}
			delete[] names;
		}
	}
	_CrtDumpMemoryLeaks();


	return 0;
}