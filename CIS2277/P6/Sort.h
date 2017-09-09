/**
* Author: Steven Chavez
* Email: steven@stevenscode.com
* File: Sort.h
* Date: 3/28/16
**/

#ifndef _SORT_H
#define _SORT_H

template <class T>
class Sort
{
public:
	Sort();
	void Bubble(T sort[], int size);
	void Comb11(T sort[], int size);
	void Insertion(T sort[], int size);
	void Selection(T sort[], int size);
	void Shaker(T sort[], int size);
};

template <class T>
Sort<T>::Sort()
{

}

template <class T>
void  Sort<T>::Bubble(T sort[], int size)
{
	for (int i = size; --i >= 0;)
	{
		bool flipped = false;
		for (int j = 0; j < i; j++)
		{
			if (sort[j] > sort[j + 1])
			{
				T S = sort[j];
				sort[j] = sort[j + 1];
				sort[j + 1] = S;
				flipped = true;
			}
		}
		if (!flipped)
		{
			return;
		}
	}
}

template <class T>
void Sort<T>::Comb11(T sort[], int size)
{
	float SHRINKFACTOR = float(1.3);
	bool flipped = false;
	int gap, top;
	int i, j;
	gap = size;
	do {
		gap = int((float(gap) / SHRINKFACTOR));
		switch (gap) {
		case 0: /* the smallest gap is 1 ? bubble sort */
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
			if (sort[i] > sort[j]) {
				T S = sort[i];
				sort[i] = sort[j];
				sort[j] = S;
				flipped = true;
			}
		}
	} while (flipped || (gap > 1));
	/* like the bubble and shell sorts we check for a clean pass */
}

template <class T>
void Sort<T>::Insertion(T sort[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i;
		T B = sort[i];
		while ((j > 0) && (sort[j - 1] > B))
		{
			sort[j] = sort[j - 1];
			j--;
		}
		sort[j] = B;
	}
}

template <class T>
void Sort<T>::Selection(T sort[], int size)
{
	for (int i = 0; i < size; i++) {
		int min = i;
		int j;
		/*
		* Find the smallest element in the unsorted list
		*/
		for (j = i + 1; j < size; j++) {

			if (sort[j] < sort[min]) {
				min = j;
			}
		}
		/*
		* Swap the smallest unsorted element into the end of the
		* sorted list.
		*/
		T S = sort[min];
		sort[min] = sort[i];
		sort[i] = S;
	}
}

template <class T>
void Sort<T>::Shaker(T sort[], int size)
{
	int i = 0;
	int k = size - 1;
	while (i < k) {
		int min = i;
		int max = i;
		int j;
		for (j = i + 1; j <= k; j++) {
			if (sort[j] < sort[min]) {
				min = j;
			}
			if (sort[j] > sort[max]) {
				max = j;
			}
		}
		T S = sort[min];
		sort[min] = sort[i];
		sort[i] = S;
		if (max == i) {
			S = sort[min];
			sort[min] = sort[k];
			sort[k] = S;
		}
		else {
			S= sort[max];
			sort[max] = sort[k];
			sort[k] = S;
		}
		i++;
		k--;
	}
}
#endif
