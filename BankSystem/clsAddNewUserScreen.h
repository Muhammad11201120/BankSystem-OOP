#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUsers.h"
using namespace std;
class clsAddNewUserScreen :protected clsScreen
{
private:
	static int ReadUserPremission()
	{
		int premission = 0;
		char answer;
		cout << "Do You To Give This Full Accsess? : ";
		cin >> answer;
		if ( answer == 'Y' || answer == 'y' )
		{
			return -1;
		}
		cout << "Do You Want To Give This User  Access To Show Clients List ? : ";
		cin >> answer;
		if ( answer == 'y' || answer == 'Y' )
		{
			premission += clsUsers::enPremissions::pListClients;
		}
		cout << "Do You Want To Give This User Access To Add New Client ? : ";
		cin >> answer;
		if ( answer == 'y' || answer == 'Y' )
		{
			premission += clsUsers::enPremissions::pAddNewClint;
		}
		cout << "Do You Want To Give This User Access To Delete Clients ? : ";
		cin >> answer;
		if ( answer == 'y' || answer == 'Y' )
		{
			premission += clsUsers::enPremissions::pDeleteClient;
		}
		cout << "Do You Want To Give This User Access To Update Clients ? : ";
		cin >> answer;
		if ( answer == 'y' || answer == 'Y' )
		{
			premission += clsUsers::enPremissions::pUpdateClients;
		}
		cout << "Do You Want To Give This User Access To Find A Client ? : ";
		cin >> answer;
		if ( answer == 'y' || answer == 'Y' )
		{
			premission += clsUsers::enPremissions::pFindClients;
		}
		cout << "Do You Want To Give This User Access To See Transactions ? : ";
		cin >> answer;
		if ( answer == 'y' || answer == 'Y' )
		{
			premission += clsUsers::enPremissions::pTransactions;
		}
		cout << "Do You Want To Give This User Access To Manage Clients ? : ";
		cin >> answer;
		if ( answer == 'y' || answer == 'Y' )
		{
			premission += clsUsers::enPremissions::pManagUsers;
		}
		return premission;
	}
	static clsUsers _readClientInfo( clsUsers& user )
	{
		cout << "Enter Client First Name: ";
		user.setFirstName( clsInputValidate::ReadString() );
		cout << "Enter Client Last Name: ";
		user.setLastName( clsInputValidate::ReadString() );
		cout << "Enter Client Email: ";
		user.setEmail( clsInputValidate::ReadString() );
		cout << "Enter Client Phone: ";
		user.setPhone( clsInputValidate::ReadString() );
		cout << "Enter Client Pin Code: ";
		user.setUserName( clsInputValidate::ReadString() );
		cout << "Enter Account Balance: ";
		user.setPassword( clsInputValidate::ReadString() );
		user.setPremissions( clsAddNewUserScreen::ReadUserPremission() );
		return user;
	}
	static void _printClientData( clsUsers user )
	{

		cout << "\n\t**** CLINT: (" << user.FullName() << ") ****";
		cout << "\n--------------------------------------------";
		cout << "\nUSER NAME     |" << left << setw( 10 ) << user.UserName();
		cout << "\n--------------------------------------------";
		cout << "\nPASSWORD      |" << left << setw( 10 ) << user.Password();
		cout << "\n--------------------------------------------";
		cout << "\nFIRST NAME    |" << left << setw( 40 ) << user.FirstName();
		cout << "\n--------------------------------------------";
		cout << "\nLAST NAME     |" << left << setw( 40 ) << user.LastName();
		cout << "\n--------------------------------------------";
		cout << "\nFULL NAME     |" << left << setw( 40 ) << user.FullName();
		cout << "\n--------------------------------------------";
		cout << "\nEMAIL         |" << left << setw( 15 ) << user.Email();
		cout << "\n--------------------------------------------";
		cout << "\nPHONE         |" << left << setw( 12 ) << user.Phone();
		cout << "\n--------------------------------------------";
		cout << "\nPREMISSIONS   |" << left << setw( 12 ) << user.Premissions() << "$";
		cout << "\n--------------------------------------------\n";
	}
public:
	static void addUserScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "ADD CLIENT SCREEN" );
		string userName = "";
		cout << "Enter A Client Account Number: ";
		userName = clsInputValidate::ReadString();
		while ( clsUsers::isUserExists( userName ) )
		{
			cout << "There Is An Account Already With This Account Number..\nEnter Another Account Number..";
			userName = clsInputValidate::ReadString();
		}

		clsUsers newUser = clsUsers::GetAddNewUserObject( userName );

		_readClientInfo( newUser );
		clsUsers::enSaveResults result;
		result = newUser.Save();

		switch ( result )
		{
		case clsUsers::enSaveResults::svFaildEmptyObject:
			cout << "ERRORO: No Client With That Account Number..Operation Failed.." << endl;
			break;
		case clsUsers::enSaveResults::svFaildObjectAccountExists:
			cout << "ERROR: There Is Already An Account With This Account Number.." << endl;
			break;
		case clsUsers::enSaveResults::svSucceed:
			cout << "SUCCESS: Client Information Updated Successfully.." << endl;
			_printClientData( newUser );
			break;
		default:
			break;
		}
	}
};