/* Test reference declaration and initialization (TestReferenceDeclaration.cpp) */ 
#include <iostream> 
using namespace std; 
  
int main() { 
   int number = 88;          // Declare an int variable called number 
   int & refNumber = number; // Declare a reference (alias) to the variable number 
                             // Both refNumber and number refer to the same value 
  
   cout << number << endl;    // Print value of variable number (88) 
   cout << refNumber << endl; // Print value of reference (88) 
  
   refNumber = 99;            // Re-assign a new value to refNumber 
   cout << refNumber << endl; 
   cout << number << endl;    // Value of number also changes (99) 
  
   number = 55;               // Re-assign a new value to number 
   cout << number << endl; 
   cout << refNumber << endl; // Value of refNumber also changes (55) 
}