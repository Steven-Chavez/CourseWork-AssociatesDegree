//Steven Chavez
//schavez256@yahoo.cnm.edu
//BankAccount.cpp

#include "BankAccount.h"
#include <iostream>
#include <string>

using namespace std;

BankAccount::BankAccount() 
{
	balance = 0.0;
	deposit = 0.0;
	withdrawal = 0.0;
	statusMsg = "Deposit successful.";
}

void BankAccount::SetDeposit(double dep)
{
	
	if(dep > 0.0)
	{
		deposit = dep;
		balance += deposit;
	}
	else
	{
		statusMsg = "Do not enter a zero negative deposit!";
	}
}

void BankAccount::SetWithdrawal(double with)
{
	withdrawal = with;
	if(withdrawal > balance)
	{
		withdrawal = 0;
		statusMsg = "Oops, that would overdraw your account!";
	}
	else
	{
		withdrawal = with;
		balance -= withdrawal;
		statusMsg = "Successful Withdrawal!";
	}

}
