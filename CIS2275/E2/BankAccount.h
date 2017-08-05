//Steven Chavez
//schavez256@yahoo.com
//BankAccount.h


#ifndef _BANKACCOUNT_H
#define _BANKACCOUNT_H

#include <string>
using namespace std;

class BankAccount
{

private:
	double balance;
	double deposit;
	double withdrawal;
	string statusMsg;

public:
	BankAccount();  //default constructor
	void SetDeposit(double dep);
	void SetWithdrawal(double with);
	double GetBalance(){return balance;}
	string GetStatusMesg(){return statusMsg;}

};

#endif