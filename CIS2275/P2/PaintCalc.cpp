//Steven Chavez
//schavez256@yahoo.com	
//PaintCalc.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
#include "PaintCalc.h"

#define FILE_OUT (ss.str())

using namespace std;

//PUBLIC
PaintCalc::PaintCalc()
{
	rmH=rmW=rmL=rmR=0.0;
	paintCov = 1;
	exactP = 0.0;
	gallons = 0;
	numCoats = 0;	
	bCeiling = " ";	
	desc = " ";
	name = " ";
	filename = " ";   
	type = 1;
	percentNoPaint = 0;
	bFileOk = true;

}

void PaintCalc::SetType(int t)
{
	type = t;

	//Calls class function
	Calculate();
}

void PaintCalc::SetName(string n)
{
	name = n;
}

void PaintCalc::SetRoomDim(double l, double w, double h, int pnp)
{
	rmH = h;
	rmL = l;
	rmW = w;
	percentNoPaint = pnp;

	//Calls class function
	Calculate();
}

void PaintCalc::SetRoomDim(double rad, double h, int pnp)
{
	rmR = rad;
	rmH = h;
	percentNoPaint = pnp;

	//Calls class function
	Calculate();
}

void PaintCalc::SetPaintInfo(int pCov, int coats, string bCeil)
{
	paintCov = pCov;
	numCoats = coats;
	bCeiling = bCeil;

	//Calls class function
	Calculate();
}


//PRIVATE
void PaintCalc::Calculate()
{
	const double PI = 3.14159265;
	double wallArea = 0.0;
	double ceilArea = 0.0;
	double perNP = 0.0;


	if(type == 1)	//rectangle
	{
		wallArea = 2* (rmL *rmH) + 2 * (rmW * rmH);
		ceilArea = rmL * rmW;
	}
	else if(type == 2)	//circle
	{
		wallArea = 2 * PI * rmR * rmH;
		ceilArea = PI * pow(rmR, 2);
	}
	perNP = (100 - static_cast<double>(percentNoPaint)) /100;
	exactP = wallArea * perNP;

	//acounts for ceiling if they wanted it
	if(bCeiling == "true")
	{
		exactP += ceilArea;
	}

	exactP *= numCoats;
	exactP /= paintCov;

	gallons = static_cast<int>(ceil(exactP));

	BuildDesc();

}

void PaintCalc::BuildDesc()
{

	stringstream ss;
	//Customer name
	ss << "\nCustomer Name: " << name;
	ss.setf(ios::fixed | ios::showpoint);
	ss.precision(2);

	//How much will be subtracted for doors and windows
	ss << "\nPercent Subtracted: " << percentNoPaint
		<< "%";

	//Number of coats and the paint coverage
	ss << "\nNumberof Coats: " << numCoats;
	ss << "\nPaint Covarage: " << paintCov 
		<< " sqft/gal";
	
	//Ceiling
	ss << "\nCeiling: ";
	if(bCeiling == "true")
	{
		ss << "True";
	}
	else
	{
		ss << "False";
	}

	//Exact amount of paint required
	ss << "\nExact Amount of Paint: " << exactP
		<< " gal";

	//Number of whole gallons needed
	ss << "\nWhole Gallons Needed: " << gallons
		<< " gal";

	if(type == 1)
	{
		//Dimensions and shape of room
		ss << "\nRoom Shape: Rectangle";

		ss << "\nRoom Dimensions\n"
			<< "Width: " << rmW
			<< "\nLength: " << rmL
			<< "\nHeight: " << rmH
			<< "\n";
	}
	if(type == 2)
	{
		//Dimensions and shape of room
		ss << "\nRoom Shape: Circular";

		ss << "\nRoom Dimensions\n"
			<< "Radius: " << rmR
			<< "\nHeight: " << rmH
			<< "\n";

	}

	desc = ss.str();

}

void PaintCalc::WriteReport()
{
	//Set the Date variables to the computer's date.
	int month, day, yr;
	int hr, min;

	time_t rawtime;
	tm OStime;

	time(&rawtime);

	//Old Way p.389
	//OStime = localtime(&rawtime);

	//New way, not deprecated
	localtime_s(&OStime, &rawtime);
	
	month = OStime.tm_mon + 1;
	day = OStime.tm_mday;
	yr = OStime.tm_year + 1900;
	hr = OStime.tm_hour;
	min = OStime.tm_min;

	//File name
	//format: custName_date_time.txt
	stringstream ss;
	ss << name << "_" <<month <<day <<yr
		<< "_" << hr << min << ".txt";

	//rFileName catches the stringstream and
	//returns it to main.
	filename = ss.str();

	ofstream write;

	//open for input
	write.open(FILE_OUT);

	//check to see file is open.
	if(!write)
	{
		cout << "\nCan't find Output file " << FILE_OUT;
		bFileOk = false;
	}

	write << desc;
	
	write.close();
	bFileOk = true;

	BuildDesc();
}