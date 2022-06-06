#include <iostream>
#include <string>
using namespace std;

class Book {
   public:
      void SetTitle(string bookTitle) { title = bookTitle; }
      void SetNumPages(int bookNumPages) { numPages = bookNumPages; }
      void Print() const {
         cout << title << ". Pages: " << numPages << endl;
      }

   private:
      string title;
      int numPages;
};

int main() {
   Book myBook;

   myBook.SetTitle("It");
   myBook.SetNumPages(1138);

   myBook.Print();

   return 0;
}
