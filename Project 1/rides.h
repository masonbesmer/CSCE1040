#ifndef RIDES_H
#define RIDES_H

#include "ride.h"
#include "passengers.h"
#include "drivers.h"

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstring>

using namespace std;

class Rides
{
    private:
        int RideCount;
        typedef map <int,Ride*> RideType;
        RideType RideList;
        typedef map <int,Driver*> DriverType;
        DriverType DriverList;
        typedef map <int,Passenger*> PassengerType;
        PassengerType PassengerList;
    public:
        Rides() {RideCount = 0;}
        void LoadDrivers();
        void LoadPassengers();
        void SaveRides();
        void LoadRides();
        void AddRide();//
        void AddRide(Ride*);//
        void RemoveRide(Ride*);//
        void RemoveRide();//
        void PrintRide();//
        void EditRide();//
        void PrintActiveRides();
        void PrintDriverRides(int);
        void PrintPassengerRides(int);
        int GetRideCount(); //testing needed
        void IncrementRideCount(); //
        void DecrementRideCount();//
        Ride* SearchRideByID(int);//
        void PrintEveryRideEver();
        time_t StringToEpochTime(string);
        bool IsTimeBetween(time_t, time_t, time_t);
        bool CheckIfDriverIsAvailableAtThisTime(int, time_t, time_t);
        bool CheckIfPassengerIsAvailableAtThisTime(int, time_t, time_t);
        bool CheckIfDriverHasSeatsRequired(int, int);
        bool CheckIfDriverCanDoPets(int, bool);
        bool CheckIfDriverHasCorrectRating(int, double);
        bool CheckIfDriverCanDoHandicap(int, int);
        bool VerifyRideCanExist(Ride*);
        void PrintRidesByStatus();
        void PrintDriverSchedule(int);
        void PrintPassengerSchedule(int);
        void PrintDriverSchedules();
        void PrintPassengerSchedules();
        string GetTimestamp(time_t);
        void PrintRidesByStatus(char);
        void ClearCanceledRides();
        void ClearCompletedRides();
        void UpdateRideStatuses();
};

#endif