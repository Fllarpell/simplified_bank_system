#include "include.h"

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

        BankingSystem& operator=( BankingSystem& );
        friend class BankingSystemDestroyer;
    public:
        BankingSystem() { }
        BankingSystem( const BankingSystem& );
        ~BankingSystem() { }
        static BankingSystem& getInstance();

    };
}

#endif //SIMPLIFIED_BANK_SYSTEM_BANKINGSYSTEM_H
