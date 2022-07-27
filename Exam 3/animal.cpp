#include "animal.h"

Animal::Animal() {
    Weight = 0;
    Name = "";
    Sex ='a';
    Color = "";
}

Animal::Animal(float Weight, string Name, char Sex, string Color) {
    this->Weight=Weight;
    this->Name=Name;
    this->Sex=Sex;
    this->Color=Color;
}

void Animal::SetWeight(float Weight) {
    this->Weight=Weight;
}

void Animal::SetName(string Name) {
    this->Name=Name;
}

void Animal::SetSex(char Sex) {
    this->Sex=Sex;
}

void Animal::SetColor(string Color) {
    this->Color=Color;
}

float Animal::GetWeight() {
    return Weight;
}

string Animal::GetName() {
    return Name;
}

char Animal::GetSex() {
    return Sex;
}

string Animal::GetColor() {
    return Color;
}

void Animal::Print () {
    cout << "Weight: " << Weight << endl
        << "Name: " << Name << endl
        << "Sex: " << Sex << endl
        << "Color: " << Color << endl;
}