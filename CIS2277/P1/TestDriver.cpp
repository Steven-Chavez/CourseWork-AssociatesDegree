//Name: Steven Chavez
//Email: schavez256@cnm.edu
//File: Person.cpp

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;


void WhoIsGreaterAlphabeticaly(Person &name1, Person &name2);

int main()
{
	// test 1
	cout << "\n NAME: Steven Chavez" 
		<< "\n PROGRAM TILE:P1: Person Class \n"
		<< " OBJECTIVE: Test and create a person class to the according to the\n"
		<< " specs. If a future date is entered today's date will replace it \n"
		<< " automatically.\n";
	cout << "\n TEST 1: Does the default constructor create\n object as specified?";
	
	
	Person p1;

	cout << "\n\n RESULTS:";
	cout << " " << p1.GetFullDesc();

	// test 2
	cout << "\n\n TEST 2: Does constructor with name and 3 int age\n input create object correctly?"
		<< "\n TESTCASE: Person(\"Steven\", 2, 28, 1990)";

	cout << "\n\n RESULTS:";

	Person p1("Steven Chavez", 2, 28, 1990);
	cout << " " << p1.GetFullDesc();

	// test 3
	cout << "\n\n TEST 3: Does the setName and setBirthday(with name and date)\n create the object correctly?"
		<< "\n TESTCASE: Person(\"Jack\", date) date = \"January 22, 2014\"";

	cout << "\n\n RESULTS:";

	
	Date date(1, 22, 2014, "Birthdate");
	p1 = Person("Jack Smith", date);
	cout << " " << p1.GetFullDesc();

	// test 4
	cout << "\n\n TEST 4: Does the getName, and getNameAge functions return\n the required info in the requested format?";
	cout << "\n\n GetName() should return the name";
	cout << "\n " << p1.GetName();
	cout << "\n\n GetNameAge() should return the name plus the age in years"
		<< "\n " << p1.GetNameAge();

	// test 5
	cout << "\n\n\n TEST 5: Does the getFullDesc return the required info\n and in the requested format?";
	cout << "\n " << p1.GetFullDesc();

	// test 6 
	cout << "\n\n TEST 6: What is the result, if a person is created\n with a birthday of 1/1/2016?";
	
	Date date(1, 1, 2016, "Birthdate");
	p1.SetBirthday(date);
	cout << p1.GetFullDesc();
	
	// test 7
	cout << "\n\n TEST 7: Is Adam Chavez greater than Steven Chavez?";
	Person p1("Adam Chavez", 2, 28, 1990);
	Person p2("Steven Chavez", 2, 28, 1990);
	WhoIsGreaterAlphabeticaly(p1, p2);

	// test 8 
	cout << "\n\n\n TEST 8: Future dates are considered invalid.\n Does the program handle it?";
	cout << "\n TESTCASE: Person(\"Steven Chavez\", 2, 28, 2020)";
	p2.SetBirthday(2, 28, 2020);
	cout << "\n\n RESULT: " << p2.GetFullDesc();

	cout << "\n\n";


	cout << "\n\n LEAP YEAR TEST";
	Person pLeap("Leap Chavez", 2, 29, 2000);
	cout << "\n" << pLeap.GetFullDesc();

	return 0;
}

void WhoIsGreaterAlphabeticaly(Person &name1, Person &name2)
{
	if (name1 > name2)
	{
		cout << "\n " << name1.GetName() << " is greater!";
	}
	else
	{
		cout << "\n " << name2.GetName() << " is greater!";
	}
}