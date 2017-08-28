/**
* Programmer: Steven Chavez
* Email: steven@stevenscode.com
* File: Sorter.cpp
* Date: 3/1/16
**/

#include <iostream>
#include "Sorter.h"
using namespace std;

void Sorter::BubbleSort(int num[], int size)
{
	for (int i = size; --i >= 0;)
	{
		bool flipped = false;
		for (int j = 0; j < i; j++)
		{
			if (num[j] > num[j + 1])
			{
				int T = num[j];
				num[j] = num[j + 1];
				num[j + 1] = T;
				flipped = true;
			}
		}
		if (!flipped)
		{
			return;
		}
	}
}

void Sorter::InsertionSort(int num[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i;
		int B = num[i];
		while ((j > 0) && (num[j - 1] > B))
		{
			num[j] = num[j - 1];
			j--;
		}
		num[j] = B;
	}
}

void Sorter::SelectionSort(int num[], int size)
{
	for (int i = 0; i < size; i++) {
		int min = i;
		int j;
		/*
		* Find the smallest element in the unsorted list
		*/
		for (j = i + 1; j < size; j++) {
			
			if (num[j] < num[min]) {
				min = j;
			}
		}
		/*
		* Swap the smallest unsorted element into the end of the
		* sorted list.
		*/
		int T = num[min];
		num[min] = num[i];
		num[i] = T;
	}
}

void Sorter::CombSort11(int num[], int size)
{
	float SHRINKFACTOR = float(1.3);
	bool flipped = false;
	int gap, top;
	int i, j;
	gap = size;
	do {
		gap = int((float(gap) / SHRINKFACTOR));
		switch (gap) {
		case 0: /* the smallest gap is 1 ‐ bubble sort */
			gap = 1;
			break;
		case 9: /* this is what makes this Combsort11 */
		case 10:
			gap = 11;
			break;
		default: break;
		}
		flipped = false;
		top = size - gap;
		for (i = 0; i < top; i++) {
			j = i + gap;
			if (num[i] > num[j]) {
				int T = num[i];
				num[i] = num[j];
				num[j] = T;
				flipped = true;
			}
		}
	} while (flipped || (gap > 1));
	/* like the bubble and shell sorts we check for a clean pass */
}

void Sorter::ShakerSort(int num[], int size)
{
	int i = 0;
	int k = size - 1;
	while (i < k) {
		int min = i;
		int max = i;
		int j;
		for (j = i + 1; j <= k; j++) {
			if (num[j] < num[min]) {
				min = j;
			}
			if (num[j] > num[max]) {
				max = j;
			}
		}
		int T = num[min];
		num[min] = num[i];
		num[i] = T;
		if (max == i) {
			T = num[min];
			num[min] = num[k];
			num[k] = T;
		}
		else {
			T = num[max];
			num[max] = num[k];
			num[k] = T;
		}
		i++;
		k--;
	}
}

void Sorter::Shell(int num[], int size)
{
	int h = 1;
	/*
	* find the largest h value possible
	*/
	while ((h * 3 + 1) < size) {
		h = 3 * h + 1;
	}
	/*
	* while h remains larger than 0*/
	while (h > 0) {
		/*
		* for each set of elements (there are h sets)
		*/
		for (int i = h - 1; i < size; i++) {
			/*
			* pick the last element in the set
			*/
			int B = num[i];
			int j = i;
			/*
			* compare the element at B to the one before it in the set
			* if they are out of order continue this loop, moving
			* elements "back" to make room for B to be inserted.
			*/
			for (j = i; (j >= h) && (num[j - h] > B); j -= h) {
				num[j] = num[j - h];
			}
			/*
			* insert B into the correct place
			*/
			num[j] = B;
		}
		/*
		* all sets h‐sorted, now decrease set size
		*/
		h = h / 3;
	}
}

void Sorter::InPlaceMergeSort(int a[], int lo0, int hi0)
{
	int lo = lo0;
	int hi = hi0;
	if (lo >= hi) {
		return;
	}
	int mid = (lo + hi) / 2;
	/*
	* Partition the list into two lists and sort them recursively
	*/
	InPlaceMergeSort(a, lo, mid);
	InPlaceMergeSort(a, mid + 1, hi);
	/*
	* Merge the two sorted lists
	*/
	int end_lo = mid;
	int start_hi = mid + 1;
	while ((lo <= end_lo) && (start_hi <= hi)) {

		if (a[lo] < a[start_hi]) {
			lo++;
		}
		else {
			/** a[lo] >= a[start_hi]
			* The next element comes from the second list,
			* move the a[start_hi] element into the next
			* position and shuffle all the other elements up.
			*/
			int T = a[start_hi];
			for (int k = start_hi - 1; k >= lo; k--) {
				a[k + 1] = a[k];
			}
			a[lo] = T;
			lo++;
			end_lo++;
			start_hi++;
		}
	}
}

void Sorter::QuickSort(int a[], int lo0, int hi0)
{
	int lo = lo0;
	int hi = hi0;
	if (lo >= hi) {
		return;
	}
	else if (lo == hi - 1) {
		/*
		*  sort a two element list by swapping if necessary
		*/
		if (a[lo] > a[hi]) {
			int T = a[lo];
			a[lo] = a[hi];
			a[hi] = T;
		}
		return;
	}

	/*
	*  Pick a pivot and move it out of the way
	*/
	int pivot = a[(lo + hi) / 2];
	a[(lo + hi) / 2] = a[hi];
	a[hi] = pivot;

	while (lo < hi) {
		/*
		*  Search forward from a[lo] until an element is found that
		*  is greater than the pivot or lo >= hi
		*/
		while (a[lo] <= pivot && lo < hi) {
			lo++;
		}

		/*
		*  Search backward from a[hi] until element is found that
		*  is less than the pivot, or lo >= hi
		*/
		while (pivot <= a[hi] && lo < hi) {
			hi--;
		}

		/*
		*  Swap elements a[lo] and a[hi]
		*/
		if (lo < hi) {
			int T = a[lo];
			a[lo] = a[hi];
			a[hi] = T;
		}
	}

	/*
	*  Put the median in the "center" of the list
	*/
	a[hi0] = a[hi];
	a[hi] = pivot;

	/*
	*  Recursive calls, elements a[lo0] to a[lo-1] are less than or
	*  equal to pivot, elements a[hi+1] to a[hi0] are greater than
	*  pivot.
	*/
	QuickSort(a, lo0, lo - 1);
	QuickSort(a, hi + 1, hi0);
}

void Sorter::GoofySort(int num[], int size)
{
	int i = 0;
	while (i < size) {
		if (i == 0)
			i++;
		else if(num[i] < num[i-1]){
			//swap
			int k = num[i - 1];
			num[i - 1] = num[i];
			num[i] = k;
			i--;
		}
		else
		{
			i++;
		}
	}
}
