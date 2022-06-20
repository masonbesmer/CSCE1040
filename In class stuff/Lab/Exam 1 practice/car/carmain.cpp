#include "car.h"

int main()
{
    Car* myCars = new Car[6];
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

        myCars[i].SetMake(Make);
        myCars[i].SetModel(Model);
        myCars[i].SetWeight(Weight);
        myCars[i].SetModelYear(ModelYear);
        myCars[i].SetPrice(Price);
        myCars[i].SetColor(Color);
        myCars[i].SetMPG(MPG);
    }

    for (int i =0; i<6; i++)
    {
        myCars[i].PrintInfo();
    }

    delete [] myCars;
    
    return 0;
}