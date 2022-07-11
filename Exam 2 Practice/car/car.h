#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car
{
    private:
        string Make, Model, Color;
        double Weight, Price, MPG;
        int ModelYear;

    public:
        Car();
        Car(string, string, double, int, double, string, double);
        void SetMake(string);
        void SetModel(string);
        void SetWeight(double);
        void SetModelYear(int);
        void SetPrice(double);
        void SetColor(string);
        void SetMPG(double); // not impletemented

        string GetMake();
        string GetModel();
        double GetWeight();
        int GetModelYear();
        double GetPrice();
        string GetColor();
        double GetMPG();

        void PrintInfo();
};

#endif