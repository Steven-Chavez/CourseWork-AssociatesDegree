//Steven Chavez
//schavez256@cnm.edu
//PGA.h

#ifndef _PGA_H
#define _PGA_H

#include <string>
#include "Date.h"
using namespace std;

class PGA
{
private:
	int minIn, hrIn, minOut, hrOut, minTotal, hrTotal, dayTotal;
	double fee, rate; //rate = $/min or $/day
	bool bValid, bValidFile;
	string filename;
	string results;
	Date dateIn, dateOut;

	void ValidateTimeAndDate();
	void CalculateFee();
	void WriteResults();
	void WriteReceipt();

public:
	PGA();
	void SetTimeAndDateIn(int hr, int min, Date dateIn);
	bool IsValidFile(){return bValidFile;}
	bool IsValidTime(){return bValid;}
	string GetFilename(){return filename;}
	string GetResults(){return results;}
};
#endif