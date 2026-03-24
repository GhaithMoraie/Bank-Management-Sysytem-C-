#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"

class clsCurrenciesListScreen:public clsScreen
{
private:

	static void _PrintCurrenciesInfo(clsCurrency CurrenciesInfo)
	{
		cout << "\n\t" << left << "" << "| " << left << setw(35) << CurrenciesInfo.Country();
		cout << "| " << left << setw(8) << CurrenciesInfo.CurrencyCode();
		cout << "| " << left << setw(40) << CurrenciesInfo.CurrencyName();
		cout << "| " << left << setw(10) << CurrenciesInfo.Rate();

	}





public:

	static void ShowListCurrencyScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		string Title = "\t  Currencies List Scrren";
		string SubTitle = "\t  (" + to_string(vCurrencies.size()) + ") Currencies.";

		_DrawScreenHeader(Title, SubTitle);


		cout << "\n\t" << "===============================================";
		cout << "	====================================================\n";
		cout << "\t" << "| " << left << setw(35) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(10) << "Rate(1$)";
		cout << "\n\t" << "======================================================";
		cout << "==============================================";

		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else
		{
			for (clsCurrency& C : vCurrencies)
			{
				_PrintCurrenciesInfo(C);
			}
		}

		cout << "\n\t" << "===============================================";
		cout << "=====================================================\n";


	}




};
