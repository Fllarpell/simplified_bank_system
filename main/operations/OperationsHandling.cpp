#include "OperationsHandling.h"
// Processing flow of the operations
void OperationsHandling::OperationsHandling::operationsHandling(int amount_operations) {
    std::string     operation           ; // name of operation

    std::string     accountType         ; // type of account
    std::string     accountName         ; // name of account
    std::string     fromAccountName     ; // name account for transfer operation (from where transfer money)
    std::string     toAccountName       ; // name account for transfer operation (to where transfer money)
    std::string     _created_what       ; // what function Create is create

    float           initialDeposit      ; // default amount money on the account
    float           depositAmount       ; // amount money for deposit
    float           withdrawalAmount    ; // amount money for withdraw
    float           transferAmount      ; // amount money for transfer

    for (int i = 0; i < amount_operations; ++i) {
        std::cin >> operation;              // input name of operation

        if (operation == "Create") {        // Processing Create operation
            std::cin >> _created_what   ;   // input what function Create is create
            std::cin >> accountType     ;   // input type of the account
            std::cin >> accountName     ;   // input name of the account
            std::cin >> initialDeposit  ;   // input default amount money on the account

            if (Account::accountMap.find(accountName) != Account::accountMap.end()) {   // check existing account already or not.
                printf("Error: Account %s exists.\n", accountName.c_str());         // output if account already exists.
                continue;
            }

            create(accountType, accountName, initialDeposit);   // function of creating instance of the account
            SuccessfulMessages::SuccessfulMessages::successfulCreated(Account::accountMap.find(accountName)->second);   // message about successful creating account
        } else if (operation == "Deposit") {    // Processing Deposit operation
            std::cin >> accountName     ;       // input name of the account
            std::cin >> depositAmount   ;       // input amount money for deposit

            if (checkoutErrorExistAccount(accountName)
            || checkoutErrorAccountActivity(accountName)) {
                continue;
            }
            Account::accountMap.find(accountName)->second->deposit(depositAmount);  // function of deposit money on the account
            SuccessfulMessages::SuccessfulMessages::successfulDeposit(Account::accountMap.find(accountName)->second, depositAmount);    // message about successful deposit money on the account
        } else if (operation == "Withdraw") {   // Processing Withdraw operation
            std::cin >> accountName     ;       // input name of the account
            std::cin >> withdrawalAmount;       // input amount money for withdraw

            if (checkoutErrorExistAccount(accountName)   // check existing account
            || checkoutErrorAccountActivity(accountName)   // check activity account
            || checkoutErrorInsufficientFunds(accountName, withdrawalAmount)) {   // check sufficient funds or not
                continue;
            }

            Account::accountMap.find(accountName)->second->withdraw(withdrawalAmount);  // function of withdraw money from the account

            SuccessfulMessages::SuccessfulMessages::successfulWithdrew(Account::accountMap.find(accountName)->second, withdrawalAmount,
                                                                       Account::accountMap.find(accountName)->second->getTransactionFeePercentage());  // message about successful withdraw money from the account
        } else if (operation == "Transfer") {   // Processing Transfer operation
            std::cin >> fromAccountName ;       // input name account for transfer operation (from where transfer money)
            std::cin >> toAccountName   ;       // input name account for transfer operation (to where transfer money)
            std::cin >> transferAmount  ;       // input amount money for transfer

            if (checkoutErrorExistAccount(fromAccountName)      // check existing of the sender account
            || checkoutErrorExistAccount(toAccountName)         // check existing of the recipient account
            || checkoutErrorAccountActivity(fromAccountName)    // check activity of the sender account
            || checkoutErrorAccountActivity(toAccountName)      // check activity of the recipient account
            || checkoutErrorInsufficientFunds(fromAccountName, transferAmount)) {   // check sufficient funds or not
                continue;
            }

            Account::accountMap.find(fromAccountName)->second->transfer(Account::accountMap.find(toAccountName)->second, transferAmount);   // function of transfer money from account to another account

            SuccessfulMessages::SuccessfulMessages::successfulTransfer(Account::accountMap.find(fromAccountName)->second,
                                                                       Account::accountMap.find(toAccountName)->second, transferAmount,
                                                                       Account::accountMap.find(toAccountName)->second->getTransactionFeePercentage()); // message about successful transfer money from account to another account
        } else if (operation == "View") {       // Processing View operation
            std::cin >> accountName     ;       // input name of the account

            if (checkoutErrorExistAccount(accountName)) {   // check existing account
                continue;
            }

            SuccessfulMessages::SuccessfulMessages::successfulView(Account::accountMap.find(accountName)->second);  // function that output information about user of bank
        } else if (operation == "Deactivate") { // Processing Deactivate operation
            std::cin >> accountName     ;       // input name of the account
            bool notErrorFlag = true    ;       // flag for check error linked with activity of the user
            if (checkoutErrorExistAccount(accountName)) {   // check existing account
                continue;
            }
            if (!Account::accountMap.find(accountName)->second->getCurrentStateAccount()->getState()) { // check activity of the user
                notErrorFlag = false;
            }

            Account::accountMap.find(accountName)->second->deactivate();    // function that deactivate account or report about error

            if (notErrorFlag)
                SuccessfulMessages::SuccessfulMessages::successfulDeactivated(Account::accountMap.find(accountName)->second);   // successful message about deactivation of the account
        } else if (operation == "Activate") {   // Processing Activate operation
            std::cin >> accountName     ;       // input name of the account
            bool notErrorFlag = true    ;       // flag for check error linked with activity of the user
            if (checkoutErrorExistAccount(accountName)) { // check existing account
                continue;
            }
            if (Account::accountMap.find(accountName)->second->getCurrentStateAccount()->getState()) {   // check activity of the user
                notErrorFlag = false;
            }
            Account::accountMap.find(accountName)->second->activate();  // function that activate account or report about error

            if (notErrorFlag)
                SuccessfulMessages::SuccessfulMessages::successfulActivated(Account::accountMap.find(accountName)->second);    // successful message about activation of the account
        }
    }
}
// Function create instance of the need type account and write it to the accountMap where stores all existing accounts
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

// Handle exception linked with existing account in the banking system
bool OperationsHandling::OperationsHandling::checkoutErrorExistAccount(const std::string& accountName) {
    if (Account::accountMap.find(accountName) == Account::accountMap.end()) {
        ErrorHandling::ErrorHandling::AccountDoesNotExistError(accountName);
        return true;
    }
    return false;
}
// Handle exception linked with inactivity account in the banking system
bool OperationsHandling::OperationsHandling::checkoutErrorAccountActivity(const std::string &accountName) {
    if (!Account::accountMap.find(accountName)->second->getCurrentStateAccount()->getState()) {
        ErrorHandling::ErrorHandling::WithdrawalFromAnInactiveAccountError(accountName);
        return true;
    }
    return false;
}
// Handle exception linked with Insufficient funds during withdraw or transfer money
bool OperationsHandling::OperationsHandling::checkoutErrorInsufficientFunds(const std::string& accountName, float DepositTransferMoney) {
    if (DepositTransferMoney > Account::accountMap.find(accountName)->second->getBalance()) {
        ErrorHandling::ErrorHandling::InsufficientFundsForTransferAndWithdrawError(accountName);
        return true;
    }
    return false;
}



