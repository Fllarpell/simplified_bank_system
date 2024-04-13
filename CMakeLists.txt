cmake_minimum_required(VERSION 3.27)
project(simplified_bank_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(simplified_bank_system main.cpp
        Account.cpp
        Account.h
        include.h
        BankingSystem.cpp
        BankingSystem.h
        ErrorHandling.cpp
        ErrorHandling.h)
