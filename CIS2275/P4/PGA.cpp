//Steven Chavez
//schavez256@cnm.edu
//PGA.cpp

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "PGA.h"
#include "Date.h"

#define FILE_OUT (rr.str())

using namespace std;

PGA::PGA()
{
	minIn = hrIn = 0;
	minOut = dateOut.GetMin();
	hrOut = dateOut.GetHour();
	minTotal = hrTotal = dayTotal = 0;
	fee = rate = 0;
	bValid = bValidFile = true;
	filename = results = " ";

}

void PGA::SetTimeAndDateIn(int hr, int min, Date dateIn)
{
	hrIn = hr;
	minIn = min;
	this -> dateIn = dateIn;

	ValidateTimeAndDate();
	if(bValid)
	{
		CalculateFee();
		WriteResults();
		WriteReceipt();
	}
	else
	{
		results = "Time or Date not valid!";
	}

}

void PGA::ValidateTimeAndDate()
{
	//checks that minute value is within 0-59 
	//checks that hour is within 0-23
	//checks dateOut is not sooner that dateIn
	//if on same day time out is not sooner than time in
	//Sets Boolean Value indicating true for valide times
	bValid = true;

	if(dateIn.ValidateThisDate() == false)
	{
		bValid = false;
	}

	if(hrIn < 0 || hrIn > 23)
	{
		bValid = false;
	}
	else if(minIn < 0 || minIn > 59)
	{
		bValid = false;
	}
	else if(dateIn > dateOut)
	{
		bValid = false;
	}
	else if(dateIn == dateOut)
	{
		if(hrIn > hrOut)
		{
			bValid = false;
		}
		else if(hrIn == hrOut)
		{
			if(minIn > minOut)
			{
				bValid = false;
			}
			else if(minIn == minOut)
			{
				bValid = false;
			}
		}
	}
}


void PGA::CalculateFee()
{
	//dayTotal using overloaded operators
	dayTotal = dateOut - dateIn;
	
	//finding hrTotal
	if(dayTotal == 0)
	{
		hrTotal = hrOut - hrIn;
		
	}
	else if(dayTotal > 0)
	{
		hrTotal = 23-hrIn;
		hrTotal += hrOut;
	}

	//finding minTotal
	if(minOut > minIn)
	{
		minTotal = minOut - minIn;
	}
	else if(minOut < minIn)
	{
		minTotal = 60 - minIn;
		minTotal += minOut;
	}

	//calculate fee
	if(dayTotal == 0)
	{
		fee = hrTotal * 2;

		if(hrOut == hrIn && minTotal > 0)
		{
			fee = 2;
		}
	}
	else if(dayTotal > 0 && dayTotal <= 7)
	{
		fee = dayTotal * 10;
	}
	else
	{
		fee = dayTotal * 7;
	}
}

void PGA::WriteResults()
{
	stringstream ss;

	//dateIn results
	ss << "C++ International Airport\r\n"
		<< "\r\nDate In: "
		<< dateIn.GetFormattedDate()
		<<"   Time In: " << hrIn
		<< ":" << minIn

		//dateOut results
		<< "\r\n" << dateOut.GetFormattedDate()
		<<"   Time Out: " << dateIn.GetHour()
		<< ":" << dateIn.GetMin()
		

		//Total time parked
		<< "\r\n\r\nTotal Time Parked "
		<< "\r\nDays: " << dayTotal
		<< "\r\nHours: " << hrTotal
		<< "\r\nMinutes: " << minTotal;

		//Fee
		ss.setf(ios::fixed | ios::showpoint);
		ss.precision(2);
		ss << "\r\nTotal Fee: $" << fee;

		results = ss.str();

		//Display Results
		cout << results;
}

void PGA::WriteReceipt()
{
	stringstream rr;
	rr << hrIn << "_" << minOut 
		<< ".txt";
	
	ofstream receipt;
	
	//open for input
	receipt.open(FILE_OUT);

	if(!receipt)
	{
		bValidFile = false;
	}

	receipt << results
		<< "\n\nHave a nice day!";

}
