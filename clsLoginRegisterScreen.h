#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{

private:
	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(40) << left << LoginRecord.DateandTime;
		cout << "| " << setw(18) << left << LoginRecord.UserName;
		cout << "| " << setw(18) << left << LoginRecord.Password;
		cout << "| " << setw(15) << left << to_string(LoginRecord.Permission);

	}

public:

	static void ShowLoginRegisterList()
	{

		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pLoginRegister))
			return;

		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "\t  Login Register List Screen";
		string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(40) << "Date/Time";
		cout << "| " << left << setw(18) << "UserName";
		cout << "| " << left << setw(18) << "Password";
		cout << "| " << left << setw(15) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Record Available In the System!";
		else

			for (clsUser::stLoginRegisterRecord &Record : vLoginRegisterRecord)
			{

				_PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}

};


