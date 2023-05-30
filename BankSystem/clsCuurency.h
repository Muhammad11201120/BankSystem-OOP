#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"clsInputValidate.h"
#include<fstream>
#include"clsString.h"
using namespace std;
class clsCurrency
{
private:
	enum enMode
	{
		empty = 1 ,
		updated = 2
	};
	enMode _mode;
	string _countryName;
	string _CurrencySymbol;
	string _CurrencyName;
	double _dblCurrencyRate;

	static clsCurrency _ConvertLinetoCurrencyObject( string Line , string Seperator = "#//#" )
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split( Line , Seperator );

		return clsCurrency( enMode::updated , vCurrencyData[ 0 ] , vCurrencyData[ 1 ] , vCurrencyData[ 2 ] ,
			stod( vCurrencyData[ 3 ] ) );

	}
	static  vector <clsCurrency> _LoadCurrencysDataFromFile()
	{

		vector <clsCurrency> vCurrencys;

		fstream MyFile;
		MyFile.open( "Currency.txt" , ios::in );//read Mode

		if ( MyFile.is_open() )
		{

			string Line;

			while ( getline( MyFile , Line ) )
			{

				clsCurrency Currency = _ConvertLinetoCurrencyObject( Line );

				vCurrencys.push_back( Currency );
			}

			MyFile.close();

		}

		return vCurrencys;

	}
	static string _ConverCurrencyObjectToLine( clsCurrency Currency , string Seperator = "#//#" )
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.countryName() + Seperator;
		stCurrencyRecord += Currency.currencyName() + Seperator;
		stCurrencyRecord += Currency.currencySymbol() + Seperator;
		stCurrencyRecord += to_string( Currency.currencyRate() );

		return stCurrencyRecord;

	}

	static void _SaveCurrencyDataToFile( vector <clsCurrency> vCurrencys )
	{

		fstream MyFile;
		MyFile.open( "Currency.txt" , ios::out );//overwrite

		string DataLine;

		if ( MyFile.is_open() )
		{

			for ( clsCurrency C : vCurrencys )
			{
				DataLine = _ConverCurrencyObjectToLine( C );
				MyFile << DataLine << endl;
			}

			MyFile.close();

		}

	}
	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();

		for ( clsCurrency& C : _vCurrencys )
		{
			if ( C.currencySymbol() == currencySymbol() )
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile( _vCurrencys );

	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency( enMode::empty , "" , "" , "" , 0 );
	}

public:
	clsCurrency( enMode mode , string countryName , string currencySymbol , string currencyName , double currencyRate )
	{
		this->_mode = mode;
		this->_countryName = countryName;
		this->_CurrencyName = currencyName;
		this->_CurrencySymbol = currencySymbol;
		this->_dblCurrencyRate = currencyRate;
	}
	string countryName()
	{
		return this->_countryName;
	}
	string currencyName()
	{
		return this->_CurrencyName;
	}
	string currencySymbol()
	{
		return this->_CurrencySymbol;
	}
	void updateCurrencyRate( double currencyRate )
	{
		this->_dblCurrencyRate = currencyRate;
		_Update();
	}
	double currencyRate()
	{
		return this->_dblCurrencyRate;
	}
	bool isEmpty()
	{
		return( this->_mode == enMode::empty );
	}
	static clsCurrency FindByCode( string CurrencyCode )
	{

		CurrencyCode = clsString::upperCase( CurrencyCode );

		fstream MyFile;
		MyFile.open( "Currency.txt" , ios::in );//read Mode

		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline( MyFile , Line ) )
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject( Line );
				if ( Currency.currencySymbol() == CurrencyCode )
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}
	static   clsCurrency FindByCountry( string Country )
	{
		Country = clsString::upperCase( Country );

		fstream MyFile;
		MyFile.open( "Currency.txt" , ios::in );//read Mode

		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline( MyFile , Line ) )
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject( Line );
				if ( clsString::upperCase( Currency.countryName() ) == Country )
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}
	static bool IsCurrencyExist( string CurrencyCode )
	{
		clsCurrency C1 = clsCurrency::FindByCode( CurrencyCode );
		return ( !C1.isEmpty() );

	}
	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}
};