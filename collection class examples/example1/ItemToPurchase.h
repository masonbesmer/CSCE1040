/*
* File: ItemToPurchase.h
* Description: This is an .h file. .h files contain class definitions. A class definition starts
* with the keyword class followed by the name of the class and then {}. Inside the {} we will
* have a block of code containing the class functions and the class data members.
* Class functions are public because they are the ones that will be called in main when working with 
* objects of said class. Class data members are private because main or other classes/objects
* cannot access the data members of another class. Only the functions of each class can access its
* data members.
* It is possible to have private functions and public data members but we are not working with those
* in this example.
*/

#ifndef ITEM_TO_PURCHASE_H // header file guard
#define ITEM_TO_PURCHASE_H // header file guard


#include <string>
using namespace std;

class ItemToPurchase {
   
   public:
      ItemToPurchase(); // Default constructor
      ItemToPurchase(string name, string description, 
                  int price, int quantity = 1); // Constructor with arguments. Constructor overloading
      
      void SetName(string name); // Mutator function
      void SetDescription(string description); // Mutator function
      void SetPrice(int price); // Mutator function
      void SetQuantity(int quantity); // Mutator function
      
      string GetName() const; // Accessor function
      string GetDescription() const; // Accessor function
      int GetPrice() const; // Accessor function
      int GetQuantity() const; // Accessor function
      
      void PrintItemCost(); // Accessor function
      void PrintItemDescription(); // Accessor function
   
   private:
      string itemName;
      string itemDescription;
      int itemPrice;
      int itemQuantity;
};


#endif // header file guard

/*
* STUDY NOTE: 
* #ifndef FILENAME_H
* #define FILENAME_H
* #endif
* These are called header file guards. In between the header file guards, you write the
* contents of your .h files. Header file guards are important. Their function is to tell the 
* C++ compiler to only include the content of your .h file once.
*/