#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

enum Payment { Cash = 'C', Debit = 'D', Credit = 'R'};

class Passenger
{
    private:
        string name;
        int id;
        Payment paymentMethod;
        bool handicap,pets;
        double ratingMin;
    public:
        Passenger();
        Passenger(string, int, char, bool, bool, double);
        string GetName();
        int GetId();
        Payment GetPaymentMethod();
        bool GetHandicap();
        bool GetPets();
        double GetRatingMin();

        void SetName(string);
        void SetId(int);
        void SetPaymentMethod(char);
        void SetHandicap(bool);
        void SetPets(bool);
        void SetRatingMin(double);

        void PrintPassenger();
};

#endif