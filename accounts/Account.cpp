#include "Account.h"
// constructor of the base class account (default in Decorator)
Account::Account::Account(const std::string &accountType, const std::string &accountName, float initialDeposit) {
    this->accountType               = accountType       ;   // type of account
    this->accountName               = accountName       ;   // name of account
    this->balance                   = initialDeposit    ;   // default amount money on the account

    this->history["InitialDeposit"] = initialDeposit    ;   // default amount initial deposit on the account write in the history
    this->history["Deposit"]        = 0.0               ;   // default amount Deposit on the account write in the history
    this->history["Withdrawal"]     = 0.0               ;   // default amount Withdrawal on the account write in the history
    this->history["Transfer"]       = 0.0               ;   // default amount Transfer on the account write in the history

    this->current = new ACTIVATE();                         // default state of the activity of the user
}
// default function withdraw of the account
void Account::Account::withdraw(float withdrawalAmount) { this->history.find("Withdrawal")->second += withdrawalAmount; }
// default function transfer of the account
void Account::Account::transfer(Account::AccountFunctions *toAccount, float transferAmount) { this->history.find("Transfer")->second += transferAmount; }
// default function deposit of the account
void Account::Account::deposit(float depositAmount) {
    this->balance += depositAmount;
    this->history.find("Deposit")->second += depositAmount;
}
// default getter of balance of the account
float Account::Account::getBalance() {
    return this->balance;
}
// default setter of balance of the account
void Account::Account::setBalance(float newBalance) {
    this->balance = newBalance;
}
// default getter of history of the account
std::map<std::string, float> Account::Account::getHistory() {
    return this->history;
}
// default getter of name of the account
std::string Account::Account::getAccountName() {
    return this->accountName;
}
// default getter of type of the account
std::string Account::Account::getAccountType() {
    return this->accountType;
}
// default getter of transaction fee percentage of the account
float Account::Account::getTransactionFeePercentage() {
    return 0.0;
}
// default function activate
void Account::Account::activate() {
    current->activate(this);
}
// default function deactivate
void Account::Account::deactivate() {
    current->deactivate(this);
}

// constructor of linking class in decorator
Account::DecoratorAccount::DecoratorAccount(Account::AccountFunctions *a) {
    acc = a;
}
// calling default function withdraw
void Account::DecoratorAccount::withdraw(float withdrawalAmount) {
    return acc->withdraw(withdrawalAmount);
}
// calling default function transfer
void Account::DecoratorAccount::transfer(Account::AccountFunctions *toAccount, float transferAmount) {
    return acc->transfer(toAccount, transferAmount);
}
// calling default function deposit
void Account::DecoratorAccount::deposit(float depositAmount) {
    return acc->deposit(depositAmount);
}
// calling default function getBalance
float Account::DecoratorAccount::getBalance() {
    return acc->getBalance();
}
// calling default function setBalance
void Account::DecoratorAccount::setBalance(float newBalance) {
    acc->setBalance(newBalance);
}
// calling default function getHistory
std::map<std::string, float> Account::DecoratorAccount::getHistory() {
    return acc->getHistory();
}
// calling default function getAccountName
std::string Account::DecoratorAccount::getAccountName() {
    return acc->getAccountName();
}
// calling default function getAccountType
std::string Account::DecoratorAccount::getAccountType() {
    return acc->getAccountType();
}
// calling default function getTransactionFeePercentage
float Account::DecoratorAccount::getTransactionFeePercentage() {
    return acc->getTransactionFeePercentage();
}
// calling default function activate
void Account::DecoratorAccount::activate() {
    return acc->activate();
}
// calling default function deactivate
void Account::DecoratorAccount::deactivate() {
    return acc->deactivate();
}
// calling default function setCurrent
void Account::DecoratorAccount::setCurrent(StateActivation *state) {
    return acc->setCurrent(state);
}
// calling default function getCurrentStateAccount
Account::StateActivation *Account::DecoratorAccount::getCurrentStateAccount() {
    return acc->getCurrentStateAccount();
}

// calling default function withdraw + additional functional of the SavingAccount account's type
void Account::SavingAccount::withdraw(float withdrawalAmount) {
    DecoratorAccount::withdraw(withdrawalAmount);

    this->setBalance(this->getBalance() - withdrawalAmount);
}
// calling default function transfer + additional functional of the SavingAccount account's type
void Account::SavingAccount::transfer(Account::AccountFunctions *toAccount, float transferAmount) {
    DecoratorAccount::transfer(toAccount, transferAmount);

    this->setBalance(this->getBalance() - transferAmount);

    toAccount->setBalance(toAccount->getBalance() + transferAmount - transferAmount * this->transactionFeePercentage);
}
// calling default function deposit + additional functional of the SavingAccount account's type
void Account::SavingAccount::deposit(float depositAmount) {
    DecoratorAccount::deposit(depositAmount);
}
// calling default function getBalance + additional functional of the SavingAccount account's type
float Account::SavingAccount::getBalance() {
    return DecoratorAccount::getBalance();
}
// calling default function setBalance + additional functional of the SavingAccount account's type
void Account::SavingAccount::setBalance(float newBalance) {
    DecoratorAccount::setBalance(newBalance);
}
// calling default function getHistory + additional functional of the SavingAccount account's type
std::map<std::string, float> Account::SavingAccount::getHistory() {
    return DecoratorAccount::getHistory();
}
// calling default function getAccountName + additional functional of the SavingAccount account's type
std::string Account::SavingAccount::getAccountName() {
    return DecoratorAccount::getAccountName();
}
// calling default function getAccountType + additional functional of the SavingAccount account's type
std::string Account::SavingAccount::getAccountType() {
    return DecoratorAccount::getAccountType();
}
// calling default function getTransactionFeePercentage + additional functional of the SavingAccount account's type
float Account::SavingAccount::getTransactionFeePercentage() {
    return DecoratorAccount::getTransactionFeePercentage() + this->transactionFeePercentage;
}
// calling default function activate + additional functional of the SavingAccount account's type
void Account::SavingAccount::activate() {
    DecoratorAccount::activate();
}
// calling default function deactivate + additional functional of the SavingAccount account's type
void Account::SavingAccount::deactivate() {
    DecoratorAccount::deactivate();
}
// calling default function setCurrent + additional functional of the SavingAccount account's type
void Account::SavingAccount::setCurrent(StateActivation *state) {
    DecoratorAccount::setCurrent(state);
}
// calling default function getCurrentStateAccount + additional functional of the SavingAccount account's type
Account::StateActivation *Account::SavingAccount::getCurrentStateAccount() {
    return DecoratorAccount::getCurrentStateAccount();
}

// calling default function withdraw + additional functional of the CheckingAccount account's type
void Account::CheckingAccount::withdraw(float withdrawalAmount) {
    DecoratorAccount::withdraw(withdrawalAmount);

    this->setBalance(this->getBalance() - withdrawalAmount);
}
// calling default function transfer + additional functional of the CheckingAccount account's type
void Account::CheckingAccount::transfer(AccountFunctions *toAccount, float transferAmount) {
    DecoratorAccount::transfer(toAccount, transferAmount);

    this->setBalance(this->getBalance()-transferAmount);
    toAccount->setBalance(toAccount->getBalance() + transferAmount - transferAmount * this->transactionFeePercentage);
}
// calling default function deposit + additional functional of the CheckingAccount account's type
void Account::CheckingAccount::deposit(float depositAmount) {
    DecoratorAccount::deposit(depositAmount);
}
// calling default function getBalance + additional functional of the CheckingAccount account's type
float Account::CheckingAccount::getBalance() {
    return DecoratorAccount::getBalance();
}
// calling default function setBalance + additional functional of the CheckingAccount account's type
void Account::CheckingAccount::setBalance(float newBalance) {
    DecoratorAccount::setBalance(newBalance);
}
// calling default function getHistory + additional functional of the CheckingAccount account's type
std::map<std::string, float> Account::CheckingAccount::getHistory() {
    return DecoratorAccount::getHistory();
}
// calling default function getAccountName + additional functional of the CheckingAccount account's type
std::string Account::CheckingAccount::getAccountName() {
    return DecoratorAccount::getAccountName();
}
// calling default function getAccountType + additional functional of the CheckingAccount account's type
std::string Account::CheckingAccount::getAccountType() {
    return DecoratorAccount::getAccountType();
}
// calling default function getTransactionFeePercentage + additional functional of the CheckingAccount account's type
float Account::CheckingAccount::getTransactionFeePercentage() {
    return DecoratorAccount::getTransactionFeePercentage() + this->transactionFeePercentage;
}
// calling default function activate + additional functional of the CheckingAccount account's type
void Account::CheckingAccount::activate() {
    DecoratorAccount::activate();
}
// calling default function deactivate + additional functional of the CheckingAccount account's type
void Account::CheckingAccount::deactivate() {
    DecoratorAccount::deactivate();
}
// calling default function setCurrent + additional functional of the CheckingAccount account's type
void Account::CheckingAccount::setCurrent(StateActivation *state) {
    DecoratorAccount::setCurrent(state);
}
// calling default function getCurrentStateAccount + additional functional of the CheckingAccount account's type
Account::StateActivation *Account::CheckingAccount::getCurrentStateAccount() {
    return DecoratorAccount::getCurrentStateAccount();
}

// calling default function withdraw + additional functional of the BusinessAccount account's type
void Account::BusinessAccount::withdraw(float withdrawalAmount) {
    DecoratorAccount::withdraw(withdrawalAmount);

    this->setBalance(this->getBalance() - withdrawalAmount);
}
// calling default function transfer + additional functional of the BusinessAccount account's type
void Account::BusinessAccount::transfer(Account::AccountFunctions *toAccount, float transferAmount) {
    DecoratorAccount::transfer(toAccount, transferAmount);

    this->setBalance(this->getBalance()-transferAmount);
    toAccount->setBalance(toAccount->getBalance() + transferAmount - transferAmount * this->transactionFeePercentage);
}
// calling default function deposit + additional functional of the BusinessAccount account's type
void Account::BusinessAccount::deposit(float depositAmount) {
    DecoratorAccount::deposit(depositAmount);
}
// calling default function getBalance + additional functional of the BusinessAccount account's type
float Account::BusinessAccount::getBalance() {
    return DecoratorAccount::getBalance();
}
// calling default function setBalance + additional functional of the BusinessAccount account's type
void Account::BusinessAccount::setBalance(float newBalance) {
    DecoratorAccount::setBalance(newBalance);
}
// calling default function getHistory + additional functional of the BusinessAccount account's type
std::map<std::string, float> Account::BusinessAccount::getHistory() {
    return DecoratorAccount::getHistory();
}
// calling default function getAccountName + additional functional of the BusinessAccount account's type
std::string Account::BusinessAccount::getAccountName() {
    return DecoratorAccount::getAccountName();
}
// calling default function getAccountType + additional functional of the BusinessAccount account's type
std::string Account::BusinessAccount::getAccountType() {
    return DecoratorAccount::getAccountType();
}
// calling default function getTransactionFeePercentage + additional functional of the BusinessAccount account's type
float Account::BusinessAccount::getTransactionFeePercentage() {
    return DecoratorAccount::getTransactionFeePercentage() + this->transactionFeePercentage;
}
// calling default function activate + additional functional of the BusinessAccount account's type
void Account::BusinessAccount::activate() {
    DecoratorAccount::activate();
}
// calling default function deactivate + additional functional of the BusinessAccount account's type
void Account::BusinessAccount::deactivate() {
    DecoratorAccount::deactivate();
}
// calling default function setCurrent + additional functional of the BusinessAccount account's type
void Account::BusinessAccount::setCurrent(StateActivation *state) {
    DecoratorAccount::setCurrent(state);
}
// calling default function getCurrentStateAccount + additional functional of the BusinessAccount account's type
Account::StateActivation *Account::BusinessAccount::getCurrentStateAccount() {
    return DecoratorAccount::getCurrentStateAccount();
}

// handling exception linked with activation of the active account
void Account::StateActivation::activate(Account::AccountFunctions *account) {
    ErrorHandling::ErrorHandling::ActivateAnActivatedAccountError(account->getAccountName());
}
// handling exception linked with deactivation of the inactive account
void Account::StateActivation::deactivate(Account::AccountFunctions *account) {
    ErrorHandling::ErrorHandling::DeactivateADeactivatedAccountError(account->getAccountName());
}

// change activation of the account to inactive
void Account::ACTIVATE::deactivate(AccountFunctions *account) {
    account->setCurrent(new DEACTIVATE());
    delete this;
}
// check of the activation account (return true if activate)
bool Account::ACTIVATE::getState() {
    return true;
}

// change activation of the account to active
void Account::DEACTIVATE::activate(AccountFunctions *account) {
    account->setCurrent(new ACTIVATE());
    delete this;
}
// check of the activation account (return false if inactivate)
bool Account::DEACTIVATE::getState() {
    return false;
}
