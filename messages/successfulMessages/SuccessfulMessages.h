#include "../../main/include.h"
#include "../../accounts/Account.h"

#ifndef SIMPLIFIED_BANK_SYSTEM_SUCCESSFULMESSAGES_H
#define SIMPLIFIED_BANK_SYSTEM_SUCCESSFULMESSAGES_H

namespace SuccessfulMessages {

    class SuccessfulMessages {
    public:
        static void successfulCreated(Account::AccountFunctions* account);
        static void successfulWithdrew(Account::AccountFunctions* account, float withdrawalAmount, float transactionFeePercentage);
        static void successfulTransfer(Account::AccountFunctions* accountFrom, Account::AccountFunctions* accountTo, float transferAmount, float transactionFeePercentage);
        static void successfulDeposit(Account::AccountFunctions* account, float depositAmount);
        static void successfulView(Account::AccountFunctions* account);
        static void successfulActivated(Account::AccountFunctions* account);
        static void successfulDeactivated(Account::AccountFunctions* account);
    };
}

#endif //SIMPLIFIED_BANK_SYSTEM_SUCCESSFULMESSAGES_H
