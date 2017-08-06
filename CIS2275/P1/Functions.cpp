//Steven Chavez
//schavez256@yahoo.com	
//Functions.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>

#define FILE_OUT (ss.str())

using namespace std;

void CourseHeader()
{
	cout << "NAME: Steven Chavez\n"
		<< "PROJECT NAME: P1 Painting\n"
		<< "PROJECT OBJECTIVE: The objective of this program is to\n"
		<< "ask the user for the dimensions of the room they want\n"
		<< "to paint plus other questions so that the program\n"
		<< "can tell the user how many gallons of paint they\n"
		<< "need.\n\n";
}


void AskForNameAndShape(string &rName, int &rShape)
{
	//asks for customers name
	cout << "What is your name? ";
	getline(cin, rName);

	//asks for room shape
	cout << "\nPlease select the number associated with "
		<< "the shape of your room.\n"
		<< "1 - Rectangular\n"
		<< "2 - Circular\n"
		<< "==> ";
	cin >> rShape;
	cin.ignore();
	cout << "\n\n";
}


void AskForPaintInfo(int &rCoats, int &rCovarage, string &rCeiling)
{

	//asks for number of coats
	cout << "How many coats of paint are you going to do? ";
	cin >> rCoats;
	cin.ignore();

	//asks for square ft covarage of paint chosen
	cout << "How much square feet does your paint cover per gallon? ";
	cin >> rCovarage;
	cin.ignore();

	//asks if user wants to paint the ceiling
	cout << "Do you plan on painting the ceiling? true/false  ";
	getline(cin, rCeiling);

}


//Asks for rectangle dimensions
void AskForDimensions(double *pW, double *pL, 
					  double *pH, int *pPercent)
{
	cout << "\nPlease enter the following dimensions in feet.\n";
	cout << "Width: ";
	cin >> *pW;
	cin.ignore();

	cout << "Length: ";
	cin >> *pL;
	cin.ignore();

	cout << "Height: ";
	cin >> *pH;
	cin.ignore();

	cout << "Estimate the total percentage of windows and doors\n"
		<< "compared to the room. (round to nearest whole number)\n"
		<< "==> ";
	cin >> *pPercent;
	cin.ignore();
}

//Asks for circular dimensions
void AskForDimensions(double *pR, double *pH, int *pPercent)
{
	cout << "\nPlease enter the following dimensions in feet.\n";
	cout << "Radius: ";
	cin >> *pR;
	cin.ignore();

	cout << "Height: ";
	cin >> *pH;
	cin.ignore();

	cout << "Estimate the total percentage of windows and doors\n"
		<< "compared to the room. (round to nearest whole number)\n"
		<< "==> ";
	cin >> *pPercent;
	cin.ignore();

}




int HowManyGallons(double r, double h, string ceiling, 
				   int coats, int covarage, int percent,
				   double *pWallArea,double *pCeilArea, 
				   double *pAmount, double *pTotal)
{
	const double PI = 3.14159265;
	double p = 0.0;
	double a , b;
	a = b = 0.0;
	int c = 0;

	if(ceiling == "false")
	{
		*pWallArea = 2 * PI * r * h;
		*pTotal = *pWallArea;
		a = *pTotal/covarage;
		b = coats * a;
		p = (100 - static_cast<double>(percent)) /100;
		*pAmount = b * p;
		c = static_cast<int>(ceil(*pAmount));
	

		return c;
	}
	else if(ceiling == "true")
	{
		*pWallArea = 2 * PI * r * h;
		*pCeilArea = PI * pow(r,2);
		*pTotal = *pWallArea + *pCeilArea;
		a = *pTotal/covarage;
		b = coats * a;
		p = (100 - static_cast<double>(percent)) /100;
		*pAmount = b * p;
		c = static_cast<int>(ceil(*pAmount));
		

		return c;
	}

	
	return 0;
}


int HowManyGallons(double w, double l, double h, 
				   string ceiling, 
				   int coats, int covarage, int percent, 
				   double *pWallArea, double *pCeilArea,
				   double *pAmount, double *pTotal)
{
	

	//makes it easier for me to do math
	//in the equation
	double p = 0.0;
	double a , b;
	a = b = 0.0;
	int c = 0;


	if(ceiling == "false")
	{
		*pWallArea = 2 * (l * h) + 2 * (w * h);
		*pTotal = *pWallArea;
		a = *pTotal/covarage;
		b = coats * a;
		p = (100 - static_cast<double>(percent)) /100;
		*pAmount = b * p;
		c = static_cast<int>(ceil(*pAmount));
		

		return c;
	}
	else if(ceiling == "true")
	{
		*pWallArea = 2 * (l * h) + 2 * (w * h);
		*pCeilArea = l * w;
		*pTotal = *pWallArea + *pCeilArea;
		a = *pTotal/covarage;
		b = coats * a;
		p = (100 - static_cast<double>(percent)) /100;
		*pAmount = b * p;
		c = static_cast<int>(ceil(*pAmount));
		

		return c;
	}

	return 0;
}


//Made a function for display because I didn't want to
//crowd up main
void DisplayToUser(double r, double w, double l, double h, 
				   string ceiling, 
				   int coats, int covarage, int percent, 
				   double wallArea, double ceilArea, 
				   string name,
				   double amount, int shape, int numGal, 
				   double total)
{
	//for Rectangle shape room desplay
	if(shape == 1)
	{
		//Customer name
		cout << "\nCustomer Name: " << name;
		cout.setf(ios::fixed | ios::showpoint);
		cout.precision(2);

        //Square footage of the walls and ceiling
		cout << "\nTotal Square Footage: " <<total;

		//How much will be subtracted for doors and windows
		cout << "\nPercent Subtracted: " << percent
			<< "%";

		//Number of coats and the paint coverage
		cout << "\nNumber of Coats: " << coats;
		cout << "\nPaint Covarage: " << covarage 
			<< " sqft/gal";

		//Exact amount of paint required
		cout << "\nExact Amount of Paint: " << amount
			<< " gal";

		//Number of whole gallons needed
		cout << "\nWhole Gallons Needed: " << numGal
			<< " gal";

		//Dimensions and shape of room
		cout << "\nRoom Shape: Rectangle";

		cout << "\nRoom Dimensions\n"
			<< "Width: " << w
			<< "\nLength: " << l
			<< "\nHeight: " << h
			<< "\n";

	}

	//for Circular shape room desplay
	else if(shape == 2)
	{
			//Customer name
		cout << "\nCustomer Name: " << name;
		cout.setf(ios::fixed | ios::showpoint);
		cout.precision(2);

        //Square footage of the walls and ceiling
		cout << "\nTotal Square Footage: " <<total;

		//How much will be subtracted for doors and 
		//windows
		cout << "\nPercent Subtracted: " << percent
			<< "%";

		//Number of coats and the paint coverage
		cout << "\nNumber of Coats: " << coats;
		cout << "\nPaint Covarage: " << covarage 
			<< " sqft/gal";

		//Exact amount of paint required
		cout << "\nExact Amount of Paint: " << amount
			<< " gal";

		//Number of whole gallons needed
		cout << "\nWhole Gallons Needed: " << numGal
			<< " gal";

		//Dimensions and shape of room
		cout << "\nRoom Shape: Circular";

		cout << "\nRoom Dimensions\n"
			<< "Radius: " << r
			<< "\nHeight: " << h
			<< "\n";

	}

}


bool WriteReport(double r, double w, double l, double h,
				 string ceiling, int coats, int covarage,
				 int percent, double wallArea, 
				 double ceilArea, string name, 
				 double amount, int shape, int numGal, 
				 double total,string &rFileName)
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
	rFileName = ss.str();

	ofstream write;

	//open for input
	write.open(FILE_OUT);

	//check to see file is open.
	if(!write)
	{
		cout << "\nCan't find Output file " << FILE_OUT;
		return false;
	}

	//for Rectangle shape room desplay
	if(shape == 1)
	{
		//Customer name
		write << "Customer Name: " << name;
		write.setf(ios::fixed | ios::showpoint);
		write.precision(2);

        //Square footage of the walls and ceiling
		write << "\nTotal Square Footage: " <<total;

		//How much will be subtracted for doors and windows
		write << "\nPercent Subtracted: " << percent
			<< "%";

		//Number of coats and the paint coverage
		write << "\nNumber of Coats: " << coats;
		write << "\nPaint Covarage: " << covarage 
			<< " sqft/gal";

		//Exact amount of paint required
		write<< "\nExact Amount of Paint: " << amount
			<< " gal";

		//Number of whole gallons needed
		write << "\nWhole Gallons Needed: " << numGal
			<< " gal";

		//Dimensions and shape of room
		write << "\nRoom Shape: Rectangle";

		write << "\nRoom Dimensions\n"
			<< "Width: " << w
			<< "\nLength: " << l
			<< "\nHeight: " << h
			<< "\n";

	}

	//for Circular shape room desplay
	else if(shape == 2)
	{
			
		//Customer name
		write << "Customer Name: " << name;
		write.setf(ios::fixed | ios::showpoint);
		write.precision(2);

        //Square footage of the walls and ceiling
		write << "\nTotal Square Footage: " <<total;

		//How much will be subtracted for doors and 
		//windows
		write << "\nPercent Subtracted: " << percent
			<< "%";

		//Number of coats and the paint coverage
		write << "\nNumber of Coats: " << coats;
		write << "\nPaint Covarage: " << covarage 
			<< " sqft/gal";

		//Exact amount of paint required
		write<< "\nExact Amount of Paint: " << amount
			<< " gal";

		//Number of whole gallons needed
		write << "\nWhole Gallons Needed: " << numGal
			<< " gal";

		//Dimensions and shape of room
		write << "\nRoom Shape: Circular";

		write << "\nRoom Dimensions\n"
			<< "Radius: " << r
			<< "\nHeight: " << h
			<< "\n";
	}

	write.close(); 

	return true;
}