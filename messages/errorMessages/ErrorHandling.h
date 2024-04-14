#include "../../main/include.h"

#ifndef SIMPLIFIED_BANK_SYSTEM_ERRORHANDLING_H
#define SIMPLIFIED_BANK_SYSTEM_ERRORHANDLING_H

namespace ErrorHandling {
    class ErrorHandling {
    public:
        static void AccountDoesNotExistError(const std::string& accountName);
        static void WithdrawalFromAnInactiveAccountError(const std::string& accountName);
        static void InsufficientFundsForTransferAndWithdrawError(const std::string& accountName);
        static void ActivateAnActivatedAccountError(const std::string& accountName);
        static void DeactivateADeactivatedAccountError(const std::string& accountName);
    };
}

#endif //SIMPLIFIED_BANK_SYSTEM_ERRORHANDLING_H
