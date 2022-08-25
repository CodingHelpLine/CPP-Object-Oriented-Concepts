//
// Created by Programmer on 8/25/2022.
//

#ifndef PROJECT_ACCOUNT_H
#define PROJECT_ACCOUNT_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

class Account {

public:

    // Default constructor
    Account();

    // Parameter Constructor
    Account(const int);

    // Getter functions
    int getAccountNumber() const; // constant - readonly access
    double getBalance() const;

    // Setter functions
    void setAccountNumber(const int); // update account number

    // Pure virtual methods
    virtual bool deposit(const double) = 0; // abstract method
    virtual bool withdraw(const double) = 0; // abstract method

    // Function to transfer funds from one account to another.
    bool transfer(Account *, const double);

private:
    int accountNumber;

protected:
    double balance;

};

#endif //PROJECT_ACCOUNT_H
