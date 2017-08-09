//Steven Chavez
//schavez256@yahoo.com	
//Driver.cpp

#include <iostream>
#include <string>
#include <sstream>
#include "PaintCalc.h"
#include "Functions.h"

using namespace std;

int main()
{
	//Variables
	string answer = "yes";
	string custName;
	string ceiling;
	string fileName;
	int roomShape;
	int paintCovarage, numCoats, percent;
	double width = 0.0;
	double height = 0.0;
	double length = 0.0;
	double radius = 0.0;
	double wallArea = 0.0;
	double amountPaint = 0.0;
	double ceilingArea = 0.0;
	double totalSqFt = 0.0;
	bool writeInfo = true;
	

	//Course Header
	CourseHeader();

	//Create PaintCalc object
	PaintCalc pCalc;

	do
	{
		AskForNameAndShape(custName, roomShape);
		pCalc.SetType(roomShape); 
		pCalc.SetName(custName);

		AskForPaintInfo(numCoats, paintCovarage, ceiling);
		pCalc.SetPaintInfo(paintCovarage, numCoats, ceiling);

		if(roomShape == 1)
		{
			//Rectangle
			AskForDimensions(&width, &length,
								&height, &percent);

			pCalc.SetRoomDim(length, width, height, percent);
		
			
		}
		else if(roomShape == 2)
		{
			//Circular
			AskForDimensions(&radius, &height, &percent);
			pCalc.SetRoomDim(radius, height, percent);
		}

		cout << pCalc.GetDescription();
		
		fileName = pCalc.GetFilename();
		writeInfo = pCalc.IsFileOk();

		if(writeInfo = true)
		{
			cout << "\nA copy of your info was successfully"
				<< " written to a file!\nThe file name is <" 
				<< fileName << ">"; 
		}
		else if(writeInfo == false)
		{
			cout << "Ending program, Can't find Output file!\n";

			//can't find file so we end the program.
			exit(1);
		}
		
		//stops or continues do-while
		cout << "\n\nWould you like to do more calculations? "
			<< "yes/no  ";
		getline(cin, answer);

	}while(answer == "yes");

	//good-bye message
	cout << "\n\nGood-Bye!!\n";

	return 0;
}