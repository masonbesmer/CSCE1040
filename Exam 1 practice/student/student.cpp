#include "student.h"

Student::Student() {
    Name = "";
    ID = 0;
    Gender = 'N';
    Race = "";
    Major = "";
    Minor = "";
    GPA = 0.0;
}

Student::Student(string name, int id, char gender, string race, string major, string minor, double gpa)
{
    Name = name;
    ID = id;
    Gender = gender;
    Race = race;
    Major = major;
    Minor = minor;
    GPA = gpa;
}

void Student::SetName(string name)
{
    Name = name;
}

void Student::SetID(int id)
{
    ID = id;
}

void Student::SetGender(char gender)
{
    Gender = gender;
}

void Student::SetRace(string race)
{
    Race = race;
}

void Student::SetMajor(string major)
{
    Major = major;
}

void Student::SetMinor(string minor)
{
    Minor = minor;
}

void Student::SetGPA(double gpa)
{
    GPA = gpa;
}

string Student::GetName()
{
    return Name;
}

int Student::GetID()
{
    return ID;
}

char Student::GetGender()
{
    return Gender;
}

string Student::GetRace()
{
    return Race;
}

string Student::GetMajor()
{
    return Major;
}

string Student::GetMinor()
{
    return Minor;
}

double Student::GetGPA()
{
    return GPA;
}

void Student::PrintInfo()
{
    cout << "=====================" << endl;
    cout << "Name: " << Name << endl;
    cout << "ID: " << ID << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Race: " << Race << endl;
    cout << "Major: " << Major << endl;
    cout << "Minor: " << Minor << endl;
    cout << "GPA: " << GPA << endl;
}