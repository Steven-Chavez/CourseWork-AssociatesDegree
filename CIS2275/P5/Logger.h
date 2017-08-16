//Authour: Steven Chavez
//Email: steven@stevenscode.com
//File: Logger.h

#ifndef _LOGGER_H
#define _LOGGER_H

#include <string>
#include <fstream>

using namespace std;

class Logger
{
private:
	string fileName;
	bool bLogOpen;
	ofstream output;
	int hr, min, sec, day, mnth, yr;
	
	
	void Filename();	//creates the file name
	void Time();		//Gets the system time

public:
	Logger();

	//Writes the initial lines of the log file
	void StartLog(string begin);	

	//writes any time a juice is dispensed
	void WriteLog(string lgDsc); //time(), string

	//writes the message from the VendingMachine destructor
	//and closes file.
	void CloseLog(string summary);
		//string openfile = "notepad.exe " + filename;
		//system(openfile.c_str());

	bool IsLogOpen(){return bLogOpen;}
};
#endif
