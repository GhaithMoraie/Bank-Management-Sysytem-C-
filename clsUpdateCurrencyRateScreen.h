#pragma once
#include<iomanip>
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

class clsUpdateCurrencyRateScreen:public clsScreen
{
private:
	static void _PrintCurrencyInfo(clsCurrency Currency)
	{
		cout << "\nCurrency Code: ";
		cout << "\n-------------------------------\n";
		cout << "\nCountry  :" << Currency.Country();
		cout << "\nCode     :" << Currency.CurrencyCode();
		cout << "\nName     :" << Currency.CurrencyName();
		cout << "\nRate(1$) :" << Currency.Rate();
		cout << "\n\n--------------------------------\n";
	}

	static float _ReadRate()
	{
		float NewRate = 0;

		cout << "\n Please Enter New Rate : ";
	    NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	
	}

public:
	
	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t Update Currecny Screen");
		
		string Currnceycode = "";
		cout << "\nPlease Enter Currency Code : ";
		Currnceycode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Currnceycode))
		{
			cout << "\nCurrency is not found choose anthore one: ";
			Currnceycode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(Currnceycode);
		_PrintCurrencyInfo(Currency);

		cout << "\nAre you sure you want to update the Rate of this Currency y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpdate Currency Rate: ";
			cout << "\n------------------------\n";
			
			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Update Successfully :-).\n";
			_PrintCurrencyInfo(Currency);

		}
		else
			cout << "\nCurrency Rate not Update.";




	}





};
