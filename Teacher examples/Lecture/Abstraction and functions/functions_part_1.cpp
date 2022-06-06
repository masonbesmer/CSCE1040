#include <iostream>
using namespace std;

void PrintPizzaArea() {
   double pizzaDiameter;
   double pizzaRadius;
   double pizzaArea;
   double piVal = 3.14159265;

   pizzaDiameter = 12.0;
   pizzaRadius = pizzaDiameter / 2.0;
   pizzaArea = piVal * pizzaRadius * pizzaRadius;
   cout << pizzaDiameter << " inch pizza is ";
   cout << pizzaArea << " inches squared." << endl;
}

int PrintTest(){
    int a = 3;
    int b = 5;
    int c = a + b;
    
    return c;
}

int main() {
   int z;
   PrintPizzaArea();
   
   cout << endl;
   z = PrintTest();
   
   z = z + 5;
   
   cout << "Test " << z << endl;
   return 0;
}
