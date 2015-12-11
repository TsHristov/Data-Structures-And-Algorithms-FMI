#include <iostream>

void swap(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}

int Partition(int *A, int start, int end)
{
	int pivot = A[end];
	int partitionIndex = start;
	for (int i = start; i < end; ++i)
	{
		if (A[i] <= pivot)
		{
			swap(A[i], A[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(A[partitionIndex], A[end]);
	return partitionIndex;
}
/**
* #time complexity:
*	-0(nlogn) - average case
*	-0(n^2) - worst case
* #In-place sorting
* #Divide and Conquer algorithm
*/
void QuickSort(int *A, int start, int end)
{
	if (start < end)
	{
		int partitionIndex = Partition(A, start, end);
		QuickSort(A, start, partitionIndex - 1);
		QuickSort(A, partitionIndex + 1, end);
	}
}

/**
* #time complexity:
*	-O(n) - best case
*	-O(n^2) - average case
*	-O(n^2) - worst case
* #In-place sorting
* #Space complexity:
*	-O(1)
*/
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
	QuickSort(arr, 0 ,5);
	for (size_t i = 0; i < 5; ++i){
		std::cout << arr[i];
	}
	return 0;
}