/* *
* Programmer: Steven Chavez
* Email: steven@stevenscode.com
* File: Driver.cpp
* Date: 3/7/2016
**/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <random>
#include <chrono>
#include "Sorter.h"

//change the Size and filename for the two data runs.
//#define Size 50000
//#define FILENAME "BJTest50K.txt"
//#define Size 100000
//#define FILENAME "BJTest100K.txt"
#define Size 200000
#define FILENAME "BJTest200K.txt"

//TODO:  Program  88/150  Testing  100/100

using namespace std;

int main()
{
	//HEADER
	cout << "NAME: Steven Chavez\n"
		<< "PROGRAM: P4 Eight Plus Goofy Sort\n"
		<< "OBJECTIVE: The objective is to compare different\n"
		<< "sorts to each other and time them.\n";

	Sorter sorter;
	int *nums, *tmpNums;
	nums = new int[Size];  // allocates memory for nums array
	tmpNums = new int[Size]; // allocates memory for tmpNums array
	stringstream ss;

	ifstream read(FILENAME);
	if (!read)
		cout << "Cannot Find File!\n";
	else
	{
		for (int i = 0; i < Size; i++)
		{
			read >> nums[i];
			tmpNums[i] = nums[i];
		}
		read.close();
	}

	// writes summary of information
	ss << "Summary" << Size << ".txt";
	ofstream sum(ss.str());
	if (!sum)
		cout << "Cannot Find File!\n";

	sum << "Name: Steven Chavez\n"
		<< "File Size: " << Size
		<< "\n\nName of Sort Function:      " 
		<< "    Elapsed time in secs.msec";


	//code located inside a function
	clock_t  start, stop;

	// BUBLE SORT
	cout << "\nBUBBLE SORT\n";
	start = clock();
	sorter.BubbleSort(nums, Size);
	stop = clock();
	int diff_in_msec = (int)(stop - start);
	double diff_in_sec = (double)diff_in_msec / 1000;
	cout << "Time: " << diff_in_sec << "\n";
	sum << "\nBubbleSort                      "
		<< diff_in_sec << " : " << diff_in_msec << "\n";

	for (int i = 0; i < Size; i++)
	{
		nums[i] = tmpNums[i];
	}

	// COMB SORT 11
	cout << "\nCOMB SORT 11\n";
	start = clock();
	sorter.CombSort11(nums, Size);
	stop = clock();
	diff_in_msec = (int)(stop - start);
	diff_in_sec = (double)diff_in_msec / 1000;
	cout << "Time: " << diff_in_sec << "\n";
	sum << "\nCombSort11                      "
		<< diff_in_sec << " : " << diff_in_msec << "\n";

	for (int i = 0; i < Size; i++)
	{
		nums[i] = tmpNums[i];
	}

	// GOOFY SORT
	cout << "\nGOOFY SORT\n";
	start = clock();
	sorter.GoofySort(nums, Size);
	stop = clock();
	diff_in_msec = (int)(stop - start);
	diff_in_sec = (double)diff_in_msec / 1000;
	cout << "Time: " << diff_in_sec << "\n";
	sum << "\nGoofySort                       "
		<< diff_in_sec << " : " << diff_in_msec << "\n";

	for (int i = 0; i < Size; i++)
	{
		nums[i] = tmpNums[i];
	}

	// IN PLACE MERGE SORT
	cout << "\nIN PLACE MERGE SORT\n";
	start = clock();
	sorter.InPlaceMergeSort(nums, 0, Size - 1);
	stop = clock();
	diff_in_msec = (int)(stop - start);
	diff_in_sec = (double)diff_in_msec / 1000;
	cout << "Time: " << diff_in_sec << "\n";
	sum << "\nInPlaceMergeSort                "
		<< diff_in_sec << " : " << diff_in_msec << "\n";

	for (int i = 0; i < Size; i++)
	{
		nums[i] = tmpNums[i];
	}

	// INSERTION SORT
	cout << "\nINSERTION SORT\n";
	start = clock();
	sorter.InsertionSort(nums, Size);
	stop = clock();
	diff_in_msec = (int)(stop - start);
	diff_in_sec = (double)diff_in_msec / 1000;
	cout << "Time: " << diff_in_sec << "\n";
	sum << "\nInsertionSort                   "
		<< diff_in_sec << " : " << diff_in_msec << "\n";

	for (int i = 0; i < Size; i++)
	{
		nums[i] = tmpNums[i];
	}

	//	QUICK SORT
	cout << "\nQUICK SORT\n";
	start = clock();
	sorter.QuickSort(nums, 0, Size - 1);
	stop = clock();
	diff_in_msec = (int)(stop - start);
	diff_in_sec = (double)diff_in_msec / 1000;
	cout << "Time: " << diff_in_sec << "\n";
	sum << "\nQuickSort                       "
		<< diff_in_sec << " : " << diff_in_msec << "\n";

	for (int i = 0; i < Size; i++)
	{
		nums[i] = tmpNums[i];
	}

	// SELECTION SORT
	cout << "\nSELECTION SORT\n";
	start = clock();
	sorter.SelectionSort(nums, Size);
	stop = clock();
	diff_in_msec = (int)(stop - start);
	diff_in_sec = (double)diff_in_msec / 1000;
	cout << "Time: " << diff_in_sec << "\n";
	sum << "\nSelectionSort                   "
		<< diff_in_sec << " : " << diff_in_msec << "\n";

	for (int i = 0; i < Size; i++)
	{
		nums[i] = tmpNums[i];
	}

	//SHAKER SORT
	cout << "\nSHAKER SORT\n";
	start = clock();
	sorter.ShakerSort(nums, Size);
	stop = clock();
	diff_in_msec = (int)(stop - start);
	diff_in_sec = (double)diff_in_msec / 1000;
	cout << "Time: " << diff_in_sec << "\n";
	sum << "\nShakerSort                      "
		<< diff_in_sec << " : " << diff_in_msec << "\n";

	for (int i = 0; i < Size; i++)
	{
		nums[i] = tmpNums[i];
	}

	//SHELL SORT
	cout << "\nSHELL SORT\n";
	start = clock();
	sorter.Shell(nums, Size);
	stop = clock();
	diff_in_msec = (int)(stop - start);
	diff_in_sec = (double)diff_in_msec / 1000;
	cout << "Time: " << diff_in_sec << "\n";
	sum << "\nShell                           "
		<< diff_in_sec << " : " << diff_in_msec << "\n";
	
	// close summary file
	sum.close();
	cout << "\n\n";

	// deallocate memory
	delete[] nums, tmpNums;
	return 0;
}