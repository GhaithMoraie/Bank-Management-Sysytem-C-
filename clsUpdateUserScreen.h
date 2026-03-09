#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include"clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen :protected clsScreen

{
private:

	enum enUserInfo { FirstName = 1, LastName = 2, Email = 3, Phone = 4, Password = 5, Permissions = 6, All = 7 };

	static void _PrintUser(clsUser Client)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nUser Name   : " << Client.UserName;
		cout << "\nPassword    : " << Client.Password;
		cout << "\nPermission  : " << Client.Permissions;
		cout << "\n___________________\n";

	}

	static int _ReadPermissionsToSet()
	{

		int Permissions = 0;
		char Answer = 'n';


		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{


			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nLogin Register? y/n?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}

		return Permissions;

	}

	static void _ReadAllClientInfo(clsUser& Client) {
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		Client.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission: ";
		Client.Permissions = _ReadPermissionsToSet();
	}

	static void _ReadClientInfo(clsUser& Client)
	{
		int ClientChange = 0;
		string ChangeAgain = "y";

		while (ChangeAgain == "Y" || ChangeAgain == "y")
		{
			cout << "\nWhat you want to change? Please Enter A Number:\n(FirstName = 1, LastName = 2, Email = 3, Phone = 4, PinCode = 5, Balance = 6, All = 7 )  ";
			ClientChange = clsInputValidate::ReadIntNumber();

			switch (ClientChange)
			{
			case enUserInfo::All:
			{
				_ReadAllClientInfo(Client);
				break;
			}
			case enUserInfo::FirstName:
			{
				cout << "\nEnter FirstName: ";
				Client.FirstName = clsInputValidate::ReadString();
				break;
			}
			case enUserInfo::LastName:
			{
				cout << "\nEnter LastName: ";
				Client.LastName = clsInputValidate::ReadString();
				break;
			}
			case enUserInfo::Email:
			{
				cout << "\nEnter Email: ";
				Client.Email = clsInputValidate::ReadString();
				break;
			}
			case enUserInfo::Phone:
			{
				cout << "\nEnter Phone: ";
				Client.Phone = clsInputValidate::ReadString();
				break;
			}
			case enUserInfo::Password:
			{
				cout << "\nEnter PinCode: ";
				Client.Password = clsInputValidate::ReadString();
				break;
			}
			case enUserInfo::Permissions:
			{
				cout << "\nEnter Account Balance: ";
				Client.Permissions = _ReadPermissionsToSet();
				break;

			}
			default:
				cout << "Invalid choice!";
				break;
			}
			cout << "\nDo you want to change any thing more? Y/N? ";
			ChangeAgain = clsInputValidate::ReadString();

		}

	}



public:

	static void ShowUpdateUserScreen()
	{

		_DrawScreenHeader("\tUpdate User Screen");

		string UserName = "";

		cout << "\nPlease Enter  User Name: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);

		_PrintUser(User1);

		cout << "\nAre you sure you want to update this User y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate User Info:";
			cout << "\n____________________\n";


			_ReadAllClientInfo(User1);

			clsUser::enSaveResults SaveResult;

			SaveResult = User1.Save();

			switch (SaveResult)
			{
			case  clsUser::enSaveResults::svSucceeded:
			{
				cout << "\nUser Name Updated Successfully :-)\n";

				_PrintUser(User1);
				break;
			}
			case clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError User Name was not saved because it's Empty";
				break;

			}

			}

		}

	}
};

