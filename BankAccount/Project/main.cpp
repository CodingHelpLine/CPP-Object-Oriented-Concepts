#include <iostream>
#include <cstdlib>

#include "Account.h"
#include "Bank.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

// Function prototypes

//-----------------------------------------------------
// Name: menu()
// Display the menu to the user and get option
//-----------------------------------------------------
int menu();

//-----------------------------------------------------
// Name: create()
// Create Object and add to the Bank
//-----------------------------------------------------
void createAccount(Bank & bank);

//-----------------------------------------------------
// Name: deposit()
// Deposit amount to an account
//-----------------------------------------------------
void deposit(Bank &);

//-----------------------------------------------------
// Name: withdraw()
// Withdraw amount to an account
//-----------------------------------------------------
void withdraw(Bank &);

//-----------------------------------------------------
// Name: transfer()
// Transfer amount to an account
//-----------------------------------------------------
void transfer(Bank &);

//-----------------------------------------------------
// Name: checkBalance()
// Check account balance
//-----------------------------------------------------
void checkBalance(Bank &);

//-----------------------------------------------------
// Name: main()
// Entry point of the program.
//-----------------------------------------------------
int main() {

    // Declare Bank class object
    Bank bank;

    // user option
    int option;

    do
    {
        // Call menu
        option = menu();

        if(option == 1) { // create object
            createAccount(bank);
        } else if(option == 2) { // Check Balance
            checkBalance(bank);
        } else if(option == 3) { // Deposit
            deposit(bank);
        } else if(option == 4) { // Withdraw
            withdraw(bank);
        } else if(option == 5) { // Transfer
            transfer(bank);
        } else if(option == 0) { // Exit
            cout << "Thank you for using Bank App!" << endl;
        }

        cout << endl;

    } while(option != 0);

    return 0;
}

int menu() {

    int option;

    do {
        cout << "\t\tWelcome to Bank Alpha" << endl;
        cout << "\t\t1. Create An Account" << endl;
        cout << "\t\t2. Check Balance" << endl;
        cout << "\t\t3. Deposit" << endl;
        cout << "\t\t4. Withdraw" << endl;
        cout << "\t\t5. Transfer" << endl;
        cout << "\t\t0. Exit" << endl;
        cout << endl;
        cout << "Enter Option: ";
        cin >> option;

        if(option < 0 || option > 5) {
            cout << "ERROR: Invalid input - try again" << endl;
        }

    } while(option < 0 || option > 5);

    cout << endl;

    return option;
}

//-----------------------------------------------------
// Name: create()
// Create Object and add to the Bank
//-----------------------------------------------------
void createAccount(Bank & bank) {

    Account * account = nullptr;
    int choice = 0;

    do {
        // ask for type
        cout << "Select Account Type" << endl;
        cout << "1. Checking Account" << endl;
        cout << "2. Savings Account" << endl;
        cout << "3. Return to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice < 1 || choice > 3) {
            cout << "ERROR: Invalid choice - try again" << endl;
        }

    } while(choice < 1 || choice > 3);

    cout << endl;

    if(choice == 1 || choice == 2) {

        int accountNumber = bank.getNextAccountNumber();

        if(choice == 1) {
            account = new CheckingAccount(accountNumber);
            cout << "Checking account has been created with Account Number: " << accountNumber << endl;
        } else {
            account = new SavingsAccount(accountNumber);
            cout << "Checking account has been created with Account Number: " << accountNumber << endl;
        }

        bank.addAccount(account);
    }
}

//-----------------------------------------------------
// Name: deposit()
// Deposit amount to an account
//-----------------------------------------------------
void deposit(Bank & bank) {

    int accountNumber;
    double amount;

    // get account number
    cout << "Please enter account number: ";
    cin >> accountNumber;

    // get Amount
    cout << "Enter Deposit Amount: ";
    cin >> amount;

    // Call function from bank
    if(bank.deposit(accountNumber, amount)) {
        cout << "Transaction is Successful!" << endl;
    } else {
        cout << "Transaction is failed!" << endl;
    }
}

//-----------------------------------------------------
// Name: withdraw()
// Withdraw amount to an account
//-----------------------------------------------------
void withdraw(Bank & bank) {
    int accountNumber;
    double amount;

    // get account number
    cout << "Please enter account number: ";
    cin >> accountNumber;

    // get Amount
    cout << "Enter Withdraw Amount: ";
    cin >> amount;

    // Call function from bank
    if(bank.withdraw(accountNumber, amount)) {
        cout << "Transaction is Successful!" << endl;
    } else {
        cout << "Transaction is failed!" << endl;
    }
}

//-----------------------------------------------------
// Name: transfer()
// Transfer amount to an account
//-----------------------------------------------------
void transfer(Bank & bank) {
    int accountNumberFrom;
    int accountNumberTo;
    double amount;

    // get account number from account
    cout << "Please enter account number of From Account: ";
    cin >> accountNumberFrom;

    cout << "please enter account number to transfer amount: ";
    cin >> accountNumberTo;

    // get Amount
    cout << "Enter Transfer Amount: ";
    cin >> amount;

    // Call function from bank
    if(bank.transfer(accountNumberFrom, accountNumberTo, amount)) {
        cout << "Transaction is Successful!" << endl;
    } else {
        cout << "Transaction is failed!" << endl;
    }
}

//-----------------------------------------------------
// Name: checkBalance()
// Check account balance
//-----------------------------------------------------
void checkBalance(Bank & bank) {
    int accountNumber;

    // get account number
    cout << "Please enter account number: ";
    cin >> accountNumber;

    Account * account = bank.getAccount(accountNumber);

    if(account != nullptr) {
        cout << "Your account balance is: $" << account->getBalance() << endl;
    } else {
        cout << "No Such account exist with account number: " << accountNumber << endl;
    }


}