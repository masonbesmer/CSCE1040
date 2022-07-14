#include "horse.h"

Horse::Horse()
{
    this->Breed="";
    this->Name="";
    this->ID="";
    this->Color="";
    this->Notes="";
    this->Weight=0.0;
    this->Sex='M';
    this->Fixed=false;
}

Horse::Horse(string Breed, float Weight, char Sex, bool Fixed, string Name, string ID, string Color, string Notes)
{
    this->Breed=Breed;
    this->Weight=Weight;
    this->Sex=Sex;
    this->Fixed=Fixed;
    this->Name=Name;
    this->ID=ID;
    this->Color=Color;
    this->Notes=Notes;
}

string Horse::GetBreed() {return this->Breed;}
float Horse::GetWeight() {return this->Weight;}
char Horse::GetSex() {return this->Sex;}
bool Horse::GetIsFixed() {return this->Fixed;}
string Horse::GetID() {return this->ID;}
string Horse::GetColor() {return this->Color;}
string Horse::GetNotes() {return this->Notes;}

void Horse::SetBreed(string Breed) {this->Breed=Breed;}
void Horse::SetWeight(float Weight) {this->Weight=Weight;}
void Horse::SetSex(char Sex) {this->Sex=Sex;}
void Horse::SetIsFixed(bool Fixed) {this->Fixed=Fixed;}
void Horse::SetID(string ID) {this->ID=ID;}
void Horse::SetColor(string Color) {this->Color=Color;}
void Horse::SetNotes(string Notes) {this->Notes=Notes;}

void Horse::PrintInfo()
{
    cout << "==========================================================" << endl;
    cout<<"Breed: "<<this->Breed<<endl;
    cout<<"Weight: "<<this->Weight<<endl;
    cout<<"Name: "<<this->Name<<endl;
    cout<<"Sex: "<<this->Sex<<endl;
    cout<<"Fixed: "<<this->Fixed<<endl;
    cout<<"ID: "<<this->Notes<<endl;
    cout<<"Color: "<<this->Color<<endl;
    cout<<"Notes: "<<this->Notes<<endl;
    cout<<"==========================================================" << endl;
}