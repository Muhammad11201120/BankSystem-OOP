#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsInputValidate.h"
using namespace std;
class clsDeleteUser :protected clsScreen
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
public:
	static void DeleteUserScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "DELETE USER SCREEN" );
		string userName = "";
		cout << "Enter UserName To Delete: ";
		userName = clsInputValidate<string>::ReadString();
		while ( !clsUsers::isUserExists( userName ) )
		{
			cout << "ERROR: NO USER AVAILABLE WITH ENTERED USERNAME \nEnter UserName To Delete: ";
			userName = clsInputValidate<string>::ReadString();
		}
		clsUsers user = clsUsers::Find( userName );
		_printUserData( user );
		char answer;
		cout << "Are You Sure That You Want To Delete This User..?" << endl;
		cin >> answer;
		if ( answer == 'Y' || answer == 'y' )
		{
			if ( user.Delete() )
			{
				cout << "User Account Deleted Successfuly.." << endl;
				_printUserData( user );
			}
			else
			{
				cout << "ERROR: There Is Something Went Wrong..\nThe User Account Dosen`t Deleted.." << endl;
			}
		}
	}
};
