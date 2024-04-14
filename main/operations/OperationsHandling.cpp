#include "OperationsHandling.h"

void OperationsHandling::OperationsHandling::operationsHandling(int amount_operations) {
    std::string     operation           ;

    std::string     accountType         ;
    std::string     accountName         ;
    std::string     fromAccountName     ;
    std::string     toAccountName       ;
    std::string     _created_what       ;

    float           initialDeposit      ;
    float           depositAmount       ;
    float           withdrawalAmount    ;
    float           transferAmount      ;

    for (int i = 0; i < amount_operations; ++i) {
        std::cin >> operation;

        if (operation == "Create") {
            std::cin >> _created_what   ;
            std::cin >> accountType     ;
            std::cin >> accountName     ;
            std::cin >> initialDeposit  ;

            if (Account::accountMap.find(accountName) != Account::accountMap.end()) {
                std::cout << "Error: Account " << accountName << " exists." << std::endl;
                continue;
            }

            create(accountType, accountName, initialDeposit);
            SuccessfulMessages::SuccessfulMessages::successfulCreated(Account::accountMap.find(accountName)->second);
        } else if (operation == "Deposit") {
            std::cin >> accountName     ;
            std::cin >> depositAmount   ;

            if (checkoutErrorExistAccount(accountName)
            || checkoutErrorAccountActivity(accountName)) {
                continue;
            }
            Account::accountMap.find(accountName)->second->deposit(depositAmount);
            SuccessfulMessages::SuccessfulMessages::successfulDeposit(Account::accountMap.find(accountName)->second, depositAmount);
        } else if (operation == "Withdraw") {
            std::cin >> accountName     ;
            std::cin >> withdrawalAmount;

            if (checkoutErrorExistAccount(accountName)
            || checkoutErrorAccountActivity(accountName)
            || checkoutErrorInsufficientFunds(accountName, withdrawalAmount)) {
                continue;
            }

            Account::accountMap.find(accountName)->second->withdraw(withdrawalAmount);

            SuccessfulMessages::SuccessfulMessages::successfulWithdrew(Account::accountMap.find(accountName)->second, withdrawalAmount, Account::accountMap.find(accountName)->second->getTransactionFeePercentage());
        } else if (operation == "Transfer") {
            std::cin >> fromAccountName ;
            std::cin >> toAccountName   ;
            std::cin >> transferAmount  ;

            if (checkoutErrorExistAccount(fromAccountName)
            || checkoutErrorExistAccount(toAccountName)
            || checkoutErrorAccountActivity(fromAccountName)
            || checkoutErrorAccountActivity(toAccountName)
            || checkoutErrorInsufficientFunds(fromAccountName, transferAmount)) {
                continue;
            }

            Account::accountMap.find(fromAccountName)->second->transfer(Account::accountMap.find(toAccountName)->second, transferAmount);

            SuccessfulMessages::SuccessfulMessages::successfulTransfer(Account::accountMap.find(fromAccountName)->second, Account::accountMap.find(toAccountName)->second, transferAmount, Account::accountMap.find(toAccountName)->second->getTransactionFeePercentage());
        } else if (operation == "View") {
            std::cin >> accountName     ;

            if (checkoutErrorExistAccount(fromAccountName)) {
                continue;
            }

            SuccessfulMessages::SuccessfulMessages::successfulView(Account::accountMap.find(accountName)->second);
        } else if (operation == "Deactivate") {
            std::cin >> accountName     ;

            Account::accountMap.find(accountName)->second->deactivate();

            SuccessfulMessages::SuccessfulMessages::successfulDeactivated(Account::accountMap.find(accountName)->second);
        } else if (operation == "Activate") {
            std::cin >> accountName     ;

            Account::accountMap.find(accountName)->second->activate();

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


bool OperationsHandling::OperationsHandling::checkoutErrorExistAccount(const std::string& accountName) {
    if (Account::accountMap.find(accountName) == Account::accountMap.end()) {
        ErrorHandling::ErrorHandling::AccountDoesNotExistError(accountName);
        return true;
    }
    return false;
}

bool OperationsHandling::OperationsHandling::checkoutErrorAccountActivity(const std::string &accountName) {
    return false;
}

bool OperationsHandling::OperationsHandling::checkoutErrorInsufficientFunds(const std::string& accountName, float DepositTransferMoney) {
    if (DepositTransferMoney > Account::accountMap.find(accountName)->second->getBalance()) {
        ErrorHandling::ErrorHandling::InsufficientFundsForTransferAndWithdrawError(accountName);
        return true;
    }
    return false;
}



