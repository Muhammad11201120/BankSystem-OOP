#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCuurency.h"
#include"clsInputValidate.h"

class clsFindCurrencyScreen :protected clsScreen
{
private:
	static void _PrintCurrency( clsCurrency Currency )
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.countryName();
		cout << "\nCode       : " << Currency.currencySymbol();
		cout << "\nName       : " << Currency.currencyName();
		cout << "\nRate(1$) = : " << Currency.currencyRate();

		cout << "\n_____________________________\n";

	}
	static void _ShowResults( clsCurrency Currency )
	{
		if ( !Currency.isEmpty() )
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency( Currency );
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}
public:
	static void FindCurrencyScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "FIND CUURENCY SCREEN" );
		short choice = 0;
		cout << "Choose Currency With Contry Name ( 1 ) OR Currency Code ( 2 ) ? : ";
		cin >> choice;
		while ( choice < 1 && choice > 2 )
		{
			cout << "Choose Currency With Contry Name ( 1 ) OR Currency Code ( 2 ) ? : ";
			cin >> choice;
		}

		if ( choice == 1 )
		{
			string country;
			cout << "Enter Country Name ? : ";
			country = clsInputValidate::ReadString();
			clsCurrency currency = clsCurrency::FindByCountry( country );
			_ShowResults( currency );
		}
		else
		{
			string code;
			cout << "Enter Currency Code ? : ";
			code = clsInputValidate::ReadString();
			clsCurrency currency = clsCurrency::FindByCode( code );
			_ShowResults( currency );
		}
	}
};