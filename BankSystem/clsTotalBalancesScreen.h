#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsTotlalBalncesScreen :protected clsScreen
{
private:
	static void _PrintClientRecordBalanceLine( clsBankClient Client )
	{

		cout << setw( 25 ) << left << "" << "| " << setw( 15 ) << left << Client.AccountNumber();
		cout << "| " << setw( 40 ) << left << Client.FullName();
		cout << "| " << setw( 12 ) << left << Client.Balance();
	}
public:
	static void TotalBalancesScreen()
	{
		system( "cls" );
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
		string title = "TOTAL BALANESE SCREEN";
		string subTitle = "( " + to_string( vClients.size() ) + " )Client/s";
		_DrawScreenHeader( title , subTitle );

		cout << setw( 25 ) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw( 25 ) << left << "" << "| " << left << setw( 15 ) << "Accout Number";
		cout << "| " << left << setw( 40 ) << "Client Name";
		cout << "| " << left << setw( 12 ) << "Balance";
		cout << setw( 25 ) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalance();

		if ( vClients.size() == 0 )
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for ( clsBankClient Client : vClients )
			{
				_PrintClientRecordBalanceLine( Client );
				cout << endl;
			}

		cout << setw( 25 ) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw( 8 ) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
		cout << setw( 8 ) << left << "" << "\t\t\t\t  ( " << clsUtil::NumberToText( TotalBalances ) << ")\n\n";
	}
};

