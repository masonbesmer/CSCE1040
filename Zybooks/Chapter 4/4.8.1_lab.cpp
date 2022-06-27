#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> inputIntegers;
   int value = 0;
   while (value != -1) {
      
      cin >> value;
      inputIntegers.push_back(value);
   }
   for (int i=((inputIntegers.at(inputIntegers.size()-2))%2)*((inputIntegers.at(inputIntegers.size()-2))%2); i<inputIntegers.size()-1; i+=2) {
      cout << inputIntegers.at(i) << endl;
   }

   return 0;
}