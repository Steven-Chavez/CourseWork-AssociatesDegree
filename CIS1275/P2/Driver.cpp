//Name: Steven Chavez
//Email: schavez256@yahoo.com
//File: Driver.cpp

#include <iostream>
#include <string> 
#include <cmath> 

using namespace std;

int main()
{
	//VARIABLES
	//constants
	const double GOLD_DENSITY = 0.698;     // lb/in3
	const double LEAD_DENSITY = 0.410;     // lb/in3
	const double SILVER_DENSITY = 0.379;	// lb/in3
	const double ALUMINUM_DENSITY = 0.098;	// lb/in3
	const double PI = 3.14159265;

	//string
	string metal;    //for input to decide metal
	string answer;   //for end of do while loop

	//input
	double diameter;
	double length;

	//output
	double volume_in3;
	double weight_lbs;

	//other
	double density = 0;

	//COURSE HEADER
	cout << "\n NAME: Steven Chavez"
		<< "\n PROGRAM TITLE: P2 Metal Cylinders"
		<< "\n PROGRAM OBJECTIVE: The objective of this program"
		<< "\n is to input the dimensions for a cylinder of metal"
		<< "\n and output the weight in pounds, type of metal, and"
		<< "\n the dimensions of the cylinder in inches. \n\n";

	//START OF DO WHILE LOOP
	do
	{
		//INSTRUCTIONS FOR INPUT
		cout << "\n INSTRUCTIONS:"
			<< "\n Please enter the type of metal by its 2-character"
			<< "\n chemical name. Don't forget to use a capital letter"
			<< "\n for the first letter and lower case for the"
			<< "\n last letter of the chemical name. Also enter the"
			<< "\n length and diameter of your cylinder in inches."
			<< "\n\n Au = GOLD"
			<< "\n Ag = SILVER"
			<< "\n Al = ALUMINUM"
			<< "\n Pb = LEAD";

		//GET USER INPUT FOR METAL
		cout << "\n\n Enter chemical name here: ";
		getline(cin, metal);

		//IF, IF ELSE, ELSE TO DECIDE METAL DENSITY
		if (metal == "Au")
		{
			density = GOLD_DENSITY;
			metal = "Gold";

			cout << " Length: ";
			cin >> length;
			cin.ignore();

			cout << " Diameter: ";
			cin >> diameter;
			cin.ignore();
			cout << "\n\n";
		}
		else if (metal == "Pb")
		{
			density = LEAD_DENSITY;
			metal = "Lead";

			cout << " Length: ";
			cin >> length;
			cin.ignore();

			cout << " Diameter: ";
			cin >> diameter;
			cin.ignore();
			cout << "\n\n";
		}
		else if (metal == "Ag")
		{
			density = SILVER_DENSITY;
			metal = "Silver";

			cout << " Length: ";
			cin >> length;
			cin.ignore();

			cout << " Diameter: ";
			cin >> diameter;
			cin.ignore();
			cout << "\n\n";
		}
		else if (metal == "Al")
		{
			density = ALUMINUM_DENSITY;
			metal = "Aluminum";

			cout << " Length: ";
			cin >> length;
			cin.ignore();

			cout << " Diameter: ";
			cin >> diameter;
			cin.ignore();
			cout << "\n\n";
		}
		else
		{
			//For incorrect metal input
			cout << "\n\n\n METAL NOT RECOGNIZED PLEASE ENTER ONE LISTED ABOVE!\n";
			cout << "\n Would you wish to perform more calculations? yes/no ";
			getline(cin, answer);

			diameter = length = density = 0;
			continue;
		}

		//EQUATIONS
		volume_in3 = length * PI * pow(diameter, 2) / 4;
		weight_lbs = density * volume_in3;

		//OUTPUT
		cout << "\n RESULTS: ";
		cout.setf(ios::fixed | ios::showpoint);
		cout.precision(2);

		cout << "\n Metal: ";
		cout << metal;

		cout << "\n Length: ";
		cout << length;
		cout << " in";

		cout << "\n Diameter: ";
		cout << diameter;
		cout << " in";

		cout << "\n Weight: ";
		cout << weight_lbs;
		cout << " lbs";

		//CONDITION VARIABLE 
		cout << "\n\n\n Would you wish to perform more calculations? yes/no";
		getline(cin, answer);

	} while (answer == "yes"); //keep going until not yes

	return 0;
}
