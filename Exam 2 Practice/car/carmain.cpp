#include "car.h"

int main()
{
    vector<Car*> myCars;
    string Make, Model, Color;
    double Weight, Price, MPG;
    int ModelYear;

    for (int i =0; i<6; i++)
    {
        cout << "Enter make for car #" << i+1 << ": "; getline(cin, Make); cout << endl;
        cout << "Enter model for car #" << i+1 << ": "; getline(cin, Model); cout << endl;
        cout << "Enter color for car #" << i+1 << ": "; getline(cin, Color); cout << endl;
        cout << "Enter weight for car #" << i+1 << ": "; cin >> Weight; cout << endl;
        cout << "Enter model year for car #" << i+1 << ": "; cin >> ModelYear; cout << endl;
        cout << "Enter price for car #" << i+1 << ": "; cin >> Price; cout << endl;
        cout << "Enter MPG for car #" << i+1 << ": "; cin >> MPG; cout << endl;

        cin.ignore();

        myCars.push_back(new Car(Make, Model, Weight, ModelYear, Price, Color, MPG));
    }

    for (auto it = myCars.begin(); it != myCars.end(); it++)
    {
        (*it)->PrintInfo();
    }

    for (auto it = myCars.begin(); it != myCars.end(); it++)
    {
        delete *it;
    }

    myCars.clear();

    cout << "Allocated space cleared." << endl;
    
    return 0;
}