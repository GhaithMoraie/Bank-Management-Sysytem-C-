#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

using namespace std;

class clsLogTransferScreen :protected clsScreen
{


private:
	static void _PrintTransferRecordLine(clsBankClient::stLogTransferRecord Record)
	{

		cout << setw(8) << left << "" << "| " << setw(22) << left << Record.DateandTime;
		cout << "| " << setw(10) << left << Record.SourceClient;
		cout << "| " << setw(10) << left << Record.DestinationClient;
		cout << "| " << setw(12) << left << to_string(Record.Amount);
		cout << "| " << setw(12) << left << to_string(Record.SourceBalance);
		cout << "| " << setw(12) << left << to_string(Record.DestnationBalance);
		cout << "| " << setw(8) << left << Record.UserName;

	}

public:

	static void ShowTransferList()
	{
		vector <clsBankClient::stLogTransferRecord> vLogTransferRecord = clsBankClient::GetLogTransferList();
		string Title = "\t  Transfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vLogTransferRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(22) << "Date/Time";
		cout << "| " << left << setw(10) << "S.Account";
		cout << "| " << left << setw(10) << "D.Account";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(12) << "S.Balance";
		cout << "| " << left << setw(12) << "D.Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vLogTransferRecord.size() == 0)
			cout << "\t\t\t\tNo Record Available In the System!";
		else

			for (clsBankClient::stLogTransferRecord &Record : vLogTransferRecord)
			{

				_PrintTransferRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}














};