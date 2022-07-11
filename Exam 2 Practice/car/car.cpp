#include "car.h"

Car::Car()
{
    Make = "";
    Model = "";
    Weight = 0;
    ModelYear = 0;
    Price = 0;
    Color = "";
    MPG = 0;
}

Car::Car(string make, string model, double weight, int year, double price, string color, double mpg)
{
    Make = make;
    Model = model;
    Weight = weight;
    ModelYear = year;
    Price = price;
    Color = color;
    MPG = mpg;
}

void Car::SetMake(string make)
{
    Make = make;
}

void Car::SetModel(string model)
{
    Model=model;
}

void Car::SetWeight(double weight)
{
    Weight=weight;
}

void Car::SetModelYear(int year)
{
    ModelYear=year;
}

void Car::SetPrice(double price)
{
    Price=price;
}

void Car::SetColor(string color)
{
    Color=color;
}

void Car::SetMPG(double mpg)
{
    MPG=mpg;
}

string Car::GetMake()
{
    return Make;
}

string Car::GetModel()
{
    return Model;
}

double Car::GetWeight()
{
    return Weight;
}

int Car::GetModelYear()
{
    return ModelYear;
}

double Car::GetPrice()
{
    return Price;
}

string Car::GetColor()
{
    return Color;
}

double Car::GetMPG()
{
    return MPG;
}

void Car::PrintInfo()
{
    cout << "=====================" << endl;
    cout << "Make: " << Make << endl;
    cout << "Model: " << Model << endl;
    cout << "Weight: " << Weight << endl;
    cout << "Model Year: " << ModelYear << endl;
    cout << "Price: " << Price << endl;
    cout << "Color: " << Color << endl;
    cout << "MPG: " << MPG << endl;
}