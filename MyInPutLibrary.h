#include <iostream>
#pragma once

using namespace std;

namespace MyInputLibrary
{
	int ReadPositiveNumber(string massage)
	{

		int number = 0;
		do
		{
			cout << massage << endl;
			cin >> number;

		} while (number < 0);

		return number;

	}

	int ReadIntNumber(string massage)
	{
		int number = 0;
		
		cout << massage;
		cin >> number;

		return number;

	}

	int ReadOnlyNumber()
	{
		int Number;
		cout << "Please Enter Number : " << endl;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid InPut, Enter A Valid one: " << endl;
			cin >> Number;

		}

		return Number;

	}

	void ReadNumberInVector(vector <int>& vNumber)
	{
		char Again = 'y';
		int Number = 0;

		do
		{
			cout << "\nPlease Enter A Number in Vector: ";
			cin >> Number;
			vNumber.push_back(Number);

			cout << "\nDo You Want To Add More Numbers?  Y / N\n";
			cin >> Again;

		} while (Again == 'y' || Again == 'Y');


	}



}

