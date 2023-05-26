#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsString.h"
#include "clsUtil.h"
using namespace std;
class clsInputValidate
{

public:
	// tap
	static void Tap( short taps )
	{
		for ( int i = 0; i < taps; i++ )
		{
			cout << "\t" << endl;
		}
	}
	// read String
	static bool IsNumberBetween( int Number , int From , int To )
	{
		if ( Number >= From && Number <= To )
			return true;
		else
			return false;

	}

	static bool IsNumberBetween( double Number , double From , double To )
	{
		if ( Number >= From && Number <= To )
			return true;
		else
			return false;
	}
	static short ReadShortNumber( string ErrorMessage = "Invalid Number, Enter again\n" )
	{
		short Number;
		while ( !( cin >> Number ) )
		{
			cin.clear();
			cin.ignore( numeric_limits<streamsize>::max() , '\n' );
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumber( string ErrorMessage = "Invalid Number, Enter again\n" )
	{
		int Number;
		while ( !( cin >> Number ) )
		{
			cin.clear();
			cin.ignore( numeric_limits<streamsize>::max() , '\n' );
			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadShortNumberBetween( short From , short To , string ErrorMessage = "Number is not within range, Enter again:\n" )
	{
		int Number = ReadShortNumber();

		while ( !IsNumberBetween( Number , From , To ) )
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	static int ReadIntNumberBetween( int From , int To , string ErrorMessage = "Number is not within range, Enter again:\n" )
	{
		int Number = ReadIntNumber();

		while ( !IsNumberBetween( Number , From , To ) )
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadFloatNumber( string ErrorMessage = "Invalid Number, Enter again\n" )
	{
		float Number;
		while ( !( cin >> Number ) )
		{
			cin.clear();
			cin.ignore( numeric_limits<streamsize>::max() , '\n' );
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadFloatNumberBetween( double From , double To , string ErrorMessage = "Number is not within range, Enter again:\n" )
	{
		float Number = ReadFloatNumber();

		while ( !IsNumberBetween( Number , From , To ) )
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static double ReadDblNumber( string ErrorMessage = "Invalid Number, Enter again\n" )
	{
		double Number;
		while ( !( cin >> Number ) )
		{
			cin.clear();
			cin.ignore( numeric_limits<streamsize>::max() , '\n' );
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween( double From , double To , string ErrorMessage = "Number is not within range, Enter again:\n" )
	{
		double Number = ReadDblNumber();

		while ( !IsNumberBetween( Number , From , To ) )
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValideDate( clsDate Date )
	{
		return	clsDate::isValidDate( Date );
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline( cin >> ws , S1 );
		return S1;
	}
	//  is Date Between
	static bool IsDateBetween( clsDate Date , clsDate DateOne , clsDate DateTwo )
	{
		if ( ( clsDate::IsFirstDatefterSecondDate( Date , DateOne ) || clsDate::AreTwoDatesEqual( Date , DateOne ) ) && ( clsDate::IsFirstDateBeforeSecondDate( Date , DateTwo ) || clsDate::AreTwoDatesEqual( Date , DateTwo ) ) )
		{
			return true;
		}
		if ( ( clsDate::IsFirstDatefterSecondDate( Date , DateTwo ) || clsDate::AreTwoDatesEqual( Date , DateTwo ) ) && ( clsDate::IsFirstDateBeforeSecondDate( Date , DateOne ) || clsDate::AreTwoDatesEqual( Date , DateOne ) ) )
		{
			return true;
		}

		return false;
	}
	//  is valid Date
	static bool IsDate( clsDate Date )
	{
		return clsDate::isValidDate( Date );
	}
};
