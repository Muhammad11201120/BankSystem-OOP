#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCuurency.h"
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"

class clsCuurencyScreen :protected clsScreen
{
private:
	enum enCuurencyChoice
	{
		LIST_CURRENCIES = 1 ,
		FIND_CURRENCY = 2 ,
		UPDATE_RATE = 3 ,
		CURRENCY_CALCULATOR = 4 ,
		MAIN_MENUE = 5
	};
	static short _ReadUserInput()
	{
		int choice = 0;
		cout << setw( 37 ) << left << "" << "Enter your choice: ";
		choice = clsInputValidate::ReadShortNumberBetween( 1 , 5 , "Invalid choice, please try again: " );
		return choice;
	}
	static void _ShowCuurenciesList()
	{
		clsCurrenciesListScreen::CurrenciesListScreen();
	}
	static void _FindCurrency()
	{
		cout << "Find Currency Will Bw Here.." << endl;
	}
	static void _UpdateRate()
	{
		cout << "Update Rate Will Bw Here.." << endl;
	}
	static void _CurrencyCalculator()
	{
		cout << "Currency Calculator Will Bw Here.." << endl;
	}
	static void _CurrencyMenueScreen()
	{
		system( "pause" );
		system( "cls" );
		CurrencyScreen();
	}
	static void _PerformCurrencyExchange( enCuurencyChoice choice )
	{
		switch ( choice )
		{
		case clsCuurencyScreen::LIST_CURRENCIES:
			_ShowCuurenciesList();
			_CurrencyMenueScreen();
			break;
		case clsCuurencyScreen::FIND_CURRENCY:
			_FindCurrency();
			_CurrencyMenueScreen();
			break;
		case clsCuurencyScreen::UPDATE_RATE:
			_UpdateRate();
			_CurrencyMenueScreen();
			break;
		case clsCuurencyScreen::CURRENCY_CALCULATOR:
			_CurrencyCalculator();
			_CurrencyMenueScreen();
			break;
		case clsCuurencyScreen::MAIN_MENUE:
			//Do Nothing
			break;
		}
	}
public:
	static void CurrencyScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "CUURENCY SCREEN" );
		cout << setw( 37 ) << left << "" << "===========================================\n";
		cout << setw( 37 ) << left << "" << "\t\t Currency Menue\n";
		cout << setw( 37 ) << left << "" << "===========================================\n";
		cout << setw( 37 ) << left << "" << "\t[1] List Currencies.\n";
		cout << setw( 37 ) << left << "" << "\t[2] Find Currency.\n";
		cout << setw( 37 ) << left << "" << "\t[3] Update Rate.\n";
		cout << setw( 37 ) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw( 37 ) << left << "" << "\t[5] Main Menue.\n";
		cout << setw( 37 ) << left << "" << "===========================================\n";

		short choice = 0;
		cout << setw( 37 ) << left << "" << "Enter your Operation: ";
		choice = clsInputValidate::ReadShortNumberBetween( 1 , 5 );
		_PerformCurrencyExchange( ( enCuurencyChoice ) choice );
	}
};