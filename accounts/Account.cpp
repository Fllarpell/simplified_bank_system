#include "Account.h"

Account::Account::Account(const std::string &accountType, const std::string &accountName, float initialDeposit) {
    this->accountType               = accountType       ;
    this->accountName               = accountName       ;
    this->balance                   = initialDeposit    ;

    this->history["InitialDeposit"] = initialDeposit    ;
    this->history["Deposit"]        = 0.0               ;
    this->history["Withdrawal"]     = 0.0               ;
    this->history["Transfer"]       = 0.0               ;

    this->current = new ACTIVATE();
}

void Account::Account::withdraw(float withdrawalAmount) {
    if (withdrawalAmount > this->balance)
        ErrorHandling::ErrorHandling::InsufficientFundsForTransferAndWithdrawError(this->accountName);
}

void Account::Account::transfer(Account::AccountFunctions *toAccount, float transferAmount) {
    if (transferAmount > this->balance)
        ErrorHandling::ErrorHandling::InsufficientFundsForTransferAndWithdrawError(this->accountName);
}

void Account::Account::deposit(float depositAmount) {
    this->balance += depositAmount;
    this->history.find("Deposit")->second += depositAmount;
}

float Account::Account::getBalance() {
    return this->balance;
}

void Account::Account::setBalance(float newBalance) {
    this->balance = newBalance;
}

std::map<std::string, float> Account::Account::getHistory() {
    return this->history;
}

std::string Account::Account::getAccountName() {
    return this->accountName;
}

std::string Account::Account::getAccountType() {
    return this->accountType;
}

float Account::Account::getTransactionFeePercentage() {
    return 0.0;
}

void Account::Account::activate() {
    current->activate(this);
}

void Account::Account::deactivate() {
    current->deactivate(this);
}


Account::DecoratorAccount::DecoratorAccount(Account::AccountFunctions *a) {
    acc = a;
}

void Account::DecoratorAccount::withdraw(float withdrawalAmount) {
    return acc->withdraw(withdrawalAmount);
}

void Account::DecoratorAccount::transfer(Account::AccountFunctions *toAccount, float transferAmount) {
    return acc->transfer(toAccount, transferAmount);
}

void Account::DecoratorAccount::deposit(float depositAmount) {
    return acc->deposit(depositAmount);
}

float Account::DecoratorAccount::getBalance() {
    return acc->getBalance();
}

void Account::DecoratorAccount::setBalance(float newBalance) {
    acc->setBalance(newBalance);
}

std::map<std::string, float> Account::DecoratorAccount::getHistory() {
    return acc->getHistory();
}

std::string Account::DecoratorAccount::getAccountName() {
    return acc->getAccountName();
}

std::string Account::DecoratorAccount::getAccountType() {
    return acc->getAccountType();
}

float Account::DecoratorAccount::getTransactionFeePercentage() {
    return acc->getTransactionFeePercentage();
}

void Account::DecoratorAccount::activate() {
    return acc->activate();
}

void Account::DecoratorAccount::deactivate() {
    return acc->deactivate();
}

void Account::DecoratorAccount::setCurrent(StateActivation *state) {
    return acc->setCurrent(state);
}


void Account::SavingAccount::withdraw(float withdrawalAmount) {
    DecoratorAccount::withdraw(withdrawalAmount);

    this->setBalance(this->getBalance() - withdrawalAmount);
    this->getHistory().find("Withdrawal")->second += withdrawalAmount;
}

void Account::SavingAccount::transfer(Account::AccountFunctions *toAccount, float transferAmount) {
    DecoratorAccount::transfer(toAccount, transferAmount);

    this->setBalance(this->getBalance() - transferAmount);

    toAccount->setBalance(toAccount->getBalance() + transferAmount - transferAmount * this->transactionFeePercentage);
    this->getHistory().find("Transfer")->second += transferAmount;
}

void Account::SavingAccount::deposit(float depositAmount) {
    DecoratorAccount::deposit(depositAmount);
}

float Account::SavingAccount::getBalance() {
    return DecoratorAccount::getBalance();
}

void Account::SavingAccount::setBalance(float newBalance) {
    DecoratorAccount::setBalance(newBalance);
}

std::map<std::string, float> Account::SavingAccount::getHistory() {
    return DecoratorAccount::getHistory();
}

std::string Account::SavingAccount::getAccountName() {
    return DecoratorAccount::getAccountName();
}

std::string Account::SavingAccount::getAccountType() {
    return DecoratorAccount::getAccountType();
}

float Account::SavingAccount::getTransactionFeePercentage() {
    return DecoratorAccount::getTransactionFeePercentage() + this->transactionFeePercentage;
}

void Account::SavingAccount::activate() {
    DecoratorAccount::activate();
}

void Account::SavingAccount::deactivate() {
    DecoratorAccount::deactivate();
}

void Account::SavingAccount::setCurrent(StateActivation *state) {
    DecoratorAccount::setCurrent(state);
}


void Account::CheckingAccount::withdraw(float withdrawalAmount) {
    DecoratorAccount::withdraw(withdrawalAmount);

    this->setBalance(this->getBalance() - withdrawalAmount);
    this->getHistory().find("Withdrawal")->second += withdrawalAmount;
}

void Account::CheckingAccount::transfer(AccountFunctions *toAccount, float transferAmount) {
    DecoratorAccount::transfer(toAccount, transferAmount);

    this->setBalance(this->getBalance()-transferAmount);
    toAccount->setBalance(toAccount->getBalance() + transferAmount - transferAmount * this->transactionFeePercentage);
    this->getHistory().find("Transfer")->second += transferAmount;
}

void Account::CheckingAccount::deposit(float depositAmount) {
    DecoratorAccount::deposit(depositAmount);
}

float Account::CheckingAccount::getBalance() {
    return DecoratorAccount::getBalance();
}

void Account::CheckingAccount::setBalance(float newBalance) {
    DecoratorAccount::setBalance(newBalance);
}

std::map<std::string, float> Account::CheckingAccount::getHistory() {
    return DecoratorAccount::getHistory();
}

std::string Account::CheckingAccount::getAccountName() {
    return DecoratorAccount::getAccountName();
}

std::string Account::CheckingAccount::getAccountType() {
    return DecoratorAccount::getAccountType();
}

float Account::CheckingAccount::getTransactionFeePercentage() {
    return DecoratorAccount::getTransactionFeePercentage() + this->transactionFeePercentage;
}

void Account::CheckingAccount::activate() {
    DecoratorAccount::activate();
}

void Account::CheckingAccount::deactivate() {
    DecoratorAccount::deactivate();
}

void Account::CheckingAccount::setCurrent(StateActivation *state) {
    DecoratorAccount::setCurrent(state);
}


void Account::BusinessAccount::withdraw(float withdrawalAmount) {
    DecoratorAccount::withdraw(withdrawalAmount);

    this->setBalance(this->getBalance() - withdrawalAmount);
    this->getHistory().find("Withdrawal")->second += withdrawalAmount;
}

void Account::BusinessAccount::transfer(Account::AccountFunctions *toAccount, float transferAmount) {
    DecoratorAccount::transfer(toAccount, transferAmount);

    this->setBalance(this->getBalance()-transferAmount);
    toAccount->setBalance(toAccount->getBalance() + transferAmount - transferAmount * this->transactionFeePercentage);
    this->getHistory().find("Transfer")->second += transferAmount;
}

void Account::BusinessAccount::deposit(float depositAmount) {
    DecoratorAccount::deposit(depositAmount);
}

float Account::BusinessAccount::getBalance() {
    return DecoratorAccount::getBalance();
}

void Account::BusinessAccount::setBalance(float newBalance) {
    DecoratorAccount::setBalance(newBalance);
}

std::map<std::string, float> Account::BusinessAccount::getHistory() {
    return DecoratorAccount::getHistory();
}

std::string Account::BusinessAccount::getAccountName() {
    return DecoratorAccount::getAccountName();
}

std::string Account::BusinessAccount::getAccountType() {
    return DecoratorAccount::getAccountType();
}

float Account::BusinessAccount::getTransactionFeePercentage() {
    return DecoratorAccount::getTransactionFeePercentage() + this->transactionFeePercentage;
}

void Account::BusinessAccount::activate() {
    DecoratorAccount::activate();
}

void Account::BusinessAccount::deactivate() {
    DecoratorAccount::deactivate();
}

void Account::BusinessAccount::setCurrent(StateActivation *state) {
    DecoratorAccount::setCurrent(state);
}


void Account::StateActivation::activate(Account::AccountFunctions *account) {
    ErrorHandling::ErrorHandling::ActivateAnActivatedAccountError(account->getAccountName());
}

void Account::StateActivation::deactivate(Account::AccountFunctions *account) {
    ErrorHandling::ErrorHandling::DeactivateADeactivatedAccountError(account->getAccountName());
}


void Account::ACTIVATE::deactivate(AccountFunctions *account) {
    account->setCurrent(new DEACTIVATE());
    delete this;
}


void Account::DEACTIVATE::activate(AccountFunctions *account) {
    account->setCurrent(new ACTIVATE());
    delete this;
}
