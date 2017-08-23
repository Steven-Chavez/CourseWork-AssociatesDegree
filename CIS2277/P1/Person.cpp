//Name: Steven Chavez
//Email: schavez256@cnm.edu
//File: Person.cpp

#include "Person.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// default constructor
Person::Person()
{
	name = "";
	age = 0;
}

// overloaded constructor
Person::Person(string p, Date d)
{
	name = p;
	bday = d;
	
	CalcAge();
}

// overloaded constructor
Person::Person(string p, int m, int d, int y)
{
	name = p;

	Date date(m, d, y, "Birthdate");
	bday = date;

	CalcAge();
}

// setters
void Person::SetBirthday(Date d)
{
	bday = d;

	CalcAge();
}

void Person::SetBirthday(int m, int d, int y)
{
	Date date(m, d, y, "Birthdate");
	bday = date;
	
	CalcAge();
}

// getters
string Person::GetNameAge()
{
	stringstream ss;
	ss << name << " " << age;
	return ss.str();
}

string Person::GetFullDesc()
{
	stringstream ss;
	ss << "\n"
		<< " Name: " << name << " "
		<< " Age: " << age << "  "
		<< bday.GetFormattedDate() << "\n";

	return ss.str();
}

Date Person::GetBirthDay()
{
	return bday;
}

// overloaded operators
bool Person::operator<(Person p)
{
	if (name < p.name)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Person::operator>(Person p)
{
	if (name > p.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// calculation method for age
void Person::CalcAge() 
{
	Date today;
	Date leapYear;

	// Check for leap year
	if (bday.GetDay() == 29 && bday.GetMonth() == 2)
	{
		if (bday.GetYear() % 4 == 0 && bday.GetDayOfYear() % 100 != 0)
		{
			bday.SetDesc("Birthday (Leap Year Baby): ");
		}
		else if (bday.GetYear() % 400 == 0)
		{

			bday.SetDesc("Birthday (Leap Year Baby)");
		}
		else
		{
			bday = today;
			bday.SetDesc("Invalid Leap Year Date: Date Reset To Current!");
		}
	}

	// make birthday today's date if user enters a future date
	if (bday.GetYear() > today.GetYear())
	{
		bday = today;

		bday.SetDesc("Invalid Date: Future Dates Will Be Set To Today!");
	}
	else if (bday.GetYear() == today.GetYear())
	{
		if (bday.GetDayOfYear() > today.GetDayOfYear())
		{
			bday = today;
			bday.SetDesc("Invalid Date: Future Dates Will Be Set To Today!");
		}
	}

	// if bday day of the year is less or equal 
	// to the current day of the year than we can 
	// subtract the years directly.
	if (bday.GetDayOfYear() < today.GetDayOfYear() ||
		bday.GetDayOfYear() == today.GetDayOfYear())
	{
		age = today.GetYear() - bday.GetYear();
	}
	// if bday day of the year is greater than the 
	// current day of the year than the persons bday
	// has not come to pass so we minus one from the year
	else 
	{
		age = (today.GetYear() - bday.GetYear()) - 1;
	}
}