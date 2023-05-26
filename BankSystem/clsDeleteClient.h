#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsDeleteClient :protected clsScreen
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
	static void deleteClientScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "\tDELETE CLIENT SCREEN" );
		string accountNumber = "";
		cout << "Enter An Account Number To Delete: ";
		accountNumber = clsInputValidate::ReadString();

		while ( !clsBankClient::isClientExists( accountNumber ) )
		{
			cout << "There Is No Account With This Account Number..\nPlease Enter A Valid Account Number: ";
			accountNumber = clsInputValidate::ReadString();
		}
		clsBankClient client = clsBankClient::Find( accountNumber );
		_printClientData( client );
		char answer;
		cout << "Are You Sure That You Want To Delete This Client..?" << endl;
		cin >> answer;
		if ( answer == 'Y' || answer == 'y' )
		{
			if ( client.Delete() )
			{
				cout << "Client Account Deleted Successfuly.." << endl;
				_printClientData( client );
			}
			else
			{
				cout << "ERROR: There Is Something Went Wrong..\nThe Account Dosen`t Deleted.." << endl;
			}
		}
	}
};
