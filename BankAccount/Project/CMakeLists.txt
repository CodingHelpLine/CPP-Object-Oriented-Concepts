cmake_minimum_required(VERSION 3.12)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp Account.cpp Account.h SavingsAccount.cpp SavingsAccount.h CheckingAccount.cpp CheckingAccount.h Bank.cpp Bank.h)