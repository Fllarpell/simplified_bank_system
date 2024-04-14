#include "../main/include.h"
#include "../main/operations/OperationsHandling.h"

#ifndef SIMPLIFIED_BANK_SYSTEM_BANKINGSYSTEM_H
#define SIMPLIFIED_BANK_SYSTEM_BANKINGSYSTEM_H

namespace BankingSystem {

    class BankingSystem;

    class BankingSystemDestroyer
    {
    private:
        BankingSystem* unique;
    public:
        ~BankingSystemDestroyer();
        void initialize( BankingSystem* p );
    };

    class BankingSystem {
    private:
        static BankingSystem *unique;
        static BankingSystemDestroyer destroyer;

        friend class BankingSystemDestroyer;
    public:
        BankingSystem() = default;
        BankingSystem( const BankingSystem& );
        BankingSystem& operator=( BankingSystem& );
        ~BankingSystem() = default;
        static BankingSystem& getInstance();
        void startHandlingOperations();

    };
}

#endif //SIMPLIFIED_BANK_SYSTEM_BANKINGSYSTEM_H
