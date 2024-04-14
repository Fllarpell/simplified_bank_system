#include "SuccessfulMessages.h"

void SuccessfulMessages::SuccessfulMessages::successfulCreated(Account::AccountFunctions* account) {
    std::string accountType = account->getAccountType();
    std::string accountName = account->getAccountName();
    float balance = account->getBalance();

    std::cout << std::fixed << std::setprecision(2) << "A new " << accountType << " created for " << accountName << " with an initial balance of $" << balance << "." << std::endl;
}

void SuccessfulMessages::SuccessfulMessages::successfulWithdrew(Account::AccountFunctions* account, float withdrawalAmount, float transactionFeePercentage) {
    std::string accountName = account->getAccountName();
    float balance = account->getBalance();

    std::cout << std::fixed << std::setprecision(2) << accountName << " successfully withdrew "
              << withdrawalAmount - withdrawalAmount*transactionFeePercentage << ". New Balance: " << balance <<
              ". Transaction Fee: $" << withdrawalAmount*transactionFeePercentage << " (" << transactionFeePercentage*100 << "%) in the system." << std::endl;
}

void SuccessfulMessages::SuccessfulMessages::successfulTransfer(Account::AccountFunctions* accountFrom, Account::AccountFunctions* accountTo, float transferAmount, float transactionFeePercentage) {
    std::string fromAccountName = accountFrom->getAccountName();
    std::string toAccountName = accountTo->getAccountName();
    float targetBalance = accountTo->getBalance();

    std::cout << std::fixed << std::setprecision(2) << fromAccountName <<
              " successfully transferred " << transferAmount-transferAmount*transactionFeePercentage <<
              " to "<< toAccountName << ". New Balance: $" << targetBalance << ". Transaction Fee: $" <<
              transferAmount*transactionFeePercentage << " (" << transactionFeePercentage*100 << "%) in the system." << std::endl;
}

void SuccessfulMessages::SuccessfulMessages::successfulDeposit(Account::AccountFunctions* account, float depositAmount) {
    std::string accountName = account->getAccountName();
    float balance = account->getBalance();

    std::cout << std::fixed << std::setprecision(2) << accountName << " successfully deposited $" << depositAmount << ". New Balance: $" << balance << "." << std::endl;
}

void SuccessfulMessages::SuccessfulMessages::successfulView(Account::AccountFunctions* account) {
    auto name = account->getAccountName();
    auto type = account->getAccountType();
    auto balance = account->getBalance();
    auto state = "Active";

    std::string initDeposit;
    std::string allDeposit;
    std::string allWithdrew;
    std::string allTransfers;

    account->getHistory().find("InitialDeposit")->second == 0 ? initDeposit = "" : initDeposit = "Initial deposit $" + std::to_string(account->getHistory().find("InitialDeposit")->second);
    account->getHistory().find("Deposit")->second == 0 ? allDeposit = "" : allDeposit = "Deposit $" + std::to_string(account->getHistory().find("Deposit")->second);
    account->getHistory().find("Withdrawal")->second == 0 ? allWithdrew = "" : allWithdrew = "Withdrawal $" + std::to_string(account->getHistory().find("Withdrawal")->second);
    account->getHistory().find("Transfer")->second == 0 ? allTransfers = "" : allTransfers = "Transfer $" + std::to_string(account->getHistory().find("Transfer")->second);

    std::cout << std::fixed << std::setprecision(2) << name << "'s Account: " <<
              "Type: "<< type << " Balance: $" << balance << " State: " << state << " Transactions: [" << initDeposit << allDeposit << allWithdrew << allTransfers << "]." << std::endl;
}

void SuccessfulMessages::SuccessfulMessages::successfulActivated(Account::AccountFunctions* account) {
    std::cout << std::fixed << std::setprecision(2) << account->getAccountName() << "'s account is now activated." << std::endl;
}

void SuccessfulMessages::SuccessfulMessages::successfulDeactivated(Account::AccountFunctions* account) {
    std::cout << std::fixed << std::setprecision(2) << account->getAccountName() << "'s account is now deactivated." << std::endl;
}
