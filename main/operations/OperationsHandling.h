#include "../include.h"
#include "../../accounts/Account.h"
#include "../../messages/successfulMessages/SuccessfulMessages.h"
#include "../../messages/errorMessages/ErrorHandling.h"

#ifndef SIMPLIFIED_BANK_SYSTEM_OPERATIONSHANDLING_H
#define SIMPLIFIED_BANK_SYSTEM_OPERATIONSHANDLING_H

namespace OperationsHandling {

    class OperationsHandling {
    public:
        static void operationsHandling(int amount_operations);
    private:
        static void create(const std::string& accountType, const std::string& accountName, float initialDeposit);
        static bool checkoutErrorExistAccount(const std::string& accountName);
        static bool checkoutErrorAccountActivity(const std::string& accountName);
        static bool checkoutErrorInsufficientFunds(const std::string& accountName, float DepositTransferMoney);
    };

}

#endif //SIMPLIFIED_BANK_SYSTEM_OPERATIONSHANDLING_H
