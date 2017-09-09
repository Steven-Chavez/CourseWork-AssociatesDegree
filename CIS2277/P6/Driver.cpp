/**
* Author: Steven Chavez
* Email: steven@stevenscode.com
* File: Functions.cpp
* Date: 3/28/16
**/

#include <iostream>
#include <fstream>
#include <time.h>
#include "Sort.h"
#include "Functions.h"
#include "ChavezPersonGen\Person.h"

using namespace std;

const int NUMBERS_SIZE = 200000;
const int NAMES_SIZE = 25000;
const int PERSONS_SIZE = 10000;

Person persons[PERSONS_SIZE];
Person resetPersons[PERSONS_SIZE];

int main()
{
	string filename;
	ofstream output;
	clock_t start, stop;
	bool populated[3];
	int *numbers = new int[NUMBERS_SIZE];
	int *resetNumbers = new int[NUMBERS_SIZE];
	string *names = new string[NAMES_SIZE];
	string *resetNames = new string[NAMES_SIZE];

	Sort<int> sortNumbers;
	Sort<string> sortNames;
	Sort<Person> sortPersons;

	
	populated[0] = PopulateNumbers(numbers, resetNumbers, NUMBERS_SIZE);
	populated[1] = PopulateNames(names, resetNames, NAMES_SIZE);
	populated[2] = PopulatePersons(persons, resetPersons, PERSONS_SIZE);


	DisplayHeader();
	ObtainOutputFileName(&filename);
	
	output.open(filename);
	if ( !output || populated[0] == false 
		|| populated[1] == false || populated[2] == false)
	{
		delete[] numbers, resetNumbers, names, 
			resetNames, persons, resetPersons;
	}
	else
	{
		output << "Name: Steven Chavez\n"
			   << "Project: P6 Template Class\n\n"
			   << "** BEFORE SORT **"
			   << FirstAndLastTenNumbers(numbers, NUMBERS_SIZE)
		       << FirstAndLastTenNames(names, NAMES_SIZE)
		       << FirstAndLastTenPersons(persons, PERSONS_SIZE);

		output << "\n\n** SORT TIMES **\n\n";

		// ###########################################################
		// (INTEGER) BUBBLE SORT
		start = clock();
		sortNumbers.Bubble(numbers, NUMBERS_SIZE);
		stop = clock();
		output << RecordSortTime("Bubble Sort", "int[]", start, stop);
		ResetSortedArray(numbers, resetNumbers, NUMBERS_SIZE);

		// (INTEGER) COMB11 SORT
		start = clock();
		sortNumbers.Comb11(numbers, NUMBERS_SIZE);
		stop = clock();
		output << RecordSortTime("Comb 11 Sort", "int[]", start, stop);
		ResetSortedArray(numbers, resetNumbers, NUMBERS_SIZE);

		// (INTEGER) INSERTION SORT
		start = clock();
		sortNumbers.Insertion(numbers, NUMBERS_SIZE);
		stop = clock();
		output << RecordSortTime("Insertion Sort", "int[]", start, stop);
		ResetSortedArray(numbers, resetNumbers, NUMBERS_SIZE);

		// (INTEGER) SELECTION SORT
		start = clock();
		sortNumbers.Selection(numbers, NUMBERS_SIZE);
		stop = clock();
		output << RecordSortTime("Selection Sort", "int[]", start, stop);
		ResetSortedArray(numbers, resetNumbers, NUMBERS_SIZE);

		// (INTEGER) SHAKER SORT
		start = clock();
		sortNumbers.Shaker(numbers, NUMBERS_SIZE);
		stop = clock();
		output << RecordSortTime("Shaker Sort", "int[]", start, stop) << "\n\n\n";
		

		//#############################################################
		// (STRING) BUBBLE SORT
		start = clock();
		sortNames.Bubble(names, NAMES_SIZE);
		stop = clock();
		output << RecordSortTime("Bubble Sort", "string[]", start, stop);
		ResetSortedArray(names, resetNames, NAMES_SIZE);

		// (STRING) COMB11 SORT
		start = clock();
		sortNames.Comb11(names, NAMES_SIZE);
		stop = clock();
		output << RecordSortTime("Comb 11 Sort", "string[]", start, stop);
		ResetSortedArray(names, resetNames, NAMES_SIZE);

		// (STRING) INSERTION SORT
		start = clock();
		sortNames.Insertion(names, NAMES_SIZE);
		stop = clock();
		output << RecordSortTime("Insertion Sort", "string[]", start, stop);
		ResetSortedArray(names, resetNames, NAMES_SIZE);

		// (STRING) SELECTION SORT
		start = clock();
		sortNames.Selection(names, NAMES_SIZE);
		stop = clock();
		output << RecordSortTime("Selection Sort", "string[]", start, stop);
		ResetSortedArray(names, resetNames, NAMES_SIZE);

		// (STRING) SHAKER SORT
		start = clock();
		sortNames.Shaker(names, NAMES_SIZE);
		stop = clock();
		output << RecordSortTime("Shaker Sort", "string[]", start, stop) << "\n\n\n";


		//#############################################################
		// (PERSON) BUBBLE SORT
		start = clock();
		sortPersons.Bubble(persons, PERSONS_SIZE);
		stop = clock();
		output << RecordSortTime("Bubble Sort", "Person[]", start, stop);
		ResetSortedArray(persons, resetPersons, PERSONS_SIZE);

		// (PERSON) COMB11 SORT
		start = clock();
		sortPersons.Comb11(persons, PERSONS_SIZE);
		stop = clock();
		output << RecordSortTime("Comb 11 Sort", "Person[]", start, stop);
		ResetSortedArray(persons, resetPersons, PERSONS_SIZE);

		// (PERSON) INSERTION SORT
		start = clock();
		sortPersons.Insertion(persons, PERSONS_SIZE);
		stop = clock();
		output << RecordSortTime("Insertion Sort", "Person[]", start, stop);
		ResetSortedArray(persons, resetPersons, PERSONS_SIZE);

		// (PERSON) SELECTION SORT
		start = clock();
		sortPersons.Selection(persons, PERSONS_SIZE);
		stop = clock();
		output << RecordSortTime("Selection Sort", "Person[]", start, stop);
		ResetSortedArray(persons, resetPersons, PERSONS_SIZE);

		// (PERSON) SHAKER SORT
		start = clock();
		sortPersons.Shaker(persons, PERSONS_SIZE);
		stop = clock();
		output << RecordSortTime("Shaker Sort", "Person[]", start, stop) << "\n\n\n";

		output << "** AFTER SORT **"
			<< FirstAndLastTenNumbers(numbers, NUMBERS_SIZE)
			<< FirstAndLastTenNames(names, NAMES_SIZE)
			<< FirstAndLastTenPersons(persons, PERSONS_SIZE);

		output.close();

		// free memory
		delete[] numbers, resetNumbers, names,
			resetNames, persons, resetPersons;
	}

	return 0;
}