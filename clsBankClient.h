#pragma once
#include <iostream>
#include <string>
#include"clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum  enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;


	struct stLogTransferRecord;
	static stLogTransferRecord _ConverLogInRegistertoRecord(string Line, string Seperator = "#//#")
	{
		vector<string> LoginRegisterDataLine;
		LoginRegisterDataLine = clsString::Split(Line, Seperator);
		stLogTransferRecord Register;

		Register.DateandTime = LoginRegisterDataLine[0];
		Register.SourceClient = LoginRegisterDataLine[1];
		Register.DestinationClient = LoginRegisterDataLine[2];
		Register.Amount = stof(LoginRegisterDataLine[3]);
		Register.SourceBalance = stof(LoginRegisterDataLine[4]);
		Register.DestnationBalance = stof(LoginRegisterDataLine[5]);
		Register.UserName = LoginRegisterDataLine[6];

		return Register;

	}

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;

		vClientData = clsString::Split(Line, Seperator);
		// «–« ﬂ«‰Ê ⁄œœ «·⁄‰«’— «ﬁ· „‰7 ·«‰Ê »ÃÊ“ ÌﬂÊ‰ ›Ì Œÿ« »«·„·› › »ÂÌ «·Õ«·… »⁄„· ﬂ·«Ì‰  ›«÷Ì
		//if (vClientData.size() < 7)
		//	return _GetClientEmpty();

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3]
			, vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static  vector <clsBankClient> _LoadUsersDataFromFile()
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient& C : vClients)
			{
				if (C.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadUsersDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);

	}

	void _Add()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsBankClient _GetEmptyUserObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareTransferLogRecord(clsBankClient DestinationClient, float Amount, string CurrentUserName, string Seperater = "#//#")
	{
		string LogTransfer = "";

		LogTransfer += clsDate::GetSystemDateAndTime() + Seperater;
		LogTransfer += AccountNumber() + Seperater;
		LogTransfer += DestinationClient.AccountNumber() + Seperater;
		LogTransfer += to_string(Amount) + Seperater;
		LogTransfer += to_string(AccountBalance) + Seperater;
		LogTransfer += to_string(DestinationClient.AccountBalance) + Seperater;
		LogTransfer += CurrentUserName;

		return LogTransfer;
	}

	void _RegisterTransferLog(clsBankClient DestinationClient, float Amount, string UserName)
	{
		string DataLine = _PrepareTransferLogRecord(DestinationClient, Amount, UserName);

		fstream Myfile;
		Myfile.open("TransferLog.txt", ios::out | ios::app);

		if (Myfile.is_open())
		{
			Myfile << DataLine << endl;
			Myfile.close();
		}


	}

public:
	struct stLogTransferRecord
	{
		string DateandTime;
		string SourceClient;
		string DestinationClient;
		float Amount;
		float SourceBalance;
		float DestnationBalance;
		string UserName;
	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	void SetPIN(string PinCode)
	{
		this->_PinCode = PinCode;
	}

	string GetPIN()
	{
		return _PinCode;
	}

	_declspec(property(get = GetPIN, put = SetPIN))string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		this->_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	_declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	static clsBankClient  Find(string AccountNumber)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;
			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();


	}

	static clsBankClient  Find(string AccountNumber, string PINCode)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.GetPIN() == PINCode)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();


	}

	static clsBankClient GetAddNewClientObject(string Accountnumber)
	{
		return clsBankClient(enMode::AddNew, "", "", "", "", Accountnumber, "", 0);
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildClientNameExists = 2 };

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceeded;

			break;
		}
		case enMode::AddNew:
		{
			if (IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildClientNameExists;
			}

			_Add();

			_Mode = enMode::UpdateMode;
			return enSaveResults::svSucceeded;

		}

		}



	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);

		return(!(Client.IsEmpty()));
	}

	bool IsClientDelete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadUsersDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;

				_SaveCleintsDataToFile(_vClients);
				*this = _GetEmptyUserObject();

				return true;
			}
		}
		return false;
	}

	static vector < clsBankClient > GetClientsList()
	{
		return _LoadUsersDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClient = GetClientsList();

		double TotalBalance = 0;

		for (clsBankClient& C : vClient)
		{
			TotalBalance += C.AccountBalance;
		}

		return TotalBalance;

	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool TransferMoney(clsBankClient &DestinationClient, double Amount,string UserName)
	{
		if (Amount > AccountBalance)
			return false;
		else
		{
			Withdraw(Amount);
			DestinationClient.Deposit(Amount);
			_RegisterTransferLog(DestinationClient, Amount, UserName);
			return true;
		}
	}
	
	static vector<stLogTransferRecord> GetLogTransferList()
	{
		vector<stLogTransferRecord> vRegister;

		fstream Myfile;
		Myfile.open("TransferLog.txt", ios::in);

		if (Myfile.is_open())
		{
			string Line;
			stLogTransferRecord TransferRecord;

			while (getline(Myfile, Line))
			{
				TransferRecord = _ConverLogInRegistertoRecord(Line);
				vRegister.push_back(TransferRecord);
			}
		
			Myfile.close();
		}


		return vRegister;

	}


















};