#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h

/*
* Function: PrintMenu()
* Parameters: None
* Objective: This function displays a menu on screen. It is
* a print-only function. It creates a user interface for the user
* of the program
* Return value: None
*/

void PrintMenu() {
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl << endl;
}

/*
* Function: ExecuteMenu()
* Parameters: a char variable, an object of type ShoppingCart passed by reference.
* Objective: This function 
*
*/
void ExecuteMenu(char option, ShoppingCart& theCart) {
   string name;
   string descr;
   int price;
   int quantity;
   ItemToPurchase item;
   
   switch(option) {
      case 'a':
         cin.ignore();

         cout << "ADD ITEM TO CART" << endl;
         cout << "Enter the item name:" << endl;
         getline(cin, name);

         cout << "Enter the item description:" << endl;
         getline(cin, descr);

         cout << "Enter the item price:" << endl;
         cin >> price;

         cout << "Enter the item quantity:" << endl;
         cin >> quantity;
         
         item.SetName(name);
         item.SetDescription(descr);
         item.SetPrice(price);
         item.SetQuantity(quantity);
         
         theCart.AddItem(item);
         cout << endl;
      break;

      case 'd':
         cin.ignore();

         cout << "REMOVE ITEM FROM CART" << endl;
         cout << "Enter name of item to remove:" << endl;
         getline(cin, name);

         theCart.RemoveItem(name);
         cout << endl;
         break;

      case 'c':
         cin.ignore();

         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter the item name:" << endl;
         getline(cin, name);

         cout << "Enter the new quantity:" << endl;
         cin >> quantity;

         item.SetName(name);
         item.SetQuantity(quantity);

         theCart.ModifyItem(item);
         cout << endl;
      break;

      case 'i':
         cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
         theCart.PrintDescriptions();
         cout << endl;
         break;

      case 'o':
         cout << "OUTPUT SHOPPING CART" << endl;
         theCart.PrintTotal();
         cout << endl;
         break;
   }
}

int main() {
   string custName;
   string today;
   char menuChoice;
   
   menuChoice = ' ';

   cout << "Enter customer's name:" << endl;
   getline(cin, custName);

   cout << "Enter today's date:" << endl;
   getline(cin, today);
   cout << endl;

   cout << "Customer name: " << custName << endl;
   cout << "Today's date: " << today << endl << endl;

   ShoppingCart myCart(custName, today);

   PrintMenu();

   while (menuChoice != 'q') {
      cout << "Choose an option:" << endl;
      cin >> menuChoice;
      if (menuChoice == 'a' || menuChoice == 'd' || menuChoice == 'c' ||
          menuChoice == 'i' || menuChoice == 'o') {
         ExecuteMenu(menuChoice, myCart);
         PrintMenu();
      }
   }

   return 0;
}
