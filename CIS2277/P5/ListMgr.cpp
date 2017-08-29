// Author: Steven Chavez
// Email: steven@stevenscode.com
// Program: P5 Linked List
// File: ListMgr.cpp
// Date: 3/24/16 2:00 PM

#include "ListMgr.h"

/**
 * CONSTRUCTOR
 * 
 * Instantiate variables and set to default values
 **/
ListMgr::ListMgr()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}


/**
 * Takes person as a perameter and adds that person
 * to the front of the list
 **/
void ListMgr::push_front(Person * p)
{
	PersonNode* pn = new PersonNode();
	pn->setPerson(p);
	if (count == 0)
	{
		first = pn;
		last = pn;
	}
	else
	{
		pn->setNext(first);
		first->setPrev(pn);
		first = pn;
	}

	count++;
}


/**
 * Takes person as a perameter and adds that person
 * to the back of the list
 **/
void ListMgr::push_back(Person * p)
{
	PersonNode* pn = new PersonNode();
	pn->setPerson(p);
	if (count == 0)
	{
		first = pn;
		last = pn;
	}
	else
	{
		last->setNext(pn);
		pn->setPrev(last);
		last = pn;
	}

	count++;
}


/**
 * Deletes the first person in the list and adjusts
 * the first position accordingly
 **/
void ListMgr::pop_front()
{
	PersonNode *temp;
	if (count > 1)
	{
		temp = first;
		first = first->getNext();
		first->setPrev(NULL);
		delete temp;
		count--;
	}
	else if(count == 1)
	{
		delete first;
		count--;
	}
	else
	{
		cout << "\n\nNothing Remove: File is Empty!\n\n";
	}
	
}


/**
 * Deletes the last person in the list and adjusts
 * the last position accordingly
 **/
void ListMgr::pop_back()
{
	PersonNode *temp;
	if (count > 1)
	{
		temp = last;
		last = last->getPrev();
		last->setNext(NULL);
		delete temp;
		count--;
	}
	else if(count == 1)
	{
		delete first;
		count--;
	}
	else
	{
		cout << "\n\nNothing Remove: File is Empty!\n\n";
	}
}


/**
 * Returns first person in the list
 **/
Person * ListMgr::front()
{
	Person *person = first->getPerson();
	return person;
}


/**
 * Returns last person in the list
 **/
Person * ListMgr::back()
{
	Person *person = last->getPerson();
	return person;
}


/** 
 * Returns a bool depending on whether the list is empty or not
 **/
bool ListMgr::empty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/**
 * Removes all persons with names that contain or match the string 
 * that was passed through the parameter. Adjusts the lists accordingly. 
 * Depending on the location of the name deleted.
 **/
void ListMgr::remove(string n)
{
	if (count == 0)
	{
		cout << "Nothing to remove, list is empty.";
	}
	else
	{
		PersonNode *search, *temp;
		int i = 0;
		search = first;

		// for persons to a row
		while(search != nullptr)
		{
			i++;
			if (search->getPerson()->GetName().find(n) != -1)
			{
				if (i == 1)
				{
					pop_front();
					if (count > 1)
					{
						search = first;
					}
					else
					{
						search = nullptr;
					}

					i--;
				}
				else if(i == count)
				{
					pop_back();
					search = nullptr;
					i--;
				}
				else 
				{
					// holder nodes
					PersonNode *prev, *next;
					temp = search;

					// set the prevous and next nodes of search
					// into appropriate holder nodes
					prev = temp->getPrev();
					next = temp->getNext();

					// no connect the prevous and next nodes of
					// search to each other
					prev->setNext(next);
					next->setPrev(prev);
					count--;

					//check next node in list
					search = prev;

					//free unused memory
					delete temp, prev, next;

					i--;
				}
			}
			else
			{
				search = search->getNext();
			}
		}
	}
}


/**
 * Removes a person at the same position as the int
 * passed through the parameter and adjusts list accordingly
 **/
void ListMgr::erase(int pos)
{
	if (count == 0 || pos > count || pos < 1)
	{
		cout << "Nothing to show";
	}
	else
	{
		PersonNode *search, *temp;
		string name = "";
		int i = 0;
		search = first;

		for (int i = 0; i < pos+1; i++)
		{
			if (pos == i + 1)
			{
				if (search == first)
				{
					pop_front();
				}
				else if (search == last)
				{
					pop_back();
				}
				else
				{
					// holder nodes
					PersonNode *prev, *next;
					temp = search;

					// set the prevous and next nodes of search
					// into appropriate holder nodes
					prev = search->getPrev();
					next = search->getNext();

					// no connect the prevous and next nodes of
					// search to each other
					prev->setNext(next);
					next->setPrev(prev);
					count--;

					//free unused memory
					delete temp, prev, next;
				}
			}
			else
			{
				search = search->getNext();
			}
		}
	}
}


/**
 * Clears the entire list of persons
 **/
void ListMgr::clear()
{
	PersonNode *temp;
	temp = first;

	while (temp != nullptr)
	{
		temp = first->getNext();
		delete first;
		first = temp;
	}
	delete temp;
	count = 0;
}


/**
 * Shows all persons in list. Formated to have 3
 * person on each line and position number besides
 * each persons name.
 **/
void ListMgr::show()
{
	if (count == 0)
	{
		cout << "\n\nNothing to show\n\n";
	}
	else
	{
		PersonNode* temp;
		temp = first;
		int i = 1;

		cout << "\n\n";
		// for persons to a row
		while(temp != nullptr)
		{ 
			//Display name
			cout << i << ")";
			cout << temp->getPerson()->GetName();
			
			if (i % 3 == 0)
			{
				cout << "\n";
			}
			else
			{
				cout << "  ";
			}

			i++;
			temp = temp->getNext();
		}
		cout << "\n\n";
	}
}


/**
* Returns a string that shows all persons in the list. 
* Formated to have 3 person on each line and position 
* number besides each persons name.
**/
string ListMgr::showString()
{
	stringstream ss;

	// cout how many in the list
	if (count == 0)
	{
		cout << "\n\nNothing to show\n\n";
	}
	else
	{
		PersonNode* temp;
		temp = first;
		int i = 1;
		
		ss << "\n\n";
		// for persons to a row
		while (temp != nullptr)
		{
			//Display name
			ss << i << ")";
			ss << temp->getPerson()->GetName();

			if (i % 3 == 0)
			{
				ss << "\n";
			}
			else
			{
				ss << "  ";
			}

			i++;
			temp = temp->getNext();
		}
		ss << "\n\n";
	}
	return ss.str();
}


/**
 *	DESTRUCTOR
 * 
 *  calls clear() to clear and free list from memory
 **/
ListMgr::~ListMgr()
{
	clear();
}
