#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCuurency.h"

class clsUpdateCurrencyScreen : public clsScreen
{
private:
	static double _ReadNewRate()
	{
		double newRate = 0;
		cout << setw( 37 ) << left << "" << "Enter new rate: ";
		newRate = clsInputValidate::ReadDblNumber( "\nInvalid rate, please try again: \n" );
		return newRate;
	}
	static void _PrintCurrencyInfo( clsCurrency Currency )
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.countryName();
		cout << "\nCode       : " << Currency.currencySymbol();
		cout << "\nName       : " << Currency.currencyName();
		cout << "\nRate(1$) = : " << Currency.currencyRate();
		cout << "\n_____________________________\n";
	}
public:
	static void UpdateCurrencyScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "UPDATE CURRENCY SCREEN" );

		string currencyCode = "";
		cout << setw( 37 ) << left << "" << "Enter A Currency Code To Update: ";
		currencyCode = clsInputValidate::ReadString();

		while ( !clsCurrency::IsCurrencyExist( currencyCode ) )
		{
			cout << setw( 37 ) << left << "" << "Currency Is Not Found Please Enter Another One:  ";
			currencyCode = clsInputValidate::ReadString();
		}
		clsCurrency currency = clsCurrency::FindByCode( currencyCode );
		_PrintCurrencyInfo( currency );
		char choice;
		cout << setw( 37 ) << left << "" << "Are You Sure You Want To Update This Currency? (Y/N): ";
		cin >> choice;
		if ( choice == 'Y' || choice == 'y' )
		{
			currency.updateCurrencyRate( _ReadNewRate() );
			_PrintCurrencyInfo( currency );
			cout << setw( 37 ) << left << "" << "Currency Updated Successfully!";
		}
		else
		{
			cout << setw( 37 ) << left << "" << "Currency Not Updated!";
		}
	}
};