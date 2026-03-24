#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h";
#include <iomanip>
#include"clsDepositScreen.h";
#include"clsWithdrawScreen.h";
#include"clsTotalBalancesScreen.h";
#include"clsTransferMoneyScreen.h";
#include"clsLogTransferScreen.h"

using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eTransferLog = 4, TransferMoney = 5, eShowMainMenue = 6
	};

	static short ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}


	static void _ShowDepositScreen()
	{
		/* If anytime I make a change i show this Massage: 
		cout << "\n Deposit Screen will be here.\n";*/
		clsDepositScreen::ShowDepositScreen();

	}

	static void _ShowWithdrawScreen()
	{
		/* If anytime I make a change i show this Massage:
		cout << "\n Withdraw Screen will be here.\n";*/
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		/* If anytime I make a change i show this Massage:
		cout << "\n Balance Screen will be here.\n";*/
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferMoneyScreen()
	{
		/* If anytime I make a change i show this Massage:
			cout << "\n Tranfer Screen will be here.\n";*/
		clsTranferMoneyScreen::ShowTransferScreen();
	}

	static void _ShowlogTransferRegisterScreen() 
	{
		clsLogTransferScreen::ShowTransferList();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();

	}

	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::TransferMoney:
		{
			system("cls");
			_ShowTransferMoneyScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowlogTransferRegisterScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eShowMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
			break;
		}
		}


	}



public:


	static void ShowTransactionsMenue()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Tranfer Money.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
	}

};

