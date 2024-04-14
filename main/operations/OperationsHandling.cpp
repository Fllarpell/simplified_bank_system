#include "OperationsHandling.h"

void OperationsHandling::OperationsHandling::operationsHandling(int amount_operations) {
    std::string     operation       ;

    std::string     accountType     ;
    std::string     accountName     ;
    std::string     fromAccountName ;
    std::string     toAccountName   ;
    std::string     _created_what   ;

    float           initialDeposit  ;
    float           depositAmount   ;
    float           withdrawalAmount;
    float           transferAmount  ;

    for (int i = 0; i < amount_operations; ++i) {
        std::cin >> operation;

        if (operation == "Create") {
            std::cin >> _created_what   ;
            std::cin >> accountType     ;
            std::cin >> accountName     ;
            std::cin >> initialDeposit  ;

            create(accountType, accountName, initialDeposit);
            SuccessfulMessages::SuccessfulMessages::successfulCreated(Account::accountMap.find(accountName)->second);
        } else if (operation == "Deposit") {
            std::cin >> accountName;
            std::cin >> depositAmount;

            Account::accountMap.find(accountName)->second->deposit(depositAmount);
            SuccessfulMessages::SuccessfulMessages::successfulDeposit(Account::accountMap.find(accountName)->second, depositAmount);
        } else if (operation == "Withdraw") {
            std::cin >> accountName;
            std::cin >> withdrawalAmount;

            Account::accountMap.find(accountName)->second->withdraw(withdrawalAmount);

            SuccessfulMessages::SuccessfulMessages::successfulWithdrew(Account::accountMap.find(accountName)->second, withdrawalAmount, Account::accountMap.find(accountName)->second->getTransactionFeePercentage());
        } else if (operation == "Transfer") {
            std::cin >> fromAccountName;
            std::cin >> toAccountName;
            std::cin >> transferAmount;

            Account::accountMap.find(fromAccountName)->second->transfer(Account::accountMap.find(toAccountName)->second, transferAmount);

            SuccessfulMessages::SuccessfulMessages::successfulTransfer(Account::accountMap.find(fromAccountName)->second, Account::accountMap.find(toAccountName)->second, transferAmount, Account::accountMap.find(toAccountName)->second->getTransactionFeePercentage());
        } else if (operation == "View") {
            std::cin >> accountName;

            SuccessfulMessages::SuccessfulMessages::successfulView(Account::accountMap.find(accountName)->second);
        } else if (operation == "Deactivate") {
            std::cin >> accountName;

            SuccessfulMessages::SuccessfulMessages::successfulDeactivated(Account::accountMap.find(accountName)->second);
        } else if (operation == "Activate") {
            std::cin >> accountName;

            SuccessfulMessages::SuccessfulMessages::successfulActivated(Account::accountMap.find(accountName)->second);
        }
    }
}

void OperationsHandling::OperationsHandling::create(const std::string& accountType, const std::string& accountName, float initialDeposit) {
    if (accountType == "Savings") {
        Account::AccountFunctions* savingAccount = new Account::SavingAccount(new Account::Account(accountType, accountName, initialDeposit));
        Account::accountMap.insert({accountName, savingAccount});
    } else if (accountType == "Checking") {
        Account::AccountFunctions* checkingAccount = new Account::CheckingAccount(new Account::Account(accountType, accountName, initialDeposit));
        Account::accountMap.insert({accountName, checkingAccount});
    } else if (accountType == "Business") {
        Account::AccountFunctions* businessAccount = new Account::BusinessAccount(new Account::Account(accountType, accountName, initialDeposit));
        Account::accountMap.insert({accountName, businessAccount});
    }

}


