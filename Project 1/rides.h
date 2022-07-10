#ifndef RIDES_H
#define RIDES_H

#include "ride.h"
#include "drivers.h"
#include "passengers.h"

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

class Rides
{
    private:
        int RideCount;
        typedef map <int,Ride*> RideType;
        RideType RideList;
    public:
        Rides() {RideCount = 0;}
        void SaveRides();
        void LoadRides();
        void AddRide();//
        void AddRide(Ride*);//
        void RemoveRide(Ride*);//
        void RemoveRide();//
        void PrintRide();//
        void EditRide();//
        void PrintActiveRides();
        void PrintDriverRides();
        int GetRideCount(); //testing needed
        void IncrementRideCount(); //
        void DecrementRideCount();//
        Ride FindRide(int);//
        void PrintPassengerRides();
        void PrintEveryRideEver();
};

#endif