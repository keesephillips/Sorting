#ifndef SORT_H
#define SORT_H

/* Imports */
#include <iostream>
#include<cstdlib>
#include<ctime>

class Sort {
public:

	/* The name of the implementing sorting algorithm */
	std::string sort;

	/* Counts the total number of swaps made by the implemented sorting algorithm */
	long long totalSwaps = 0;

	/* Counts the total number of comparisons made by the implemented sorting algorithm */
	long long totalComparisons = 0;

	/*
	* Swaps the two integer values and increments the amount of total swaps.
	*/
	void Swap(int* a, int* b);

	/*
	* Prints the entire array.
	*/
	void Print(int data[], int length);

	/*
	* Prints the total amount of comparisons made by the sorting algorithm.
	*/
	void Analysis();

	/*
	* Compares the two integers and returns positive if the first integer is greater than, negative if the first
	* integer is less than, and 0 if the two are equal.
	*/
	int compareTo(int a, int b);
};

class SelectionSort : public Sort {
public:

	/*
	* Constructor for the Selection Sort algorithm. Implements the Selection Sort
	* algorithm.
	*/
	SelectionSort(int data[], int length);

	/*
	* Returns the index of the minimum value.
	*/
	int MinIndex(int data[], int start, int end);
};

class MergeSort : public Sort {
public:

	/*
	* Constructor for the Merge Sort algorithm.
	*/
	MergeSort(int data[], int length);

	/*
	* Allocates the memory needed for the two subarrays then sorts the two
	* arrays.
	*/
	void Merge(int data[], int left, int middle, int right);

	/*
	* Seperates the array into two parts after sorting the two arrays
	* it will merge the two arrays back into the original array
	*/
	void mergeSort(int data[], int left, int right);
};

class HeapSort : public Sort {
public:

	/*
	* Constructor for the Heap Sort.
	*/
	HeapSort(int data[], int length);

	/*
	* Creates the heap for the sorting algorithm to use.
	*/
	void Heap(int data[], int index, int tree);

	/*
	* Implements the heap sort algorithm.
	*/
	void heapSort(int data[], int length);
};

class QuickSort : public Sort {
public:

	/*
	* Constructor for the quick sort without a random pivot.
	*/
	QuickSort(int data[], int length);

	/*
	* Returns the pivot point.
	*/
	int Split(int data[], int start, int end);

	/*
	* Recursively calls the quick sort until sorted.
	*/
	void quickSort(int data[], int start, int end);
};

class RandomQuickSort : public Sort {
public:

	/*
	* Constructor for the quick sort with the random pivot.
	*/
	RandomQuickSort(int data[], int length);

	/*
	* Returns the partition index.
	*/
	int Partition(int data[], int start, int end);

	/*
	* Creates a random pivot and swaps the random pivot with the last element
	*/
	int RandomPartition(int data[], int start, int end);

	/*
	* Implements the Randomized Quick Sort
	*/
	void randomQuickSort(int data[], int start, int end);
};

#endif
