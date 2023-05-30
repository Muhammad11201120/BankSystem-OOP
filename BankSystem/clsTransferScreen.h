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
		while ( !clsBankClient::isClientExists( transferFromAccountNumber ) )
		{
			cout << "Enter Account Number To Transfer From ?: ";
			string transferFromAccountNumber = clsInputValidate::ReadString();
		}
		cout << "Enter Account Number To Transfer To ?: ";
		string transferToAccountNumber = clsInputValidate::ReadString();
		while ( !clsBankClient::isClientExists( transferToAccountNumber ) )
		{
			cout << "Enter Account Number To Transfer To ?: ";
			string transferToAccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient ClientFrom = clsBankClient::Find( transferFromAccountNumber );
		_printClientData( ClientFrom );
		clsBankClient ClientTo = clsBankClient::Find( transferToAccountNumber );
		_printClientData( ClientTo );

		cout << "How Mutch Do You Want To Transfer ?: ";
		double transferAmount = clsInputValidate::ReadDblNumber();

		while ( ClientFrom.Balance() < transferAmount )
		{
			cout << "Account Has No Enough Balance To Transfer " << transferAmount << "$" << endl;
			cout << "How Mutch Do You Want To Transfer ?: ";
			double transferAmount = clsInputValidate::ReadDblNumber();
		}

		char confirm;
		cout << "Are You Sure You Want T Transfer " << transferAmount << "$ From (" << ClientFrom.FullName() << ") To (" << ClientTo.FullName() << ") ? (Y/N): ";
		cin >> confirm;
		if ( confirm != 'Y' && confirm != 'y' )
		{
			cout << "Operation Canceled .." << endl;
			return;
		}
		if ( ClientFrom.TransferMoney( ClientTo , transferAmount ) )
		{
			ClientFrom.TransfersRigester( ClientTo , transferAmount );
			_printClientData( ClientFrom );
			_printClientData( ClientTo );
			ClientFrom.TransfersRigester( ClientTo , transferAmount );
			cout << "Transfer (" << transferAmount << "$) From (" << ClientFrom.FullName() << ") To (" << ClientTo.FullName() << ")" << endl;
			cout << "\n\tTransfer Done Successfully .." << endl;
		}
		else
		{
			cout << "There Was Something Went Wrong .. Operation Canceled.." << endl;
		}
	}
};
