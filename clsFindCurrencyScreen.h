#pragma once
#include<iomanip>
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsString.h"

using namespace std;

class clsFindCurrencyScreen:public clsScreen
{
private:

	static short _ReadFindNumber()
	{
		cout << "\nFind By [1] Code or [2] Country ?  ";
		
		short FindAnswer = clsInputValidate::ReadShortNumberBetween(1, 2, "Please Ebter Number Between 1 and 2? ");
		return FindAnswer;

	}

	static void _PrintCurrencyInfo(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n-------------------------------------\n";
		cout << "\nCountry   :" << Currency.Country();
		cout << "\nCode      :" << Currency.CurrencyCode();
		cout << "\nName      :" << Currency.CurrencyName();
		cout << "\nRate(1$)  :" << Currency.Rate();
		cout << "\n\n-------------------------------------\n\n";

	}

	static void _ShowResult(clsCurrency Currency)
	{
		if(Currency.IsEmpty())
			cout << "\nCurrency not Found :-(\n";
		else
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyInfo(Currency);
		}
	}


public:
	
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		short FindAnswer = _ReadFindNumber();

		if (FindAnswer == 1)
		{
			cout << "\nPlease Enter CurrencyCode: ";
			string Currencycode = clsInputValidate::ReadString();
			clsCurrency CurrencybyCode = clsCurrency::FindByCode(Currencycode);
			_ShowResult(CurrencybyCode);

		}
		else
		{
			cout << "\nPlease Enter Country Name: ";
			string Countryname = clsInputValidate::ReadString();
			clsCurrency CurrencybyCountry = clsCurrency::FindByCountry(Countryname);
			_ShowResult(CurrencybyCountry);
		}


	}



};

