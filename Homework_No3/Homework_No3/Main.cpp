#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "RadixSort.h"
using namespace std;


void print(DynamicArray<string> arr)
{
	size_t N = arr.GetSize();
	for (size_t i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

//	Slices the array passed array
//	,and return the newly formed one
//	,so that it can be processed with a QUERY.
DynamicArray<string> ENTER(DynamicArray<string> arr)
{
	int min, max;
	std::cin >> min >> max;

	DynamicArray<string> result;
	for (int i = min; i <= max; ++i)
	{
		result.insert(arr[i]);
	}
	cout << "You are now searching in: ";
	print(result);

	return result;
}

//	Checks how many times arr contatins query
//	,and returns these count of times.
void QUERY(DynamicArray<string> arr)
{
	string query;
	std::cin >> query;
	int count = 0;
	size_t N = arr.GetSize();

	for (size_t i = 0; i <= N; ++i)
	{
		//I took this peace of code from here:http://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
		//I needed it so that I can easily see if a string contains a certain other string.
		if (arr[i].find(query) != string::npos)
		{
			++count;
		}
	}
	std::cout << count << endl;
}

int main()
{

	int T;
	int maxLengthOfName = 8;
	cout << "T=";
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N, Q;
		cout << "N=";
		cin >> N;
		cout << "Q=";
		cin >> Q;

		//	Enter the names that should be sorted.
		DynamicArray<string> names;
		for (int i = 0; i < N; ++i)
		{
			cout << "[" << i << "]=";
			string name;
			cin >> name;
			while (name.length() > maxLengthOfName)
			{
				cout << "\nEnter the name again(length should be less or equal to 8):";
				cout << "\n[" << i << "]=";
				cin >> name;
			}
			names.insert(name);
		}

		//	Perform Radix Sort on the list of names.
		RadixSort rdxsrt(names);
		names = rdxsrt.sort();
		cout << "The sorted names are:";
		print(names);
		cout << endl;

		//	Make copy of names
		//	,so that the ENTER query doesn`t change it.
		DynamicArray<string> copy;
		for (int i = 0; i < N; ++i)
		{
			copy.insert(names[i]);
		}

		//	Process the Q queries.
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
				copy = ENTER(names);
			}
		}
	}

	return 0;
}