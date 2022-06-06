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
   cout << title << ", " << author << endl;
}

int main() {
   Book myBook;

   myBook.SetTitle("1984");
   myBook.SetAuthor("G. Orwell");

   myBook.Print();

   return 0;
}
