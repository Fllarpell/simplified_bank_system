#include "BankingSystem.h"
#include "Account.h"

BankingSystem::BankingSystem* BankingSystem::BankingSystem::unique = nullptr;
BankingSystem::BankingSystemDestroyer BankingSystem::BankingSystem::destroyer;

BankingSystem::BankingSystemDestroyer::~BankingSystemDestroyer() {
    delete unique;
}
void BankingSystem::BankingSystemDestroyer::initialize( BankingSystem* p ) {
    unique = p;
}
BankingSystem::BankingSystem& BankingSystem::BankingSystem::getInstance() {
    if(!unique) {
        unique = new BankingSystem();
        destroyer.initialize( unique);
    }
    return *unique;
}
