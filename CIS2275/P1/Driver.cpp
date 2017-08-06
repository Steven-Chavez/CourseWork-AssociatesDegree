//Steven Chavez
//schavez256@yahoo.com
//Driver.cpp

#include <iostream>
#include <string>
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
	int paintCovarage, numCoats, percent, numGal;
	double width = 0.0;
	double height = 0.0;
	double length = 0.0;
	double radius = 0.0;
	double wallArea = 0.0;
	double amountPaint = 0.0;
	double ceilingArea = 0.0;
	double totalSqFt = 0.0;
	bool writeInfo;

	//Displays course header  
	CourseHeader();

	do
	{
		AskForNameAndShape(custName, roomShape);
		AskForPaintInfo(numCoats, paintCovarage, ceiling);

		if(roomShape == 1)
		{
			//Rectangle
			AskForDimensions(&width, &length, &height,
												&percent);

			numGal = HowManyGallons(width, length, height, 
				ceiling, numCoats, paintCovarage, percent, 
				&wallArea, &ceilingArea, &amountPaint,
											&totalSqFt);
			
		}
		else if(roomShape == 2)
		{
			//Circular
			AskForDimensions(&radius, &height, &percent);

			numGal = HowManyGallons(radius, height, ceiling,
				numCoats, paintCovarage, percent, &wallArea, 
				&ceilingArea, &amountPaint, &totalSqFt);
		}

		//Displays info to user
		DisplayToUser(radius, width, length, height, ceiling,
			numCoats, paintCovarage, percent, wallArea,
			ceilingArea, custName, amountPaint, roomShape, 
			numGal, totalSqFt);

		//Writes info to .txt file
		writeInfo = WriteReport(radius, width, length, height,
			ceiling, numCoats, paintCovarage, percent, 
			wallArea, ceilingArea, custName, amountPaint,
			roomShape, numGal, totalSqFt, fileName);

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