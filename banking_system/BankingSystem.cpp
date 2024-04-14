#include "BankingSystem.h"

BankingSystem::BankingSystem* BankingSystem::BankingSystem::unique = nullptr;
BankingSystem::BankingSystemDestroyer BankingSystem::BankingSystem::destroyer;

BankingSystem::BankingSystem::BankingSystem(const BankingSystem&) {}

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

void BankingSystem::BankingSystem::startHandlingOperations() {
    int amount_operations;
    std::cin >> amount_operations;
    OperationsHandling::OperationsHandling::operationsHandling(amount_operations);
}
