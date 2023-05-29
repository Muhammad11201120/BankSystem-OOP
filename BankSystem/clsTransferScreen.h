#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUsers.h"

class clsTransferScreen :protected clsScreen
{
private:
	static void _printClientData( clsBankClient client )
	{

		cout << "\n\t**** CLINT: (" << client.FullName() << ") ****";
		cout << "\n--------------------------------------------";
		cout << "\nACCOUNT NUMBER |" << left << setw( 10 ) << client.AccountNumber();
		cout << "\n--------------------------------------------";
		cout << "\nPIN CODE NAME  |" << left << setw( 10 ) << client.PinCode();
		cout << "\n--------------------------------------------";
		cout << "\nFIRST NAME     |" << left << setw( 40 ) << client.FirstName();
		cout << "\n--------------------------------------------";
		cout << "\nLAST NAME      |" << left << setw( 40 ) << client.LastName();
		cout << "\n--------------------------------------------";
		cout << "\nFULL NAME      |" << left << setw( 40 ) << client.FullName();
		cout << "\n--------------------------------------------";
		cout << "\nEMAIL          |" << left << setw( 15 ) << client.Email();
		cout << "\n--------------------------------------------";
		cout << "\nPHONE          |" << left << setw( 12 ) << client.Phone();
		cout << "\n--------------------------------------------";
		cout << "\nBALANCE        |" << left << setw( 12 ) << client.Balance() << "$";
		cout << "\n--------------------------------------------\n";
	}
public:
	static void TransferScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "TRANSFER SCREEN" );
		cout << "Enter Account Number To Transfer From ?: ";
		string transferFromAccountNumber = clsInputValidate::ReadString();
		cout << "Enter Account Number To Transfer To ?: ";
		string transferToAccountNumber = clsInputValidate::ReadString();
		cout << "How Mutch Do You Want To Transfer ?: ";
		double transferAmount = clsInputValidate::ReadDblNumber();

		clsBankClient ClientFrom = clsBankClient::Find( transferFromAccountNumber );
		_printClientData( ClientFrom );
		clsBankClient ClientTo = clsBankClient::Find( transferToAccountNumber );
		_printClientData( ClientTo );

		if ( clsBankClient::TransferMoney( ClientFrom , ClientTo , transferAmount ) )
		{
			cout << "Operation Completed Successfully" << endl;
			_printClientData( ClientFrom );
			_printClientData( ClientTo );
		}
		else
		{
			cout << "There Was Something Went Wrong .. Operation Canceled.." << endl;
		}
	}
};
