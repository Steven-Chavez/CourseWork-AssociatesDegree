//Steven Chavez
//schavez256@yahoo.com
//Driver.cpp

#include <iostream>
#include <string>
#include <sstream>
#include "Functions.h"

using namespace std;

int main()
{
	//Declare Variables
	string answer = "";
	string sentance = "";
	char mostFre = ' ';
	int check = 0;
	int freqOfChar = 0;										

	//Display Header
	Header();

	//Brief Explanation
	cout << "\nThe program counts the most frequent character"
		<< "\nof the sentance you enter.\n";

	//Open a do-while loop
	do
	{
		//Ask User to enter sentence or phrase
		cout << "\nPlease enter a sentance.\n==>";
		getline(cin, sentance);

		//Call MostFrequentChar
		MostFrequentChar(sentance, mostFre, &freqOfChar);

		//Display Results
		cout << "\nThe Most Frequent Character is: ";
		
		//So that space doesn't output as a blank
		check = mostFre;		//turns char to ascii for chk
		if(check == 32)
		{
			cout << "Space";
		}
		else
		{
			cout << mostFre;
		}

		cout << "\nNumber of Occurances: " << freqOfChar;


		//To end do-while
		cout << "\n\nWould you like to enter another sentence?"
			<< " yes/no  ";
		getline(cin, answer);

	}while(answer == "yes");

	cout << "\n\nGood-Bye!\n\n";
	
	return 0;
}