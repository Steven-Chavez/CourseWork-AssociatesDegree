/**
* Author: Steven Chavez
* Email: steven@stevenscode.com
* File: Functions.cpp
* Date: 3/28/16
**/

#include "Functions.h"

#define NUMBERS_FILENAME "BJTest200K.txt"
#define NAMES_FILENAME "BJName25000.txt"

using namespace std;

void DisplayHeader()
{
	cout << "Name: Steven Chavez\n"
		<< "Program: P6 Template Sort\n"
		<< "Objects: Use a template class to be able sort\n"
		<< "different types.\n\n";
}

bool PopulateNumbers(int numbers[], int resetNumbers[], int numberSize)
{
	ifstream input;
	input.open(NUMBERS_FILENAME);

	if (!input)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < numberSize; i++)
		{
			input >> numbers[i];
			resetNumbers[i] = numbers[i];
		}
	}

	input.close();
	return true;
}

bool PopulatePersons(Person person[], Person resetPersons[], int personSize)
{
	PersonGen personGen;

	if(!personGen.IsTextFileRead())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < personSize; i++)
		{
			resetPersons[i] = person[i] = personGen.GetPerson();
		}
	}

	return true;
}

bool PopulateNames(string names[], string resetNames[], int nameSize)
{
	string firstName = "";
	string lastName = "";

	ifstream input;
	input.open(NAMES_FILENAME);

	if (!input)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < nameSize; i++)
		{
			input >> lastName >> firstName;
			lastName += " ";
			lastName += firstName;
			names[i] = lastName;
			resetNames[i] = names[i];
		}
	}
	input.close();
	return true;
}

string RecordSortTime(string sortName, string valueType, int start, int stop)
{
	stringstream ss;
	int miliseconds = (int)(stop - start);
	double seconds = (double)miliseconds / 1000;

	ss << sortName << " (" << valueType << ")    "
		<< seconds << ":" << miliseconds << "\n";

	cout << ss.str();
	return ss.str();
}

void ObtainOutputFileName(string *pFile)
{
	string filename = "";
	stringstream ss;

	cout << "What do you want to name your output file? (Ex. Output)\n";
	cin >> *pFile;
	ss << *pFile << ".txt";
	*pFile = ss.str();
}

string FirstAndLastTenNumbers(int numbers[], int numberSize)
{
	stringstream ss;
	numberSize--;

	ss << "\n\nFIRST 10 NUMBERS\n";
	for (int i = 0; i < 10; i++)
	{
		if (i % 5 != 0 || i == 0)
		{
			ss << numbers[i] << ", ";
		}
		else
		{
			ss << numbers[i] << "\n";
		}
	}

	ss << "\n\nLAST 10 NUMBERS\n";
	for (int i = numberSize-10; i < numberSize; i++)
	{
		if (i % 5 != 0)
		{
			ss << numbers[i] << ", ";
		}
		else
		{
			ss << numbers[i] << "\n";
		}
	}

	cout << ss.str() << "\n";
	return ss.str();
}

string FirstAndLastTenNames(string names[], int nameSize)
{
	stringstream ss;
	nameSize--;

	ss << "\n\nFIRST 10 NAMES \n";
	for (int i = 0; i < 10; i++)
	{
		if (i % 3 != 0 || i == 0)
		{
			ss << names[i] << " :: ";
		}
		else
		{
			ss << names[i] << "\n";
		}
	}

	ss << "\nLAST 10 NAMES\n";
	for (int i = nameSize - 10; i < nameSize; i++)
	{
		if (i % 3 != 0)
		{
			ss << names[i] << " :: ";
		}
		else
		{
			ss << names[i] << "\n";
		}
	}

	cout << ss.str() << "\n";
	return ss.str();
}

string FirstAndLastTenPersons(Person persons[], int personSize)
{
	stringstream ss;
	personSize--;

	ss << "\n\nFIRST 10 PERSONS \n";
	for (int i = 0; i < 10; i++)
	{
		if (i % 3 != 0 || i == 0)
		{
			ss << persons[i].GetName() << " :: ";
		}
		else
		{
			ss << persons[i].GetName() << "\n";
		}
	}

	ss << "\nLAST 10 PERSONS\n";
	for (int i = personSize - 10; i < personSize; i++)
	{
		if (i % 3 != 0 || i == personSize)
		{
			ss << persons[i].GetName() << " :: ";
		}
		else
		{
			ss << persons[i].GetName() << "\n";
		}
	}

	cout << ss.str() << "\n";
	return ss.str();
}