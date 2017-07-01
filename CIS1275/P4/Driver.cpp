//Steven Chavez
//schavez256@yahoo.com
//Driver.cpp

#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
	//Declare variables
	string answer; 
	double diameterPitcher, heightPitcher;
	double diameterMarbles, beakLength;
	int numPebbles;

	//Display Course header & instructions
	WriteHeader();

	do
	{
		//Ask for data
		diameterPitcher = AskPitcherDiameter();
		heightPitcher = AskPitcherHeight();
		diameterMarbles = AskPebbleDiameter();
		beakLength = AskBeakLength();

		//Calculate number of pebbles
		numPebbles = CalcPebbles(diameterPitcher,heightPitcher, 
						diameterMarbles, beakLength);
	
		//Display results
		ShowResults (diameterPitcher,heightPitcher, 
				diameterMarbles, beakLength, numPebbles);

		//continue or stop do while loop
		cout << "\nWould you like to perform another calculation?"
		<< " yes/no ";
		getline(cin,answer);

	}while (answer == "yes");

	cout << "\nGood-bye!\n\n";

	return 0;
}



		
	

