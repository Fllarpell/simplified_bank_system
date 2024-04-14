#include "../banking_system/BankingSystem.h"


int main() {
    BankingSystem::BankingSystem& bankingSystem = BankingSystem::BankingSystem::getInstance(); // banking system instance
    bankingSystem.startHandlingOperations(); // start program

    return 0;
}
