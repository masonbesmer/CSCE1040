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
      void Print() const;

   private:
      string title;
      string author;
};

void Book::Print() const {
   cout << title << " by " << author << endl;
}

int main() {
   Book myBook;

   myBook.SetTitle("Cryptonomicon");
   myBook.SetAuthor("N. Stephenson");

   myBook.Print();

   return 0;
}
