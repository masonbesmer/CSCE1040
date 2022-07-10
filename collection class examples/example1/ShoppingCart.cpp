/*
* File: ShoppingCart.cpp
* Description: Contains the definitions of the ShoppingCart class as declared in ShoppingCart.h
*
*/


#include <iostream>
using namespace std;

#include "ShoppingCart.h"

// Default constructor that initializes the object's data members when it is called.
ShoppingCart::ShoppingCart() {
   customerName = "none";
   currentDate = "January 1, 2016";
}

// Constructor with arguments.
ShoppingCart::ShoppingCart(string name, string date) {
   customerName = name;
   currentDate = date;
}

string ShoppingCart::GetCustomerName() const {
   return customerName;
}

string ShoppingCart::GetDate() const {
   return currentDate;
}
      

/*
* Function: AddItem()
* It is linked to the ShoppingCart class using the scope resolution operator ::
* The parameter of this function is an object of type ItemToPurchase and it is passed by value.
* It is passed by value because a copy of that object will be added to the vector cartItems using
* the method push_back().
*/
void ShoppingCart::AddItem(ItemToPurchase item) {
   cartItems.push_back(item);
}


void ShoppingCart::RemoveItem(string name) {
   unsigned i = 0;
   unsigned posItem;
   unsigned cartSize;
   bool found;
   
   posItem = 0;
   cartSize = cartItems.size();
   found = false;
   
   for(i = 0; i < cartSize; ++i) {
      if(cartItems.at(i).GetName() == name && i != (cartSize - 1)) {
         found = true;
         cartItems.at(i) = cartItems.at(i + 1);
         posItem = i;
      }
      
      if(i > posItem && i != (cartSize - 1) && found) {
         cartItems.at(i) = cartItems.at(i + 1);
      }
   }
   
   if(!found) {
      cout << "Item not found in cart. Nothing removed." << endl;
   }
   
   cartItems.resize(cartSize - 1);
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
   unsigned i;
   ItemToPurchase currItem;
   bool found;
   
   found = false;
   
   for(i = 0; i < cartItems.size(); ++i) {
      if(cartItems.at(i).GetName() == item.GetName()) {
         found = true;
         if(item.GetDescription() != "none") {
            cartItems.at(i).SetDescription(item.GetDescription());
         } 
         
         if(item.GetPrice() != 0) {
            cartItems.at(i).SetPrice(item.GetPrice());
         }
         
         if(item.GetQuantity() != 0) {
            cartItems.at(i).SetQuantity(item.GetQuantity());
         }
      }
   }
   
   if(!found) {
      cout << "Item not found in cart. Nothing modified." << endl;
   }
}
      
int ShoppingCart::GetNumItemsInCart() {
   unsigned i;
   int numItems;
   
   numItems = 0;
   
   for(i = 0; i < cartItems.size(); ++i) {
      numItems += cartItems.at(i).GetQuantity();
   }
   
   return numItems;
}

double ShoppingCart::GetCostOfCart() {
   unsigned i = 0;
   int totalCost;
   
   totalCost = 0;
   
   for(i = 0; i < cartItems.size(); ++i) {
      totalCost += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
   }
   
   return totalCost;
}

void ShoppingCart::PrintTotal() {
   unsigned i;
   int totalCost;
   
   totalCost = 0;
   
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
   
   if(cartItems.size() > 0) {
      for(i = 0; i < cartItems.size(); ++i) {
         cartItems.at(i).PrintItemCost();
      }
   }
   
   else {
      cout << "SHOPPING CART IS EMPTY" << endl;
   }
   
   totalCost = GetCostOfCart();
   
   cout << endl << "Total: $" << totalCost << endl;
}

void ShoppingCart::PrintDescriptions() {
   unsigned i;
   
   cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
   cout << "Item Descriptions" << endl;
   
   if(cartItems.size() > 0) {
      for(i = 0; i < cartItems.size(); ++i) {
         cartItems.at(i).PrintItemDescription();
      }
   }
   
   else {
      cout << "SHOPPING CART IS EMPTY" << endl;
   }
}