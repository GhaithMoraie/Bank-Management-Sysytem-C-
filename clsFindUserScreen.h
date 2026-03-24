#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen :protected clsScreen
{

private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUserName    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermission  : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:

	static void ShowFindUserScreen()
	{

		_DrawScreenHeader("\tFind User Screen");

		string UserName;
		cout << "\nPlease Enter User Name: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);

		if (!User1.IsEmpty())
		{
			cout << clsUtil::BLUE << "\nUser Found :-)\n" << clsUtil::RESET;
		}
		else
		{
			cout << clsUtil::BLUE << "\nUser Was not Found :-(\n" << clsUtil::RESET;
		}

		_PrintUser(User1);

	}

};

