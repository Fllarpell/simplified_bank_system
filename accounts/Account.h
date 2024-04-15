#include "../main/include.h"
#include "../messages/errorMessages/ErrorHandling.h"

#ifndef SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H
#define SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H

namespace Account {
    // declaration prototype classes
    class AccountFunctions  ;
    class Account           ;
    class StateActivation   ;
    class DecoratorAccount  ;
    class SavingAccount     ;
    class CheckingAccount   ;
    class BusinessAccount   ;
    // map for storing of the existing accounts
    static std::map<std::string, AccountFunctions*> accountMap;

    // class with all operations for the accounts
    class AccountFunctions {
    public:
        virtual void withdraw(float withdrawalAmount) = 0;
        virtual void transfer(AccountFunctions *toAccount, float transferAmount) = 0;
        virtual void deposit(float depositAmount) = 0;
        virtual float getBalance() = 0;
        virtual void setBalance(float newBalance) = 0;
        virtual std::vector<std::string> getHistory() = 0;
        virtual std::string getAccountName() = 0;
        virtual std::string getAccountType() = 0;
        virtual float getTransactionFeePercentage() = 0;
        virtual void activate() = 0;
        virtual void deactivate() = 0;
        virtual void setCurrent(StateActivation *state) = 0;
        virtual StateActivation* getCurrentStateAccount() = 0;
    };

    // base class account (default in Decorator)
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

        std::vector<std::string> getHistory() override;

        std::string getAccountName() override;

        std::string getAccountType() override;

        float getTransactionFeePercentage() override;

        void setCurrent(StateActivation *state) override {
            current = state;
        }

        StateActivation* getCurrentStateAccount() override {
            return this->current;
        }

        void activate() override;

        void deactivate() override;

    private:
        std::vector<std::string> history;

        std::string accountName;
        std::string accountType;
        float balance;
    };
    // class for switch states
    class StateActivation {
    public:
        virtual void activate(AccountFunctions *account);

        virtual void deactivate(AccountFunctions *account);

        virtual bool getState() = 0;

    };
    // class ACTIVE account state
    class ACTIVATE : public StateActivation {
    public:
        ACTIVATE() = default;

        ~ACTIVATE() = default;

        void deactivate(AccountFunctions *account) override;

        bool getState() override;
    };
    // class INACTIVE account state
    class DEACTIVATE : public StateActivation {
    public:
        DEACTIVATE() = default;

        ~DEACTIVATE() = default;

        void activate(AccountFunctions *account) override;

        bool getState() override;
    };

    // linking class in decorator design pattern
    class DecoratorAccount : public AccountFunctions {
    public:
        AccountFunctions *acc;

        explicit DecoratorAccount(AccountFunctions *a);

        void withdraw(float withdrawalAmount) override;

        void transfer(AccountFunctions *toAccount, float transferAmount) override;

        void deposit(float depositAmount) override;

        float getBalance() override;

        void setBalance(float newBalance) override;

        std::vector<std::string> getHistory() override;

        std::string getAccountName() override;

        std::string getAccountType() override;

        float getTransactionFeePercentage() override;

        void activate() override;

        void deactivate() override;

        void setCurrent(StateActivation *state) override;

        StateActivation* getCurrentStateAccount() override;
    };

    // class for instantiation of savings account
    class SavingAccount : public DecoratorAccount {
    public:
        explicit SavingAccount(Account* account) : DecoratorAccount(account) {}

        void withdraw(float withdrawalAmount) override;

        void transfer(AccountFunctions *toAccount, float transferAmount) override;

        void deposit(float depositAmount) override;

        float getBalance() override;

        void setBalance(float newBalance) override;

        std::vector<std::string> getHistory() override;

        std::string getAccountName() override;

        std::string getAccountType() override;

        float getTransactionFeePercentage() override;

        void activate() override;

        void deactivate() override;

        void setCurrent(StateActivation *state) override;

        StateActivation* getCurrentStateAccount() override;

    private:
        float const transactionFeePercentage = 0.015;   // transaction fee percentage for savings account
    };

    // class for instantiation of checking account
    class CheckingAccount : public DecoratorAccount {
    public:
        explicit CheckingAccount(Account* account) : DecoratorAccount(account) {}

        void withdraw(float withdrawalAmount) override;

        void transfer(AccountFunctions *toAccount, float transferAmount) override;

        void deposit(float depositAmount) override;

        float getBalance() override;

        void setBalance(float newBalance) override;

        std::vector<std::string> getHistory() override;

        std::string getAccountName() override;

        std::string getAccountType() override;

        float getTransactionFeePercentage() override;

        void activate() override;

        void deactivate() override;

        void setCurrent(StateActivation *state) override;

        StateActivation* getCurrentStateAccount() override;

    private:
        float const transactionFeePercentage = 0.020;   // transaction fee percentage for checking account
    };

    // class for instantiation of business account
    class BusinessAccount : public DecoratorAccount {
    public:
        explicit BusinessAccount(Account* account) : DecoratorAccount(account) {}

        void withdraw(float withdrawalAmount) override;

        void transfer(AccountFunctions *toAccount, float transferAmount) override;

        void deposit(float depositAmount) override;

        float getBalance() override;

        void setBalance(float newBalance) override;

        std::vector<std::string> getHistory() override;

        std::string getAccountName() override;

        std::string getAccountType() override;

        float getTransactionFeePercentage() override;

        void activate() override;

        void deactivate() override;

        void setCurrent(StateActivation *state) override;

        StateActivation* getCurrentStateAccount() override;

    private:
        float const transactionFeePercentage = 0.025;   // transaction fee percentage for business account
    };
}


#endif //SIMPLIFIED_BANK_SYSTEM_ACCOUNT_H
