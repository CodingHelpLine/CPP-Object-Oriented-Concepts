//
// Created by Programmer on 8/25/2022.
//

#include "SavingsAccount.h"


// default constructor
SavingsAccount::SavingsAccount()
: Account(), ir(0.05) { // 5% Interest rate

}

// Parameter constructor
SavingsAccount::SavingsAccount(const int accountNumber)
: Account(accountNumber), ir(0.05) {

}

double SavingsAccount::calcIR() const {
    return balance * ir;
}

void SavingsAccount::applyIR() {
    double interest = balance * ir;
    balance += interest;
}

// overridden methods
bool SavingsAccount::deposit(const double amount) {

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

bool SavingsAccount::withdraw(const double amount) {

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