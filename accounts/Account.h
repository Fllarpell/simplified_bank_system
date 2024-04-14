#include "../main/include.h"
#include "../messages/errorMessages/ErrorHandling.h"

#ifndef SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H
#define SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H

namespace Account {

    class AccountFunctions;
    class Account;
    class DecoratorAccount;
    class SavingAccount;
    class CheckingAccount;
    class BusinessAccount;

    static std::map<std::string, AccountFunctions*> accountMap;


    class AccountFunctions {
    public:
        virtual void withdraw(float withdrawalAmount) = 0;
        virtual void transfer(AccountFunctions *toAccount, float transferAmount) = 0;
        virtual void deposit(float depositAmount) = 0;
        virtual float getBalance() = 0;
        virtual void setBalance(float newBalance) = 0;
        virtual std::map<std::string, float> getHistory() = 0;
        virtual std::string getAccountName() = 0;
        virtual std::string getAccountType() = 0;
        virtual float getTransactionFeePercentage() = 0;
    };


    class Account : public AccountFunctions {
    public:
        Account(const std::string& accountType, const std::string& accountName, float initialDeposit);
        virtual ~Account() = default;

        void withdraw(float withdrawalAmount) override;

        void transfer(AccountFunctions *toAccount, float transferAmount) override;

        void deposit(float depositAmount) override;

        float getBalance() override;

        void setBalance(float newBalance) override;

        std::map<std::string, float> getHistory() override;

        std::string getAccountName() override;

        std::string getAccountType() override;

        float getTransactionFeePercentage() override;

    private:
        std::map<std::string, float> history;

        std::string accountName;
        std::string accountType;
        float balance;
    };


    class DecoratorAccount : public AccountFunctions {
    public:
        AccountFunctions *acc;

        explicit DecoratorAccount(AccountFunctions *a);

        void withdraw(float withdrawalAmount) override;

        void transfer(AccountFunctions *toAccount, float transferAmount) override;

        void deposit(float depositAmount) override;

        float getBalance() override;

        void setBalance(float newBalance) override;

        std::map<std::string, float> getHistory() override;

        std::string getAccountName() override;

        std::string getAccountType() override;

        float getTransactionFeePercentage() override;

    };


    class SavingAccount : public DecoratorAccount {
    public:
        explicit SavingAccount(Account* account) : DecoratorAccount(account) {}

        void withdraw(float withdrawalAmount) override;

        void transfer(AccountFunctions *toAccount, float transferAmount) override;

        void deposit(float depositAmount) override;

        float getBalance() override;

        void setBalance(float newBalance) override;

        std::map<std::string, float> getHistory() override;

        std::string getAccountName() override;

        std::string getAccountType() override;

        float getTransactionFeePercentage() override;

    private:
        float const transactionFeePercentage = 0.015;
    };


    class CheckingAccount : public DecoratorAccount {
    public:
        explicit CheckingAccount(Account* account) : DecoratorAccount(account) {}

        void withdraw(float withdrawalAmount) override;

        void transfer(AccountFunctions *toAccount, float transferAmount) override;

        void deposit(float depositAmount) override;

        float getBalance() override;

        void setBalance(float newBalance) override;

        std::map<std::string, float> getHistory() override;

        std::string getAccountName() override;

        std::string getAccountType() override;

        float getTransactionFeePercentage() override;

    private:
        float transactionFeePercentage = 0.020;
    };


    class BusinessAccount : public DecoratorAccount {
    public:
        explicit BusinessAccount(Account* account) : DecoratorAccount(account) {}

        void withdraw(float withdrawalAmount) override;

        void transfer(AccountFunctions *toAccount, float transferAmount) override;

        void deposit(float depositAmount) override;

        float getBalance() override;

        void setBalance(float newBalance) override;

        std::map<std::string, float> getHistory() override;

        std::string getAccountName() override;

        std::string getAccountType() override;

        float getTransactionFeePercentage() override;

    private:
        float transactionFeePercentage = 0.025;
    };
}


#endif //SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H
