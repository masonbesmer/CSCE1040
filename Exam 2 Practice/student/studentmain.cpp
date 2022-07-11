#include "student.h"

int main()
{
    vector<Student*> myStudents;
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
        cout << "Enter Gender for student M/F#" << i+1 << ": "; cin >> Gender; cout << endl;
        cout << "Enter GPA for student #" << i+1 << ": "; cin >> GPA; cout << endl;
        cout << "Enter Race for student #" << i+1 << ": "; cin >> Race; cout << endl;

        cin.ignore();

        myStudents.push_back(new Student(Name, ID, Gender, Race, Major, Minor, GPA));
    }

    for (auto it = myStudents.begin(); it != myStudents.end(); it++)
    {
        (*it)->PrintInfo();
    }

    for (auto it = myStudents.begin(); it != myStudents.end(); it++)
    {
        delete *it;
    }

    myStudents.clear();

    cout << "Allocated space cleared." << endl;

    return 0;
}