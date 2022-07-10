#include <iostream>
#include <cmath>
#ifndef CAR_H
#define CAR_H
using namespace std;

class Car
{
	private:
		int modelYear, purchasePrice, currentValue;
	public:
		void setModelYear(int modelYear); //mutate
		void setPurchasePrice(int purchasePrice);
		void calcCurrentValue(int curentValue);
		int getModelYear() const; //access
		int getPurchasePrice() const;
		int getCurrentValue() const;
		void PrintInfo() const;
};

#endif
