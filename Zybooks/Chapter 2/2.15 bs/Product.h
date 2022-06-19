#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product {
   public:
      void SetPriceAndName(int productPrice, std::string productName);
      int GetPrice() const;
      std::string GetName() const;
   private:
      int price;
      std::string name;
};
#endif