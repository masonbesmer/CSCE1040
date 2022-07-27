#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>

#include "animal.h"

using namespace std;

class Cat : public Animal
{
    private:
        string Breed;
        bool Fixed;
        string ID;
        string Notes;
    public:
        Cat();
        Cat(float,string,char,string, string, bool, string, string);
        void SetBreed(string);
        void SetFixed(bool);
        void SetID(string);
        void SetNotes(string);

        string GetBreed();
        bool IsFixed();
        string GetID();
        string GetNotes();

        void Print();
};
#endif