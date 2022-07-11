#include "Account.h"

int main() {
    Account personal("Alex", 500.00, 1000.00);
    personal.SetChecking(500.00);
    personal.SetSavings(500.00);
    personal.WithdrawSavings(100.00);
    personal.WithdrawChecking(100.00);
    personal.TransferToSavings(100.00);
    personal.Print();

    cout << "Dynamicallly now..." << endl << endl;

    vector<Account*> MyAccounts;

    string names;
    double Checking, Savings;

    for (int i=0; i<4; i++) {
        cout << "Enter name for account " << i+1 << ": "; getline(cin, names);
        cout << "Enter checking balance for account " << i+1 << ": "; cin >> Checking;
        cout << "Enter savings balance for account " << i+1 << ": "; cin >> Savings;
        cin.ignore();
        MyAccounts.push_back(new Account(names, Checking, Savings));
    }

    cout << endl << "Accounts:" << endl;

    for (auto it = MyAccounts.begin(); it != MyAccounts.end(); it++) {
        (*it)->Print();
    }

    for(auto it = MyAccounts.begin(); it != MyAccounts.end(); it++) {
        delete *it;
    }

    cout << "Allocated space cleared." << endl;

    return 0;
}