#include "cat.h"
#include "animal.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {

    vector<Animal*> animals;

    float weight;
    string name;
    char sex;
    string color;
    string breed;
    bool fixed;
    string id;
    string notes;

    for(int i = 0; i < 3; i++) {
        cout << "============cat# " << i + 1 << "================" << endl;
        cout << "Enter weight: "; cin >> weight;
        cin.ignore();
        cout << "Enter name: "; getline(cin, name);
        cout << "Enter sex: "; cin >> sex;
        cin.ignore();
        cout << "Enter color: "; getline(cin,color);
        cout << "Enter breed: "; getline(cin, breed);
        cout << "Spayed/neutered?0/1 "; cin >> fixed;
        cin.ignore();
        cout << "Enter id: "; getline(cin, id);
        cout << "Enter notes: "; getline(cin, notes);
        cout << "==================================" << endl;

        animals.push_back(new Cat(weight,name,sex,color,breed,fixed,id,notes));
    }

    for(auto itr=animals.begin(); itr!=animals.end(); itr++) {
        cout << "==================================" <<endl;
        (*itr)->Print();
    }
    
    for(auto itr=animals.begin(); itr!=animals.end(); itr++) {
        delete *itr;
    }

    animals.clear();
    cout << "Space cleared." << endl;

    return 0;
}