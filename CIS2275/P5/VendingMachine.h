//Authour: Steven Chavez
//Email: steven@stevenscode.com
//File: VendingMachine.h

#ifndef _VENDINGMACHINE_H
#define _VENDINGMACHINE_H

#include <string>
#include "MoneyCtr.h"
#include "Dispenser.h"
#include "Logger.h"

using namespace std;


class VendingMachine
{
private:
	int selection;	//Set by the form
	string dispenseString;	//Sent to the form

	MoneyCtr bank;

	//Initialize array in the vending machine
	//class. 
	Dispenser d[5];
	Logger writer;

	void DispenseItem();

public:
	VendingMachine();
	~VendingMachine();

	void SetCoinsAndSelection(int dol, int qu, int dim,
				int nick, int sel);

	//You can have the same name cuz they are in different
	//class and different scopes
	double GetMoneyInput(){return bank.GetHowMuchInput();}

	string GetDispenserString(){return dispenseString;}

	string ReturnAllMoneyAndExit();

	bool IsFileOpen(){return writer.IsLogOpen();}
};
#endif