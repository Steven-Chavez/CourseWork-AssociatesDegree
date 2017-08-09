//Steven Chavez
//schavez256@yahoo.com	
//Functions.h


#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <string>

using namespace std;


void CourseHeader();

void AskForNameAndShape(string &rName, int &rShape);

void AskForPaintInfo(int &rCoats, int &rCovarage, 
					 string &rCeiling);

//Asks for Rectangle dimensions
void AskForDimensions(double *pW, double *pL, double *pH, 
					  int *pPercent);

//Asks for Circular dimensions
void AskForDimensions(double *pR, double *pH, int *pPercent);


#endif