//Author: Greg Moes
//ATM Bank Project Part 1
//2/24/2021

//preprocessors
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cassert>

using namespace std;

int main()//declare the main
{
	//declare and initialize variables
	int checkingStartBalance = 35, totalBalance, savingsStartBalance = 2500, checkingNewBalance = checkingStartBalance, savingsNewBalance = savingsStartBalance, depositAmount, totalDeposit = 0, i= 1;
	string customerName = "Robert Brown", userName, password, testName = "rbrown", testPassword = "blue123";
	char selection;
	bool exit = false, identity = false;
	
	do//login loop
	{
		cout << "Welcome to Your Bank!" << endl;//prompt user
		cout << "Please login.\nUsername: ";
		cin >> userName;
		if (userName == testName)//username test
		{
			cout << "Please enter your password: ";
			cin >> password;
			if (password == testPassword)//password test
			{
				cout << "Thank you for verifying " << customerName << "." << endl;
				identity = true;//set id flag true
			}//end password if
			else
			{
				i++;//increase invalid counter for password
				cout << "Invalid input! You have 3 attempts. Attempt #" << i << endl;
			}//end password else
		}//end username if
		else
		{
			i++;//increase invalid counter for username
			cout << "Invalid input! You have 3 attempts. Attempt #" << i << endl;
		}//end username else
		if (i == 4)//test for lockout
			assert(0);
	}while (identity == false);//test for id flag
	
	while ((identity == true) && (exit == false))//test id flag and exit flag
	{
		cout << "Welcome " << customerName << ".\nPlease select checking (C), savings (S), or exit (E): ";//prompt user again
		cin >> selection;
		switch (toupper(selection))//menu selection
		{
			case 'C': cout << "\nChecking Account\n";//checking account deposit
				cout << "You are making a deposit to your checking account.\nPlease enter the desired deposit amount: ";
				cin >> depositAmount;
				checkingNewBalance += depositAmount;
				totalDeposit += depositAmount;
				cout << "\nYou deposited $" << depositAmount << " into your checking account.\nYour new balance is: $"<< checkingNewBalance << endl << endl;
				break;
			case 'S': cout << "\nSavings Account\n";//savings deposit
				cout << "You are making a deposit to your savings account.\nPlease enter the desired deposit amount: ";
				cin >> depositAmount;
				savingsNewBalance += depositAmount;
				totalDeposit += depositAmount;
				cout << "\nYou deposited $" << depositAmount << " into your savings account.\nYour new balance is: $"<< savingsNewBalance << endl << endl;
				break;
			case 'E': cout << "\nThank you for your business.\nHave a Good Day!\n\n";//exit from menu
				exit = true;
				break;
			default : cout << "Invalid entry!\n";//invalid entry
		}
	}//end while
	
	//display results to customer
	totalBalance = checkingNewBalance + savingsNewBalance;
	cout << setprecision(2) << fixed << showpoint;
	cout << "Thank you " << customerName << ", and here is your statement:";
	cout << "\nStarting Checking Balance: $" << checkingStartBalance << "\nStarting Savings Balance: $" << savingsStartBalance << "\nStarting Total: $" << checkingStartBalance + savingsStartBalance;
	cout << "\n\nTotal Deposit: $" << totalDeposit;
	cout << "\n\nNew Checking Balance: $" << checkingNewBalance << "\nNew Savings Balance: $" << savingsNewBalance << "\nNew Total: $" << totalBalance << endl;

	return 0;
}
