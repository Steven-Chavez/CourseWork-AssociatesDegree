// Name: Steven Chavez
// Email: schavez256@yahoo.com
// File: PersonGen.cpp

#include <string>
#include "PersonGen.h"	
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include <chrono>

PersonGen::PersonGen()
{
	//Initialize age range
	yAge = 4;
	oAge = 86;

	Initialize();
}

PersonGen::PersonGen(int youngAge, int oldAge)
{
	//Initialize age range
	yAge = youngAge;
	oAge = oldAge;

	Initialize();
}

Person PersonGen::GetPerson()
{

	Person p;

	if (!bUseFile)
	{
		NameGen();
		BirthdayGen();
	}
	else
	{
		ReadUseFile();
	}

	p.SetName(name);
	p.SetBirthday(bMonth, bDay, bYear);

	return p;
}

Person* PersonGen::GetNewPerson()
{
	Person *pP = new Person();

	if (!bUseFile)
	{
		NameGen();
		BirthdayGen();
	}
	else
	{
		ReadUseFile();
	}

	pP->SetName(name);
	pP->SetBirthday(bMonth, bDay, bYear);

	return pP;
}

void PersonGen::Initialize()
{

	//Initialize member variables, include bools
	for (int i = 0; i < 3; i++)
	{
		bReadFile[i] = true;
	}
	genderFlag = bUseFile = true;
	bMonth = bDay = bYear = 0;
	lastNameIndex = firstFemaleIndex = firstMaleIndex = 0;
	fileLineCount = lineRead = 0;
	name = useFilename = "";

	//Initialize 3 arrays for name info
	bReadFile[0] = ReadFile("Last.txt", lastName);
	bReadFile[1] = ReadFile("FirstMale.txt", maleName);
	bReadFile[2] = ReadFile("FirstFemale.txt", femaleName);

	engine.seed(seed);
}

void PersonGen::BirthdayGen()
{
	// generate uniform distribution and instantiate needed local variables
	uniform_int_distribution<int> ageDistribution(yAge, oAge);

	Date now;
	bool bLeap;
	int dayOfYear;
	int age;

	age = ageDistribution(engine);
	
	// calculate birthday year
	bYear = now.GetYear() - age;
	

	// determine if leap year
	if (bYear % 4 == 0 && bYear % 100 != 0)
	{
		bLeap = true;
	}
	else if (bYear % 400 == 0)
	{
		bLeap = true;
	}
	else
	{
		bLeap = false;
	}

	if (bLeap)
	{
		uniform_int_distribution<int> dayOfYearDistribution(1, 366);
		dayOfYear = dayOfYearDistribution(engine);
	}
	else
	{
		uniform_int_distribution<int> dayOfYearDistribution(1, 365);
		dayOfYear = dayOfYearDistribution(engine);
	}
	
	CalcDateFromDayOfYear(dayOfYear, bLeap);
}

void PersonGen::NameGen()
{
	// generate uniform distribution and instantiate needed local variables
	uniform_int_distribution<int> distribution(0, 299);
	stringstream ss;

	// obtain index from random engine
	lastNameIndex = distribution(engine);
	firstFemaleIndex = distribution(engine);
	firstMaleIndex = distribution(engine);
	

	// add last name to stringstream
	ss << lastName[lastNameIndex] << ", ";

	// add first name to stringstream depending on genderFlag check
	if (genderFlag)
	{
		ss << femaleName[firstFemaleIndex] << " ";
		genderFlag = false;
	}
	else
	{
		ss << maleName[firstMaleIndex] << " ";
		genderFlag = true;
	}

	// assign stringstream into name
	name = ss.str();
	
}

bool PersonGen::ReadFile(string filename, string vn[])
{
	input.open(filename.c_str());
	if (!input)
	{
		return false;
	}

	for (int i = 0; i < 300; i++)
	{
		getline(input, vn[i]);
	}

	input.close();
	return true;
}

void PersonGen::CalcDateFromDayOfYear(int dayOfYear, bool bLeap)
{
	// create an array of days in month
	int dayCount[12] = { 31,28,31,30,31,30,
		31,31,30,31,30,31 };
	int dayTotal = 0;
	bMonth = bDay = 0;
	bool stopLoop = false;
	int index = 0;

	// if leap year make the days in Feb 29
	if (bLeap)
	{
		dayCount[1] = 29;
	}
		
	// find month and day from day of year
	do 
	{
		// day total so we can do calculations later
		dayTotal += dayCount[index];

		if (dayOfYear <= dayCount[0])
		{
			bMonth = index + 1;
			bDay = dayOfYear;
			
			stopLoop = true;
		}
		else if (dayCount[index] < dayOfYear && dayOfYear <= (dayTotal + dayCount[index +1]))
		{
			bMonth = index +2;

			bDay = dayOfYear - dayTotal;

			stopLoop = true;
		}

		index++;
	} while (stopLoop == false);
}

bool PersonGen::IsTextFileRead()
{
	if (!bReadFile[0] || !bReadFile[1] || !bReadFile[2])
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool PersonGen::CreateFile(string filename, int numPersons)
{
	// instantiate ofstream variable
	ofstream output;

	// open and check to see if output opened
	output.open(filename);
	if (!output)
	{
		return false;
	}

	// write number of persons in first line
	output << numPersons << "\n";

	// randomly generate the given number of person to the file
	for (int i = 0; i < numPersons; i++)
	{
		

		NameGen();
		BirthdayGen();

		output << name << "| " << bMonth << " | " << bDay << " | " << bYear;

		if (i != (numPersons - 1))
		{
			output << "\n";
		}
	}

	output.close();
	return true;
}

bool PersonGen::UseFile(string filename)
{
	useFilename = "";
	useFilename = filename;

	// open and check to see if input opened
	input.open(useFilename.c_str());
	if (!input)
	{
		bUseFile = false;
		input.close();
		return false;
	}
	else
	{
		bUseFile = true;
		
	}
	input.close();
	return true;
}

void PersonGen::ReadUseFile()
{
	//initialize local variables
	string lineCount, trash;
	string month, day, year;
	string lastName, firstName;
	char c;

	

	input.open(useFilename.c_str());

	// get first line for number of persons
	getline(input, lineCount);

	// cast string to int and set into class variable
	fileLineCount = atoi(lineCount.c_str());

	// generate random persons if all lines are read
	if (lineRead == fileLineCount || !input)
	{
		NameGen();
		BirthdayGen();
	}
	else
	{
		// loop to desired line and trash unwanted data
		for (int i = 0; i < fileLineCount; i++)
		{
			if (lineRead == i)
			{
				/*getline(input, name, '|');
				getline(input, month, '|');
				getline(input, day, '|');
				getline(input, year);*/

				input >> lastName >> firstName >> c >> month >> c
					>> day >> c >> year;

				name = lastName + " " + firstName;
				bMonth = atoi(month.c_str());
				bDay = atoi(day.c_str());
				bYear = atoi(year.c_str());
			}
			else
			{
				getline(input, trash);
			}
		}
		lineRead++;
	}
	input.close();
}