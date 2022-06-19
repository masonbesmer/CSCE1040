#include "Product.h"
using namespace std;

void Product::SetPriceAndName(int productPrice, string productName) {
   price = productPrice;
   name = productName;
}

int Product::GetPrice() const {
   return price;
}

string Product::GetName() const {
   return name;
}