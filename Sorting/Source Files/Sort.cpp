#include "Sort.h"

/*
* Swaps the two integer values and increments the amount of total swaps.
*/
void Sort::Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	totalSwaps++;
} // Swap

/*
* Prints the entire array.
*/
void Sort::Print(int data[], int length)
{
	int i = 0;
	while (i < length)
	{
		std::cout << data[i] << "\t";
		i++;
	} // while
	std::cout << std::endl;
} // Print

/*
* Prints the total amount of comparisons made by the sorting algorithm.
*/
void Sort::Analysis()
{
	if (totalComparisons != 0)
	{
		std::cout << "\t#" << sort << " comparisons:\t" << totalComparisons << std::endl;
	} // if
	else
	{
		std::cout << "\t#" << sort << " comparisons:\t Greater than 49995000" << std::endl;
	} // if
} // Analysis

/*
* Compares the two integers and returns positive if the first integer is greater than, negative if the first
* integer is less than, and 0 if the two are equal.
*/
int Sort::compareTo(int a, int b)
{
	totalComparisons++;
	if (a > b) { return 1; }
	else if (a < b) { return -1; }
	else { return 0; }
} // compareTo

/*
* Constructor for the Selection Sort algorithm. Implements the Selection Sort
* algorithm.
*/
SelectionSort::SelectionSort(int data[], int length)
{
	sort = "SelectionSort";
	int  end = length - 1;
	for (int index = 0; index < end; index++)
	{
		Swap(&data[index], &data[MinIndex(data, index, end)]);
	} // for
} // SelectionSort

/*
* Returns the index of the minimum value.
*/
int SelectionSort::MinIndex(int data[], int start, int end)
{
	int  minIndex = start;
	for (int index = start + 1; index <= end; index++)
	{
		if (compareTo(data[index], data[minIndex]) < 0)
		{
			minIndex = index;
		} // if
	} // for
	return minIndex;
} // MinIndex

/*
* Constructor for the Merge Sort algorithm.
*/
MergeSort::MergeSort(int data[], int length)
{
	sort = "MergeSort";
	mergeSort(data, 0, length - 1);
} // MergeSort

/*
* Allocates the memory needed for the two subarrays then sorts the two
* arrays.
*/
void MergeSort::Merge(int data[], int left, int middle, int right)
{
	int subarray_1_length = middle - left + 1;
	int subarray_2_length = right - middle;
	int* subarray_1 = new int[subarray_1_length];
	int* subarray_2 = new int[subarray_2_length];

	for (int i = 0; i < subarray_1_length; i++)
	{
		subarray_1[i] = data[left + i];
	} // for
	for (int j = 0; j < subarray_2_length; j++)
	{
		subarray_2[j] = data[middle + 1 + j];
	} // for

	int i = 0;
	int j = 0;
	int k = left;

	while (i < subarray_1_length && j < subarray_2_length)
	{
		if (compareTo(subarray_1[i], subarray_2[j]) <= 0)
		{
			Swap(&data[k], &subarray_1[i]);
			i++;
		} // if
		else
		{
			Swap(&data[k], &subarray_2[j]);
			j++;
		} // if
		k++;
	} // while

	while (i < subarray_1_length)
	{
		Swap(&data[k], &subarray_1[i]);
		i++;
		k++;
	} // while

	while (j < subarray_2_length)
	{
		Swap(&data[k], &subarray_2[j]);
		j++;
		k++;
	} // while
} // Merge

/*
* Seperates the array into two parts after sorting the two arrays
* it will merge the two arrays back into the original array
*/
void MergeSort::mergeSort(int data[], int left, int right)
{
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergeSort(data, left, middle);
		mergeSort(data, middle + 1, right);
		Merge(data, left, middle, right);
	} // if
} // mergeSort

/*
* Constructor for the Heap Sort.
*/
HeapSort::HeapSort(int data[], int length)
{
	sort = "HeapSort";
	heapSort(data, length);
} // HeapSort

/*
* Creates the heap for the sorting algorithm to use.
*/
void HeapSort::Heap(int data[], int index, int tree)
{
	int largest = tree;
	int left = 2 * tree + 1;
	int right = 2 * tree + 2;

	if ((left < index) && (compareTo(data[left], data[largest]) > 0))
	{
		largest = left;
	} // if
	if ((right < index) && (compareTo(data[right], data[largest]) > 0))
	{
		largest = right;
	} // if
	if (largest != tree)
	{
		Swap(&data[tree], &data[largest]);
		Heap(data, index, largest);
	} // if
} // Heap

/*
* Implements the heap sort algorithm.
*/
void HeapSort::heapSort(int data[], int length)
{
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		Heap(data, length, i);
	} // for

	for (int i = length - 1; i > 0; i--)
	{
		Swap(&data[0], &data[i]);
		Heap(data, i, 0);
	} // for
} // heapSort

/*
* Constructor for the quick sort without a random pivot.
*/
QuickSort::QuickSort(int data[], int length)
{
	sort = "QuickSort";
	quickSort(data, 0, length - 1);
} // QuickSort

/*
* Returns the pivot point.
*/
int QuickSort::Split(int data[], int start, int end)
{
	int pivot = data[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++)
	{
		if (data[i] <= pivot)
		{
			count++;
		} // if
	} // for

	int pivotIndex = start + count;
	Swap(&data[pivot], &data[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex)
	{
		while (compareTo(data[i], pivotIndex) <= 0)
		{
			i++;
		} // while
		while (compareTo(data[j], pivotIndex) > 0)
		{
			j--;
		} // while
		if ((i < pivotIndex) && (j > pivotIndex))
		{
			Swap(&data[i++], &data[j--]);
		} // if
	} // while
	return pivotIndex;
} // Split

/*
* Recursively calls the quick sort until sorted.
*/
void QuickSort::quickSort(int data[], int start, int end)
{
	// BASE CASE
	if (start >= end)
	{
		return;
	} // if

	int pivot = Split(data, start, end);

	// LEFT
	quickSort(data, start, pivot - 1);

	// RIGHT
	quickSort(data, pivot + 1, end);
} // quickSort

/*
* Constructor for the quick sort with the random pivot.
*/
RandomQuickSort::RandomQuickSort(int data[], int length)
{
	randomQuickSort(data, 0, length - 1);
} // RandomQuickSort

/*
* Returns the partition index.
*/
int RandomQuickSort::Partition(int data[], int start, int end)
{
	int pivot = data[end];
	int i = (start - 1);

	for (int j = start; j <= end - 1; j++)
	{
		if (compareTo(data[j], pivot) <= 0)
		{
			i++;
			Swap(&data[i], &data[j]);
		} // if
	} // for
	Swap(&data[i + 1], &data[end]);
	return (i + 1);
} // partition

/*
* Creates a random pivot and swaps the random pivot with the last element
*/
int RandomQuickSort::RandomPartition(int data[], int start, int end)
{
	srand(time(NULL));
	int random = start + rand() % (end - start);
	Swap(&data[random], &data[end]);
	return Partition(data, start, end);
} // partition_r

/*
* Implements the Randomized Quick Sort
*/
void RandomQuickSort::randomQuickSort(int data[], int start, int end)
{
	if (start < end)
	{
		int pivot = RandomPartition(data, start, end);
		randomQuickSort(data, start, pivot - 1);
		randomQuickSort(data, pivot + 1, end);
	} // if
} // randomQuickSort