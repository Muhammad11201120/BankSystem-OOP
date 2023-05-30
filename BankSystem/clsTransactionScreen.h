#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrowScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
#include"clsCuurencyScreen.h"
#include <iomanip>
using namespace std;
class clsTransaction :protected clsScreen
{
private:
	enum enTransactionsOptionScreen
	{
		eDeposit = 1 ,
		eWithDrow = 2 ,
		eTotallBalance = 3 ,
		eTransfer = 4 ,
		eTransferLog = 5 ,
		eBackToMainMenue = 7
	};


	static short _ReadTransactionsOptions()
	{
		cout << setw( 37 ) << left << "" << "Choose What You Want To Do From 1 To 6 ? : ";
		short choice = clsInputValidate::ReadShortNumberBetween( 1 , 6 , "ERROR: Choose Valid Number Between 1 - 6 ? : " );
		return choice;
	}
	static void _showDepositScreen()
	{
		clsDepositScreen::DepositScreen();
	}
	static void _showWithDrowScreen()
	{
		clsWithdrowScreen::witdrowScreen();
	}
	static void _showTotalBalncesScreen()
	{
		clsTotlalBalncesScreen::TotalBalancesScreen();
	}
	static void _showTransferScreen()
	{
		clsTransferScreen::TransferScreen();
	}
	static void _showTransferLogScreen()
	{
		clsTransferLogScreen::TransferRigesterScreen();
	}
	static void _backToTransacionsScreen()
	{
		system( "pause" );
		system( "cls" );
		TransactionsScreen();
	}
	static void _performTransactionOptions( enTransactionsOptionScreen option )
	{
		switch ( option )
		{
		case clsTransaction::eDeposit:
			_showDepositScreen();
			_backToTransacionsScreen();
			break;
		case clsTransaction::eWithDrow:
			_showWithDrowScreen();
			_backToTransacionsScreen();
			break;
		case clsTransaction::eTotallBalance:
			_showTotalBalncesScreen();
			_backToTransacionsScreen();
			break;
		case clsTransaction::eTransfer:
			_showTransferScreen();
			_backToTransacionsScreen();
			break;
		case clsTransaction::eTransferLog:
			_showTransferLogScreen();
			_backToTransacionsScreen();
			break;
		case clsTransaction::eBackToMainMenue:
			//Do Nothing
			break;
		}

	}
public:
	static void TransactionsScreen()
	{
		system( "cls" );
		if ( !CheckAccessRights( clsUsers::enPremissions::pTransactions ) )
		{
			return;
		}
		_DrawScreenHeader( "TRANSACTIONS SCREEN" );
		cout << setw( 37 ) << left << "" << "===========================================\n";
		cout << setw( 37 ) << left << "" << "\t\t Transactions Menue\n";
		cout << setw( 37 ) << left << "" << "===========================================\n";
		cout << setw( 37 ) << left << "" << "\t[1] Deposit.\n";
		cout << setw( 37 ) << left << "" << "\t[2] Withdraw.\n";
		cout << setw( 37 ) << left << "" << "\t[3] Total Balances.\n";
		cout << setw( 37 ) << left << "" << "\t[4] Transfer.\n";
		cout << setw( 37 ) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw( 37 ) << left << "" << "\t[6] Main Menue.\n";
		cout << setw( 37 ) << left << "" << "===========================================\n";
		_performTransactionOptions( ( enTransactionsOptionScreen ) _ReadTransactionsOptions() );
	}

};
