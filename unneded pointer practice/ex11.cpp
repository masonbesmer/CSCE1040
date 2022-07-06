// Dynamically allocate global pointers (TestDynamicAllocation.cpp) 
#include <iostream> 
using namespace std; 
  
int * p1, * p2;  // Global int pointers 
  
// This function allocates storage for the int* 
// which is available outside the function 
void allocate() { 
   p1 = new int;     // Allocate memory, initial content unknown 
   *p1 = 88;         // Assign value into location pointed to by pointer 
   p2 = new int(99); // Allocate and initialize 
} 
  
int main() { 
   allocate(); 
   cout << *p1 << endl;  // 88 
   cout << *p2 << endl;  // 99 
   delete p1;  // Deallocate 
   delete p2; 
   return 0; 
}