#include "ErrorHandling.h"

// Error message about wrong linked existing account
void ErrorHandling::ErrorHandling::AccountDoesNotExistError(const std::string& accountName) {
    printf("Error: Account %s does not exist.\n", accountName.c_str());
}
// Error message about wrong linked with executing operations on the inactive account
void ErrorHandling::ErrorHandling::WithdrawalFromAnInactiveAccountError(const std::string& accountName) {
    printf("Error: Account %s is inactive.\n", accountName.c_str());

}
// Error message about wrong linked with insufficient funds on the account
void ErrorHandling::ErrorHandling::InsufficientFundsForTransferAndWithdrawError(const std::string& accountName) {
    printf("Error: Insufficient funds for %s.\n", accountName.c_str());
}
// Error message about wrong linked activate of an activated account
void ErrorHandling::ErrorHandling::ActivateAnActivatedAccountError(const std::string& accountName) {
    printf("Error: Account %s is already activated.\n", accountName.c_str());
}
// Error message about wrong linked deactivate of a deactivated account
void ErrorHandling::ErrorHandling::DeactivateADeactivatedAccountError(const std::string& accountName) {
    printf("Error: Account %s is already deactivated.\n", accountName.c_str());
}
