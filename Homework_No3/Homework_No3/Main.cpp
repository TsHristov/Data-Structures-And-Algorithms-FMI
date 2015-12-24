#include <iostream>
#include <string>
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
void countSort(string names[], int n, int step, int maxLength)
{
	std::cout << "Pass No: " << step << endl;
	
	string output[5];
	int i, count[26] = { 0 };
	
	// Store count of occurrences in count[]

	for (i = 0; i < 5; i++)
	{
		if (names[i].size() >= step)
		{
			count[getPosition(getLastChar(names[i], step))]++;
			std::cout << " Name: " << names[i] << " | Letter: " << getLastChar(names[i], step) <<
				" | Position: " << getPosition(getLastChar(names[i], step)) << endl;
		}
		else
		{
			count[getPosition(getLastChar(names[i], names[i].size()))]++;
			std::cout << " Name: " << names[i] << " | Letter: " << getLastChar(names[i],names[i].size()) <<
				" | Position: " << getPosition(getLastChar(names[i], names[i].size())) << endl;

		}

	}

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]

	for (i = 1; i < 26; i++)
		count[i] = count[i - 1] + count[i];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		if (names[i].size() >= step)
		{
			output[count[getPosition(getLastChar(names[i], step))] - 1] = names[i];
			count[getPosition(getLastChar(names[i], step))]--;
		}
		else
		{
			output[count[getPosition(getLastChar(names[i], names[i].size()))] - 1] = names[i];
			count[getPosition(getLastChar(names[i], names[i].size()))]--;
		}
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted names according to current letter
	for (i = 0; i < n; i++)
	{
		if (output[i] != "")
		names[i] = output[i];
	}
	std::cout << " \n Result: ";
	print(names, 5);
	std::cout << endl << endl;
}


void radixsort(string names[], int n)
{
	// Find the maximum length of  word to know number of letters
	int maxLength = getMax(names, 5);

	// Do counting sort for every letter.
	// step - on the first step look at the last letter,on the second the letter before the last and so on...
	int step;
	for (step = 1; step <= maxLength; ++step)
		countSort(names, 5, step, maxLength);
}

int main()
{
	string names[] = { "ivan", "mitko" , "joro", "peshe" ,"tobi" };
	radixsort(names, 5);
	print(names, 5);

	return 0;
}