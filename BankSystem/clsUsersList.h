#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsScreen.h"
#include"clsUsers.h"
using namespace std;
class clsUsersList :protected clsScreen
{

private:
	static void PrintUserRecordLine( clsUsers user )
	{

		cout << setw( 8 ) << left << "" << "| " << setw( 15 ) << left << user.UserName();
		cout << "| " << setw( 20 ) << left << user.FullName();
		cout << "| " << setw( 12 ) << left << user.Phone();
		cout << "| " << setw( 20 ) << left << user.Email();
		cout << "| " << setw( 10 ) << left << user.Password();
		cout << "| " << setw( 12 ) << left << user.Premissions();
	}
public:
	static void UsersListScreen()
	{
		system( "cls" );
		vector <clsUsers> vUsers = clsUsers::GetUsersList();
		string Title = "USERS LIST SCREEN";
		string SubTitle = "\t    (" + to_string( vUsers.size() ) + ") User(s).";

		_DrawScreenHeader( Title , SubTitle );


		cout << setw( 8 ) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw( 8 ) << left << "" << "| " << left << setw( 15 ) << "User Number";
		cout << "| " << left << setw( 20 ) << "Full Name";
		cout << "| " << left << setw( 12 ) << "Phone";
		cout << "| " << left << setw( 20 ) << "Email";
		cout << "| " << left << setw( 10 ) << "Password";
		cout << "| " << left << setw( 12 ) << "Premissions";
		cout << setw( 8 ) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if ( vUsers.size() == 0 )
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for ( clsUsers& user : vUsers )
			{

				PrintUserRecordLine( user );
				cout << endl;
			}

		cout << setw( 8 ) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};
