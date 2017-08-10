// Programmer: Steven Chavez
// Email: schavez256@yahoo.com
// File: Driver.cpp
// Date: ‎June ‎19, ‎2014

#include <iostream>
#include <string>
#include "ArrayAnalyzer.h"

#define FILE_IN "Numbers.txt"
using namespace std;

int main()
{
	// Variables
	bool bValue = true;
	bool bOpn = true;
	string yesNo = "yes";
	string fileName = " ";
	string display = " ";
	string fileOut = " ";
	int answer = 1;
	int value = 0;
	int howMany = 0;

	// Header
	cout << "Name: Steven Chavez\nTitle: Array Analyzer"
		<< "\nProgram 3\n\n";

	cout << "Would you like to use the default file \""
		<< FILE_IN << "\"?  yes/no"
		<< "\n==> ";
	getline(cin, yesNo);

	//yes if they want to use default file
	//no if they want to enter their own
	if(yesNo == "yes")
	{
		fileName = FILE_IN;
	}
	else
	{
		cout << "\n\nEnter the file you wish to use."
			<< " (Please enter the\nfile extension"
			<< " also)"
			<< "\n==> ";
		getline(cin, fileName);
	}

	//create object
	ArrayAnalyzer arrayAnalyzer(fileName);

	bOpn = arrayAnalyzer.IsFileOpened();

	//Check report filname and status
	if(bOpn == false)
	{
		cout << "\nEnding program, can't find data file!\n";

		//can't find file so we end the program.
		exit(1);
	}
	else
	{
		cout << "\nThe ("
			<< fileName
			<< ") file was successfully found!\n\n";
	}
	 
	cout << "FILE RESULTS!\n\n";
	//Get data info from object to display
	cout << arrayAnalyzer.GetReport();
	
	//Ask user to enter summary file name
	cout << "\n\nPlease enter a name you wish to call your "
		<< "summary file.\n==> ";
	getline(cin, fileOut);

	//Set fileOut name into object
	bOpn = arrayAnalyzer.WriteSummary(fileOut);

	//check to see if file was written
	if(bOpn == false)
	{
		cout << "Ending program, can't find file to write too!\n";
		//can't find file so we end the program.
		exit(1);
	}
	else
	{
		cout << "\nThe (" << fileOut
			<< ") file was successfully written!\n";
	}

	do
	{
		//instructions
		cout<< "\nCHOOSE ONE OF THE FOLLOWING!" 
			<< "\n1. Enter a value, search for it, "
			<< "report whether it was found and if\n"
			<< "   so, how many were found.\n"
			<< "2. Exit Program!\n==> ";
		cin >> answer;
		cin.ignore();
		if(answer == 1)
		{
			howMany = 0;
			value = 0;

			cout << "\nPleaser enter an integer value"
				<< " ==> ";
			cin >> value;
			cout << endl;
			cin.ignore();

			bValue = arrayAnalyzer.FindValue(value, howMany);

			if(bValue)
			{
				cout <<"\nFOUND YOUR VALUE!"
					<< "\nYour Value: " << value
					<< "\nHow Many Times: " << howMany
					<< endl << endl;
			}
			else
			{
				cout << "\nCOULD NOT FIND YOUR"
					<< " VALUE!\n\n";
			}
		}
	}while(answer == 1);

	cout << "\n\nGood-Bye!\n\n";
	return 0;
}