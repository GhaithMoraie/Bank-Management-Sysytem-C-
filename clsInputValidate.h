#pragma once
#include<iostream>
#include<string>
#include"clsDate.h";
#include"clsUtil.h";

using namespace std;


class clsInputValidate
{

public:

	//Check If Template Number are Between From(_) To(_):
	template<typename T> static bool IsTemplateNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	//Check If (Number(short or int or float or double) and Date) are Between From(_) To(_):
	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate FromDate, clsDate ToDate)
	{

		if (clsDate::IsDate1AfterDate2(FromDate, ToDate))
			clsUtil::Swap(FromDate, ToDate);

		return !((clsDate::CompareDates(Date, FromDate) == clsDate::Before)
			|| (clsDate::CompareDates(Date, ToDate) == clsDate::After));

		/*
		äÝÓ ÇáÍá åí ÇÈÓØ æáßä áíßæä ÚäÇ ÊäæÚ ÈÇáÇÝßÇÑ

		return !(clsDate::IsDate1BeforeDate2(Date, FromDate)
			|| clsDate::IsDate1AfterDate2(Date, ToDate));*/

			/*	//Date>=From && Date<=To
			if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
				&&
				(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
				)
			{
				return true;
			}

			//Date>=To && Date<=From
			if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
				&&
				(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
				)
			{
				return true;
			}

			return false;*/

	}



	//Read Only Template Number :
	template <typename T> static T ReadTemplateNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Number;

	}

	//Read Only Number for(short & Int & float & Double):
	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;


	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}


	
	
	//Read Template Number Between:
	template<typename T> static T ReadTemplateNumberBetween(T From, T To, string ErrorMessage = "Number is not within Range, Enter again:\n")
	{
		T Number = ReadTemplateNumber<T>(ErrorMessage);

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadTemplateNumber();
		}

		return Number;
	}

	//Read Number Between From(_) To(_) for(Short & Int & Double)::
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}




	//Read Template Positive Number 
	template <typename T> T ReadTemplatePositiveNumber(string Massage = "Not Positive Number, Enter Again:\n")
	{
		T Number = ReadTemplateNumber<T>(Massage);

		while (Number < 0)
		{
			cout << Massage;
			Number = ReadTemplateNumber<T>(Massage);
		}

		return Number;

	}

	//Read Positive Number for(Int & Double):
	static int ReadIntPositiveNumber(string massage = "Not Positive Number, Enter Again:\n")
	{
		int Number = ReadIntNumber();

		while (Number < 0)
		{
			cout << massage;
			Number = ReadIntNumber();
		}

		return Number;

	}

	static double ReadDblPositiveNumber(string massage = "Not Positive Number, Enter Again:\n")
	{
		double Number = ReadDblNumber();

		while (Number < 0)
		{
			cout << massage;
			Number = ReadDblNumber();
		}
		return Number;

	}




	//Is Valid Date:
	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	//Read String
	static string ReadString()
	{
		string Word = "";
		getline(cin >> ws, Word);

		return Word;

	}
















};