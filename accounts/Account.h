#include "../main/include.h"
#include "../messages/errorMessages/ErrorHandling.h"

#ifndef SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H
#define SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H

namespace Account {

    class AccountFunctions;
    class Account;
    class StateActivation;
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
        virtual void activate() = 0;
        virtual void deactivate() = 0;
        virtual void setCurrent(StateActivation *state) = 0;
    };


    class Account : public AccountFunctions {
        class StateActivation *current;
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

        void setCurrent(StateActivation *state) override {
            current = state;
        }

        void activate() override;

        void deactivate() override;

    private:
        std::map<std::string, float> history;

        std::string accountName;
        std::string accountType;
        float balance;
    };

    class StateActivation {
    public:
        virtual void activate(AccountFunctions *account);

        virtual void deactivate(AccountFunctions *account);

    };

    class ACTIVATE : public StateActivation {
    public:
        ACTIVATE() = default;

        ~ACTIVATE() = default;

        void deactivate(AccountFunctions *account) override;
    };

    class DEACTIVATE : public StateActivation {
    public:
        DEACTIVATE() = default;

        ~DEACTIVATE() = default;

        void activate(AccountFunctions *account) override;
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

        void activate() override;

        void deactivate() override;

        void setCurrent(StateActivation *state) override;

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

        void activate() override;

        void deactivate() override;

        void setCurrent(StateActivation *state) override;

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

        void activate() override;

        void deactivate() override;

        void setCurrent(StateActivation *state) override;

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

        void activate() override;

        void deactivate() override;

        void setCurrent(StateActivation *state) override;

    private:
        float transactionFeePercentage = 0.025;
    };
}


#endif //SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H
