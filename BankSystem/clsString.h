#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class clsString
{
	string _value;
	char _letter;

	static bool vowelLetters( char letter )
	{
		letter = tolower( letter );
		return ( ( letter == 'a' ) || ( letter == 'e' ) || ( letter == 'i' ) || ( letter == 'o' ) || ( letter == 'u' ) );
	}

public:
	// constructors
	clsString()
	{
		this->_value = "";
	}
	clsString( string value )
	{
		this->_value = value;
	}
	clsString( string value , char letter )
	{
		this->_value = value;
		this->_letter = letter;
	}
	// setters and getters
	void setValue( string value )
	{
		this->_value = value;
	}
	string getValue()
	{
		return this->_value;
	}
	void setLetter( char letter )
	{
		this->_letter = letter;
	}
	char getLetter()
	{
		return this->_letter;
	}
	// __declspec(property(get = getValue, put = setValue)) string value;
	/// <summary>
	/// string length
	/// </summary>
	/// <param name="text"> length</param>
	/// <returns>return string length</returns>
	static short length( string text )
	{
		return text.length();
	}
	short length()
	{
		return length( this->_value );
	}
	/// <summary>
	/// Lower and Upper
	/// </summary>
	/// <param name="text">text to lower or upper</param>
	/// <returns>lower or upper</returns>
	static string lowerCase( string text )
	{
		for ( int i = 0; i < text.length(); i++ )
		{
			text[ i ] = tolower( text[ i ] );
		}
		return text;
	}
	void lowerCase()
	{
		this->_value = lowerCase( this->_value );
	}
	static string upperCase( string text )
	{
		for ( int i = 0; i < text.length(); i++ )
		{
			text[ i ] = toupper( text[ i ] );
		}
		return text;
	}
	void upperCase()
	{
		this->_value = upperCase( this->_value );
	}
	/// <summary>
	/// Trim String , Trim Left String, Trim Right String
	/// </summary>
	/// <param name="text">text to trim</param>
	/// <returns>text after trim</returns>
	static string trimLeft( string text )
	{
		for ( int i = 0; i < text.length(); i++ )
		{
			if ( text[ i ] == ' ' )
			{
				text[ i ] = '\r';
			}
			else
			{
				break;
			}
		}
		return text;
	}
	void trimLeft()
	{
		this->_value = trimLeft( this->_value );
	}
	static string trimRight( string text )
	{
		for ( int i = text.length() - 1; i >= 0; i-- )
		{
			if ( text[ i ] == ' ' )
			{
				text[ i ] = '\r';
			}
			else
			{
				break;
			}
		}
		return text;
	}
	void trimRight()
	{
		this->_value = trimRight( this->_value );
	}
	static string trim( string text )
	{
		return trimLeft( trimRight( text ) );
	}
	void trim()
	{
		this->_value = trimLeft( trimRight( this->_value ) );
	}

	/// <summary>
	/// Trim Left Spaces
	/// </summary>
	/// <returns>text after trim</returns>
	static string capitalEachWord( string text )
	{

		text[ 0 ] = toupper( text[ 0 ] ); // capitalize first letter in text
		for ( short i = 0; i < text.length(); i++ )
		{
			if ( text[ i ] == ' ' || text[ i ] == '-' || text[ i ] == '_' )
			{
				text[ i + 1 ] = toupper( text[ i + 1 ] );
			}
		}
		return text;
	}
	void capitalEachWord()
	{
		this->_value = capitalEachWord( this->_value );
	}
	/// <summary>
	/// Trim Left Spaces
	/// </summary>
	/// <returns>text after trim</returns>
	static int capitalLettersCount( string text )
	{
		int counter = 0;
		for ( int i = 0; i < text.length(); i++ )
		{
			if ( text[ i ] >= 65 && text[ i ] <= 90 )
			{
				counter++;
			}
		}
		return counter;
	}
	int capitalLettersCount()
	{
		return capitalLettersCount( this->_value );
	}
	static int smallLettersCount( string text )
	{
		int counter = 0;
		for ( int i = 0; i < text.length(); i++ )
		{
			if ( text[ i ] >= 97 && text[ i ] <= 122 )
			{
				counter++;
			}
		}
		return counter;
	}
	int smallLettersCount()
	{
		return smallLettersCount( this->_value );
	}

	/// <summary>
	/// Trim Left Spaces
	/// </summary>
	/// <returns>text after trim</returns>
	static int countLetter( string text , char letter , bool matchCases = true )
	{
		int counter = 0;
		for ( int i = 0; i < text.length(); i++ )
		{
			if ( text[ i ] == letter )
			{
				counter++;
			}
		}
		return counter;
	}
	int countLetter( char letter , bool matchCases = true )
	{
		return countLetter( this->_value , letter );
	}
	static int countNumberOfWordInTheText( string text )
	{
		int counter = 0;
		string space = " ";
		short position = 0;
		string word = "";
		while ( ( position = text.find( space ) ) != string::npos )
		{
			word = text.substr( 0 , position ); // cutting the string from 0 to first space
			if ( word != "" )
			{
				counter++;
			}
			text.erase( 0 , position + space.length() ); // erasing the word and the space to start searching
		}
		if ( text != "" )
		{
			counter++;
		}
		return counter;
	}
	int countNumberOfWordInTheText()
	{
		return countNumberOfWordInTheText( this->_value );
	}

	static int countVowels( string text )
	{
		int counter = 0;
		for ( int i = 0; i < text.length(); i++ )
		{
			if ( vowelLetters( text[ i ] ) )
			{
				counter++;
			}
		}
		return counter;
	}
	int countVowels()
	{
		return countVowels( this->_value );
	}
	static void PrintFirstletter( string Name )
	{
		cout << Name.at( 0 ) << endl;
		for ( int i = 0; i < Name.length(); i++ )
		{
			if ( Name.at( i ) == ' ' )
			{
				cout << Name.at( i + 1 ) << endl;
			}
		}
	}
	void PrintFirstletter()
	{
		PrintFirstletter( this->_value );
	}
	static char invertLetterCase( char text )
	{
		return text = isupper( text ) ? tolower( text ) : toupper( text );
	}
	void invertLetterCase()
	{
		this->_letter = invertLetterCase( this->_letter );
	}
	static string invertAllLetters( string text )
	{
		for ( int i = 0; i < text.length(); i++ )
		{
			text[ i ] = invertLetterCase( text[ i ] );
		}
		return text;
	}
	void invertAllLetters()
	{
		this->_value = invertAllLetters( this->_value );
	}

	static string lowerFirstLetterInEachWord( string text )
	{
		bool isFirst = true;
		for ( int i = 0; i < text.length(); i++ )
		{
			if ( text[ i ] != ' ' && isFirst )
			{
				text[ i ] = tolower( text[ i ] );
			}
			isFirst = text[ i ] == ' ' ? true : false;
		}
		return text;
	}
	void lowerFirstLetterInEachWord()
	{
		this->_value = lowerFirstLetterInEachWord( this->_value );
	}
	static void countEachWordInTheText( string text )
	{
		string space = " ";
		short position = 0;
		string word = "";
		while ( ( position = text.find( space ) ) != string::npos )
		{
			word = text.substr( 0 , position ); // cutting the string from 0 to first space
			if ( word != "" )
			{
				cout << word << endl;
			}
			text.erase( 0 , position + space.length() ); // erasing the word and the space to start searching
		}
		if ( text != "" )
		{
			cout << text << endl; // to print last word
		}
	}
	void countEachWordInTheText()
	{
		countEachWordInTheText( this->_value );
	}
	static void printVowels( string text )
	{
		for ( int i = 0; i < text.length(); i++ )
		{
			if ( vowelLetters( text[ i ] ) )
			{
				cout << text[ i ] << ",    ";
			}
		}
	}
	void printVowels()
	{
		printVowels( this->_value );
	}
	static void printEachStringInText( string text )
	{
		for ( int i = 0; i < text.length(); i++ )
		{
			cout << text[ i ];
			if ( text[ i ] == ' ' )
				cout << endl;
		}
	}
	void printEachStringInText()
	{
		printEachStringInText( this->_value );
	}
	static string removePunc( string text )
	{
		string text2 = "";
		for ( int i = 0; i < text.length(); i++ )
		{
			if ( !ispunct( text[ i ] ) )
			{
				text2 += text[ i ];
			}
		}
		return text2;
	}
	void removePunc()
	{
		this->_value = removePunc( this->_value );
	}
	static string joinString( vector<string> vtext , string seperator = "," )
	{
		string sentence = "";
		for ( string& t : vtext )
		{
			sentence += t + seperator;
		}
		return sentence.substr( 0 , sentence.length() - seperator.length() ); // to cut the last seperator
	}
	static vector<string> seperateString( string& text , string seperator = " " )
	{
		short position = 0;
		string word;
		vector<string> words;
		position = text.find( seperator );

		while ( position != string::npos )
		{
			word = text.substr( 0 , position );
			if ( word != "" )
			{
				words.push_back( word );
			}
			text.erase( 0 , position + seperator.length() );
			position = text.find( seperator );
		}

		if ( text != "" )
		{
			words.push_back( text );
		}
		return words;
	}
	vector<string> seperateString( string seperator = " " )
	{
		return seperateString( this->_value , seperator );
	}
	static string replaceWord( string text , string oldWord , string newWord , bool caseSensitive = true )
	{
		vector<string> vText;
		vText = seperateString( text , " " );

		for ( string& word : vText )
		{
			if ( caseSensitive )
			{
				if ( word == oldWord )
				{
					word = newWord;
				}
			}
			else
			{
				if ( lowerCase( word ) == lowerCase( oldWord ) )
				{
					word = newWord;
				}
			}
		}
		return joinString( vText , " " );
	}
	void replaceWord( string oldWord , string newWord )
	{
		this->_value = replaceWord( this->_value , oldWord , newWord , true );
	}
	static string reverseWords( string text )
	{
		vector<string> vText;
		string text2 = "";
		vText = seperateString( text , " " );
		vector<string>::iterator itr = vText.end();
		while ( itr != vText.begin() )
		{
			--itr;
			text2 += *itr + " ";
		}
		text2 = text2.substr( 0 , text2.length() - 1 );

		return text2;
	}
	void reverseWords()
	{
		this->_value = reverseWords( this->_value );
	}
	static vector<string> Split( string S1 , string Delim )
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ( ( pos = S1.find( Delim ) ) != std::string::npos )
		{
			sWord = S1.substr( 0 , pos ); // store the word   
			// if (sWord != "")
			// {
			vString.push_back( sWord );
			//}

			S1.erase( 0 , pos + Delim.length() );  /* erase() until positon and move to next word. */
		}

		if ( S1 != "" )
		{
			vString.push_back( S1 ); // it adds last word of the string.
		}

		return vString;

	}

	vector<string> Split( string Delim )
	{
		return Split( _value , Delim );
	}
};
