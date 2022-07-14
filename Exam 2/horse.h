#ifndef horse_h
#define horse_h

#include <iostream>
#include <cstring>

using namespace std;

class Horse
{
    private:
        string Breed, Name, ID, Color, Notes;
        float Weight;
        char Sex;
        bool Fixed;
    public:
        Horse();
        Horse(string, float, char, bool, string, string, string, string);
        string GetBreed();
        float GetWeight();
        char GetSex();
        bool GetIsFixed();
        string GetID();
        string GetColor();
        string GetNotes();
        
        void SetBreed(string);
        void SetWeight(float);
        void SetSex(char);
        void SetIsFixed(bool);
        void SetID(string);
        void SetColor(string);
        void SetNotes(string);
        
        void PrintInfo();
};

#endif