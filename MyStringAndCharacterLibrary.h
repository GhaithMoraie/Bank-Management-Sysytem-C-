#pragma once
#include <iostream>
#include<vector>

using namespace std;

namespace MyStringAndCharacterLibrary {

	char ReadCharacter()
	{
		char C = ' ';

		cout << "Please Enter A Character:\n";
		cin >> C;

		return C;
	}

	string ReadString()
	{
		string Word = "";

		cout << "Please Enter A String:\n";
		getline(cin, Word);

		return Word;
	}

	string LowerAllString(string Word)
	{

		for (int i = 0; i < Word.length(); i++)
		{
			Word[i] = tolower(Word[i]);
		}

		return Word;

	}

	string UpperAllString(string Word)
	{

		for (int i = 0; i < Word.length(); i++)
		{
			Word[i] = toupper(Word[i]);
		}

		return Word;

	}

	string LowerFirstLetterInString(string Word)
	{
		bool FirstLetter = true;

		for (int i = 0; i < Word.length(); i++)
		{
			if (Word[i] != ' ' && FirstLetter)
			{
				Word[i] = tolower(Word[i]);
			}

			FirstLetter = Word[i] == ' ' ? true : false;

		}

		return Word;

	}

	string UpperFirstLetterInString(string Word)
	{
		bool FirstLetter = true;

		for (int i = 0; i < Word.length(); i++)
		{
			if (Word[i] != ' ' && FirstLetter)
			{
				Word[i] = toupper(Word[i]);
			}

			FirstLetter = Word[i] == ' ' ? true : false;

		}

		return Word;

	}

	char InvertCharacter(char Char)
	{
		return isupper(Char) ? tolower(Char) : toupper(Char);

	}

	string InvertAllLetterCase(string Word)
	{

		for (int i = 0; i < Word.length(); i++)
		{

			Word[i] = InvertCharacter(Word[i]);
		}

		return Word;
	}

	short CountCapitalLetter(string Word)
	{
		short Counter = 0;

		for (short i = 0; i < Word.length(); i++)
		{
			if (isupper(Word[i]))
				Counter++;
		}

		return Counter;

	}

	short CountSmallLetters(string Word)
	{
		short Counter = 0;

		for (short i = 0; i < Word.length(); i++)
		{
			if (islower(Word[i]))
				Counter++;
		}

		return Counter;
	}

	bool IfCharacterAVowelORNot(char Char1)
	{
		char Char= tolower(Char1);

		return (Char == 'a') || (Char == 'e') || (Char == 'i') || (Char == 'o') || (Char == 'u');

	}

	int CountVowelsLetterinString(string Word)
	{
		int Count = 0;

		for (int i = 0; i < Word.length(); i++)
		{
			if (IfCharacterAVowelORNot(Word[i]))
				Count++;
		}

		return Count;

	}

	vector<string> SplitEachWordInString(string Word, string delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord;

		while ((pos = Word.find(delim)) != std::string::npos)
		{

			sWord = Word.substr(0, pos);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			Word.erase(0, pos + delim.length());

		}

		if (Word != "")
		{
			vString.push_back(Word);
		}

		return vString;

	}

	string TrimLeft(string Word)
	{

		for (short i = 0; i < Word.length(); i++)
		{
			if (Word[i] != ' ')
				return Word.substr(i, Word.length() - i);
		}

		return "";
	}

	string TrimRight(string Word)
	{

		for (short i = Word.length() - 1; i >= 0; i--)
		{
			if (Word[i] != ' ')
				return Word.substr(0, i + 1);
		}

		return " ";

	}

	string Trim(string Word)
	{
		return (TrimLeft(TrimRight(Word)));
	}

	string JoinString(vector<string> vString, string delimi)
	{

		string S1 = "";

		for (string& W : vString)
		{
			S1 = S1 + W + delimi;
		}

		return S1.substr(0, S1.length() - delimi.length());

	}
	
	string JoinString(string arr[], short Length, string delimi)
	{
		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 += arr[i] + delimi;
		}

		return S1.substr(0, S1.length() - delimi.length());

	}

	string ReversingWord(string Word, string delimi)
	{

		vector<string> vString = SplitEachWordInString(Word, delimi);
		vector<string>::iterator itr = vString.end();
		string S1 = "";


		while (itr != vString.begin())
		{
			--itr;
			S1 += *itr + delimi;
		}

		return S1.substr(0, S1.length() - delimi.length());

	}

	string ReplaceWordInStringUsingBuiltInFunction(string Word, string StringToReplace, string sReplaceTo)
	{

		short Pos = Word.find(StringToReplace);

		while (Pos != std::string::npos)
		{
			Word = Word.replace(Pos, StringToReplace.length(), sReplaceTo);
			Pos = Word.find(StringToReplace);
		}

		return Word;
	}

	string ReplaceWordUsingCustomWithMAtchCase(string Word, string StringToReplace, string sReplaceTo, bool MAtchCase = true)
	{
		vector<string> vString = SplitEachWordInString(Word, " ");

		for (string& W : vString)
		{
			if (MAtchCase)
			{
				if (W == StringToReplace)
					W = sReplaceTo;
			}
			else
			{
				if (LowerAllString(W) == LowerAllString(StringToReplace))
					W = sReplaceTo;
			}

		}

		return JoinString(vString, " ");

	}


}