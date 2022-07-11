#include "student.h"

int main()
{
    Student* myStudents = new Student[5];
    string Name, Race, Major, Minor;
    int ID;
    char Gender;
    double GPA;

    for (int i=0; i<5; i++)
    {
        cout << "Enter Name for student #" << i+1 << ": "; getline(cin, Name); cout << endl;
        cout << "Enter Major for student #" << i+1 << ": "; getline(cin, Major); cout << endl;
        cout << "Enter Minor for student #" << i+1 << ": "; getline(cin, Minor); cout << endl;
        cout << "Enter ID for student #" << i+1 << ": "; cin >> ID; cout << endl;
        cout << "Enter Gender for student #" << i+1 << ": "; cin >> Gender; cout << endl;
        cout << "Enter GPA for student #" << i+1 << ": "; cin >> GPA; cout << endl;
        cout << "Enter Race for student #" << i+1 << ": "; cin >> Race; cout << endl;

        cin.ignore();

        myStudents[i].SetGender(Gender);
        myStudents[i].SetGPA(GPA);
        myStudents[i].SetID(ID);
        myStudents[i].SetMajor(Major);
        myStudents[i].SetMinor(Minor);
        myStudents[i].SetRace(Race);
    }

    for (int i =0; i<5; i++)
    {
        myStudents[i].PrintInfo();
    }

    delete [] myStudents;

    return 0;
}