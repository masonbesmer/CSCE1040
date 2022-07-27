#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal
{
    private:
        float Weight;
        string Name;
        char Sex;
        string Color;
    public:
        Animal();
        Animal(float,string,char,string);
        void SetWeight(float);
        void SetName(string);
        void SetSex(char);
        void SetColor(string);

        float GetWeight();
        string GetName();
        char GetSex();
        string GetColor();

        virtual void Print();
};
#endif