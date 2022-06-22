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

int main() {
   PrintPizzaArea();
   return 0;
}
