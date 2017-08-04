//Steven Chavez
//schavez256@yahoo.com
//Functions.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Functions.h"

using namespace std;

void Header()
{
	cout << "NAME: Steven Chavez\n"
		<< "PROGRAM NAME: E1 Most Frequent Char"
		<< "\nPROGRAM OBJECTIVE: The objective is"
		<< "\nto have the user enter a sentence and"
		<< "\nhave the program return to the user"
		<< "\nthe most frequent character and how"
		<< "\nmany times it occurs.\n";

}


void MostFrequentChar(string &rSent, char &rMost, int *pNum)
{
	int strSize = 0;
	int count = 0;
	char ch = ' ';
	char c;
	int n = 0;
	int highValue = 0;

	vector<int> ascii;
	vector<int> asciiNum;
	vector<int> counter;

	strSize = rSent.size();
	

	for(int i = 0; i < strSize; i++)
	{
		c = rSent.at(i);
		ascii.push_back(c);
		
		//cout << "\n" <<ascii.at(i) << "\n";
	}

	//Sorts the vector from small to large
	sort(ascii.begin(), ascii.end());


	//Char counter
	for(unsigned int i = 0; i < ascii.size(); i++)
	{
		asciiNum.push_back(ascii.at(i));
	
		for(unsigned int h = 0; h < ascii.size(); h++)
		{
			if(asciiNum.at(i) == ascii.at(h))
			{
				count++;
			}
		}
		counter.push_back(count);
		count = 0;
	}


	//high value finder
	for(unsigned int i=0; i < counter.size(); i++)
	{
		if(counter.at(n) > counter.at(i))
		{
			highValue = counter.at(n);
		}
		else if(counter.at(n) < counter.at(i))
		{
			n=i;
			highValue = counter.at(n);
		}
	}
	
	//returning back values
	rMost = asciiNum.at(n);
	*pNum = counter.at(n);

}


