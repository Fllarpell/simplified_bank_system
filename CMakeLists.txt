cmake_minimum_required(VERSION 3.27)
project(simplified_bank_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(simplified_bank_system main/main.cpp
        accounts/Account.cpp
        accounts/Account.h
        main/include.h
        banking_system/BankingSystem.cpp
        banking_system/BankingSystem.h
        messages/errorMessages/ErrorHandling.cpp
        messages/errorMessages/ErrorHandling.h
        main/operations/OperationsHandling.cpp
        main/operations/OperationsHandling.h
        messages/successfulMessages/SuccessfulMessages.cpp
        messages/successfulMessages/SuccessfulMessages.h
)
