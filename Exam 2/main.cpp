#include "horse.h"
#include <vector>

int main()
{
    vector<Horse*> Horses;

    string Breed, Name, ID, Color, Notes;
    float Weight;
    char Sex;
    bool Fixed;

    //iterator cannot be used because vector is not defined in size until you add the objects
    for (int i = 0; i < 4; i++)
    {
        cout << "For horse #" << i+1 << "=======================" << endl;
        cout << "Breed: "; getline(cin, Breed);
        cout << "Weight(0.0): "; cin >> Weight;
        cin.ignore();
        cout << "Name: "; getline(cin, Name);
        cout << "Sex (M/F): "; cin>>Sex;
        cout << "Fixed (0/1): "; cin>>Fixed;
        cout << "ID: "; cin>>ID;
        cin.ignore();
        cout << "Color: "; getline(cin,Color);
        cout << "Notes: "; getline(cin,Notes);
        cout << "===============================================" << endl;
        Horses.push_back(new Horse(Breed, Weight, Sex, Fixed, Name, ID, Color, Notes));
    }

    for (auto it = Horses.begin(); it != Horses.end(); it++)
    {
        (*it)->PrintInfo();
    }

    for (auto it = Horses.begin(); it != Horses.end(); it++)
    {
        delete *it;
    }

    Horses.clear();

    cout << "Space cleared." << endl;

    return 0;
}