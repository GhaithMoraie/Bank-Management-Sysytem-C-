#pragma
#include<iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen : public clsScreen
{
	enum enCurrenciesMainMenueOptions {
		enListCurrecies = 1, enFindCurrency = 2,
		enUpdateCurrencyRate = 3, enCurrencyCalculater = 4, enMainMeneu = 5
	};

	static 	short _ReadCurrencyMenueOption()
	{
		cout << setw(37) << "" << left << "Choose what do you want to do? [1,5]? ";

		short Choose = clsInputValidate::ReadShortNumberBetween(1, 5);
		return Choose;
	}

	static void _GobackToCurrenciesMenue()
	{
		cout << "\n\nPlease Enter Any Key to Goback to Curreny Menue...\n";
		system("pause>0");
		ShowCurrenciesMenue();
	}

	static void _ShowCurrenciesListScreen()
	{
		//cout << "List Screen will be hier.";
		clsCurrenciesListScreen::ShowListCurrencyScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
	   //cout << "Find Currencies will be hier.";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << "Update Currencies will be hier.";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrncyCalculaterScreen()
	{
	//	cout << "Currency Calculater will be hier.";
		clsCurrencyCalculatorScreen::ShowCuurencyCalculatorScreen();
	}

	static void _PerformanceCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions Choose)
	{
		switch (Choose)
		{

		case clsCurrencyExchangeMainScreen::enListCurrecies:
			system("cls");
			_ShowCurrenciesListScreen();
			_GobackToCurrenciesMenue();
			break;

		case clsCurrencyExchangeMainScreen::enFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GobackToCurrenciesMenue();
			break;

		case clsCurrencyExchangeMainScreen::enUpdateCurrencyRate:
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GobackToCurrenciesMenue();
			break;

		case clsCurrencyExchangeMainScreen::enCurrencyCalculater:
			system("cls");
			_ShowCurrncyCalculaterScreen();
			_GobackToCurrenciesMenue();
			break;

		case clsCurrencyExchangeMainScreen::enMainMeneu:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}
	}

public:
	static void ShowCurrenciesMenue()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pCurrencyExchabge))
			return;

		system("cls");
		clsScreen::_DrawScreenHeader("     Currency Exchange Main Scrren");

		cout << setw(37) << "" << "===========================================\n";
		cout << setw(37) << "" << left << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << "" << "===========================================\n";
		cout << setw(37) << "" << left << "\t[1] List Currencies.\n";
		cout << setw(37) << "" << left << "\t[2] Find Currency.\n";
		cout << setw(37) << "" << left << "\t[3] Update Rate.\n";
		cout << setw(37) << "" << left << "\t[4] Currencies Calculater.\n";
		cout << setw(37) << "" << left << "\t[5] Main Menue.\n";
		cout << setw(37) << "" << "===========================================\n";

		_PerformanceCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions(_ReadCurrencyMenueOption()));





	}












};
