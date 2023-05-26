#pragma once
#include<iostream>


using namespace std;
class clsAddNewClient :protected clsScreen
{
private:
	static clsBankClient _readClientInfo( clsBankClient& client )
	{
		cout << "Enter Client First Name: ";
		client.setFirstName( clsInputValidate::ReadString() );
		cout << "Enter Client Last Name: ";
		client.setLastName( clsInputValidate::ReadString() );
		cout << "Enter Client Email: ";
		client.setEmail( clsInputValidate::ReadString() );
		cout << "Enter Client Phone: ";
		client.setPhone( clsInputValidate::ReadString() );
		cout << "Enter Client Pin Code: ";
		client.setPinCode( clsInputValidate::ReadString() );
		cout << "Enter Account Balance: ";
		client.setBalance( clsInputValidate::ReadDblNumber() );

		return client;
	}
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

	static void addClientScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "ADD CLIENT SCREEN" );
		string accountNumber = "";
		cout << "Enter A Client Account Number: ";
		accountNumber = clsInputValidate::ReadString();
		while ( clsBankClient::isClientExists( accountNumber ) )
		{
			cout << "There Is An Account Already With This Account Number..\nEnter Another Account Number..";
			accountNumber = clsInputValidate::ReadString();
		}

		clsBankClient newClient = clsBankClient::GetAddNewClientObject( accountNumber );

		_readClientInfo( newClient );
		clsBankClient::enSaveResults result;
		result = newClient.Save();

		switch ( result )
		{
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "ERRORO: No Client With That Account Number..Operation Failed.." << endl;
			break;
		case clsBankClient::enSaveResults::svFaildObjectAccountExists:
			cout << "ERROR: There Is Already An Account With This Account Number.." << endl;
			break;
		case clsBankClient::enSaveResults::svSucceed:
			cout << "SUCCESS: Client Information Updated Successfully.." << endl;
			_printClientData( newClient );
			break;
		default:
			break;
		}
	}
};

