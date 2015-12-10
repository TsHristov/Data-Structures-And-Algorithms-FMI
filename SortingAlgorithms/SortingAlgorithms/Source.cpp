#include <iostream>

void InsertionSort(int *arr, size_t size)
{
	for (int i = 1; i <= size - 1; ++i)
	{
		int value = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > value)
		{
			arr[j] = arr[j - 1];
			j = j - 1;
		}
		arr[j] = value;
	}
}
int main()
{
	int arr[] = { 7, 2, 4, 1, 5, 3 };
	InsertionSort(arr, 6);
	for (size_t i = 0; i < 6; ++i){
		std::cout << arr[i];
	}
	return 0;
}