#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUsers.h"
#include <iomanip>
#include "clsMainMenueScreen.h"
#include "Global.h"
#include"clsLoginScreen.h"
class clsLoginScreen :protected clsScreen
{

private:

	static  bool _Login()
	{
		bool LoginFaild = false;
		short failedLoginCount = 0;
		string Username , Password;
		do
		{

			if ( LoginFaild )
			{
				failedLoginCount++;

				cout << "\nInvlaid Username/Password!";
				cout << "\nYou have " << ( 3 - failedLoginCount )
					<< " Trial(s) to login.\n\n";
			}

			if ( failedLoginCount == 3 )
			{
				cout << "\nYour are Locked after 3 faild trails \n\n";
				return false;
			}

			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUsers::Find( Username , Password );

			LoginFaild = CurrentUser.isEmpty();

		} while ( LoginFaild );
		CurrentUser.LogRigester();
		clsMainMenueScreen::GetMainMenueScreen();
		return true;
	}

public:


	static bool ShowLoginScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "\t  Login Screen" );
		return _Login();

	}

};
