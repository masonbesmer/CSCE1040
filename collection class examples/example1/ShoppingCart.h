/*
* File: ShoppingCart.h
* Description: This is the .h file of the class ShoppingCart so it has the declaration
* of the class with its public functions and private data members. Like all .h files it contains:
* the default constructor, the constructor with arguments, accessors and mutators. Everything inside
* the header file guards.
* STUDY NOTE: Here we have a vector named cartItems. This vector will not hold ints, floats or strings.
* cartItems is of data type ItemToPurchase. That means that this vector will store objects of type ItemToPurchase.
* It's a vector storing objects. And each object that the vector stores has its own private data members
* and public functions, as the declared in the ItemToPurchase.h and defined in the ItemToPurchase.cpp file.
*/

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
using namespace std;

#include "ItemToPurchase.h" // Always include all the external .h files that will be used in your current file.

class ShoppingCart {
   public:
      ShoppingCart();
      ShoppingCart(string name, string date);
      
      string GetCustomerName() const;
      string GetDate() const;
      
      void AddItem(ItemToPurchase item);
      void RemoveItem(string name);
      
      void ModifyItem(ItemToPurchase item);
      
      int GetNumItemsInCart();
      double GetCostOfCart();
      
      void PrintTotal();
      void PrintDescriptions();
      
   
   private:
      string customerName;
      string currentDate;
      vector<ItemToPurchase> cartItems;
};

#endif