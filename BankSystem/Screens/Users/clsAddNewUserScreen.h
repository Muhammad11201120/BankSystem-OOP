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
	static void _printUserData( clsUsers user )
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
		cout << "\nPREMISSIONS   |" << left << setw( 12 ) << user.Premissions();
		cout << "\n--------------------------------------------\n";
	}
public:
	static void addUserScreen()
	{
		system( "cls" );
		if ( !CheckAccessRights( clsUsers::enPremissions::pAddNewClint ) )
		{
			return;
		}
		_DrawScreenHeader( "ADD USER SCREEN" );
		string userName = "";
		cout << "Enter A User Name: ";
		userName = clsInputValidate<string>::ReadString();
		while ( clsUsers::isUserExists( userName ) )
		{
			cout << "There Is An Account Already With This User Name..\nEnter Another User Name..";
			userName = clsInputValidate<string>::ReadString();
		}

		clsUsers newUser = clsUsers::GetAddNewUserObject( userName );

		_readUserInfo( newUser );
		clsUsers::enSaveResults result;
		result = newUser.Save();

		switch ( result )
		{
		case clsUsers::enSaveResults::svFaildEmptyObject:
			cout << "ERRORO: No User With That User Name..Operation Failed.." << endl;
			break;
		case clsUsers::enSaveResults::svFaildObjectAccountExists:
			cout << "ERROR: There Is Already An Ueser With This User NAme.." << endl;
			break;
		case clsUsers::enSaveResults::svSucceed:
			cout << "SUCCESS: User Information Updated Successfully.." << endl;
			_printUserData( newUser );
			break;
		default:
			break;
		}
	}
};