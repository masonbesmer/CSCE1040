#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
    private:
        string Name, Race, Major, Minor;
        int ID;
        char Gender;
        double GPA;
        
    public:
        Student();
        Student(string, int, char, string, string, string, double);
        void SetName(string);
        void SetID(int);
        void SetGender(char);
        void SetRace(string);
        void SetMajor(string);
        void SetMinor(string);
        void SetGPA(double);

        string GetName();
        int GetID();
        char GetGender();
        string GetRace();
        string GetMajor();
        string GetMinor();
        double GetGPA();

        void PrintInfo();
};

#endif