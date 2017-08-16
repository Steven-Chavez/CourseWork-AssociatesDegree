//Authour: Steven Chavez
//Email: steven@stevenscode.com
//File: Logger.cpp

#include "stdafx.h"
#include "Logger.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define FILE_OUT fileName

using namespace std;

Logger::Logger()
{
	//Initialize varibles
	bLogOpen = true;
	hr = min = sec = day = mnth = yr = 0;
	fileName = " ";

	Time();		//Gets current time.

	Filename(); 	//construct filename
			//Log_mon.day.year.txt 

	//Open LogFile
	output.open(FILE_OUT);

	//Check if its open
	if(!output)
	{
		bLogOpen = false;
	}

	if(bLogOpen)
	{
		output << "Time Stamp: "
			<< mnth << "/" << day << "/"
			<< yr << "   " <<hr <<":" <<min
			<< ":" << sec << endl;
	}
	
}

void Logger::Filename()
{
	stringstream ss;

	ss << "Log_" << mnth << "." 
		<< day << "." << yr
		<< ".txt";

	fileName = ss.str();
}


//
//	The Logger Gets the current Date and 
//	Time and Sets the variables
//
void Logger::Time()
{
	//
	time_t rawtime;
	tm OStime;

	time(&rawtime);

	//Old Way p.389
	//OStime = localtime(&rawtime);

	//New way, not deprecated
	localtime_s(&OStime, &rawtime);
	
	mnth = OStime.tm_mon + 1;
	day = OStime.tm_mday;
	yr = OStime.tm_year + 1900;
	hr = OStime.tm_hour;
	min = OStime.tm_min;
	sec = OStime.tm_sec;

}

void Logger::StartLog(string begin)
{
	//StartLog Opens and Writes the Header
	//of the log file and 

	output << "C++ VENDING MACHINE COMPANY\n"
		<< "\nLOG FILE "   << begin;


}

void Logger::WriteLog(string lgDsc)
{
	//Enters into the log any time
	//a juice is despensed writting the
	// time and string from the dispenser

	output << "\n\nDispensed     "
		<< "Time: " <<hr <<":" <<min
		<< ":" << sec << endl
		<< lgDsc;
}

void Logger::CloseLog(string summary)
{
	//writes message from ~VendingMachine
	//Closes the file
	output << summary;

	output.close();
	string openfile= "notepad.exe " + fileName;
	system(openfile.c_str());
}


