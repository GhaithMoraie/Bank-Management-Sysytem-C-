#pragma once

#include <iostream>
using namespace std;

enum PrimeNumber { Prime = 1, notprime = 2 };


namespace MyMathLibrary
{

	PrimeNumber CheckNumberPrime(int number)
	{
		int M = round(number / 2);
		for (int counter = 2; counter <= M; counter++)
		{
			if (number % counter == 0)
				return PrimeNumber::notprime;
		}

		return PrimeNumber::Prime;

	}

	int	CountDigitsFrequency(short DigitCheck, int number)
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

	int RandomNumber(int from, int to)
	{

		int randNum = rand() % (to - from + 1) + from;
		return randNum;

	}



}
