#pragma once
#include<iostream>
#include"clsScreen.h"
#include"Global.h"
class clsLogRigesterScreen :protected clsScreen
{
private:
	static void _PrintLogRigesterLine( clsUsers::stLogRigester LogRigeser )
	{

		cout << setw( 8 ) << left << "" << "| " << setw( 35 ) << left << LogRigeser.DateTime;
		cout << "| " << setw( 20 ) << left << LogRigeser.UserName;
		cout << "| " << setw( 20 ) << left << LogRigeser.FullName;
		cout << "| " << setw( 20 ) << left << LogRigeser.Password;
		cout << "| " << setw( 10 ) << left << LogRigeser.Premissions;
	}
public:
	static void LogRigesterScreen()
	{
		system( "cls" );
		if ( !CheckAccessRights( clsUsers::enPremissions::pShowLog ) )
		{
			return;
		}
		vector <clsUsers::stLogRigester> vUsers = clsUsers::GetLogRigesterList();
		string Title = "LOGIN RIGESTER SCREEN";
		string SubTitle = "\t    (" + to_string( vUsers.size() ) + ") User(s).";

		_DrawScreenHeader( Title , SubTitle );


		cout << setw( 8 ) << left << "" << "\n\t__________________________________________________________________________";
		cout << "________________________________________________\n" << endl;

		cout << setw( 8 ) << left << "" << "| " << left << setw( 35 ) << "Date/Time";
		cout << "| " << left << setw( 20 ) << "UserName";
		cout << "| " << left << setw( 20 ) << "Full Name";
		cout << "| " << left << setw( 20 ) << "Password";
		cout << "| " << left << setw( 10 ) << "Premissions";
		cout << setw( 8 ) << left << "" << "\n\t__________________________________________________________________________";
		cout << "________________________________________________\n" << endl;

		if ( vUsers.size() == 0 )
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for ( clsUsers::stLogRigester& user : vUsers )
			{

				_PrintLogRigesterLine( user );
				cout << endl;
			}

		cout << setw( 8 ) << left << "" << "\n\t__________________________________________________________________________";
		cout << "________________________________________________\n" << endl;
	}
};
