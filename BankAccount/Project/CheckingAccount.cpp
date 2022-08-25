//
// Created by Programmer on 8/25/2022.
//

#include "CheckingAccount.h"

// Default constructor
CheckingAccount::CheckingAccount()
: Account() {

}

// Parameter constructor
CheckingAccount::CheckingAccount(const int accountNUmber)
: Account(accountNUmber) { // account number

}

// overridden methods
bool CheckingAccount::deposit(const double amount) {

    if(amount <= 0) {
        cout << "ERROR: The deposit amount must be a positive value" << endl;
        return false;
    }

    // update balance
    balance += amount;

    cout << "Account has been credited $" << amount << endl;
    cout << "Current Balance: $" << balance << endl;
    return true;
}

bool CheckingAccount::withdraw(const double amount) {

    // must be positive value
    if(amount <= 0) {
        cout << "ERROR: The Withdraw amount must be a positive value" << endl;
        return false;
    }

    // Sufficient valance
    if(amount <= balance) {

        balance -= amount;

        cout << "Withdrawal of $" << amount << " has been made." << endl;
        cout << "Current Balance: $" << balance << endl;
        return true;
    }

    cout << "Balance is not sufficient to withdraw $" << amount << endl;
    cout << "Current Balance: $" << balance << endl;
    return false;
}