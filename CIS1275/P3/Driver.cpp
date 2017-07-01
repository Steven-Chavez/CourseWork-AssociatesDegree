//Steven Chavez
//schavez256@yahoo.com
//Driver.cpp

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
	//COURSE HEADER AND DIRECTIONS
	cout << "NAME: Steven Chavez\n"
		<< "PROGRAM TITLE: P3 Guess the Color\n"
		<< "PROGRAM OBJECTIVE: The objective of this program "
		<< "is to guess\nthe correct color from the hint given"
		<< "\n\nDIRECTIONS: You only get 3 tries to guess the "
		<< "color correctly.\nIf you do not guess correctly "
		<< "you will be shown the correct answer.\n\n";

	//DECLARE VARIABLES
	int number;
	int triesLeft;
	int triesTaken;
	int i;
	string answer, userGuess;

	//DECLARE TWO VECTOR STRINGS
	vector<string> colorName;
	vector<string> colorHint;

	//LOAD VECTORS
	colorName.push_back("pink");
	colorHint.push_back("What is the color of Majin Buu?");

	colorName.push_back("black");
	colorHint.push_back("What color is Batman's costume?");

	colorName.push_back("red");
	colorHint.push_back("What color is Darth Vadar's light saber?");

	colorName.push_back("white");
	colorHint.push_back("What is the color of a cartoon ghost?");

	colorName.push_back("green");
	colorHint.push_back("What color is Yoda's light saber?");

	colorName.push_back("yellow");
	colorHint.push_back("What is the hair color of a Super Saiyan?");

	do
	{
		cout << "\nHINT: ";

		//set random generator for colorHint
		//rand()%N, set N to 6 for random between 0-5
		srand((unsigned)time(NULL));
		number = rand() % 6;
		cout << setw(5) << colorHint.at(number);

		for (i = 0; i<3; ++i)
		{
			cout << "\nGUESS THE COLOR: ";
			getline(cin, userGuess);

			if (userGuess == colorName.at(number))
			{
				cout << "\nCongratulations you guessed correctly!";
				triesTaken = i + 1;
				cout << "\nTries Taken to Answer: " << triesTaken;
				break;
			}
			else
			{
				triesLeft = 3 - (i + 1);
				cout << "\nSorry wrong answer.";
				cout << " \nTries Left: " << triesLeft;
				//do math for triesLeft

				if(i==2)
				{
					cout<< "\nTHE CORRECT ANSWER WAS: "
						<< colorName.at(number);
				}
			}
		}

		cout << "\n\nPlay another round? yes/no ";
		getline(cin, answer);

	} while (answer == "yes");

	cout << "\nGood-Bye\n\n"; 
	return 0;
}