/* Test pointer declaration and initialization (TestPointerInit.cpp) */ 
#include <iostream> 
using namespace std; 
  
int main() { 
   int number = 88;    // Declare an int variable and assign an initial value 
   int * pNumber;      // Declare a pointer variable pointing to an int (or int pointer) 
   pNumber = &number;  // assign the address of the variable number to pointer pNumber 
  
   cout << pNumber << endl;  // Print content of pNumber (0x22ccf0) 
   cout << &number << endl;  // Print address of number (0x22ccf0) 
   cout << *pNumber << endl; // Print value pointed to by pNumber (88) 
   cout << number << endl;   // Print value of number (88) 
  
   *pNumber = 99;            // Re-assign value pointed to by pNumber 
   cout << pNumber << endl;  // Print content of pNumber (0x22ccf0) 
   cout << &number << endl;  // Print address of number (0x22ccf0) 
   cout << *pNumber << endl; // Print value pointed to by pNumber (99) 
   cout << number << endl;   // Print value of number (99) 
                             // The value of number changes via pointer 
  
   cout << &pNumber << endl; // Print the address of pointer variable pNumber (0x22ccec) 
}