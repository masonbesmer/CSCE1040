/* Test passing the result (TestPassResultLocal.cpp) */ 
#include <iostream> 
using namespace std; 
  
int * squarePtr(int); 
int & squareRef(int); 
  
int main() { 
   int number = 8; 
   cout << number << endl;  // 8 
   cout << *squarePtr(number) << endl;  // ?? 
   cout << squareRef(number) << endl;   // ?? 
} 
  
int * squarePtr(int number) { 
   int localResult = number * number; 
   return &localResult; 
      // warning: address of local variable 'localResult' returned
} 
  
int & squareRef(int number) { 
   int localResult = number * number; 
   return localResult; 
      // warning: reference of local variable 'localResult' returned 
}