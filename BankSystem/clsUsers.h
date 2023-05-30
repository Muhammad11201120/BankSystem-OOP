#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsString.h"
#include"Global.h"
#include"clsDate.h"
#include<string>
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
	struct stLogRigester;
	static  stLogRigester _LoadLogRigesterDataFromFile( string line , string seperator )
	{

		stLogRigester LogRigester;

		vector<string> vLogRigester;
		vLogRigester = clsString::Split( line , "#//#" );

		LogRigester.DateTime = vLogRigester[ 0 ];
		LogRigester.UserName = vLogRigester[ 1 ];
		LogRigester.FullName = vLogRigester[ 2 ];
		LogRigester.Password = clsUtil::decriptionStr( vLogRigester[ 3 ] , 2 );
		LogRigester.Premissions = stoi( vLogRigester[ 4 ] );


		return LogRigester;

	}
	static string _ConverUsaerObjectToLine( clsUsers Client , string Seperator = "#//#" )
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName() + Seperator;
		stClientRecord += Client.LastName() + Seperator;
		stClientRecord += Client.Email() + Seperator;
		stClientRecord += Client.Phone() + Seperator;
		stClientRecord += Client.UserName() + Seperator;
		stClientRecord += clsUtil::incriptionStr( Client.Password() , 2 ) + Seperator;
		stClientRecord += to_string( Client.Premissions() );

		return stClientRecord;
	}
	string _PrepareLogInRecord( string Seperator = "#//#" )
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += this->UserName() + Seperator;
		LoginRecord += this->FullName() + Seperator;
		LoginRecord += clsUtil::incriptionStr( this->Password() , 2 ) + Seperator;
		LoginRecord += to_string( this->Premissions() );
		return LoginRecord;
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
		eAll = -1 , pListClients = 1 , pAddNewClint = 2 , pDeleteClient = 4 , pUpdateClients = 8 , pFindClients = 16 , pTransactions = 32 , pManagUsers = 64 , pShowLog = 128
	};
	enum enSaveResults
	{
		svFaildEmptyObject = 0 ,
		svSucceed = 1 ,
		svFaildObjectAccountExists = 2
	};
	struct stLogRigester
	{
		string DateTime;
		string UserName;
		string FullName;
		string Password;
		int Premissions;
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
		return _getEmptyUSerObject();
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
	bool CheckAccessPremission( enPremissions premission )
	{
		if ( this->Premissions() == enPremissions::eAll )
		{
			return true;
		}
		if ( ( premission & this->Premissions() ) == premission )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void LogRigester()
	{
		string logRecordLine = _PrepareLogInRecord();
		fstream MyFile;
		MyFile.open( "LogFile.txt" , ios::out | ios::app );

		if ( MyFile.is_open() )
		{
			MyFile << logRecordLine << endl;
			MyFile.close();
		}
	}
	static vector<stLogRigester> GetLogRigesterList()
	{
		vector<stLogRigester> vLogRigester;
		fstream MyFile;
		MyFile.open( "LogFile.txt" , ios::in );

		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline( MyFile , Line ) )
			{
				stLogRigester logRecord = _LoadLogRigesterDataFromFile( Line , "#//#" );
				vLogRigester.push_back( logRecord );
			}
			MyFile.close();
		}
		return vLogRigester;
	}

};