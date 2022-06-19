#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

int main() {
   vector<Product> productList;
   Product currProduct;
   int currPrice;
   string currName;
   unsigned int i;
   Product resultProduct;

   cin >> currPrice;
   while (currPrice > 0) {
      cin >> currName;
      currProduct.SetPriceAndName(currPrice, currName);
      productList.push_back(currProduct);
      cin >> currPrice;
   }

   resultProduct = productList.at(0);
   for (i = 0; i < productList.size(); ++i) {
      if (productList.at(i).GetPrice() < resultProduct.GetPrice()) {
         resultProduct = productList.at(i);
      }
   }

   cout << resultProduct.GetName() << ": " << resultProduct.GetPrice() << endl;

   return 0;
}