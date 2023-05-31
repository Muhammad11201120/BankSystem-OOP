#pragma once
#include<iostream>
#include <iomanip>
#include"Global.h"
#include"clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader( string Title , string SubTitle = "" )
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t\t  " << Title;
		if ( SubTitle != "" )
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		cout << "\t\t\t\t\tUSER: " << CurrentUser.UserName() << endl;
		cout << "\t\t\t\t\tDATE: " << clsDate::dateToString( clsDate() ) << endl;
		cout << "\t\t\t\t\t______________________________________\n\n";
	}
	static bool CheckAccessRights( clsUsers::enPremissions Permission )
	{

		if ( !CurrentUser.CheckAccessPremission( Permission ) )
		{
			cout << "\t\t\t\t\t__________________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t__________________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}

	}
};
