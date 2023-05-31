#pragma once
#include<iostream>
#include"clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsFindClientsScreen :protected clsScreen
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
	static void FindClientScreen()
	{
		system( "cls" );
		if ( !CheckAccessRights( clsUsers::enPremissions::pFindClients ) )
		{
			return;
		}
		_DrawScreenHeader( "FIND CLIENT SCREEN" );
		string accountNumber = "";
		cout << "Enter An Account Number To Show: ";
		accountNumber = clsInputValidate<string>::ReadString();

		while ( !clsBankClient::isClientExists( accountNumber ) )
		{
			cout << "There Is No Account With This Account Number..\nPlease Enter A Valid Account Number: ";
			accountNumber = clsInputValidate<string>::ReadString();
		}
		clsBankClient client = clsBankClient::Find( accountNumber );
		if ( !client.isEmpty() )
		{
			cout << "Client Found.." << endl;
		}
		else
		{
			cout << "Client Was Not Found.." << endl;
		}
		_printClientData( client );
	}


};
