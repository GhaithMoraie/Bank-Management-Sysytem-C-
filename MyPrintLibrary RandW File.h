#pragma once
#include <iostream>
#include"MyInPutLibrary.h";
#include"MyMathLibrary.h";
#include<vector>

using namespace std;

namespace MyPrintLibrary
{

	void PrintPrimeNumber(int number)
	{
		cout << "\n";
		cout << "The Prime Number From " << 1 << " To " << number << " Are:" << endl;
		
		for (int i = 1; i <= number; i++)
		{

			if (MyMathLibrary::CheckNumberPrime(i) == PrimeNumber::Prime)
			{
				cout << i << endl;
			}

		}

	}

	void PrintAllDigitFrequncy(int number)
	{

		for (int i = 0; i < 10; i++)
		{
			short DigitFrequency = 0;
			DigitFrequency = MyMathLibrary::CountDigitsFrequency(i, number);

			if (DigitFrequency > 0)
			{
				cout << "Digit " << i << " Frequency is " << DigitFrequency << " Times" << endl;

			}

		}


	}

	void PrintVectirNumber(vector <int> vNumber)
	{

		cout << "\nVectro Number: " << endl;

		for (int& Number : vNumber)
		{
			cout << Number << " ";
		}

		cout << endl;
	}

	


}
