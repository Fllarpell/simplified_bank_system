#include "include.h"
#include "Account.h"

#ifndef SIMPLIFIED_BANK_SYSTEM_ERRORHANDLING_H
#define SIMPLIFIED_BANK_SYSTEM_ERRORHANDLING_H

namespace ErrorHandling {
    class ErrorHandling {
    public:
        static void AccountDoesNotExistError(Account::Account& account);
        static void WithdrawalFromAnInactiveAccountError(Account::Account& account);
        static void InsufficientFundsForTransferAndWithdrawError(Account::Account& account);
        static void ActivateAnActivatedAccountError(Account::Account& account);
        static void DeactivateADeactivatedAccountError(Account::Account& account);
    };
}

#endif //SIMPLIFIED_BANK_SYSTEM_ERRORHANDLING_H
