#include <iostream>
#include <sstream>
#include <fstream>
#include "Sort.h"

/* Maximum Length of the array */
const int MAX_LENGTH = 100000;

/*
* If file contains integers the method will add the integers to an array and
* will return the length of the array.
*/
int initial_insert(int data[], std::string filename)
{
	int index = 0;
	std::ifstream file;
	file.open(filename);

	if (file)
	{
		int input;
		std::stringstream ss;
		ss << file.rdbuf();
		while (ss >> input)
		{
			data[index] = input;
			index++;
		} // while
	} // if
	file.close();
	return index;
} // initial_insert

/*
* Interface for the user to choose implementing sort algorithm and calls the appropriate
* constructor. Then prints the sorted array and provides the number of comparisons made by
* implementing alorgithm.
*/
void Sort(int values[], int length)
{
	char sort;
	std::cout << "selection-sort (s) merge-sort (m) heap-sort (h) quick-sort-fp (q) quick-sort-rp (r) :\t";
	std::cin >> sort;
	if (sort == 's')
	{
		SelectionSort* ss = new SelectionSort(values, length);
		ss->Print(values, length);
		ss->Analysis();
	} // if
	else if (sort == 'm')
	{
		MergeSort* ms = new MergeSort(values, length);
		ms->Print(values, length);
		ms->Analysis();
	} // if
	else if (sort == 'q')
	{
		QuickSort* qs = new QuickSort(values, length);
		qs->Print(values, length);
		qs->Analysis();
	} // if
	else if (sort == 'r')
	{
		RandomQuickSort* rs = new RandomQuickSort(values, length);
		rs->Print(values, length);
		rs->Analysis();
	} // if
	else if (sort == 'h')
	{
		HeapSort* hs = new HeapSort(values, length);
		hs->Print(values, length);
		hs->Analysis();
	} // if
} // Sort

int main(int argc, char** argv)
{
	int data[MAX_LENGTH];

	std::string filename{};

	if (argc > 1)
	{
		std::cout << "./main " << argv[1] << std::endl;
		filename = argv[1];
	} // if file is provided as command line argument

	int length = initial_insert(data, filename);
	Sort(data, length);
	delete[] data;
}