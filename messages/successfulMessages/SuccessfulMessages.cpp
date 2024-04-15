#include "SuccessfulMessages.h"

void SuccessfulMessages::SuccessfulMessages::successfulCreated(Account::AccountFunctions* account) {
    std::string accountType = account->getAccountType();
    std::string accountName = account->getAccountName();
    float balance = account->getBalance();

    printf("A new %s created for %s with an initial balance of $%.2f.\n",
           accountType.c_str(),
           accountName.c_str(),
           balance);
}

void SuccessfulMessages::SuccessfulMessages::successfulWithdrew(Account::AccountFunctions* account, float withdrawalAmount, float transactionFeePercentage) {
    std::string accountName = account->getAccountName();
    float balance = account->getBalance();

    printf("%s successfully withdrew %.2f. New Balance: $%.2f. Transaction Fee: $%.2f (%.1f%) in the system.\n",
           accountName.c_str(),
           withdrawalAmount - withdrawalAmount*transactionFeePercentage,
           balance,
           withdrawalAmount*transactionFeePercentage,
           transactionFeePercentage*100);
}

void SuccessfulMessages::SuccessfulMessages::successfulTransfer(Account::AccountFunctions* accountFrom, Account::AccountFunctions* accountTo, float transferAmount, float transactionFeePercentage) {
    std::string fromAccountName = accountFrom->getAccountName();
    std::string toAccountName = accountTo->getAccountName();
    float targetBalance = accountTo->getBalance();

    printf("%s successfully transferred %.2f to %s. New Balance: $%.2f. Transaction Fee: $%.2f (%.1f%) in the system.\n",
           fromAccountName.c_str(),
           transferAmount-transferAmount*transactionFeePercentage,
           toAccountName.c_str(),
           targetBalance,
           transferAmount*transactionFeePercentage,
           transactionFeePercentage*100);

}

void SuccessfulMessages::SuccessfulMessages::successfulDeposit(Account::AccountFunctions* account, float depositAmount) {
    std::string accountName = account->getAccountName();
    float balance = account->getBalance();

    printf("%s successfully deposited $%.2f. New Balance: $%.2f.\n",
           accountName.c_str(),
           depositAmount,
           balance);
}

void SuccessfulMessages::SuccessfulMessages::successfulView(Account::AccountFunctions* account) {
    auto name = account->getAccountName();
    auto type = account->getAccountType();
    auto balance = account->getBalance();
    std::string state = "Inactive";
    char transactions[256];

    if (account->getCurrentStateAccount()->getState())
        state = "Active";

    if (account->getHistory().find("InitialDeposit")->second != 0)
        sprintf(transactions, "Initial Deposit $%.2f", account->getHistory().find("InitialDeposit")->second);

    if (account->getHistory().find("Deposit")->second != 0)
        transactions[0] == '\0' ?
        sprintf(transactions, ", Deposit $%.2f", account->getHistory().find("Deposit")->second)
                                : sprintf(transactions, "Deposit $%.2f",
                                          account->getHistory().find("Deposit")->second);

    if (account->getHistory().find("Withdrawal")->second != 0)
        transactions[0] == '\0' ?
        sprintf(transactions, ", Withdrawal $%.2f",
                account->getHistory().find("Withdrawal")->second)
                                : sprintf(transactions, "Withdrawal $%.2f",
                                          account->getHistory().find("Withdrawal")->second);

    if (account->getHistory().find("Transfer")->second != 0)
        transactions[0] == '\0' ?
        sprintf(transactions, ", Transfer $%.2f", account->getHistory().find("Transfer")->second)
                                : sprintf(transactions, "Transfer $%.2f",
                                          account->getHistory().find("Transfer")->second);


    printf("%s's Account: Type: %s, Balance: $%.2f, State: %s, Transactions: [%s].\n",
           name.c_str(),
           type.c_str(),
           balance,
           state.c_str(),
           transactions);
}

void SuccessfulMessages::SuccessfulMessages::successfulActivated(Account::AccountFunctions* account) {
    printf("%s's account is now activated.\n", account->getAccountName().c_str());
}

void SuccessfulMessages::SuccessfulMessages::successfulDeactivated(Account::AccountFunctions* account) {
    printf("%s's account is now deactivated.\n", account->getAccountName().c_str());
}
