#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUsers.h"
#include "clsInputValidate.h"

class clsFindUserScreen :protected clsScreen
{

private:
	static void _PrintUser( clsUsers User )
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName();
		cout << "\nLastName    : " << User.LastName();
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email();
		cout << "\nPhone       : " << User.Phone();
		cout << "\nUserName    : " << User.UserName();
		cout << "\nPassword    : " << User.Password();
		cout << "\nPermissions : " << User.Premissions();
		cout << "\n___________________\n";

	}

public:

	static void FindUserScreen()
	{

		_DrawScreenHeader( "\t  Find User Screen" );

		string UserName;
		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate<string>::ReadString();
		while ( !clsUsers::isUserExists( UserName ) )
		{
			cout << "\nUser is not found, choose another one: ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUsers User1 = clsUsers::Find( UserName );

		if ( !User1.isEmpty() )
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser Was not Found :-(\n";
		}

		_PrintUser( User1 );

	}

};

