#include "car.h"

void Car::setModelYear(int modelYear)
{
    this->modelYear = modelYear;
}

void Car::setPurchasePrice(int purcahsePrice)
{
    this->purchasePrice = purcahsePrice;
}

void Car::calcCurrentValue(int currentYear)
{
    double depreciationRate = 0.10;
    int carAge = currentYear - modelYear;

    //depreciation formula
    currentValue = (int) round(purchasePrice * pow((1 - depreciationRate), carAge));
}

int Car::getModelYear() const
{
    return modelYear;
}

int Car::getPurchasePrice() const
{
    return purchasePrice;
}

int Car::getCurrentValue() const
{
    return currentValue;
}

void Car::PrintInfo() const
{
    cout << "============== Car Info ===============" << endl;
    cout << "Model Year: " << modelYear << endl;
    cout << "Purchase Price: " << purchasePrice << endl;
    cout << "Current Value: " << currentValue << endl;
}