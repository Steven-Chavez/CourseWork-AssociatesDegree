//Authour: Steven Chavez
//Email: steven@stevenscode.com
//File: VendingMachine.cpp

#include "stdafx.h"
#include "VendingMachine.h"
#include <iostream>
#include <string>
#include <sstream>

#define DRINKTOTAL 25

using namespace std;

VendingMachine::VendingMachine()
{
	//start the dispenser
	d[0].SetStock("Orange", 1.50, DRINKTOTAL);
	d[1].SetStock("Apple", 2.00, DRINKTOTAL);
	d[2].SetStock("Pineapple", 1.75, DRINKTOTAL);
	d[3].SetStock("Grape", 1.25, DRINKTOTAL);
	d[4].SetStock("Fruit Punch", 1.00, DRINKTOTAL);

	//start the MoneyCtr Object
	//we need to have an opening string  for the logger
	string firstString = "\nLog File: Vending Machine Co.\n" 
							+ bank.GetBeginFile();

	//start the Logger
	writer.StartLog(firstString);
}

VendingMachine::~VendingMachine()
{
	//use stringstream
	stringstream ss;
	int totSold = 0;
	double gross = 0.0;

	//title "Summary of Bank and Cola Sales"
	ss << "\n\nSummary of Bank and Juice Sales";

	//List each dispenser, how Many sold, and how much paid
	for(int i = 0; i < 5; i++)
	{
		int dif = 0;
		double amtPd; 

		dif = (DRINKTOTAL - d[i].GetStock());
		amtPd = dif * d[i].GetCost();

		ss << "\n" << d[i].GetJuiceName()
			<< "\nSold: " << dif
			<< "\nAmount Paid: $" << amtPd
			<< endl;

		gross += amtPd;
		totSold += dif;

	}
	//Total colas sold Today and Gross Cola Sales
	ss << "\nTotal Drinks Sold: " << totSold
		<< "\nGross Sales: $" << gross;
	

	writer.CloseLog(ss.str());
}

void VendingMachine::SetCoinsAndSelection(int dol,
			int qu, int dim, int nick, int sel)
{
	bank.SetInputMoney(dol, qu, dim, nick);
	selection = sel;

	DispenseItem();
}

string VendingMachine::ReturnAllMoneyAndExit()
{
	stringstream ss;
	
	ss << "Returning All Money " 
		<< bank.GetHowMuchInput();

	return ss.str();
}

void VendingMachine::DispenseItem()
{
	

	int instock;
	instock = d[selection].GetStock();

	if(instock > 0)
	{
		bank.SetJuiceCost(d[selection].GetCost());
		double change = bank.GetChange();
		
		if(change >=0.0)
		{
			//The Vending Machine connects all and communicates
			//witht the other classes and passes the info 
			//from the other classes
			writer.WriteLog(d[selection].GetWriteLog()+
				bank.GetWriteLog());
			
			dispenseString = d[selection].DispenseSoda() +
				bank.GetReturnMoney();
		}
		else
		{
			dispenseString = "Not enough money " 
				+ ReturnAllMoneyAndExit();

		}
	}
	else
	{
		dispenseString = "Out of Stock "
			 + ReturnAllMoneyAndExit();
	}//method ends
}
