#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen :protected clsScreen

{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	enum enClientInfo { FirstName = 1, LastName = 2, Email = 3, Phone = 4, PinCode = 5, Balance = 6, All = 7 };

	static void _ReadAllClientInfo(clsBankClient& Client) {
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

	static void _ReadClientInfo(clsBankClient& Client)
	{
		int ClientChange = 0;
		string ChangeAgain = "y";

		while (ChangeAgain == "Y" || ChangeAgain == "y")
		{
			cout << "\nWhat you want to change? Please Enter A Number:\n(FirstName = 1, LastName = 2, Email = 3, Phone = 4, PinCode = 5, Balance = 6, All = 7 )  ";
			ClientChange = clsInputValidate::ReadIntNumber();

			switch (ClientChange)
			{
			case enClientInfo::All:
			{
				_ReadAllClientInfo(Client);
				break;
			}
			case enClientInfo::FirstName:
			{
				cout << "\nEnter FirstName: ";
				Client.FirstName = clsInputValidate::ReadString();
				break;
			}
			case enClientInfo::LastName:
			{
				cout << "\nEnter LastName: ";
				Client.LastName = clsInputValidate::ReadString();
				break;
			}
			case enClientInfo::Email:
			{
				cout << "\nEnter Email: ";
				Client.Email = clsInputValidate::ReadString();
				break;
			}
			case enClientInfo::Phone:
			{
				cout << "\nEnter Phone: ";
				Client.Phone = clsInputValidate::ReadString();
				break;
			}
			case enClientInfo::PinCode:
			{
				cout << "\nEnter PinCode: ";
				Client.PinCode = clsInputValidate::ReadString();
				break;
			}
			case enClientInfo::Balance:
			{
				cout << "\nEnter Account Balance: ";
				Client.AccountBalance = clsInputValidate::ReadFloatNumber();
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

	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}

		_DrawScreenHeader("\tUpdate Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		cout << "\nAre you sure you want to update this client y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate Client Info:";
			cout << "\n____________________\n";


			_ReadClientInfo(Client1);

			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client1.Save();

			switch (SaveResult)
			{
			case  clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\nAccount Updated Successfully :-)\n";

				_PrintClient(Client1);
				break;
			}
			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError account was not saved because it's Empty";
				break;

			}

			}

		}

	}
};

