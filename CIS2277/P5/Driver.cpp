// Author: Steven Chavez
// Email: steven@stevenscode.com
// Program: P5 Linked List
// File: Driver.cpp
// Date: 3/24/16 2:00 PM


#include <iostream>
#include "ListMgr.h"
#include "ChavezPersonGen\PersonGen.h"
#include "ScriptReader.h"

using namespace std;

//TODO:  Your program is working fine.  250/250  Your Test file is good  100/100

int main()
{
	// Header
	cout << "NAME: Steven Chavez\n"
		<< "PROGRAM: P5 Linked Lists\n"
		<< "OBJECTIVE: Use and manage a linked list. Allowing\n"
		<< "the user to add or remove objects fromm the list\n"
		<< "by giving them options to choose from\n\n";

	// Variables
	bool finished = false;
	int selection = 0;
	ListMgr *lm = new ListMgr();
	ScriptReader script("P5TestScript.txt");
	PersonGen pg;
	Person *pn = pg.GetNewPerson();

	// Instantiate log and open file
	ofstream log;
	log.open("LogFile.txt");

	/**
	 * Ensure that Usefile is able to open given file.
	 * If not display error message. And if file is opened
	 * continue to collecting info and use switch
	 * statement to process info.
	 **/
	if (!pg.UseFile("P5LinkedListPeopleNov6.txt") && !log)
	{
		cout << "No File Found!\n\n";
	}
	else
	{
		log << "Name: Steven Chavez\n"
			<< "Program: P5 Linked Lists\n\n";

		// Allow loop to continue until finished is set to true. 
		while (finished == false)
		{
			// Get selection from user
			cout << "\nPlease choose choose the number of the action you\n"
				<< "want to perform\n1 - Show List\n2 - Add to front of list\n"
				<< "3 - Add to back of list\n4 - Remove from front\n5 - "
				<< "Remove from back\n6 - Remove selected item\n7 - Return"
				<< " first person in list\n8 - Return last person in list\n"
				<< "9 - Remove by position number\n10 - Clear list\n11 - "
				<< "Total size of list\n12 - Quit program\nEnter Selection => ";
			
			// Acquire next int from script file
			selection = script.getNextInt();

			// Ensure selection is between 1 and 12
			if (selection >=1 && selection <= 12)
			{
				switch (selection)
				{
				case 1:	// Show list
					lm->show();
					log << "\n** 1 - Show list **"
						<< lm->showString();
					break;
				case 2:	// Add to front of list
					pn = pg.GetNewPerson();
					lm->push_front(pn);
					cout << lm->showString();
					log << "\n** 2 - Add to front of list **"
						<< lm->showString();
					break;
				case 3:	// Add to back of list
					pn = pg.GetNewPerson();
					lm->push_back(pn);
					cout << lm->showString();
					log << "\n** 3 - Add to back of list **"
						<< lm->showString();
					break;
				case 4: // Remove from front
					lm->pop_front();
					cout << lm->showString();
					log << "\n** 4 - Remove from front **"
						<< lm->showString();
					break;
				case 5:	// Remove from back
					lm->pop_back();
					cout << lm->showString();
					log << "\n** 5 - Remove from back **"
						<< lm->showString();
					break;
				case 6: // Remove selected item
					cout << lm->showString();
					lm->remove(script.getNextString());
					cout << lm->showString();
					log << "\n** 6 - Remove selected string **"
						<< lm->showString();
					break;
				case 7: // Return first person in list
					pn = lm->front();
					cout << pn->GetName();
					log << "\n** 7 - Return first person in list **"
						<< pn->GetName();
					break;
				case 8: // Return last person in list
					pn = lm->back();
					cout << pn->GetName();
					log << "\n** 8 - Return last person in list **\n"
						<< pn->GetName()
						<< "\n";
					break;
				case 9: // Remove by position number
					cout << lm->showString();
					lm->erase(script.getNextInt());
					cout << lm->showString();
					log << "\n** 9 - Remove by position number **\n"
						<< lm->showString()
						<< "\n";
					break;
				case 10: // Clear list
					lm->clear();
					log << "\n** 10 - Clear list **\nSize: "
						<< lm->size()
						<< "\n";
					break;
				case 11: // Total size of list
					cout << lm->size();
					log << "\n** 11 - Total size of list **"
						<< lm->size();
					break;
				case 12: // Quit Program
					log << "\n\nQuit Program\n";
					finished = true;
					break;
				default: // No valid entrys
					cout << "\n\nPlease select a number from the list\n\n";
					break;
				}
			}
			else {
				cout << "\n\nINCORRECT INPUT! PLEASE TRY AGAIN!\n\n";
			}
		}
	}

	// Delete unused memory
	delete lm, pn;

	// Close your log file
	log.close();

	cout << "\n\nThank you! Good-Bye!\n\n";
	return 0;
}