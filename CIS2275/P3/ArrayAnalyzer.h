// Programmer: Steven Chavez
// Email: schavez256@yahoo.com
// File: ArrayAnalyzer.h
// Date: ‎June ‎19, ‎2014

#ifndef _ARRAYANALYZER_H
#define _ARRAYANALYZER_H

#include <string>
using namespace std;

#define SIZE 1000

class ArrayAnalyzer
{
	private:
		int n[SIZE],total;
		double average, median;
		string filename; //input file
		string fileInfo; //data gathered from input file
		bool bOpen; // true/false depending if file is open
		int high, low; //data's high, low values
		void BuildReport(); //Build's report for summary

		//read the data, if possible and sets the bOK flag, too
		void Read(); 

		//sorts the array, low to high, uses P3_TemplateSort 
		void Sort();

		//calculates avarage
		void Average(); 

		//calculates median
		void Median(); 

	public:
		//initialize class data
		ArrayAnalyzer();

		//overloaded constructor, passed input file
		explicit ArrayAnalyzer(string filein);

		//pass in file that contains the numbers, must be 
		//1000 or less
		void SetFile(string filein);

		//returns true if file opened, false if not
		bool IsFileOpened();

		//returns fileInfo
		string GetReport();	

		//returns total number of values read
		int GetTotal();	

		void GetHighLow(int &rHigh, int &rLow);

		//returns true if found, false if not. howMany is total, 
		//0 if file not found 
		bool FindValue(int value, int &howMany);	
		       
		//writes the header, input file name, total, average, 
		//median, high, low
		bool WriteSummary(string fileout);	
};
#endif