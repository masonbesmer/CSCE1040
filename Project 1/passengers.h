#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

#include "passenger.h"
#include "rides.h"
#include "drivers.h"


using namespace std;

class Passengers
{
    private:
        typedef map <int,Passenger*> PassengerType;
        PassengerType PassengerList;
    public:
        Passengers();
        void SavePassengers();
        void LoadPassengers();
        void AddPassenger();
        void AddPassenger(Passenger*);
        void RemovePassenger(Passenger*);
        void RemovePassenger(int);
        void PrintPassengers();
        void EditPassenger();
        void PrintActieveRides();
        void PrintPassengerRides();
        void PrintDriverRides();
        void PrintActiveRides();
};

#endif