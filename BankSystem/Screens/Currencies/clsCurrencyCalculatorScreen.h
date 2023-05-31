#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCuurency.h"
#include"clsInputValidate.h"

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:
	static void _PrintCurrencyInfo( clsCurrency Currency , string title )
	{
		cout << "\n" << title << ":\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.countryName();
		cout << "\nCode       : " << Currency.currencySymbol();
		cout << "\nName       : " << Currency.currencyName();
		cout << "\nRate(1$) = : " << Currency.currencyRate();
		cout << "\n_____________________________\n";
	}
	static clsCurrency _ReadCurrencyCode()
	{
		string currencyCode = "";
		cout << "Enter Currency Code To Exchange  : ";
		currencyCode = clsInputValidate<string>::ReadString();
		clsCurrency currency = clsCurrency::FindByCode( currencyCode );
		while ( !currency.IsCurrencyExist( currencyCode ) )
		{
			cout << "ERROR: INVALID CURRENCY CODE !! \nEnter Currency Code To Exchange  : ";
			currencyCode = clsInputValidate<string>::ReadString();
		}
		return currency;
	}

public:
	static void CurrencyCalculatorScreen()
	{
		char again = 'n';
		do
		{
			system( "cls" );
			_DrawScreenHeader( "CURRENCY CALCULATOR SCREEN" );

			clsCurrency currensyFrom = _ReadCurrencyCode();
			clsCurrency currencyTo = _ReadCurrencyCode();

			double amount = 0;
			cout << "Enter Amount To Exchange  : ";

			amount = clsInputValidate<double>::ReadNumber();
			double AmountInUsd = currensyFrom.converToUsd( amount );
			_PrintCurrencyInfo( currensyFrom , "Currency From" );

			cout << "Amount	 : " << AmountInUsd << " USD " << currensyFrom.currencySymbol() << "\n";

			if ( currencyTo.currencySymbol() == "USD" )
			{
				return;
			}

			cout << "\nConverting From USD To \n";
			_PrintCurrencyInfo( currencyTo , "Currency To" );
			double AmountcurrencyTwo = currensyFrom.convertToAnotherCurrency( amount , currencyTo );

			cout << amount << " " << currensyFrom.currencySymbol()
				<< " = " << AmountcurrencyTwo << " " << currencyTo.currencySymbol();



			cout << "\nDo You Want To Perform Another Exchange? (Y/N) : ";
			cin >> again;

		} while ( again == 'Y' || again == 'y' );

	}
};