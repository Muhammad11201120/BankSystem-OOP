#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class clsUtil
{

public:
	// ENUMS
	enum enRandum
	{
		SmallLetter = 1 ,
		CapitalLetter = 2 ,
		Mix = 3 ,
		Digits = 4
	};
	// Read Positive Numbers
	static int readPositiveNumber( string msg )
	{
		int number;
		do
		{
			cout << msg;
			cin >> number;

		} while ( number < 0 );
		return number;
	}
	// srand Function
	static void Srand()
	{
		srand( ( unsigned ) time( NULL ) );
	}
	// Swaping To Integers
	static void swap( int numberOne , int numberTwo )
	{
		int temp;
		numberOne = temp;
		numberOne = numberTwo;
		numberTwo = temp;
	}
	// Swaping Two Doubels
	static void Swap( double numberOne , double numberTwo )
	{
		double temp;
		numberOne = temp;
		numberOne = numberTwo;
		numberTwo = temp;
	}
	// Swaping Two Strings
	static void Swap( string stringOne , string stringTwo )
	{
		string temp;
		stringOne = temp;
		stringOne = stringTwo;
		stringTwo = temp;
	}
	// Swaping To Chars
	static void swap( char charOne , char charTwo )
	{
		char temp;
		charOne = temp;
		charOne = charTwo;
		charTwo = temp;
	}
	// Decided Random Number
	static int RandomNumber( int from , int to )
	{
		int number = 0;
		return rand() % ( to - from + 1 ) + from;
	}
	// Random Number To 50
	int RandNumbertTo50()
	{

		return rand() % 50;
	}
	// Random Number To 10
	static int RandNumberTo10()
	{
		int range = 0;
		for ( int i = 1; i <= 10; i++ )
		{
			range = rand() % 10;
		}
		return range;
	}
	// Generate Random Capital Letter
	static char GenerateRandomCapitaLetter()
	{
		int randNum = rand() % 26;
		char capLetter = randNum + 65;
		return capLetter;
	}
	// Generate Random Small Letter
	static char GenerateRandomSmallLetter()
	{
		int randNum = rand() % 26;
		char smallLetter = randNum + 97;
		return smallLetter;
	}
	static char GetRandomChar( enRandum charType )
	{
		switch ( charType )
		{
		case enRandum::SmallLetter:
			return char( RandomNumber( 97 , 122 ) );
		case enRandum::CapitalLetter:
			return char( RandomNumber( 65 , 90 ) );
		case enRandum::Digits:
			return char( RandomNumber( 48 , 58 ) );
		case enRandum::Mix:
			short result = RandomNumber( 65 , 122 );
			if ( result < 90 || result > 97 )
			{
				return char( result );
			}
			else
			{
				return char( RandomNumber( 65 , 90 ) );
			}
		}

		return char( RandomNumber( 65 , 122 ) );
	}
	static string GenerateWord( enRandum keyType , short length )
	{
		string word = "";
		for ( short i = 1; i <= length; i++ )
		{
			word = word + GetRandomChar( keyType );
		}
		return word;
	}
	static string GenerateKey( enRandum keyType )
	{
		string word = "";
		word = GenerateWord( keyType , 4 ) + "-";
		word += GenerateWord( keyType , 4 ) + "-";
		word += GenerateWord( keyType , 4 ) + "-";
		word += GenerateWord( keyType , 4 );
		return word;
	}
	static void GenerateKeys( int numberOfKeys , enRandum keyType )
	{
		for ( int i = 1; i <= numberOfKeys; i++ )
		{
			cout << "Key [" << i << "] : " << GenerateKey( keyType ) << endl;
		}
	}
	static void GeneratArrayOfKeys( string arr[] , int indexes , enRandum keyType )
	{
		for ( int i = 0; i < indexes; i++ )
		{
			arr[ i ] = GenerateKey( keyType );
		}
	}
	static short FindNumberInArray( int arr[] , int indexes , int numberToSearchfor )
	{
		for ( int i = 0; i < indexes; i++ )
		{
			if ( arr[ i ] == numberToSearchfor )
			{
				return i;
			}
		}
		return -1;
	}
	bool IsInArray( int numberToCheck , int arr[] , int indexes )
	{
		return FindNumberInArray( arr , indexes , numberToCheck ) != -1;
	}
	static string IncriptionStr( string& str , int incriptionKey )
	{
		for ( int i = 0; i <= str.length(); i++ )
		{
			str[ i ] = char( ( int ) str[ i ] + incriptionKey );
		}
		return str;
	}
	static string DecriptionStr( string& str , int incriptionKey )
	{
		for ( int i = 0; i <= str.length(); i++ )
		{
			str[ i ] = char( ( int ) str[ i ] - incriptionKey );
		}
		return str;
	}
	static void PrintArray( int arr[] , int indexes )
	{
		for ( int i = 0; i < indexes; i++ )
		{
			cout << arr[ i ] << " ";
		}
	}
	static void PrintArray( string arr[] , int indexes )
	{
		for ( int i = 0; i < indexes; i++ )
		{
			cout << arr[ i ] << " ";
		}
	}
	static void PrintArray( char arr[] , int indexes )
	{
		for ( int i = 0; i < indexes; i++ )
		{
			cout << arr[ i ] << " ";
		}
	}
	static void PrintArray( double arr[] , int indexes )
	{
		for ( int i = 0; i < indexes; i++ )
		{
			cout << arr[ i ] << " ";
		}
	}
	static void ShuffleArray( int arr[] , int indexes )
	{
		srand( time( NULL ) );
		for ( int i = 0; i < indexes; i++ )
		{
			int randIndex = rand() % indexes;
			int temp = arr[ i ];
			arr[ i ] = arr[ randIndex ];
			arr[ randIndex ] = temp;
		}
	}
	static void ShuffleArray( string arr[] , int indexes )
	{
		srand( time( NULL ) );
		for ( int i = 0; i < indexes; i++ )
		{
			int randIndex = rand() % indexes;
			string temp = arr[ i ];
			arr[ i ] = arr[ randIndex ];
			arr[ randIndex ] = temp;
		}
	}
	static void ShuffleArray( char arr[] , int indexes )
	{
		srand( time( NULL ) );
		for ( int i = 0; i < indexes; i++ )
		{
			int randIndex = rand() % indexes;
			char temp = arr[ i ];
			arr[ i ] = arr[ randIndex ];
			arr[ randIndex ] = temp;
		}
	}
	static string NumberToText( int number )
	{
		if ( number == 0 )
		{
			return "";
		}
		if ( number >= 1 && number <= 19 )
		{
			string arr[] = { "","One","Two","Three",
				"Four","Five","Six","Seven",
				"Eight","Nine","Ten","Eleven","Twelve",
				"Thirteen","Fourteen","Fiveteen","Sixteen",
				"SevenTeen","Eighteen","Nineteen" };

			return arr[ number ] + " ";
		}
		if ( number >= 20 && number <= 99 )
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninty" };
			return arr[ number / 10 ] + " " + NumberToText( number % 10 );
		}
		if ( number >= 100 && number <= 199 )
		{
			return "One Hundred " + NumberToText( number % 100 );
		}
		if ( number >= 200 && number <= 999 )
		{
			return NumberToText( number / 100 ) + "Hundreds " + NumberToText( number % 100 );
		}
		if ( number >= 1000 && number <= 1999 )
		{
			return  "One Thousand " + NumberToText( number % 1000 );
		}
		if ( number >= 2000 && number <= 999999 )
		{
			return NumberToText( number / 1000 ) + "Thousands " + NumberToText( number % 1000 );
		}
		if ( number >= 1000000 && number <= 1999999 )
		{
			return "One Million " + NumberToText( number % 1000000 );
		}
		if ( number >= 2000000 && number <= 999999999 )
		{
			return NumberToText( number / 1000000 ) + "Millions " + NumberToText( number % 1000000 );
		}
		if ( number >= 1000000000 && number <= 1999999999 )
		{
			return "One Billion " + NumberToText( number % 1000000000 );
		}
		else
		{
			return NumberToText( number / 1000000000 ) + "Billions " + NumberToText( number % 1000000000 );
		}
	}
	static string incriptionStr( string str , int incriptionKey = 2 )
	{
		for ( int i = 0; i <= str.length(); i++ )
		{
			str[ i ] = char( ( int ) str[ i ] + incriptionKey );
		}
		return str;
	}
	static string decriptionStr( string str , int incriptionKey = 2 )
	{
		for ( int i = 0; i <= str.length(); i++ )
		{
			str[ i ] = char( ( int ) str[ i ] - incriptionKey );
		}
		return str;
	}
};