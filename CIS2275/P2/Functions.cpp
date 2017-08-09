//Steven Chavez
//schavez256@yahoo.com	
//Functions.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>

#define FILE_OUT (ss.str())

using namespace std;

void CourseHeader()
{
	cout << "NAME: Steven Chavez\n"
		<< "PROJECT NAME: P1 Painting using a Class\n"
		<< "PROJECT OBJECTIVE: The objective of this" 
		<< " program is to\n"
		<< "ask the user for the dimensions of the room"
		<< " they want\n"
		<< "to paint plus other questions so that"
		<< " the program\n"
		<< "can tell the user how many gallons of paint they\n"
		<< "need.\n\n";
}

void AskForNameAndShape(string &rName, int &rShape)
{
	//asks for customers name
	cout << "What is your name? ";
	getline(cin, rName);

	//asks for room shape
	cout << "\nPlease select the number associated with "
		<< "the shape of your room.\n"
		<< "1 - Rectangular\n"
		<< "2 - Circular\n"
		<< "==> ";
	cin >> rShape;
	cin.ignore();
	cout << "\n\n";
}

void AskForPaintInfo(int &rCoats, int &rCovarage, string 
					 &rCeiling)
{

	//asks for number of coats
	cout << "How many coats of paint are you going to do? ";
	cin >> rCoats;
	cin.ignore();

	//asks for square ft covarage of paint chosen
	cout << "How much square feet does your paint cover per"
		<< " gallon? ";
	cin >> rCovarage;
	cin.ignore();

	//asks if user wants to paint the ceiling
	cout << "Do you plan on painting the ceiling? true/false  ";
	getline(cin, rCeiling);

}


//Asks for rectangle dimensions
void AskForDimensions(double *pW, double *pL, 
					  double *pH, int *pPercent)
{
	cout << "\nPlease enter the following dimensions in feet.\n";
	cout << "Width: ";
	cin >> *pW;
	cin.ignore();

	cout << "Length: ";
	cin >> *pL;
	cin.ignore();

	cout << "Height: ";
	cin >> *pH;
	cin.ignore();

	cout << "Estimate the total percentage of windows and doors\n"
		<< "compared to the room. (round to nearest whole number)\n"
		<< "==> ";
	cin >> *pPercent;
	cin.ignore();
}

//Asks for circular dimensions
void AskForDimensions(double *pR, double *pH, int *pPercent)
{
	cout << "\nPlease enter the following dimensions in feet.\n";
	cout << "Radius: ";
	cin >> *pR;
	cin.ignore();

	cout << "Height: ";
	cin >> *pH;
	cin.ignore();

	cout << "Estimate the total percentage of windows and doors\n"
		<< "compared to the room. (round to nearest whole number)\n"
		<< "==> ";
	cin >> *pPercent;
	cin.ignore();

}