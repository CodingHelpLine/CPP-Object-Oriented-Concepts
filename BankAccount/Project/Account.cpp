//
// Created by Programmer on 8/25/2022.
//

#include "Account.h"

// Default constructor
Account::Account()
: accountNumber(0), balance(0)
{

}

// Parameter Constructor
Account::Account(const int accountNumber) {
    this->accountNumber = accountNumber;
    this->balance = 0;
}

// Getter functions
int Account::getAccountNumber() const { // constant - readonly access
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

// Setter functions
void Account::setAccountNumber(const int accountNumber) { // update account number
    this->accountNumber = accountNumber;
}


// Function to transfer funds from one account to another.
bool Account::transfer(Account * account, const double amount) {

    // check balance is sufficient
    if(balance >= amount) {

        // update current balance
        balance -= amount;

        // add to transfer account
        account->deposit(amount);

        return true;
    }

    return false;

}

