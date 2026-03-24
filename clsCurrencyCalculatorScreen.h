#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsUtil.h"

class clsCurrencyCalculatorScreen:public clsScreen
{
private:

	static void _PrintCurrencyInfo(clsCurrency Currency, string Title = "Currency Card")
	{
		cout << clsUtil::YELLOW << Title << clsUtil::RESET << endl;
		cout << "\n-------------------------------\n";
		cout << "\nCountry  :" << Currency.Country();
		cout << "\nCode     :" << Currency.CurrencyCode();
		cout << "\nName     :" << Currency.CurrencyName();
		cout << "\nRate(1$) :" << Currency.Rate();
		cout << "\n\n--------------------------------\n";
	}

	static float _ReadAmount()
	{
		float Amount = 0;

		cout << "\nEnter Amount to Exchange: ";
		Amount = clsInputValidate::ReadIntNumber();

		return Amount;
	}

	static clsCurrency _GetCurrency(string Massage)
	{
		cout << Massage << endl;

		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code not Found, Please Enter anthor one.";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCalculationsResults(clsCurrency Currency1, clsCurrency Currency2, float Amount)
	{
		_PrintCurrencyInfo(Currency1, "\nConvert From:");

		float AmounttoUSD = Currency1.ConvertToUSD(Amount);
		
		cout << Amount << " " << Currency1.CurrencyCode() << " = "
			<< AmounttoUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << clsUtil::YELLOW << "\nConverting from USD to:\n" << clsUtil::RESET;

		_PrintCurrencyInfo(Currency2, "TO:");

		float AmountInCurrency2 = Currency1.ConvertToanthorCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " 
			<< AmountInCurrency2 << " " << Currency2.CurrencyCode() << endl;

	}


public:

	static void ShowCuurencyCalculatorScreen()
	{

		char Again = 'y';

		while (Again == 'y' || Again == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\t Calculator Currency Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			
			float Amount = _ReadAmount();

			_PrintCalculationsResults(CurrencyFrom, CurrencyTo, Amount);

			cout << "\n\nDo you want to perform anthor calculation? y/n? ";
			cin >> Again;

		}




	}



};
