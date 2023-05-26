#pragma once
#include<iostream>
#include<iomanip>
#include "clsInputValidate.h"
#include"clsScreen.h"
#include"clsClientsList.h"
#include"clsBankClient.h"
#include"clsAddNewClient.h"
#include "clsUpdateClient.h"
#include"clsDeleteClient.h"
#include"clsFindClientsScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
using namespace std;
class clsMainMenueScreen :protected clsScreen
{
private:
	enum enMainMenueOptions
	{
		eListClients = 1 , eAddNewClient = 2 , eDeleteClient = 3 ,
		eUpdateClient = 4 , eFindClient = 5 , eShowTransactionsMenue = 6 ,
		eManageUsers = 7 , eExit = 8
	};

	static void PrintClientRecordBalanceLine( clsBankClient Client )
	{

		cout << "| " << setw( 15 ) << left << Client.AccountNumber();
		cout << "| " << setw( 40 ) << left << Client.FullName();
		cout << "| " << setw( 12 ) << left << Client.Balance();
	}


	static void TotalBalance()
	{
		vector<clsBankClient> vClients;
		vClients = clsBankClient::GetClientsList();

		cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n"
			<< endl;

		cout << "| " << left << setw( 15 ) << "Accout Number";
		cout << "| " << left << setw( 40 ) << "Client Name";
		cout << "| " << left << setw( 12 ) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n"
			<< endl;

		double totalBalances = clsBankClient::GetTotalBalance();
		for ( clsBankClient& C : vClients )
		{
			PrintClientRecordBalanceLine( C );
			cout << endl;
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n"
			<< endl;
		cout << "\t\t\t\t\t   Total Balances = " << totalBalances << endl;
		cout << "\t\t\t\t   ( " << clsUtil::NumberToText( totalBalances ) << ")\n\n";
	}
	static short _ReadMainMenueOption()
	{
		cout << setw( 40 ) << left << "" << "Choose What You Want To Do From 1 - 8 : ";
		short choose = clsInputValidate::ReadShortNumberBetween( 1 , 8 );
		return choose;
	}
	static void _ShowClientsListScreen()
	{
		clsClientsList::clientsListScreen();
	}
	static void _ShowAddNewClientScreen()
	{
		clsAddNewClient::addClientScreen();
	}
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClient::deleteClientScreen();
	}
	static void _ShowUpdateClientScreen()
	{
		clsUpdateClient::updateClientScreen();
	}
	static void _ShowFindClientScreen()
	{
		clsFindClientsScreen::FindClientScreen();
	}
	static void _ShowTransActionsScreen()
	{
		clsTransaction::TransactionsScreen();
	}
	static void _ShowManageUsersScreen()
	{
		clsManageUsersScreen::ManageUsersScreen();
	}
	static void _BackToMainMenueScreen()
	{
		cout << setw( 37 ) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system( "pause>0" );
		GetMainMenueScreen();
	}
	static void _PerformMainMenueOption( enMainMenueOptions option )
	{
		switch ( option )
		{
		case clsMainMenueScreen::enMainMenueOptions::eListClients:
			_ShowClientsListScreen();
			_BackToMainMenueScreen();
			break;
		case clsMainMenueScreen::enMainMenueOptions::eAddNewClient:
			_ShowAddNewClientScreen();
			_BackToMainMenueScreen();
			break;
		case clsMainMenueScreen::enMainMenueOptions::eDeleteClient:
			_ShowDeleteClientScreen();
			_BackToMainMenueScreen();
			break;
		case clsMainMenueScreen::enMainMenueOptions::eUpdateClient:
			_ShowUpdateClientScreen();
			_BackToMainMenueScreen();
			break;
		case clsMainMenueScreen::enMainMenueOptions::eFindClient:
			_ShowFindClientScreen();
			_BackToMainMenueScreen();
			break;
		case clsMainMenueScreen::enMainMenueOptions::eShowTransactionsMenue:
			_ShowTransActionsScreen();
			_BackToMainMenueScreen();
			break;
		case clsMainMenueScreen::enMainMenueOptions::eManageUsers:
			_ShowManageUsersScreen();
			_BackToMainMenueScreen();
			break;
		case clsMainMenueScreen::enMainMenueOptions::eExit:
			exit;
			break;
		}
	}
public:
	static void GetMainMenueScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "MAIN MENUE SCREEN" );
		cout << setw( 37 ) << left << "" << "===========================================\n";
		cout << setw( 37 ) << left << "" << "\t\t\tMain Menue\n";
		cout << setw( 37 ) << left << "" << "===========================================\n";
		cout << setw( 37 ) << left << "" << "\t[1] Show Client List.\n";
		cout << setw( 37 ) << left << "" << "\t[2] Add New Client.\n";
		cout << setw( 37 ) << left << "" << "\t[3] Delete Client.\n";
		cout << setw( 37 ) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw( 37 ) << left << "" << "\t[5] Find Client.\n";
		cout << setw( 37 ) << left << "" << "\t[6] Transactions.\n";
		cout << setw( 37 ) << left << "" << "\t[7] Manage Users.\n";
		cout << setw( 37 ) << left << "" << "\t[8] Logout.\n";
		cout << setw( 37 ) << left << "" << "===========================================\n";

		_PerformMainMenueOption( ( enMainMenueOptions ) _ReadMainMenueOption() );
	}

};
