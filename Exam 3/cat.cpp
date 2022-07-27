#include "cat.h"

Cat::Cat() {
    SetWeight(0);
    SetName("");
    SetSex('m');
    SetColor("");
    Breed = "";
    Fixed = 0;
    ID = "";
    Notes = "";
}

Cat::Cat(float Weight, string Name, char Sex, string Color, string Breed, bool Fixed, string ID, string Notes) {
    SetWeight(Weight);
    SetName(Name);
    SetSex(Sex);
    SetColor(Color);
    this->Breed=Breed;
    this->Fixed=Fixed;
    this->ID=ID;
    this->Notes=Notes;
}

void Cat::SetBreed(string Breed)
{
    this->Breed = Breed;
}

void Cat::SetFixed(bool Fixed)
{
    this->Fixed = Fixed;
}

void Cat::SetID(string ID)
{
    this->ID = ID;
}

void Cat::SetNotes(string Notes)
{
    this->Notes = Notes;
}

void Cat::Print() {
    cout << "I'm a cat" << endl;
    Animal::Print();
    cout << "Breed: " << Breed << endl;
    cout << "Fixed: " << Fixed << endl;
    cout << "ID: " << ID << endl;
    cout << "Notes: " << Notes << endl;
}