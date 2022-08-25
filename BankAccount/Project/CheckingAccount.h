//
// Created by Programmer on 8/25/2022.
//

#ifndef PROJECT_CHECKINGACCOUNT_H
#define PROJECT_CHECKINGACCOUNT_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

#include "Account.h"

class CheckingAccount : public Account {

public:

    // Default constructor
    CheckingAccount();

    // Parameter constructor
    CheckingAccount(const int); // account number

    // overridden methods
    virtual bool deposit(const double);
    virtual bool withdraw(const double);

};


#endif //PROJECT_CHECKINGACCOUNT_H
