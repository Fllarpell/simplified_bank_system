#include "SuccessfulMessages.h"
// message about successful creating account
void SuccessfulMessages::SuccessfulMessages::successfulCreated(Account::AccountFunctions* account) {
    std::string accountType = account->getAccountType();    // type of the account
    std::string accountName = account->getAccountName();    // name of the account
    float balance = account->getBalance();                  // balance of the account
    // output about successful creating account
    printf("A new %s created for %s with an initial balance of $%.2f.\n",
           accountType.c_str(),
           accountName.c_str(),
           balance);
}
// message about successful withdraw money from the account
void SuccessfulMessages::SuccessfulMessages::successfulWithdrew(Account::AccountFunctions* account, float withdrawalAmount, float transactionFeePercentage) {
    std::string accountName = account->getAccountName();    // name of the account
    float balance = account->getBalance();                  // balance of the account
    // output about successful withdraw money from the account
    printf("%s successfully withdrew %.2f. New Balance: $%.2f. Transaction Fee: $%.2f (%.1f%) in the system.\n",
           accountName.c_str(),
           withdrawalAmount - withdrawalAmount*transactionFeePercentage,
           balance,
           withdrawalAmount*transactionFeePercentage,
           transactionFeePercentage*100);
}
// message about successful transfer money from the account to another account
void SuccessfulMessages::SuccessfulMessages::successfulTransfer(Account::AccountFunctions* accountFrom, Account::AccountFunctions* accountTo, float transferAmount, float transactionFeePercentage) {
    std::string fromAccountName = accountFrom->getAccountName();    // name account for transfer operation (from where transfer money)
    std::string toAccountName = accountTo->getAccountName();        // name account for transfer operation (to where transfer money)
    float targetBalance = accountTo->getBalance();                  // balance of the account
    //output about successful transfer money from the account to another account
    printf("%s successfully transferred %.2f to %s. New Balance: $%.2f. Transaction Fee: $%.2f (%.1f%) in the system.\n",
           fromAccountName.c_str(),
           transferAmount-transferAmount*transactionFeePercentage,
           toAccountName.c_str(),
           targetBalance,
           transferAmount*transactionFeePercentage,
           transactionFeePercentage*100);

}
// message about successful deposit money to the account
void SuccessfulMessages::SuccessfulMessages::successfulDeposit(Account::AccountFunctions* account, float depositAmount) {
    std::string accountName = account->getAccountName();    // name of the account
    float balance = account->getBalance();                  // balance of the account
    //output about successful deposit money to the account
    printf("%s successfully deposited $%.2f. New Balance: $%.2f.\n",
           accountName.c_str(),
           depositAmount,
           balance);
}
// message about all information of the user of the bank
void SuccessfulMessages::SuccessfulMessages::successfulView(Account::AccountFunctions* account) {
    auto name = account->getAccountName();       // name of the account
    auto type = account->getAccountType();      // type of the account
    auto balance = account->getBalance();       // balance of the account
    std::string state = "Active";                    // default state of activity of the account
    char transactions[256];                         // string for recording all transactions from history

    if (!account->getCurrentStateAccount()->getState()) // check real state of the account
        state = "Inactive";
    // filling transactions string
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

    // output all information about the user
    printf("%s's Account: Type: %s, Balance: $%.2f, State: %s, Transactions: [%s].\n",
           name.c_str(),
           type.c_str(),
           balance,
           state.c_str(),
           transactions);
}
// message about successful activation of the account
void SuccessfulMessages::SuccessfulMessages::successfulActivated(Account::AccountFunctions* account) {
    printf("%s's account is now activated.\n",  // output about successful activation of the account
           account->getAccountName().c_str());
}
// message about successful deactivation of the account
void SuccessfulMessages::SuccessfulMessages::successfulDeactivated(Account::AccountFunctions* account) {
    printf("%s's account is now deactivated.\n",    // output about successful deactivation of the account
           account->getAccountName().c_str());
}
