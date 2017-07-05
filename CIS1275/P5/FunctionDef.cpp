//Steven Chavez
//schavez256@cnm.edu	
//FunctionDef.cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void FillVectors(vector<string> &rType, vector<int> 
				 &rMinGal, vector<int> &rMaxGal)
{
	//location 0
	rType.push_back("Shebunkin Sprayer");
	rMinGal.push_back(200);
	rMaxGal.push_back(400);

	//location 1
	rType.push_back("Koi Rain Head");
	rMinGal.push_back(300);
	rMaxGal.push_back(500);

	//location 2
	rType.push_back("Squid Ink-Sprayer");
	rMinGal.push_back(400);
	rMaxGal.push_back(1000);

	//location 3
	rType.push_back("Nemo Rain Traveler");
	rMinGal.push_back(900);
	rMaxGal.push_back(5000);

	//location 4
	rType.push_back("Whale Blow-Hole");
	rMinGal.push_back(3000);
	rMaxGal.push_back(10000);
}


void WriteHeader()
{
	cout << "NAME: Steven Chavez\n"
		<< "PROGRAM TITLE: P5 Fish Showers\n"
		<< "PROGRAM OBJECTIVE: The program objective is to find"
		<< "\nout which fish shower works with the users pond.\n\n"
		<< "Please choose the shower type by entering the number\n"
		<< "to the left of the shower type.\n\n";
}


void AskFishShower(vector<string> &rType, int *pIndex)
{

	//Displays shower type and index number
	for(int i=0; i < rType.size(); i++)
	{
		cout << i+1 << "-" << rType.at(i)
			<<endl;
	}

	//get index from user
	cout << "==> ";
	cin >> *pIndex;
	cin.ignore();
	*pIndex-= 1;
}

void CalcPondVol(int *pGal)
{
	//variables local to CalcPondVol
	char pondShape;
	bool boolCalcPondVol = true;
	int length = 0;
	int width = 0; 
	int height = 0;
	int radius = 0;
	int vol = 0;

	//1gal = 231 inCubed
	const int IN3_TO_GAL = 231;
	const double PI = 3.14159265;
	

	cout << "\nIs your pond circular(c) or rectangular(r)?"
		<< " c/r ";
	cin >> pondShape;
	cin.ignore();

	do
	{
		if(pondShape == 'r')
		{
			//rectangle vol= L*W*H
			//directions & input instructions
			cout << "\nPlease enter the dimensions of your"
				<< " pond."
				<< "\n*to the nearest whole number in" 
				<< " inches*";

			//dimension input
			cout << "\nLength: ";
			cin >> length;
			cout << "Width: ";
			cin >> width;
			cout << "Height: ";
			cin >> height;
			cin.ignore();

			//Rectangular pondVol and gal calc
			vol = length*width*height;
			*pGal = vol/IN3_TO_GAL;	

			boolCalcPondVol = false;
		}
		else if (pondShape == 'c')
		{
			//circular(cylinder) vol = PI*pow(r,2)*h

			//directions & input instructions
			cout << "\nPlease enter the dimensions of your"
				<< " pond."
				<< "\n*to the nearest whole number in" 
				<< " inches*";

			//deminsion input
			cout << "\nRadius: ";
			cin >> radius;
			cout << "Height: ";
			cin >> height;
			cin.ignore();

			//circular pondVol and Gal calc
			vol = PI*pow(radius,2)*height;
			*pGal = vol/IN3_TO_GAL;

			boolCalcPondVol = false;
		}
		else
		{
			//if user inputs wrong
			cout << "\nDO NOT RECOGNIZE INPUT!"
				<< "\nPlease try again."
			<< "\nIs your pond circular(c) or rectangular(r)?"
			<< " c/r ";
			cin >> pondShape;
			cin.ignore();
		}
	}while(boolCalcPondVol == true);
}


bool VallidateFishShower(int index, double pondVol,
			vector<int> &rMinGal, vector<int>
			&rMaxGal, vector<int> &rRecommendations)
{
	int i = 0;

	//checks to see if pond vol is w/in 
	//range of FishShowerType
	if(pondVol >= rMinGal.at(index) && pondVol <= rMaxGal.at(index))
	{
		//returning true will call WriteInfo function
		//in Driver.cpp
		return true;
	}
	else
	{
		//runs through vectors to check if there is
		//any fishShowerTypes to recommend
		for(i=0; i < rMinGal.size(); i++)
		{
			if(pondVol >= rMinGal.at(i) && pondVol <= rMaxGal.at(i))
			{
				rRecommendations.push_back(i);
			}
		}

		//returning false will call overloaded 
		//function WriteInfo in Driver.cpp
		return false;
	}
}

void WriteInfo(string showerType, int gallons)
{
	cout<< "\nThe volume of your pond is within range"
		<< " of the\nshower type you picked."
		<< "\n\nShower Type: " << showerType 
		<< "\nPond Volume: " << gallons << " gal"
		<< "\n\n";
}


void WriteInfo(string showerType, vector<string> &rType,
			vector<int> &rRecommendations, int gallons)
{
	
	if(rRecommendations.empty() == true)
	{
		//let user know vol is out of range
		if(gallons < 200)
		{
			cout<< "\nOUT OF RANGE!"
				<< "\nYour pond is to small. We don't have"
				<< " a fish-shower within range."
				<< "\nThe pond has to have more than 200"
				<< " gallons.\nYour pond has " << gallons
				<< " gal.\n\n";
		}
		else if(gallons > 10000)
		{
			cout << "\nOUT OF RANGE!"
				<< "\nYour pond is to big. We don't have"
				<< " a fish-shower within range."
				<< "\nThe pond has to have less than"
				<< " 10,000 gallons.\nYour pond has "
				<< gallons 
				<< " gal.\n\n"; 
		}
	}
	else
	{
		if(rRecommendations.size() >= 2)
		{
			//show recommendations
			cout << "\nThe fish-shower type you picked ("
				<< showerType 
				<< ") will not"
				<< " work\nwith your pond. We have some other"
				<< " fish-shower\ntypes that will work."
				<< "\n\nRecomendations for a " << gallons
				<< " gal pond:";
		
		
			for(int i = 0; i < rRecommendations.size(); ++i)
			{
				cout << "\n";
				cout << i+1 << "-";
				cout << rType.at(rRecommendations.at(i));
			}
			cout << "\n\n";
		}
	}
}
