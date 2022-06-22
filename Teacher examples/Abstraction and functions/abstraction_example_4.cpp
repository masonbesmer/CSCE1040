#include <iostream>
#include <string>
using namespace std;

class Book {
   public:
      void SetTitle(string bookTitle) {
         title = bookTitle;
      }
      void SetAuthor(string bookAuthor) {
         author = bookAuthor;
      }
      void Print() const {
         cout << title << " by " << author << endl;
      }

   private:
      string title;
      string author;
};

int main() {
   Book myBook;

   myBook.SetAuthor("N. G. Carr");
   myBook.SetTitle("The Shallows");

   myBook.Print();

   return 0;
}
