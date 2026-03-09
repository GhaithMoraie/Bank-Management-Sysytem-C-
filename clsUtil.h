#pragma once
#include <iostream>
#include <string>
#include"clsDate.h";

using namespace std;

class clsUtil
{

public:

	static const string RED;
	static const string GREEN;
	static const string YELLOW;
	static const string BLUE;
	static const string MAGENTA;
	static const string CYAN;
	static const string RESET;

	enum enCharacteTyper { SmallLetter = 1, CapitalLetter = 2, Digit = 3, MixChars = 4, SpecialCharacter = 5 };

	static void Srand()
	{
		srand((unsigned)time(NULL));

	}

	static int RandomNumber(int from, int to)
	{

		int randNum = rand() % (to - from + 1) + from;
		return randNum;

	}

	static int CountOfPositiveNumbers(int arr[100], int arrlength)
	{

		int Counter = 0;

		for (int i = 0; i < arrlength; i++)
		{
			if (arr[i] >= 0)
			{
				Counter++;
			}
		};

		return Counter;

	}

	static int CountOfNegativeNumbers(int arr[100], int arrlength)
	{

		int Counter = 0;

		for (int i = 0; i < arrlength; i++)
		{
			if (arr[i] < 0)
			{
				Counter++;
			}
		};

		return Counter;

	}

	static int ReverseNumber(int number)
	{

		int Remainder = 0, number2 = 0;

		while (number > 0)
		{

			Remainder = number % 10;
			number /= 10;
			number2 = number2 * 10 + Remainder;

		}

		return number2;

	}

	static int	CountDigitsFrequency(short DigitCheck, int number)
	{
		int FreqCount = 0, Remainder = 0;

		while (number > 0)
		{
			Remainder = number % 10;
			number /= 10;

			if (Remainder == DigitCheck)
				FreqCount++;
		}

		return FreqCount;
	}

	static int CountOfOddNumbers(int arr[100], int arrlength)
	{

		int Counter = 0;

		for (int i = 0; i < arrlength; i++)
		{
			if (arr[i] % 2 != 0)
			{
				Counter++;
			}
		};

		return Counter;

	}

	static bool IsArrayPalindom(int arr[100], int arrlength)
	{

		for (int i = 0; i < arrlength; i++)
		{
			if (arr[i] != arr[arrlength - i - 1])
			{
				return false;
			}

		};

		return true;

	}

	static char GetRandomCharacter(enCharacteTyper CharType)
	{
		if (CharType == MixChars)
		{
			CharType = (enCharacteTyper)(RandomNumber(1, 3));
		}

		switch (CharType)
		{
		case enCharacteTyper::CapitalLetter:
		{
			return (char)RandomNumber(65, 90);
			break;
		}
		case enCharacteTyper::SmallLetter:
		{
			return (char)RandomNumber(97, 122);
			break;
		}
		case enCharacteTyper::Digit:
		{
			return (char)RandomNumber(48, 57);
			break;
		}
		case enCharacteTyper::SpecialCharacter:
		{
			return (char)RandomNumber(33, 47);
			break;
		}
	defualt:
		{
			return char(RandomNumber(65, 90));
			break;
		}

		}

	}

	static  string GenerateWord(enCharacteTyper CharType, short Length)

	{
		string Word;

		for (int i = 1; i <= Length; i++)

		{

			Word = Word + GetRandomCharacter(CharType);

		}
		return Word;
	}

	static string GenerateKey(enCharacteTyper CharType)
	{

		string Key;

		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);

		return Key;
	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
		}
		return t;

	}

	static string EncryptText(string Text, short EncryptionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}

		return Text;

	}

	static string DecryptText(string Text, short EncryptionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);

		}

		return Text;

	}

	static void GenerateKeys(int number,enCharacteTyper Chartype)
	{

	for (int i = 1; i <= number; i++)
	{
		cout << "Key[" << i << "]: ";

		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				cout<<GetRandomCharacter(Chartype);
			}
			if (j >= 1 && j < 4) {
				cout << "-";
			}
		}
		cout << endl;
	}

}

	static void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string& S1, string& S2)
	{
		string Temp;

		Temp = S1;
		S1 = S2;
		S2 = Temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp;

		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	static void ShuffelArray(int arr[100], int arrlength)
	{
		for (int i = 0; i < arrlength; i++)
		{
			swap(arr[RandomNumber(1, arrlength) - 1], arr[RandomNumber(1, arrlength) - 1]);
		}
	}

	static void ShuffelArray(string arr[100], int arrlength)
	{
		for (int i = 0; i < arrlength; i++)
		{
			swap(arr[RandomNumber(1, arrlength) - 1], arr[RandomNumber(1, arrlength) - 1]);
		}
	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrlenght, int From, int To)
	{

		for (int i = 0; i < arrlenght; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	
	}

	static void FillArrayWithRandomWords(string arr[100], int NumberofWords, enCharacteTyper CharType, int WordLength)
	{

		for (int i = 0; i < NumberofWords; i++)
		{

			arr[i] = GenerateWord(CharType, WordLength);

		}

	}

	static void FillArrayWithRandomKeys(string arr[100], int numberKeys, enCharacteTyper CharType)
	{

		for (int i = 0; i < numberKeys; i++)
		{

			arr[i] = GenerateKey(CharType);

		}

	}

	static void PrintArray(int arr[100], int arrlenght)
	{

		for (int i = 0; i < arrlenght; i++)
		{
			cout << arr[i] << " ";
		}

		cout << "\n";

	}

	static void PrintInvertedlatter(int number)
	{
		for (int i = 65 + number - 1; i >= 65; i--)
		{
			for (int j = 1; j <= number - (65 + number - 1 - i); j++)
			{
				cout << char(i);


			}
			cout << endl;
		}
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

};

const string clsUtil::RED = "\033[31m";
const string clsUtil::GREEN = "\033[32m";
const string clsUtil::YELLOW = "\033[33m";
const string clsUtil::BLUE = "\033[34m";
const string clsUtil::MAGENTA = "\033[35m";
const string clsUtil::CYAN = "\033[36m";
const string clsUtil::RESET = "\033[0m";