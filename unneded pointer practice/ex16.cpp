/* Test sizeof array (TestSizeofArray.cpp) */ 
#include <iostream> 
using namespace std; 
  
// Function prototypes 
void fun(const int *arr, int size); 
  
// Test Driver
int main() { 
   const int SIZE = 5; 
   int a[SIZE] = {8, 4, 5, 3, 2}; 
   cout << "sizeof in main() is " << sizeof(a) << endl; 
   cout << "address in main() is " << a << endl; 
   fun(a, SIZE); 
} 
  
// Function definitions 
void fun(const int *arr, int size) { 
   cout << "sizeof in function is " << sizeof(arr) << endl; 
   cout << "address in function is " << arr << endl; 
}