#include "../include.h"
#include "../../accounts/Account.h"
#include "../../messages/successfulMessages/SuccessfulMessages.h"

#ifndef SIMPLIFIED_BANK_SYSTEM_OPERATIONSHANDLING_H
#define SIMPLIFIED_BANK_SYSTEM_OPERATIONSHANDLING_H

namespace OperationsHandling {

    class OperationsHandling {
    public:
        static void operationsHandling(int amount_operations);
    private:
        static void create(const std::string& accountType, const std::string& accountName, float initialDeposit);

    };

}

#endif //SIMPLIFIED_BANK_SYSTEM_OPERATIONSHANDLING_H
