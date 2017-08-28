/**
 * Programmer: Steven Chavez
 * Email: steven@stevenscode.com
 * File: Sorter.h
 * Date: 3/1/16
 **/

#ifndef _SORTER_H
#define _SORTER_H

using namespace std;

class Sorter
{
	private:

	public: 
		void BubbleSort(int num[], int size);
		void InsertionSort(int num[], int size);
		void SelectionSort(int num[], int size);
		void CombSort11(int num[], int size);
		void ShakerSort(int num[], int size);
		void Shell(int num[], int size);
		void InPlaceMergeSort(int a[], int lo0, int hi0);
		void QuickSort(int a[], int lo0, int hi0);
		void GoofySort(int num[], int size);
};
#endif