//Steven Chavez
//schavez256@yahoo.com
//Driver.cpp

#include <string>
#include <iostream>
#include "BankAccount.h"

using namespace std;

void Header();

int main()
{
	//declare variables
	double depositAmt = 0.0;
	double withdrawAmt = 0.0;
	double balanceAmt = 0.0;
	int choice = 0;

	//Display header
	Header();

	BankAccount bank;

	do
	{
		cout<< "\n\n Please select a number: "
			<< "\n 1. Balance Inquiry"
			<< "\n 2. Make a deposit"
			<< "\n 3. Withdraw money"
			<< "\n 4. I'm done with banking.";

		cin>> choice;
		cin.ignore();



		cout.precision(2);
		cout.setf(ios::fixed | ios::showpoint);

		switch(choice)
		{
		case 1:
			cout << "\n Your balance is: $" << bank.GetBalance();
			break;
		case 2:
			cout << "\n\n Enter the amount to deposit: $";
			cin >> depositAmt;
			cin.ignore();

			cout << "\n Your prior balance is: $" <<bank.GetBalance()
				<< "\n ";
			bank.SetDeposit(depositAmt);
			cout << bank.GetStatusMesg();

			if(bank.GetStatusMesg() == "Deposit successful.")
			{
				cout << "\n Your deposited: $" <<depositAmt;
				cout << "\n Your new balance is: $" 
					<<bank.GetBalance();
			}
			break;
		case 3:
			cout << "\n Enter the amount to withdraw: $";
			cin >> withdrawAmt;
			cin.ignore();
			bank.SetWithdrawal(withdrawAmt);
			cout << "\n " << bank.GetStatusMesg();
			if(bank.GetStatusMesg() == "Successful Withdrawal!")
			{
				cout << "\n You withdrew: $" << withdrawAmt;
				cout << "\n Your new balance is: $"
					<<bank.GetBalance();
			}
			break;
		case 4:
			cout <<"\n Thank you for using the C++ Bank!\n\n";
			break;
		default:
			cout << "\n That is not a valid selection. Try again."
				<< "\n\n";
			break;
		}

	}while(choice !=4 );


	return 0;
}

void Header()
{
	cout << "\n NAME: Steven Chavez"
		<< "\n PROJECT NAME: Exercise 2"
		<< "\n OBJECTIVE: The objective is to make a bank class\n"
		<< " that allows you to check your balance, make a"
		<< "\n withdraws, and make deposits.\n";
}