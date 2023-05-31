#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsString.h"
#include "clsUtil.h"
using namespace std;
template<typename T>
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
	static T  IsNumberBetween( T Number , T From , T To )
	{
		if ( Number >= From && Number <= To )
			return true;
		else
			return false;

	}
	static T ReadNumber( string ErrorMessage = "Invalid Number, Enter again\n" )
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

	static T ReadNumberBetween( T From , T To , string ErrorMessage = "Number is not within range, Enter again:\n" )
	{
		int Number = ReadShortNumber();

		while ( !IsNumberBetween( Number , From , To ) )
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
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
