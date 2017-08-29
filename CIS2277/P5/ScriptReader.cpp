// Author: Steven Chavez
// Email: steven@stevenscode.com
// Program: P5 Linked List
// File: ScriptReader.cpp
// Date: 3/24/16 2:00 PM


#include "ScriptReader.h"

using namespace std;

/**
 * CONSTRUCTOR
 *
 * Takes file name as a parameter and then opens file
 * and checks to see if file has been opened.
 **/
ScriptReader::ScriptReader(string file)
{
	in.open(file);
	if(!in)
	{
		cout << "\n\nScriptReader could not find file!\n\n";
	}
}

/**
 * Ignores pound symbol, space, and enter untill it finds 
 * an integer to return.
 **/
int ScriptReader::getNextInt()
{
	bool nextInt = false;
	string trash = "";
	char peek = ' ';
	int num = 0;

	while (nextInt == false)
	{
		peek = in.peek();
		if (peek == '#' || peek == ' ' || peek == '\n')
		{
			getline(in, trash);
		}
		else
		{
			getline(in, trash);
			num = stoi(trash);
			nextInt = true;
		}
	}
	return num;
}

/**
* Ignores pound symbol, space, and enter untill it finds
* an string to return.
**/
string ScriptReader::getNextString()
{
	bool nextInt = false;
	string trash = "";
	string name = "";
	char peek = ' ';

	while (nextInt == false)
	{
		peek = in.peek();
		if (peek == '#' || peek == ' ' || peek == '\n')
		{
			getline(in, trash);
		}
		else
		{
			in >> name;
			nextInt = true;
		}
	}
	return name;
}