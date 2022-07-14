#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

#include "passenger.h"

using namespace std;

class Passengers
{
    private:
        typedef map <int,Passenger*> PassengerType;
        PassengerType PassengerList;
        int PassengerCount;
    public:
        void AddPassenger();
        void AddPassenger(Passenger*);
        void EditPassenger();
        void RemovePassenger(int);
        void RemovePassenger();
        void IncrementPassengerCount();
        void DecrementPassengerCount();
        Passenger* SearchPassengerByID(int);
        void PrintPassengers();
        void PrintPassenger();
        void SavePassengers();
        void LoadPassengers();
};

#endif