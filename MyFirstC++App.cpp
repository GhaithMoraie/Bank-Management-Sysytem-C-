#pragma warning(disable:4996)
#include<ctime>
#include <iostream>
#include<string>
#include<cctype>
#include <cmath>
#include<cstdlib>
#include <time.h>
#include<iomanip>
#include<vector>
#include<fstream>
#include"clsDate.h"
#include"clsString.h";
#include"clsPeriod.h";
#include"clsUtil.h";
#include"clsInputValidate.h";
#include"clsBankClient.h"
#include"clsMainScreen.h";
#include"clsUser.h"
#include"clsLoginScreen.h"

using namespace std;

int main()

{
	//clsMainScreen::ShowMainMenue();
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
			break;
	}
	
	

	//system("pause>0");

	return 0;

}
