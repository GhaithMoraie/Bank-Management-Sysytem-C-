#pragma once
#include <iostream>
#include<vector>
#include<ctime>
#include"MyStringAndCharacterLibrary.h"
#include<string>

using namespace std;

enum enDateCompare { Befor = -1, Equal = 0, After = 1 };


namespace MyDateLibrary
{
	struct sDate
	{
		short Day;
		short _Month;
		short Year;
	};

	struct sPeriods
	{
		sDate DateStart;
		sDate DateEnd;
	};

	short ReadYear()
	{
		short Year = 0;

		cout << "\nPlease Enter a Year:";
		cin >> Year;

		return Year;
	}

	short ReadMonth()
	{
		short Month = 0;

		cout << "\nPlease Enter a Month: ";
		cin >> Month;

		return Month;

	}

	short ReadDay()
	{
		short Day = 0;

		cout << "\nPlease Enter A Day: ";
		cin >> Day;

		return Day;

	}

	bool IFLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

	}

	short NumberofDayInYear(short Year)
	{
		return (IFLeapYear(Year)) ? 366 : 365;
	}

	short NUmberOFHoursInYear(short Year)
	{
		return (NumberofDayInYear(Year) * 24);
	}

	int NUmberOFMinutesInYear(short Year)
	{
		return (NUmberOFHoursInYear(Year) * 60);
	}

	int NumberOfSecondsInyear(short YEar)
	{
		return (NUmberOFMinutesInYear(YEar) * 60);
	}

	short NumberOFDaysinMonth(short Year, short Month)
	{
		if (Month < 1 || Month>12)
			return 0;

		short arrNumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return Month == 2 ? (MyDateLibrary::IFLeapYear(Year) ? 29 : 28) : arrNumberOfDays[Month - 1];

	}

	short NumberofHoursinMonth(short Year, short Month)
	{
		return NumberOFDaysinMonth(Year, Month) * 24;
	}

	int NumberOFMinutesinMonth(short Year, short Month)
	{
		return NumberofHoursinMonth(Year, Month) * 60;
	}

	int NumberOfSecondinMonth(short Year, short Month)
	{
		return NumberOFMinutesinMonth(Year, Month) * 60;
	}

	short DayOfWeekOrder(short Year, short Month, short Day)
	{
		short a, y, m, d;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	}

	string DayShortName(short DayOfWeekOrder)
	{
		string arrNameOfDay[] = { "Sun","Mon","Tue","Wen","Thu","Fre","Sat" };
		return arrNameOfDay[DayOfWeekOrder];
	}

	string MonthShortName(short Month)
	{
		string arrMonthName[] = { "Jan","Feb","Mai","Apr","Mar","Jul","Jun","Aug","Sep","Okt","Nov","Dez" };
		return arrMonthName[Month - 1];

	}

	void MonthCalendar(short Year, short Month)
	{
		short NumberofDayinMonth = MyDateLibrary::NumberOFDaysinMonth(Year, Month);
		short current = DayOfWeekOrder(Year, Month, 1);

		cout << "\n  ----------------" << MonthShortName(Month) << "---------------\n";
		cout << "  Sun  Mon  Tue  Wed  The  Fri  Sat\n";

		int i;
		for (i = 0; i < current; i++)
		{
			cout << "     ";
		}

		for (short j = 1; j <= NumberofDayinMonth; j++)
		{

			cout << setw(5) << j;

			if (++i == 7)
			{
				i = 0;
				cout << "\n";
			}

		}


		cout << "\n  ----------------------------------\n";

	}

	void YearCalendar(short Year)
	{
		cout << "\n  ----------------------------------\n";
		cout << "           Calendat : " << Year;
		cout << "\n  ----------------------------------\n";

		for (short i = 1; i <= 12; i++)
		{
			MyDateLibrary::MonthCalendar(Year, i);
		}
	}

	short NumberOfDayFromBeginningOfYear(short Year, short Month, short Day)
	{
		short NumberofDay = 0;

		for (short i = 1; i < Month; i++)
		{
			NumberofDay += MyDateLibrary::NumberOFDaysinMonth(Year, i);
		}

		return NumberofDay + Day;

	}

	sDate GetDateFromDayOrderinYear(short OrderDay, short Year)
	{

		sDate Date;
		short Day = OrderDay;
		short MonthDay = 0;

		Date._Month = 1;
		Date.Year = Year;

		while (true)
		{
			MonthDay = MyDateLibrary::NumberOFDaysinMonth(Date.Year, Date._Month);

			if (Day > MonthDay)
			{
				Day -= MonthDay;
				Date._Month++;
			}
			else
			{
				Date.Day = Day;
				break;
			}



		}

		return Date;

	}

	sDate DateAfterAddDays(sDate Date, short AddDay)
	{
		short Day = AddDay + NumberOfDayFromBeginningOfYear(Date.Year, Date._Month, Date.Day);
		short MonthDay = 0;

		Date._Month = 1;

		while (true)
		{
			MonthDay = NumberOFDaysinMonth(Date.Year, Date._Month);

			if (Day > MonthDay)
			{
				Day -= MonthDay;
				Date._Month++;

				if (Date._Month > 12)
				{
					Date.Year++;
					Date._Month = 1;
				}

			}
			else
			{
				Date.Day = Day;
				break;
			}



		}

		return Date;

	}

	bool IfDate1IsEqualDate2(sDate Date1, sDate Date2)
	{
		return  (Date1.Year == Date2.Year) ? ((Date1._Month == Date2._Month) ? (Date1.Day == Date2.Day) : false) : false;
	}

	bool IfDate1IslessThanDate2(sDate Date1, sDate Date2)
	{

		return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1.Day < Date2.Day : false)) : false);

	}

	bool IfDate1AfterDate2(sDate Date1, sDate Date2)
	{
		return ((!IfDate1IslessThanDate2(Date1, Date2)) && IfDate1IsEqualDate2(Date1, Date2));
	}

	bool IfLastDayInMonth(sDate Date)
	{
		short MonthDay = NumberOFDaysinMonth(Date.Year, Date._Month);
		return (Date.Day == MonthDay);
	}

	bool IfMonthIsLastMonthInYear(sDate Date)
	{
		return Date._Month == 12;
	}

	sDate IncreaseDateByOneDay(sDate Date)
	{
		if (IfLastDayInMonth(Date))
		{

			if (IfMonthIsLastMonthInYear(Date))
			{
				Date.Day = 1;
				Date._Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date._Month++;
			}


		}
		else
		{
			Date.Day++;
		}

		return Date;

	}

	int GetDiffDate1AndDate2(sDate Date1, sDate Date2, bool IncludeEndDay = false)
	{
		int countDays = 0;

		while (IfDate1IslessThanDate2(Date1, Date2))
		{
			Date1 = IncreaseDateByOneDay(Date1);
			countDays++;
		}

		return IncludeEndDay ? ++countDays : countDays;

	}

	short DayOfWeekOrder(sDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date._Month, Date.Year);
	}

	bool IfEndOFWeek(sDate Date)
	{
		short OrderDay = DayOfWeekOrder(Date);
		return OrderDay == 6;
	}

	bool IfWeekEnd(sDate Date)
	{
		short OrderDay = DayOfWeekOrder(Date);
		return (OrderDay == 5 || OrderDay == 6);
	}

	bool IfBusinessDay(sDate Date)
	{
		return (!IfWeekEnd(Date));
	}

	short DaysUntilTheEndofWeek(sDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}

	short DaysUntilTheEndofMonth(sDate Date)
	{
		sDate EndOfMonthDate;

		EndOfMonthDate.Day = NumberOFDaysinMonth(Date.Year, Date._Month);
		EndOfMonthDate._Month = Date._Month;
		EndOfMonthDate.Year = Date.Year;

		return GetDiffDate1AndDate2(Date, EndOfMonthDate, true);
	}

	short DaysUntilTheEndofYears(sDate Date)
	{
		sDate EndofYear;

		EndofYear.Day = 31;
		EndofYear._Month = 12;
		EndofYear.Year = Date.Year;

		return GetDiffDate1AndDate2(Date, EndofYear, true);
	}

	sDate GetSystemDate()
	{
		sDate Date;

		time_t t = time(0);
		tm* Now = localtime(&t);

		Date.Day = Now->tm_mday;
		Date._Month = Now->tm_mon + 1 + 1;
		Date.Year = Now->tm_year + 1900;

		return Date;

	}

	bool IfValidateDate(sDate Date)
	{
		//
		//My First Sulotion:

		//if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
		//	return false;
		//if (Date.Month > 12)
		//	return false;

		//return true;

		//My Srcond Sulotion:
		//return (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) ? false : ((Date.Month > 12) ? false : true);



		//Doctor Sulotion:

		if (Date.Day < 1 || Date.Day>31)
			return false;

		if (Date._Month < 1 || Date._Month>12)
			return false;

		if (Date._Month == 2)
		{
			if (IFLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short DayinMonth = NumberOFDaysinMonth(Date._Month, Date.Year);

		if (Date.Day > DayinMonth)
			return false;


		return true;

	}

	sDate StringToDate(string DateString, string Separators = "/")
	{
		sDate Date;
		vector<string> vDate;

		vDate = MyStringAndCharacterLibrary::SplitEachWordInString(DateString, Separators);
		Date.Day = stoi(vDate[0]);
		Date._Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;

	}

	string DataToString(sDate Date, string Separator = "/")
	{

		return  to_string(Date.Day) + Separator + to_string(Date._Month) + Separator + to_string(Date.Year);

	}

	string FormatDate(sDate Date, string DateString = "dd/mm/yyyy")
	{
		string FormattedDateString = "";

		FormattedDateString = MyStringAndCharacterLibrary::ReplaceWordInStringUsingBuiltInFunction(DateString, "dd", to_string(Date.Day));
		FormattedDateString = MyStringAndCharacterLibrary::ReplaceWordInStringUsingBuiltInFunction(FormattedDateString, "mm", to_string(Date._Month));
		FormattedDateString = MyStringAndCharacterLibrary::ReplaceWordInStringUsingBuiltInFunction(FormattedDateString, "yyyy", to_string(Date.Year));

		return FormattedDateString;

	}

	enDateCompare ComperDates(sDate Date1, sDate Date2)
	{
		if (IfDate1IslessThanDate2(Date1, Date2))
			return enDateCompare::Befor;

		if (IfDate1IsEqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;

	}

	bool IfPeriodsIsOverLap(sPeriods Period1, sPeriods Period2)
	{

		if (
			ComperDates(Period2.DateEnd, Period1.DateStart) == enDateCompare::Befor
			||
			ComperDates(Period2.DateStart, Period1.DateEnd) == enDateCompare::After
			)
			return false;
		else
			return true;

		//if (IfDate1IsEqualDate2(Period1.DateStart, Period2.DateStart) || IfDate1IsEqualDate2(Period1.DateEnd, Period2.DateEnd))
		//	return true;

		//if (IfDate1IsBeforThanDate2(Period2.DateStart, Period1.DateStart) && IfDate1AfterDate2(Period2.DateEnd, Period1.DateEnd))
		//return true;

		//if (IfDate1IsBeforThanDate2(Period1.DateStart, Period2.DateStart) && IfDate1AfterDate2(Period1.DateEnd, Period2.DateEnd))
		//	return true;

	/*
		while ((Period1.DateStart.Day) <= (Period1.DateEnd.Day))
		{
			if (ComperDates(Period1.DateStart, Period2.DateStart) == 0)
				return true;

			Period1.DateStart = InceaseDateByOneDay(Period1.DateStart);

		}

		while (Period2.DateStart.Day <= Period2.DateEnd.Day)
		{
			if (ComperDates(Period2.DateStart, Period1.DateStart) == 0)
				return true;

			Period2.DateStart = InceaseDateByOneDay(Period2.DateStart);

		}
	*/


		return false;

	}

	short PeriodLengthInDays(sPeriods Period, bool IncludEndDate = false)
	{
		return GetDiffDate1AndDate2(Period.DateStart, Period.DateEnd, IncludEndDate);
	}

	bool IsDateInPeriod(sPeriods Period, sDate Date)
	{
		return !(ComperDates(Date, Period.DateStart) == enDateCompare::Befor
			||
			ComperDates(Date, Period.DateEnd) == enDateCompare::After);

	}

	int CountOverlapDays(sPeriods Period1, sPeriods Period2)
	{
		short Period1Length = PeriodLengthInDays(Period1, true);
		short Period2Length = PeriodLengthInDays(Period2, true);
		short OverLap = 0;

		if (!IfPeriodsIsOverLap(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length)
		{

			while (IfDate1IslessThanDate2(Period1.DateStart, Period1.DateEnd))
			{
				if (IsDateInPeriod(Period2, Period1.DateStart))
					OverLap++;

				Period1.DateStart = IncreaseDateByOneDay(Period1.DateStart);
			}

		}
		else
		{

			while (IfDate1IslessThanDate2(Period2.DateStart, Period2.DateEnd))
			{
				if (IsDateInPeriod(Period1, Period2.DateStart))
					OverLap++;

				Period2.DateStart = IncreaseDateByOneDay(Period2.DateStart);

			}

		}


		return OverLap;



	}



}



