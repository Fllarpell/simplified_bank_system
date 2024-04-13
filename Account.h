#include "include.h"

#ifndef SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H
#define SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H

namespace Account {

    class Account {
    public:
        Account(const std::string& accountName, float initialDeposit) {
            this->accountName = accountName;
            this->balance = initialDeposit;
        }
        virtual ~Account() {}
        virtual void deposit(float depositAmount) {
            this->balance += depositAmount;
        };
        virtual void withdraw(float withdrawalAmount) = 0;
        virtual void transfer(std::string toAccountName, float transferAmount) = 0;
        virtual void view() {}
        virtual void deactivate() {}
        virtual void activate() {}
        virtual std::string getAccountName() {
            return this->accountName;
        }

    private:
        std::string accountName;
        float balance;
    };

    class SavingAccount : virtual public Account {
    public:
        SavingAccount(const std::string& accountName, float initialDeposit) : Account(accountName, initialDeposit) {}
        void withdraw(float withdrawalAmount) override {

        }
    private:
        float transactionFeePercentage = 1.5;
    };

    class CheckingAccount : virtual public Account {
    public:
        CheckingAccount(const std::string& accountName, float initialDeposit) : Account(accountName, initialDeposit) {}
        void withdraw(float withdrawalAmount) override {

        }
    private:
        float transactionFeePercentage = 2.0;
    };

    class BusinessAccount : virtual public Account {
    public:
        BusinessAccount(const std::string& accountName, float initialDeposit) : Account(accountName, initialDeposit) {}
        void withdraw(float withdrawalAmount) override {

        }
    private:
        float transactionFeePercentage = 2.5;
    };

}



#endif //SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H
