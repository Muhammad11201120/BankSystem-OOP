#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsString.h"

using namespace std;
class clsUsers :public clsPerson
{
private:
	enum enMode
	{
		empty = 0 ,
		updated = 1 ,
		add = 2
	};
	enMode _enMode;
	string _userName;
	string _password;
	int _premissions;
	bool _deleteFlag = false;

	static clsUsers _convertLineToUsertObject( string line , string seperator = "#//#" )
	{
		vector<string> vUsers;
		vUsers = clsString::Split( line , seperator );
		return clsUsers( enMode::updated , vUsers[ 0 ] , vUsers[ 1 ] , vUsers[ 2 ] , vUsers[ 3 ] , vUsers[ 4 ] , vUsers[ 5 ] , stod( vUsers[ 6 ] ) );
	}
	static clsUsers _getEmptyUSerObject()
	{
		return clsUsers( enMode::empty , "" , "" , "" , "" , "" , "" , 0 );
	}
	static vector<clsUsers> _LoadUsersDataFromFile()
	{

		vector<clsUsers> vClients;

		fstream MyFile;
		MyFile.open( "Users.txt" , ios::in ); // read Mode

		if ( MyFile.is_open() )
		{

			string Line;

			while ( getline( MyFile , Line ) )
			{

				clsUsers Client = _convertLineToUsertObject( Line );

				vClients.push_back( Client );
			}

			MyFile.close();
		}

		return vClients;
	}
	static string _ConverUsaerObjectToLine( clsUsers Client , string Seperator = "#//#" )
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName() + Seperator;
		stClientRecord += Client.LastName() + Seperator;
		stClientRecord += Client.Email() + Seperator;
		stClientRecord += Client.Phone() + Seperator;
		stClientRecord += Client.UserName() + Seperator;
		stClientRecord += Client.Password() + Seperator;
		stClientRecord += to_string( Client.Premissions() );

		return stClientRecord;
	}
	static void _SaveUsersDataToFile( vector<clsUsers> vUsers )
	{

		fstream MyFile;
		MyFile.open( "Users.txt" , ios::out ); // overwrite

		string DataLine;

		if ( MyFile.is_open() )
		{

			for ( clsUsers C : vUsers )
			{
				if ( C._deleteFlag == false )
				{
					DataLine = _ConverUsaerObjectToLine( C );
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}
	void _AddDataLineToFile( string dataLine )
	{
		fstream MyFile;
		MyFile.open( "Users.txt" , ios::out | ios::app );

		if ( MyFile.is_open() )
		{

			MyFile << dataLine << endl;

			MyFile.close();
		}
	}
	void _Update()
	{
		vector<clsUsers> vUsers;
		vUsers = _LoadUsersDataFromFile();

		for ( clsUsers& C : vUsers )
		{
			if ( C.UserName() == this->UserName() )
			{
				C = *this;
				break;
			}
		}

		_SaveUsersDataToFile( vUsers );
	}
	void _Add()
	{
		_AddDataLineToFile( _ConverUsaerObjectToLine( *this ) );
	}
public:
	enum enPremissions
	{
		eAll = -1 , pListClients = 1 , pAddNewClint = 2 , pDeleteClient = 4 , pUpdateClients = 8 , pFindClients = 16 , pTransactions = 32 , pManagUsers = 64
	};
	enum enSaveResults
	{
		svFaildEmptyObject = 0 ,
		svSucceed = 1 ,
		svFaildObjectAccountExists = 2
	};
	clsUsers( enMode mode , string firstName , string lastName , string email , string phone , string userName , string password , int premission )
		: clsPerson( firstName , lastName , email , phone )
	{
		this->_enMode = mode;
		this->_userName = userName;
		this->_password = password;
		this->_premissions = premission;
	}
	bool isEmpty()
	{
		return ( _enMode == enMode::empty );
	}
	void setUserName( string userName )
	{
		this->_userName = userName;
	}
	string UserName()
	{
		return this->_userName;
	}

	void setPassword( string password )
	{
		this->_password = password;
	}
	string Password()
	{
		return this->_password;
	}
	void setPremissions( int premmission )
	{
		this->_premissions = premmission;
	}
	int Premissions()
	{
		return this->_premissions;
	}
	static clsUsers Find( string userName )
	{
		fstream MyFile;
		MyFile.open( "Users.txt" , ios::in ); // read Mode

		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline( MyFile , Line ) )
			{
				clsUsers user = _convertLineToUsertObject( Line );
				if ( user.UserName() == userName )
				{
					MyFile.close();
					return user;
				}
			}
			MyFile.close();
		}
		return _getEmptyUSerObject();
	}
	static clsUsers Find( string userName , string password )
	{

		clsUsers user = Find( userName );
		if ( user.Password() == password )
		{
			return user;
		}
		else
		{
			_getEmptyUSerObject();
		}
	}
	static clsUsers GetAddNewUserObject( string userName )
	{
		return clsUsers( enMode::add , "" , "" , "" , "" , userName , "" , 0 );
	}
	static vector<clsUsers> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}
	bool Delete()
	{
		vector<clsUsers> vUsers;
		vUsers = _LoadUsersDataFromFile();
		for ( clsUsers& C : vUsers )
		{
			if ( C.UserName() == this->_userName )
			{
				C._deleteFlag = true;
				break;
			}
		}
		_SaveUsersDataToFile( vUsers );
		*this = _getEmptyUSerObject();
		return true;
	}
	enSaveResults Save()
	{

		switch ( this->_enMode )
		{
		case enMode::empty:
			{

				if ( isEmpty() )
				{
					return enSaveResults::svFaildEmptyObject;
				}
			}

		case enMode::updated:
			{
				_Update();
				return enSaveResults::svSucceed;
			}
		case enMode::add:
			{
				if ( clsUsers::isUserExists( this->_userName ) )
				{
					return enSaveResults::svFaildObjectAccountExists;
				}
				else
				{
					_Add();
					this->_enMode = enMode::updated;
					return enSaveResults::svSucceed;
				}
			}
		}
		return enSaveResults::svFaildEmptyObject;
	}
	static bool isUserExists( string userName )
	{
		clsUsers user = clsUsers::Find( userName );
		return ( !user.isEmpty() );
	}

};