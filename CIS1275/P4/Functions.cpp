//Steven Chavez
//schavez256@yahoo.com
//Functions.cpp

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Write header
void WriteHeader()
{
	cout<< "NAME: Steven Chavez\n"
		<< "PROGRAM TITLE: P4 The Crow and the Pitcher\n"
		<< "PROGRAM OBJECTIVE: The objective is to find out\n"
		<< "how many pebbles the crow needs to put in a\n"
		<< "half filled pitcher to raise the water level\n"
		<< "so that the crow can drink the water.\n\n";

	cout << "Please enter the following values in inches.\n";
}

//Ask for Diameter
double AskPitcherDiameter()
{
	double diameter;
	cout<< "\nPitcher Diameter: ";
	cin >> diameter;
	cin.ignore();

	return diameter;
}

//Ask for Height
double AskPitcherHeight()
{
	double height;
	cout << "Pitcher Height: ";
	cin >> height;
	cin.ignore();

	return height;
}


//Ask for Pebble Diameter
double AskPebbleDiameter()
{
	double diameter;
	cout << "Pebble Diameter: ";
	cin >> diameter;
	cin.ignore();
	
	return diameter;
}


//Ask for Beak length
double AskBeakLength()
{
	double length;
	cout << "Beack Length: ";
	cin >> length;
	cin.ignore();

	return length;
}


//Calc for number of pebbles
int CalcPebbles(double diameterPitcher,double heightPitcher, 
				double diameterMarbles, double beakLength)
{
	int numPebbles;
	double cylinderVol, sphereVol;
	double halfCylinderVol, volPerInch;
	double minusFromHeight, drinkHeight;
	double drinkVol, pebbleVol;
	const double PI = 3.14159265;

	//Cylinder Vol
	cylinderVol = PI*heightPitcher*pow(diameterPitcher, 2)/4;

	//Sphere Vol
	sphereVol = PI*pow(diameterMarbles,3)/6;

	//Water lever is at half point in cyliner
	halfCylinderVol = cylinderVol/2;

	//Volume per inch
	volPerInch = cylinderVol/heightPitcher;

	//Beak has to be 0.5in submerged
	minusFromHeight = beakLength-0.5;

	//the water height crow can drink from
	drinkHeight = heightPitcher - minusFromHeight;

	//use volPerInch to calc the vol for drinkHeight
	drinkVol = drinkHeight * volPerInch;

	//Minus from halfCylinder for pebbleVol;
	pebbleVol = drinkVol - halfCylinderVol;

	//number of pebbles
	numPebbles = (int)ceil(pebbleVol/sphereVol);
	
	return numPebbles;
}



//Display results
void ShowResults(double diameterPitcher, double heightPitcher, 
				 double diameterMarbles, double beakLength, 
				 int numPebbles)
{
	cout<< "\nResults:\n"
		<< "Number of Pebbles: " << numPebbles
		<< "\nDiameter of Pebble: " << diameterMarbles
		<< " in\n"
		<< "Beak Length: " << beakLength
		<< " in\n"
		<< "Diameter of Pitcher: " << diameterPitcher 
		<< " in\n"
		<< "Height of Pitcher: " << heightPitcher
		<< " in\n\n";	
}
