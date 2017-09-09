/**
* Author: Steven Chavez
* Email: steven@stevenscode.com
* File: Functions.h
* Date: 3/28/16
**/

#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ChavezPersonGen\Person.h"
#include "ChavezPersonGen\PersonGen.h"

using namespace std;

void DisplayHeader();
void ObtainOutputFileName(string *pFile);
bool PopulateNumbers(int numbers[], int resetNumbers[], int numberSize);
bool PopulatePersons(Person person[], Person resetPersons[], int personSize);
bool PopulateNames(string names[], string resetNames[], int nameSize);
string RecordSortTime(string sortName, string valueType, int start, int stop);
string FirstAndLastTenNumbers(int numbers[], int numberSize);
string FirstAndLastTenNames(string names[], int nameSize);
string FirstAndLastTenPersons(Person persons[], int personSize);

template<class T>
void ResetSortedArray(T sorted[], T original[], int size)
{
	for (int i = 0; i < size; i++)
	{
		sorted[i] = original[i];
	}
}

#endif