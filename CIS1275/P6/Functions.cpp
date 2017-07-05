//Steven Chavez
//schavez256@yahoo.com
//Functions.cpp

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void ObtainTimeOut(int &rCurHour, int &rCurMin, int &rDay,
	int &rMonth, int &rYear)
{
	time_t rawtime;
	struct tm OStime;
	time(&rawtime);
	localtime_s(&OStime, &rawtime);

	rMonth = OStime.tm_mon + 1;
	rDay = OStime.tm_mday;
	rYear = OStime.tm_year + 1900;

	rCurHour = OStime.tm_hour;
	rCurMin = OStime.tm_min;

	cout << "Welcome to the C++ Airport Parking "
		<< "Garage      Current time is "
		<< rCurHour << ":" << rCurMin << "\n";
}

void AskTimeIn(int &rArivHour, int &rArivMin)
{
	cout << "What time did you arrive at the "
		<< "airport? (enter time in HR:MIN) ";
	cout << "\nHour: ";
	cin >> rArivHour;
	cout << "Min: ";
	cin >> rArivMin;
	cin.ignore();

	cout << "Your arrival time is "
		<< rArivHour << ":" << rArivMin << "\n";
}

bool ValidateTimes(int &rCurHour, int &rCurMin,
	int &rArivHour, int &rArivMin)
{
	if (rArivHour >= 0 && rArivHour <= 23)
	{
		cout << "\nSorry, that is an invalid entry time.\n";
		return false;
	}
	else if (rArivMin >= 0 && rArivHour <= 59)
	{
		cout << "\nSorry, that is an invalid entry time.\n";
		return false;
	}

}