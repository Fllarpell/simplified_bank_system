#include "ErrorHandling.h"


void ErrorHandling::ErrorHandling::AccountDoesNotExistError(const std::string& accountName) {
    std::cout << "Error: Account " << accountName << " does not exist." << std::endl;
}
void ErrorHandling::ErrorHandling::WithdrawalFromAnInactiveAccountError(const std::string& accountName) {
    std::cout << "Error: Account " << accountName << " is inactive." << std::endl;
}
void ErrorHandling::ErrorHandling::InsufficientFundsForTransferAndWithdrawError(const std::string& accountName) {
    std::cout << "Error: Insufficient funds for " << accountName << "." << std::endl;
}
void ErrorHandling::ErrorHandling::ActivateAnActivatedAccountError(const std::string& accountName) {
    std::cout << "Error: Account " << accountName << " is already activated." << std::endl;
}
void ErrorHandling::ErrorHandling::DeactivateADeactivatedAccountError(const std::string& accountName) {
    std::cout << "Error: Account " << accountName << " is already deactivated." << std::endl;
}
