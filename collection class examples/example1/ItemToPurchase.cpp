/*
* File: ItemToPurchase.cpp
* Remember that each class will have a corresponding .cpp file and .h file. Two files for each class.
* Description: This file contains the function definitions of all the functions that were declared
* in the file ItemToPurchase.h
* The definition of a function includes the code that each function will be executing.
*/



#include <iostream>
using namespace std;

#include "ItemToPurchase.h" // Always include the corresponding .h file of the class and any other .h files required.

// Using the :: or scope resolution operator.
// The scope resolution operator allows you to link a function to its corresponding class.
// Here the default constructor is used to initialize the values item objects when we create them. 
ItemToPurchase::ItemToPurchase() {
   itemName = "none";
   itemDescription = "none";
   itemPrice = 0;
   itemQuantity = 0;
}

// Constructor with arguments.
ItemToPurchase::ItemToPurchase(string name, string description, 
                               int price, int quantity) {
   itemName = name;
   itemDescription = description;
   itemPrice = price;
   itemQuantity = quantity;
}

// Notice that all methods are associated with the class ItemtoPurchase using ::
void ItemToPurchase::SetName(string name) {
   itemName = name;
}

void ItemToPurchase::SetDescription(string description) {
   itemDescription = description;
}

void ItemToPurchase::SetPrice(int price) {
   itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity) {
   itemQuantity = quantity;
}

string ItemToPurchase::GetName() const {
   return itemName;
}

string ItemToPurchase::GetDescription() const {
   return itemDescription;
}

int ItemToPurchase::GetPrice() const {
   return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
   return itemQuantity;
}

void ItemToPurchase::PrintItemCost() {
   cout << itemName << " " << itemQuantity << " @ $" << itemPrice
   << " = $" << itemPrice * itemQuantity << endl;
}

void ItemToPurchase::PrintItemDescription() {
   cout << itemName << ": " << itemDescription << endl;
}