# Bank Management System (C++)

A simple Command-Line Interface (CLI) Bank Management System written in C++.  

This system allows managing customer accounts, performing deposits and withdrawals, and viewing account details easily. It is designed for educational purposes and demonstrates basic banking operations in a console application.

## Features

- Create New Accounts: Add a new customer with personal details and initial balance.  

- Deposit Money: Add funds to an existing account.  

- Withdraw Money: Withdraw funds from an account if sufficient balance is available.  

- View Account Information: Check account details including current balance.  

- Simple CLI Interface: Navigate easily using console menus.  

- Persistent Data Storage: All account data is stored in text files (Users.txt, Clients.txt).  

## Project Structure

`text

Bank-Management-Sysytem-C-/


├── main.cpp        → Main program, runs the CLI menus

├── Account.cpp     → Handles account creation and management

├── Transaction.cpp → Handles deposits and withdrawals

├── Global.h        → Global variables and settings

├── Users.txt       → Stores user credentials (if applicable)

├── Clients.txt     → Stores client account data

├── README.md       → Project explanation and instructions (this file)

#How to Run

1.Clone the repository

git clone https://github.com/GhaithMoraie/Bank-Management-Sysytem-C-.git⁠�

2.Compile the code (requires C++ compiler)

g++ *.cpp -o BankApp

3.Run the program

./BankApp

After running, follow the on-screen menus to interact with the bank system.

#Future Improvements

-Add detailed transaction history for each account.

-Integrate a database (e.g., SQLite) for better data management.

-Implement a Graphical User Interface (GUI) for easier navigation.

-Add enhanced user/admin permissions.

#License

This project is licensed under the MIT License (or any license you prefer).
