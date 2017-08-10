// Programmer: Steven Chavez
// Email: schavez256@yahoo.com
// File: ArrayAnalyzer.cpp
// Date: ‎June ‎19, ‎2014

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ArrayAnalyzer.h"
#include "P3_TemplateSort.h"

#define FILE_OUT (ss.str())

using namespace std;

ArrayAnalyzer::ArrayAnalyzer()
{
	total = 0;
	average = 0;
	median = 0;
	high = 0;
	low = 0;
	filename = "default";			
	bOpen = true;		
	
	//initialize array
	for(int i = 0; i < SIZE; i++)
	{
		n[i] = 0;
	}
}

/**
 * Overloaded Constructor 
 *
 * Initializes fields and takes in the file name
 * as an argument. If the file is open perform
 * necessary methods.
 **/
ArrayAnalyzer::ArrayAnalyzer(string filein)
{
	filename = filein;
	total = 0;
	average = 0;
	median = 0;
	high = 0;
	low = 0;
	bOpen = true;

	//initialize array
	for(int i = 0; i < SIZE; i++)
	{
		n[i] = 0;
	}

	Read();

	//makes sure file is open before 
	//calling private functions
	if(bOpen)  
	{
		Sort();
		Average();
		Median();
		BuildReport();
	}
}

void ArrayAnalyzer::SetFile(string filein)
{
	filename = filein;
	total = 0;
	average = 0;
	median = 0;
	high = 0;
	low = 0;
	bOpen = true;

	Read();

	//makes sure file is open before 
	//calling private functions
	if(bOpen)  
	{
		Sort();
		Average();
		Median();
		BuildReport();
	}
}

bool ArrayAnalyzer::IsFileOpened()
{
	return bOpen;
}

int ArrayAnalyzer::GetTotal()
{
	return total;
}

string ArrayAnalyzer::GetReport()
{
	return fileInfo;
}

void ArrayAnalyzer::GetHighLow(int &rHigh, int &rLow)
{
	high = rHigh;
	low = rLow;
}

bool ArrayAnalyzer::FindValue(int value, int &howMany)
{
	for(int i = 0; i < total; i++)
	{
		if(value == n[i])
		{
			howMany ++;
		}
	}

	if(howMany == 0)
	{
		return false;
	}

	return true;
}

bool ArrayAnalyzer::WriteSummary(string fileout)
{
	ofstream output;

	//gives the filename the extension
	stringstream ss;
	ss << fileout << ".txt";

	fileout = ss.str();

	output.open(fileout);

	//check to see if file opened
	if(! output)
	{
		return false;
	}

	output << fileInfo;

	output.close();

	return true;

}

//PRIVATE METHODS

/**
 * Read()
 *
 * Opens file using the default or given filename.
 * Sets the bOpen field to true or false depending
 * if the file was able to be opened. If the file 
 * is opened the array is populated with the numbers.
 **/
void ArrayAnalyzer::Read()
{
	ifstream input;

	//open data file
	input.open(filename);

	if(! input)
	{
		bOpen = false;
	}
	else
	{
		bOpen = true;

		total = 0;

		while (!input.eof() && total < 1000)
		{
			input >> n[total];
			total++;
		}
	}

	input.close();
}

void ArrayAnalyzer::Sort()
{
	TemplateSort<int> srt;
	srt.shellSort(n, total);

	high = n[total -1];
	low = n[0];
}

void ArrayAnalyzer::Average()
{
	double avg = 0;
	double add = 0;

	for(int i = 0; i < total; i++)
	{
		add = n[i];
		avg += add;
	}
	average = avg/total;
}

void ArrayAnalyzer::Median()
{
	
	//check for even number
	if( (total) %2 == 0)
	{
		//once divided by two total will be in the mid
		//of the two values needed for the avarage
		median = 0.5 * (n[total/2] + n[total/2 -1]);
	}
	else    //else its odd
	{
		//median is middle value if odd
		median = n[(total /2)];
	}
}

void ArrayAnalyzer::BuildReport()
{
	stringstream ss;

	//write the header
	//input file name, 
	//total, average, median, 
	//high, low
	ss << "P3 ARRAY ANALYZER\n\n"
		<< "File Name: " << filename
		<< "\nTotal: " << total
		<< "\nHigh: " << high
		<< "\nLow: " << low;
	ss.setf(ios::fixed | ios::showpoint);
	ss.precision(2);
	ss	<< "\nAverage: " << average
		<< "\nMedian: " << median;
		
	fileInfo = ss.str();
}