#include <iostream>
#include <string>
using namespace std;

class Patron
{
    private:
        string Name;
        int ID;
        double Fine;
        int BooksCheckedOut;
    
    public:
        void setName(string Name) { this->Name = Name; }
        void setID(int ID) { this->ID = ID; }
        void setFine(double Fine) { this->Fine = Fine; }
        void setBooksCheckedOut(int BooksCheckedOut) { this->BooksCheckedOut = BooksCheckedOut; }

        string getName() { return Name; }
        int getID() { return ID; }
        double getFine() { return Fine; }
        int getBooksCheckedOut() { return BooksCheckedOut; }

        void Print()
        {
            cout << "Name: " << Name << endl;
            cout << "ID: " << ID << endl;
            cout << "Fine: " << Fine << endl;
            cout << "Books Checked Out: " << BooksCheckedOut << endl;
        }
};

int main()
{
    Patron patron;
    patron.setName("John Doe");
    patron.setID(12345);
    patron.setFine(0.0);
    patron.setBooksCheckedOut(3);
    patron.Print();

    ////////////////////////////////////////////////////////////////////////////

    Patron patron2;
    patron2.setName("Jane Doe");
    patron2.setID(54321);
    patron2.setFine(1.80);
    patron2.setBooksCheckedOut(2);
    patron2.Print();
    return 0;
}
