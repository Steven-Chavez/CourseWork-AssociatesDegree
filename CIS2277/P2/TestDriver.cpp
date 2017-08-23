//Name: Steven Chavez
//Email: schavez256@cnm.edu
//File: TestDriver.cpp

#include <iostream>
#include <string>
#include "PersonGen.h"

using namespace std;

//TODO:  PersopnGen Class score 191/200, Testing Spec 100/100

int main()
{
	PersonGen pg;
	pg.CreateFile("UseFile.txt", 15);
	Person p;
	Person *pP;

	//###################################################
	// TEST 1: 
	// Run the generator and create Persons (no file use)
	// Does it alternate male and female, and Person 
	// objects have name, age, birthday?
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 1: \n";
	for (int i = 0; i < 6; i++)
	{
		p = pg.GetPerson();
		cout << p.GetFullDesc() << "\n";
	}

	//###################################################
	// TEST 2:
	// Does the GetPerson return a Person object and 
	// GetNewPerson return a pointer to a Person? Do 
	// persons have name, age, birthday?
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 2: \n";

	p = pg.GetPerson();
	pP = pg.GetNewPerson();

	cout << p.GetFullDesc() << "\n"
		<< pP->GetFullDesc() << "\n";

	//###################################################
	// TEST 3:
	// Have the generator use BJTest15.txt. Can it read 
	// it correctly? While testing, create more than 15 
	// names, make sure 16+ are random.
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 3: \n";

	if (!pg.UseFile("BJTest15.txt"))
	{
		cout << "Your file could not be located";
	}
	else
	{
		for (int i = 0; i < 20; i++)
		{
			p = pg.GetPerson();
			cout << p.GetFullDesc() << "\n";
		}
	}


	//###################################################
	// TEST 4:
	// Have the generator write a file with 10 persons. 
	// Does the requested file have the correct number 
	// of people & in correct format? (Only write file.)
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 4: \n";

	if (!pg.CreateFile("TestCase_10Persons.txt", 10))
	{
		cout << "\n File Not Opened!\n";
	}
	else
	{
		cout << "\n File Created!\n";
	}


	//###################################################
	// TEST 5:
	// Have generator use the file of 10 persons you just
	// created. Run a loop that obtains 15 Persons. Are 
	// the first 10 people from the file and then 5 
	// random people are created?
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 5: \n";
	PersonGen pg5;

	if (!pg5.UseFile("TestCase_10Persons.txt"))
	{
		cout << "Your file could not be located";
	}
	else
	{
		for (int i = 0; i < 15; i++)
		{
			p = pg5.GetPerson();
			cout << p.GetFullDesc() << "\n";
		}
	}


	//###################################################
	// TEST 6:
	// Have the generator make a few calls to GetPerson, 
	// then call GetNewPerson, then GetPerson, GetNewPerson. 
	// Are persons unique?
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 6: \n";

	PersonGen pg6;

	p = pg6.GetPerson();
	cout << p.GetFullDesc() << "\n";
	pP = pg6.GetNewPerson();
	cout << pP->GetFullDesc() << "\n";

	p = pg6.GetPerson();
	cout << p.GetFullDesc() << "\n";
	pP = pg6.GetNewPerson();
	cout << pP->GetFullDesc() << "\n";

	p = pg6.GetPerson();
	cout << p.GetFullDesc() << "\n";
	pP = pg6.GetNewPerson();
	cout << pP->GetFullDesc() << "\n";


	//###################################################
	// TEST 7:
	// Tell generator to use a file that doesn’t exist. 
	// Does the generator then go ahead and create random 
	// persons correctly?
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 7: \n";

	PersonGen pg7;

	if (!pg7.UseFile("DoesntExist.txt"))
	{
		cout << "\n File Not Found!\n";
	}

	for (int i = 0; i < 4; i++)
	{
		p = pg7.GetPerson();
		cout << p.GetFullDesc() << "\n";
	}

	//###################################################
	// TEST 8:
	// first create 10 Person using Getperson. Assign to an array
	// Person pArray[10]
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 8: \n";
	PersonGen pg8;
	Person pArray[10];

	for (int i = 0; i < 10; i++)
	{
		pArray[i] = pg8.GetPerson();
		cout << pArray[i].GetFullDesc() << "\n";
	}


	//###################################################
	// TEST 9:
	// create 5 persons using GetPerson and assign into array
	// Person *pArray25 = new Person[5]
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 9: \n";
	PersonGen pg9;
	Person *pArray25 = new Person[5];

	for (int i = 0; i < 5; i++)
	{
		pArray25[i] = pg9.GetPerson();
		cout << pArray25[i].GetFullDesc() << "\n";
	}

	//deallocate space
	delete[] pArray25;


	//###################################################
	// TEST 10:
	// create 10 persons using GetNewPerson. Assign to an array 
	// Person *pArray2[10];
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 10: \n";
	PersonGen pg10;
	Person *pArray2[10];

	for (int i = 0; i < 10; i++)
	{
		pArray2[i] = pg10.GetNewPerson();
		cout << pArray2[i]->GetFullDesc() << "\n";
	}

	//deallocate space
	for (int i = 0; i < 10; i++)
	{
		delete pArray2[i];
	}

	//###################################################
	// TEST 11:
	// create 10 new person for 
	// Person **pArray3 = new Person*[10];
	//###################################################
	cout << "\n###################################################\n"
		<< "TEST 11: \n";
	PersonGen pg11;
	Person **pArray3 = new Person*[10];

	for (int i = 0; i < 10; i++)
	{
		pArray3[i] = pg11.GetNewPerson();
		cout << pArray3[i]->GetFullDesc() << "\n";
	}

	//deallocate space
	for (int i = 0; i < 10; i++)
	{
		delete pArray3[i];
	}

	return 0;
}