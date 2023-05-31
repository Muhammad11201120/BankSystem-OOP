#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsInputValidate.h"
using namespace std;
class clsUpdateUserScreen :protected clsScreen
{
private:
	static void _printUserData( clsUsers user )
	{

		cout << "\n\t**** CLINT: (" << user.FullName() << ") ****";
		cout << "\n--------------------------------------------";
		cout << "\nUserName      |" << left << setw( 10 ) << user.UserName();
		cout << "\n--------------------------------------------";
		cout << "\nPassword      |" << left << setw( 10 ) << user.Password();
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
		cout << "\nPremissions   |" << left << setw( 12 ) << user.Premissions() << "$";
		cout << "\n--------------------------------------------\n";
	}
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
		cout << "Do You Want To Give This User Access To To See Login Rigester ? : ";
		cin >> answer;
		if ( answer == 'y' || answer == 'Y' )
		{
			premission += clsUsers::enPremissions::pShowLog;
		}
		return premission;
	}
	static clsUsers _readUserInfo( clsUsers& user )
	{
		cout << "Enter User First Name: ";
		user.setFirstName( clsInputValidate<string>::ReadString() );
		cout << "Enter User Last Name: ";
		user.setLastName( clsInputValidate<string>::ReadString() );
		cout << "Enter User Email: ";
		user.setEmail( clsInputValidate<string>::ReadString() );
		cout << "Enter User Phone: ";
		user.setPhone( clsInputValidate<string>::ReadString() );
		cout << "Enter Password: ";
		user.setPassword( clsInputValidate<string>::ReadString() );
		cout << "Enter Permissions: \n" << endl;
		user.setPremissions( ReadUserPremission() );
		return user;
	}
public:
	static void UpdateUserScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "UPDATE USER SCREEN" );
		string userName = "";
		cout << "Enter UserName To Update: ";
		userName = clsInputValidate<string>::ReadString();
		while ( !clsUsers::isUserExists( userName ) )
		{
			cout << "There is No User Available With Entered UserName..\n Please Enter UserName: ";
			userName = clsInputValidate<string>::ReadString();
		}

		clsUsers user = clsUsers::Find( userName );
		_printUserData( user );
		cout << "UPDATE USER INFORMATION" << endl;
		cout << "-----------------------------" << endl;

		_readUserInfo( user );

		clsUsers::enSaveResults saveResult;
		saveResult = user.Save();

		switch ( saveResult )
		{
		case clsUsers::enSaveResults::svSucceed:
			{
				cout << "SUCCESS: User Information Updated Successfully.." << endl;
				_printUserData( user );
				break;
			}
		case clsUsers::enSaveResults::svFaildEmptyObject:
			{
				cout << "ERRORO: No User With That UserName..Operation Failed.." << endl;
				break;
			}
		}

	}
};

