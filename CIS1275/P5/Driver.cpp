//Steven Chavez
//schavez256@yahoo.com	
//Driver.cpp

#include <iostream>
#include <vector>
#include <string>
#include "Functions.h"

using namespace std;

int main()
{
	//Declare vectors
	vector<string> type;  //shower type
	vector<int> minGal;
	vector<int> maxGal;
	vector<int> recommendation;
	string answer = "no";
	bool boolVFS;
	int index;
	int pGal;

	FillVectors(type, minGal, maxGal);
	WriteHeader();

	do
	{
		AskFishShower(type, &index);
		CalcPondVol (&pGal);
		boolVFS = VallidateFishShower(index, pGal,
			minGal, maxGal, recommendation);
		
		if(boolVFS == true)
		{
			WriteInfo(type.at(index), pGal);
		}
		else if(boolVFS == false)
		{
			WriteInfo(type.at(index), type, 
				recommendation, pGal);
		}

		cout << "Would you like to play again?"
			<< " yes/no ";
		getline(cin, answer);

	}while(answer == "yes");

 cout << "\nGood-bye\n\n";
	return 0;
}