#include "ErrorHandling.h"


void ErrorHandling::ErrorHandling::AccountDoesNotExistError(Account::Account& account) {
    std::cout << "Error: Account " << account.getAccountName() << " does not exist." << std::endl;
}
void ErrorHandling::ErrorHandling::WithdrawalFromAnInactiveAccountError(Account::Account& account) {
    std::cout << "Error: Account " << account.getAccountName() << " is inactive." << std::endl;
}
void ErrorHandling::ErrorHandling::InsufficientFundsForTransferAndWithdrawError(Account::Account& account) {
    std::cout << "Error: Insufficient funds for " << account.getAccountName() << "." << std::endl;
}
void ErrorHandling::ErrorHandling::ActivateAnActivatedAccountError(Account::Account& account) {
    std::cout << "Error: Account " << account.getAccountName() << " is already activated." << std::endl;
}
void ErrorHandling::ErrorHandling::DeactivateADeactivatedAccountError(Account::Account& account) {
    std::cout << "Error: Account " << account.getAccountName() << " is already deactivated." << std::endl;
}
