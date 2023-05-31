#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCuurency.h"

class clsCurrenciesListScreen :protected clsScreen
{
private:
	static void _PrintCurrencyRecordLine( clsCurrency Currency )
	{
		cout << setw( 8 ) << left << "" << "| " << setw( 30 ) << left << Currency.countryName();
		cout << "| " << setw( 50 ) << left << Currency.currencyName();
		cout << "| " << setw( 15 ) << left << Currency.currencySymbol();
		cout << "| " << setw( 15 ) << left << Currency.currencyRate();
	}
public:
	void static CurrenciesListScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		system( "cls" );
		string Title = "Currencies List Screen";
		string SubTitle = "\t    (" + to_string( vCurrencies.size() ) + ") Currency(s).";
		_DrawScreenHeader( Title , SubTitle );

		cout << setw( 8 ) << left << "" << "\n\t_______________________________________________________";
		cout << "_____________________________________________________________________\n" << endl;

		cout << setw( 8 ) << left << "" << "| " << left << setw( 30 ) << "Country Name";
		cout << "| " << left << setw( 50 ) << "Currency Name";
		cout << "| " << left << setw( 15 ) << "Currency Code";
		cout << "| " << left << setw( 15 ) << "Exchange Rate";
		cout << setw( 8 ) << left << "" << "\n\t_______________________________________________________";
		cout << "_____________________________________________________________________\n" << endl;
		if ( vCurrencies.size() == 0 )
		{
			cout << "\t\t\t\tNo Currencies Available In the System!";
		}
		else
		{
			for ( clsCurrency& currency : vCurrencies )
			{
				_PrintCurrencyRecordLine( currency );
				cout << endl;
			}
		}
		cout << setw( 8 ) << left << "" << "\n\t_______________________________________________________";
		cout << "_____________________________________________________________________\n" << endl;
	}
};
