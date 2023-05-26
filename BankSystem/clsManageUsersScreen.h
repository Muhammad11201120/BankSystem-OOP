#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMainMenueScreen.h"
#include"clsUsersList.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUser.h"
#include"clsUpdateUserScreen.h"
using namespace std;
class clsManageUsersScreen :protected clsScreen
{
private:
	enum enManageUsersOptions
	{
		listUsers = 1 ,
		addUser = 2 ,
		updateUser = 3 ,
		deleteUser = 4 ,
		findUser = 5 ,
		backToMainMenue = 6
	};
	static short _readUserInputOption()
	{
		cout << "Choose What You Want From 1 - 6 ";
		short choice = clsInputValidate::ReadShortNumberBetween( 1 , 6 , "Please Enter Valid Number Between 1 - 6 " );
		return choice;
	}
	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system( "pause>0" );
		ManageUsersScreen();

	}

	static void _showListUsersScreen()
	{
		clsUsersList::UsersListScreen();
	}
	static void _showAddUserScreen()
	{
		clsAddNewUserScreen::addUserScreen();
	}
	static void _showUpdasteUserScreen()
	{
		clsUpdateUserScreen::UpdateUserScreen();
	}
	static void _showDeleteUSerScreen()
	{
		clsDeleteUser::DeleteUserScreen();
	}
	static void _showFindUserScreen()
	{
		cout << "Find User Will Be Here.." << endl;
	}
	static void _BackToUsersMainMenueScreen()
	{
		system( "pause>0" );
		ManageUsersScreen();
	}
	static void _performUsersMenueOptions( enManageUsersOptions option )
	{
		switch ( option )
		{
		case clsManageUsersScreen::listUsers:
			_showListUsersScreen();
			_BackToUsersMainMenueScreen();
			break;
		case clsManageUsersScreen::addUser:
			_showAddUserScreen();
			_BackToUsersMainMenueScreen();
			break;
		case clsManageUsersScreen::updateUser:
			_showUpdasteUserScreen();
			_BackToUsersMainMenueScreen();
			break;
		case clsManageUsersScreen::deleteUser:
			_showDeleteUSerScreen();
			_BackToUsersMainMenueScreen();
			break;
		case clsManageUsersScreen::findUser:
			_showFindUserScreen();
			_BackToUsersMainMenueScreen();
			break;
		case clsManageUsersScreen::backToMainMenue:
			//IT Will Be Handeled By main menue class
			break;
		}
	}
public:

	static void ManageUsersScreen()
	{
		system( "cls" );
		_DrawScreenHeader( "MANAGE USERS SCREEN" );

		cout << setw( 37 ) << left << "" << "===========================================\n";
		cout << setw( 37 ) << left << "" << "\t\tManage Users Menue\n";
		cout << setw( 37 ) << left << "" << "===========================================\n";
		cout << setw( 37 ) << left << "" << "\t[1] Show Users List.\n";
		cout << setw( 37 ) << left << "" << "\t[2] Add New User.\n";
		cout << setw( 37 ) << left << "" << "\t[3] Update User.\n";
		cout << setw( 37 ) << left << "" << "\t[4] Delete USer.\n";
		cout << setw( 37 ) << left << "" << "\t[5] Find User.\n";
		cout << setw( 37 ) << left << "" << "\t[6] Back To Main Menue.\n";
		cout << setw( 37 ) << left << "" << "===========================================\n";

		_performUsersMenueOptions( ( enManageUsersOptions ) _readUserInputOption() );
	}
};

