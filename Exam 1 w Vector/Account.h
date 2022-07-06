#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
    private:
        string Name;
        double SavingsBalance;
        double CheckingBalance;
    public:
        Account(string, double, double);
        Account();
        void SetName(string);
        string GetName();
        void SetChecking(double);
        double GetChecking();
        void SetSavings(double);
        double GetSavings();
        void DepositChecking(double);
        void DepositSavings(double);
        void WithdrawChecking(double);
        void WithdrawSavings(double);
        void TransferToSavings(double);
        void Print();
};


#endif