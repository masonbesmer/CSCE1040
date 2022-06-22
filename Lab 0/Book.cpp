#include <iostream>
#include <string>
using namespace std;

class Book
{
	private:
		string Author;
		string Title;
		int ISBN_NUM;
		int LID_NUM; //library ID number
		double Cost;
		string Status;
	public:
		void SetAuthor(string Author) {this->Author = Author;}
		void SetTitle(string Title) {this->Title = Title;}
		void SetISBN_NUM(int ISBN_NUM) {this->ISBN_NUM = ISBN_NUM;}
		void SetLID_NUM(int LID_NUM) {this->LID_NUM = LID_NUM;}
		void SetCost(double Cost) {this->Cost = Cost;}
		void SetStatus(string Status) {this->Status = Status;}
		
		string GetAuthor() {return Author;}
		string GetTitle() {return Title;}
		int GetISBN_NUM() {return ISBN_NUM;}
		int GetLID_NUM() {return LID_NUM;}
		double GetCost() {return Cost;}
		string GetStatus() {return Status;}

		void Print()
		{
			cout << "Author: " << Author << endl;
			cout << "Title: " << Title << endl;
			cout << "ISBN_NUM: " << ISBN_NUM << endl;
			cout << "LID_NUM: " << LID_NUM << endl;
			cout << "Cost: " << Cost << endl;
			cout << "Status: " << Status << endl;
		}

		Book() //blank constructor to avoid nil values.
		{
			Author = "";
			Title = "";
			ISBN_NUM = 0;
			LID_NUM = 0;
			Cost = 0;
			Status = "";
		}
};

int main()
{
	Book book1;
	book1.SetAuthor("John Doe");
	book1.SetTitle("The Great Book");
	book1.SetISBN(123456789);
	book1.SetLID(12345);
	book1.SetCost(12.99);
	book1.SetStatus("Available");
	book1.Print();

	///////////////////////////////////////////////////////////////////////////////////

	Book book2;
	book2.SetAuthor("Jane Doe");
	book2.SetTitle("The Great Book");
	book2.SetISBN(123456789);
	book2.SetLID(12345);
	book2.SetCost(12.99);
	book2.SetStatus("Available");
	book2.Print();


	return 0;
}