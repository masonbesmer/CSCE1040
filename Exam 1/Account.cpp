#include "Account.h"

Account::Account() {
    Name = "";
    SavingsBalance = -1;
    CheckingBalance = -1;
}

Account::Account(string name, double CBalance, double SBalance)
{
    this->Name = name;
    this->CheckingBalance = CBalance;
    this->SavingsBalance = SBalance;
}

void Account::SetName(string name) { this->Name = name; }
string Account::GetName() { return Name; }
void Account::SetChecking(double CBalance) { this->CheckingBalance = CBalance; }
double Account::GetChecking() { return CheckingBalance; }
void Account::SetSavings(double SBalance) { this->SavingsBalance = SBalance; }
double Account::GetSavings() { return SavingsBalance; }
void Account::DepositChecking(double CBalance) { this->CheckingBalance += CBalance; }
void Account::DepositSavings(double SBalance) { this->SavingsBalance += SBalance; }
void Account::WithdrawChecking(double CBalance) { this->CheckingBalance -= CBalance; }
void Account::WithdrawSavings(double SBalance) { this->SavingsBalance -= SBalance; }
void Account::TransferToSavings(double amount)
{
    if (this->CheckingBalance-amount >= 0)
    {
        this->CheckingBalance -= amount;
        this->SavingsBalance += amount;
    }
    else
    {
        cout << "Insufficient funds" << endl;
    }
}

void Account::Print() {
    cout << "==========================================================" << endl;
    cout << "Name: " << Name << endl;
    cout << "Checking Balance: " << CheckingBalance << endl;
    cout << "Savings Balance: " << SavingsBalance << endl;
}