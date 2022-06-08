#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Loan
{
    private:
        int LoanID;
        int BookID;
        int PatronID;
        time_t DueDate; //int because I will use unix time.
        string Status;
        double Fine; //might not be used/needed. (implemented elsewhere)

    public:
        void setLoanID(int LoanID) {this->LoanID = LoanID;}
        void setBookID(int BookID) {this->BookID = BookID;}
        void setPatronID(int PatronID) {this->PatronID = PatronID;}
        void setDueDate(time_t DueDate) {this->DueDate = DueDate;}
        void setStatus(string Status) {this->Status = Status;}
        void setFine(double Fine) {this->Fine = Fine;}

        int getLoanID() { return LoanID; }
        int getBookID() { return BookID; }
        int getPatronID() { return PatronID; }
        time_t getDueDate() { return DueDate; }
        string getStatus() { return Status; }
        double getFine() { return Fine; }

        void Print() {
            cout << "Loan ID: " << LoanID << endl;
            cout << "Book ID: " << BookID << endl;
            cout << "Patron ID: " << PatronID << endl;
            cout << "Due Date: " << ctime(&DueDate);
            cout << "Status: " << Status << endl;
            cout << "Fine: $" << Fine << endl;
        }
};

int main()
{
    Loan loan;
    loan.setLoanID(1);
    loan.setBookID(2);
    loan.setPatronID(3);
    loan.setDueDate(time(NULL)+84600);
    loan.setStatus("Overdue");
    loan.setFine(1.80);
    loan.Print();

    ////////////////////////////////////////////////////////////////////////////////

    Loan loan2;
    loan2.setLoanID(2);
    loan2.setBookID(3);
    loan2.setPatronID(4);
    loan2.setDueDate(time(NULL)+84600);
    loan2.setStatus("Overdue");
    loan2.setFine(1.80);
    loan2.Print();

    return 0;
}