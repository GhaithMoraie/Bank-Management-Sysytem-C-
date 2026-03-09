#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"
#include"clsInputValidate.h";

using namespace std;

class clsTranferMoneyScreen :protected clsScreen
{

private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAccount Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
	
	static float _ReadAmount(clsBankClient SourceClinet)
	{
		float Amount;
	
		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClinet.AccountBalance)
		{
			cout << clsUtil::RED << "\nAmount Exceeds the availabe Balance, Enter another Amount: " << clsUtil::RESET;
			Amount = clsInputValidate::ReadFloatNumber();
		}

		return Amount;

	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen");

		cout << "\n\nPlease Enter ClientAccout you want to TransferMoney From it: ";
		string AccountNumberFrom = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumberFrom)))
		{
			cout << "\nClient is not Exist.Please Enter anthor Clinet: ";
			AccountNumberFrom = clsInputValidate::ReadString();
		}

		clsBankClient SourceClient = clsBankClient::Find(AccountNumberFrom);
		_PrintClient(SourceClient);

		cout << "\n\nPlease Enter ClientAccout you want to TransferMoney to it: ";
		string AccountNumberTo = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumberTo)))
		{
			cout << "\nClient is not Exist.Please Enter anthor Clinet: ";
			AccountNumberTo = clsInputValidate::ReadString();
		}

		clsBankClient DestinationClient = clsBankClient::Find(AccountNumberTo);
		_PrintClient(DestinationClient);


		float Amount = _ReadAmount(DestinationClient);
		

		cout << "\nAre you sure you want to Transfer (" << clsUtil::GREEN << Amount << "$" << clsUtil::RESET << ")"
			<< " From -" << clsUtil::RED << AccountNumberFrom << clsUtil::RESET
			<< "- To -" << clsUtil::RED << AccountNumberTo << clsUtil::RESET << "- ? Y/N?: ";
		char Answer = 'n';
		cin >> Answer;


		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.TransferMoney(DestinationClient, Amount, CurrentUser.UserName))
			{
				cout << clsUtil::CYAN << "\n\nTransfer Successfully :-)." << clsUtil::RESET;
				cout << "\n\nClientBalance That withdraw From: " << SourceClient.AccountBalance;
				cout << "\n\nClientBalance That Deposit To: " << DestinationClient.AccountBalance << endl;

			}
			else
			{
				cout << clsUtil::RED << "\nError, Amount is bigger than ClientBalance you want to Transfer From." << clsUtil::RESET;
			}
		}
		else
		{
			cout << "\n\nOperation is cancelled.";
		}
		




	}

};