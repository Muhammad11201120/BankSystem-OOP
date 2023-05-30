#pragma once
#include <iostream>
#include <vector>
#include "clsPerson.h"
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
	enum enMode
	{
		empty = 0 ,
		updated = 1 ,
		add = 2
	};

	enMode _enMode;
	string _pinCode;
	string _accountNumber;
	float _balance;
	bool _deleteFlag = false;
	struct stTransferRigesters;
	static  stTransferRigesters _LoadTransferRigesterDataFromFile( string line , string seperator )
	{

		stTransferRigesters LogRigester;

		vector<string> vLogRigester;
		vLogRigester = clsString::Split( line , "#//#" );

		LogRigester.DateTime = vLogRigester[ 0 ];
		LogRigester.FromAccount = vLogRigester[ 1 ];
		LogRigester.ToAccount = vLogRigester[ 2 ];
		LogRigester.Amount = stod( vLogRigester[ 3 ] );
		LogRigester.fromAccountBalance = stod( vLogRigester[ 4 ] );
		LogRigester.ToAccountBalance = stod( vLogRigester[ 5 ] );
		LogRigester.userName = vLogRigester[ 6 ];

		return LogRigester;

	}
	string _PrepareTransferRecord( clsBankClient ToAccount , double amount , string Seperator = "#//#" )
	{
		string TransferRecord = "";
		TransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferRecord += this->FullName() + Seperator;
		TransferRecord += ToAccount.FullName() + Seperator;
		TransferRecord += to_string( amount ) + Seperator;
		TransferRecord += to_string( this->Balance() ) + Seperator;
		TransferRecord += to_string( ToAccount.Balance() ) + Seperator;
		TransferRecord += CurrentUser.UserName();
		return TransferRecord;
	}
	static clsBankClient _convertLineToClientObject( string line , string seperator = "#//#" )
	{
		vector<string> vClient;
		vClient = clsString::Split( line , seperator );
		return clsBankClient( enMode::updated , vClient[ 0 ] , vClient[ 1 ] , vClient[ 2 ] , vClient[ 3 ] , vClient[ 4 ] , vClient[ 5 ] , stod( vClient[ 6 ] ) );
	}
	static string _ConverClientObjectToLine( clsBankClient Client , string Seperator = "#//#" )
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName() + Seperator;
		stClientRecord += Client.LastName() + Seperator;
		stClientRecord += Client.Email() + Seperator;
		stClientRecord += Client.Phone() + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode() + Seperator;
		stClientRecord += to_string( Client.Balance() );

		return stClientRecord;
	}
	static vector<clsBankClient> _LoadClientsDataFromFile()
	{

		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open( "Clients.txt" , ios::in ); // read Mode

		if ( MyFile.is_open() )
		{

			string Line;

			while ( getline( MyFile , Line ) )
			{

				clsBankClient Client = _convertLineToClientObject( Line );

				vClients.push_back( Client );
			}

			MyFile.close();
		}

		return vClients;
	}
	static void _SaveCleintsDataToFile( vector<clsBankClient> vClients )
	{

		fstream MyFile;
		MyFile.open( "Clients.txt" , ios::out ); // overwrite

		string DataLine;

		if ( MyFile.is_open() )
		{

			for ( clsBankClient C : vClients )
			{
				if ( C._deleteFlag == false )
				{
					DataLine = _ConverClientObjectToLine( C );
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}
	void _AddDataLineToFile( string stDataLine )
	{
		fstream MyFile;
		MyFile.open( "Clients.txt" , ios::out | ios::app );

		if ( MyFile.is_open() )
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}
	void _Update()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for ( clsBankClient& C : _vClients )
		{
			if ( C.AccountNumber() == AccountNumber() )
			{
				C = *this;
				break;
			}
		}

		_SaveCleintsDataToFile( _vClients );
	}
	void _Add()
	{
		_AddDataLineToFile( _ConverClientObjectToLine( *this ) );
	}
	static clsBankClient _getEmptyClientObject()
	{
		return clsBankClient( enMode::empty , "" , "" , "" , "" , "" , "" , 0 );
	}
public:

	enum enSaveResults
	{
		svFaildEmptyObject = 0 ,
		svSucceed = 1 ,
		svFaildObjectAccountExists = 2
	};
	struct stTransferRigesters
	{
		string DateTime;
		string FromAccount;
		string ToAccount;
		double Amount;
		double fromAccountBalance;
		double ToAccountBalance;
		string userName;
	};
	clsBankClient( enMode mode , string firstName , string lastName , string email , string phone , string accountNumber , string pinCode , float balance )
		: clsPerson( firstName , lastName , email , phone )
	{
		this->_enMode = mode;
		this->_accountNumber = accountNumber;
		this->_pinCode = pinCode;
		this->_balance = balance;
	}
	bool isEmpty()
	{
		return ( this->_enMode == enMode::empty );
	}
	string AccountNumber()
	{
		return this->_accountNumber;
	}
	void setPinCode( string pinCode )
	{
		this->_pinCode = pinCode;
	}
	string PinCode()
	{
		return this->_pinCode;
	}
	void setBalance( float balance )
	{
		this->_balance = balance;
	}
	float Balance()
	{
		return this->_balance;
	}
	static clsBankClient Find( string accountNumber )
	{
		fstream MyFile;
		MyFile.open( "Clients.txt" , ios::in ); // read Mode

		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline( MyFile , Line ) )
			{
				clsBankClient Client = _convertLineToClientObject( Line );
				if ( Client.AccountNumber() == accountNumber )
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _getEmptyClientObject();
	}
	static clsBankClient Find( string accountNumber , string pinCode )
	{

		clsBankClient Client = Find( accountNumber );
		if ( Client.PinCode() == pinCode )
		{
			return Client;
		}
		else
		{
			_getEmptyClientObject();
		}
	}
	static clsBankClient GetAddNewClientObject( string accountNumber )
	{
		return clsBankClient( enMode::add , "" , "" , "" , "" , accountNumber , "" , 0 );
	}
	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}
	bool Delete()
	{
		vector<clsBankClient> vClient;
		vClient = _LoadClientsDataFromFile();
		for ( clsBankClient& C : vClient )
		{
			if ( C.AccountNumber() == this->_accountNumber )
			{
				C._deleteFlag = true;
				break;
			}
		}
		_SaveCleintsDataToFile( vClient );
		*this = _getEmptyClientObject();
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
				if ( clsBankClient::isClientExists( this->_accountNumber ) )
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
	static bool isClientExists( string accountNumber )
	{
		clsBankClient client = clsBankClient::Find( accountNumber );
		return ( !client.isEmpty() );
	}
	static double GetTotalBalance()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();
		double totalBalance = 0;
		for ( clsBankClient& C : vClients )
		{
			totalBalance += C.Balance();
		}
		return totalBalance;
	}
	//Transactions
	void Deposit( double amount )
	{
		this->_balance += amount;
		Save();
	}
	bool Withdrow( double amount )
	{
		if ( amount > this->_balance )
		{
			return false;
		}
		else
		{
			this->_balance -= amount;
			Save();
			return true;
		}
	}
	bool TransferMoney( clsBankClient& toClient , double amount )
	{
		if ( amount > this->Balance() )
		{
			return false;
		}
		else
		{
			this->Withdrow( amount );
			toClient.Deposit( amount );
			return true;
		}
	}
	void TransfersRigester( clsBankClient ToAccount , double amount )
	{
		string logRecordLine = _PrepareTransferRecord( ToAccount , amount );
		fstream MyFile;
		MyFile.open( "TransactionsFile.txt" , ios::out | ios::app );

		if ( MyFile.is_open() )
		{
			MyFile << logRecordLine << endl;
			MyFile.close();
		}
	}
	static vector<stTransferRigesters> GetTransferRigesterList()
	{
		vector<stTransferRigesters> vLogRigester;
		fstream MyFile;
		MyFile.open( "TransactionsFile.txt" , ios::in );

		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline( MyFile , Line ) )
			{
				stTransferRigesters logRecord = _LoadTransferRigesterDataFromFile( Line , "#//#" );
				vLogRigester.push_back( logRecord );
			}
			MyFile.close();
		}
		return vLogRigester;
	}
};
