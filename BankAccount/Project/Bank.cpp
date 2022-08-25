//
// Created by Programmer on 8/25/2022.
//

#include "Bank.h"

// static field initialize
int Bank::nextAccountNumber = 1000;

// Add function
void Bank::addAccount(Account * account) {
    accounts.push_back(account);
}

Account * Bank::getAccount(const int accountNumber) {

    for(size_t i=0; i<accounts.size(); i++) {
        if(accounts[i]->getAccountNumber() == accountNumber) {
            return accounts[i];
        }
    }

    return nullptr;

}

bool Bank::deposit(const int accountNumber, const double amount) {
    // Get object
    Account * account = getAccount(accountNumber);

    if(account != nullptr) {
        return account->deposit(amount);
    }

    return false;

}

bool Bank::withdraw(const int accountNumber, const double amount) {

    // Get object
    Account * account = getAccount(accountNumber);

    if(account != nullptr) {
        return account->withdraw(amount);
    }

    return false;
}

bool Bank::transfer(const int first, const int second, const double amount) {

    // find objects
    Account * from = getAccount(first);
    Account * to = getAccount(second);

    // check both are valid objects
    if(from != nullptr && to != nullptr) {
        return from->transfer(to, amount);
    }

    return false; // some account is not valid
}

int Bank::getNextAccountNumber() {
    Bank::nextAccountNumber += 1;
    return Bank::nextAccountNumber;
}