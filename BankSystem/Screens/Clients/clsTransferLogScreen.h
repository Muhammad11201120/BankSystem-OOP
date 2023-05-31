#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"Global.h"
class clsTransferLogScreen :protected clsScreen
{
private:
	static void _PrintTransferRigesterLine( clsBankClient::stTransferRigesters TransferRigester )
	{

		cout << setw( 8 ) << left << "" << "| " << setw( 20 ) << left << TransferRigester.DateTime;
		cout << "| " << setw( 15 ) << left << TransferRigester.FromAccount;
		cout << "| " << setw( 15 ) << left << TransferRigester.ToAccount;
		cout << "| " << setw( 15 ) << left << TransferRigester.Amount;
		cout << "| " << setw( 15 ) << left << TransferRigester.fromAccountBalance;
		cout << "| " << setw( 15 ) << left << TransferRigester.ToAccountBalance;
		cout << "| " << setw( 15 ) << left << TransferRigester.userName;
	}
public:
	static void TransferRigesterScreen()
	{
		system( "cls" );
		vector <clsBankClient::stTransferRigesters> vUsers = clsBankClient::GetTransferRigesterList();
		string Title = "TRANSFER RIGESTER SCREEN";
		string SubTitle = "\t    (" + to_string( vUsers.size() ) + ") TRANSFERS(S).";

		_DrawScreenHeader( Title , SubTitle );


		cout << setw( 8 ) << left << "" << "\n\t__________________________________________________________________________";
		cout << "________________________________________________\n" << endl;

		cout << setw( 8 ) << left << "" << "| " << left << setw( 20 ) << "Date/Time";
		cout << "| " << left << setw( 15 ) << "F.Account";
		cout << "| " << left << setw( 15 ) << "D.Account";
		cout << "| " << left << setw( 15 ) << "Amount";
		cout << "| " << left << setw( 15 ) << "F.Balance";
		cout << "| " << left << setw( 15 ) << "D.Balance";
		cout << "| " << left << setw( 15 ) << "Operator";
		cout << setw( 8 ) << left << "" << "\n\t__________________________________________________________________________";
		cout << "________________________________________________\n" << endl;

		if ( vUsers.size() == 0 )
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for ( clsBankClient::stTransferRigesters& user : vUsers )
			{

				_PrintTransferRigesterLine( user );
				cout << endl;
			}

		cout << setw( 8 ) << left << "" << "\n\t__________________________________________________________________________";
		cout << "________________________________________________\n" << endl;
	}
};

