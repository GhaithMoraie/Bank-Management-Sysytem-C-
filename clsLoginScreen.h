#pragma once
#include <iostream>
#include<iomanip>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsUser.h"
#include"Global.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{

private:



	static bool _Login()
	{
		string UserName, Password;
		bool LoginFaild = false;
		int FaildLoginCount = 3;
		

		do
		{

			cout << "\nPlease Enter User Name: ";
			UserName = clsInputValidate::ReadString();
			
			cout << "Please Enter Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);


			LoginFaild = CurrentUser.IsEmpty();

			if (LoginFaild)
			{
				FaildLoginCount--;
				cout << "\nInvaild UserName/Password!.\n"
					<< "You have " << FaildLoginCount << " Trial(s) to login.\n";
			}

			if (FaildLoginCount == 0)
			{
				cout << "\nYour are Locked after 3 faild trails.\n\n";
				return false;
			}

		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;

	}


public:

	static bool ShowLoginScreen()
	{
			system("cls");
			_DrawScreenHeader("\t Login Screen");
			return _Login();
		
	}


};

