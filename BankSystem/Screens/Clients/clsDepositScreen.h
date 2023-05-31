#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsDepositScreen :protected clsScreen
{

private:
	static void _printClientData( clsBankClient client )
	{

		cout << "\n\t**** CLINT: (" << client.FullName() << ") ****";
		cout << "\n--------------------------------------------";
		cout << "\nACCOUNT NUMBER|" << left << setw( 10 ) << client.AccountNumber();
		cout << "\n--------------------------------------------";
		cout << "\nPIN CODE NAME |" << left << setw( 10 ) << client.PinCode();
		cout << "\n--------------------------------------------";
		cout << "\nFIRST NAME    |" << left << setw( 40 ) << client.FirstName();
		cout << "\n--------------------------------------------";
		cout << "\nLAST NAME     |" << left << setw( 40 ) << client.LastName();
		cout << "\n--------------------------------------------";
		cout << "\nFULL NAME     |" << left << setw( 40 ) << client.FullName();
		cout << "\n--------------------------------------------";
		cout << "\nEMAIL         |" << left << setw( 15 ) << client.Email();
		cout << "\n--------------------------------------------";
		cout << "\nPHONE         |" << left << setw( 12 ) << client.Phone();
		cout << "\n--------------------------------------------";
		cout << "\nBALANCE       |" << left << setw( 12 ) << client.Balance() << "$";
		cout << "\n--------------------------------------------\n";
	}
public:

	static void DepositScreen()
	{
		system( "cls" );
		_DrawScreenHeader( ( "DEPOSIT SCREEN" ) );
		string accountNumber = "";
		cout << "Enter An Account Number To Deposit To: ";
		accountNumber = clsInputValidate<string>::ReadString();

		while ( !clsBankClient::isClientExists( accountNumber ) )
		{
			cout << "ERROR: Invalid Account Number\n Enter A valid Account Number Please: ";
			accountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient client = clsBankClient::Find( accountNumber );
		_printClientData( client );

		double amount = 0;
		cout << "Enter An Amount To Deposit?: ";
		amount = clsInputValidate<double>::ReadNumber();

		char answer;
		cout << "Are You Sure You Want To Deposit : " << amount << " ?: ( Y | N ) ?";
		cin >> answer;
		if ( answer == 'Y' || answer == 'y' )
		{
			client.Deposit( amount );
			cout << "Operation Completed Successfully.." << endl;
			cout << client.FullName() << " Balance Is: " << client.Balance() << endl;
		}
		else
		{
			cout << "Operation Was Canceled.." << endl;
		}
	}
};

