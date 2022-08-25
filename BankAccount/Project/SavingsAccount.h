//
// Created by Programmer on 8/25/2022.
//

#ifndef PROJECT_SAVINGSACCOUNT_H
#define PROJECT_SAVINGSACCOUNT_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

#include "Account.h"


class SavingsAccount : public Account {

public:

    // default constructor
    SavingsAccount();

    // Parameter constructor
    SavingsAccount(const int);

    // overridden methods
    virtual bool deposit(const double);
    virtual bool withdraw(const double);

    double calcIR() const;
    void applyIR();

private:
        double ir;

};


#endif //PROJECT_SAVINGSACCOUNT_H
