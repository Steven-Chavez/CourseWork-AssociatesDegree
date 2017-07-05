//Steven Chavez
//schavez256@yahoo.com
//Driver.cpp

#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
	int curHour, curMin;
	int day, month, year;
	int arivHour, arivMin;

	string parkAnswer = "yes";

	do
	{
		ObtainTimeOut(curHour, curMin, day, month, year);
		AskTimeIn(arivHour, arivMin);

		cout << "More parking? yes/no   ";
		getline(cin, parkAnswer);

	} while (parkAnswer == "yes");


}