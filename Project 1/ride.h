#ifndef RIDE_H
#define RIDE_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

enum Status { Active = 'A', Completed = 'C', Cancelled = 'L' };

class Ride
{
    private:
        int RideID, PartySize;
        string PickupLocation, DropoffLocation;
        time_t PickupTime, DropoffTime;
        bool IncludesPets;
        Status RideStatus;
        double Rating;
        int DriverID;
        int PassengerID;
    public:
        Ride();
        Ride(int, int, string, string, time_t, time_t, bool, char, double, int, int);
        int GetRideID();
        int GetPartySize();
        string GetPickupLocation();
        string GetDropoffLocation();
        time_t GetPickupTime();
        time_t GetDropoffTime();
        bool GetIncludesPets();
        Status GetRideStatus();
        double GetRating();
        int GetDriverID();
        int GetPassengerID();

        void SetRideID(int);
        void SetPartySize(int);
        void SetPickupLocation(string);
        void SetDropoffLocation(string);
        void SetPickupTime(time_t);
        void SetDropoffTime(time_t);
        void SetIncludesPets(bool);
        void SetRideStatus(char);
        void SetRating(double);
        void SetDriverID(int);
        void SetPassengerID(int);

        void PrintRide();
};

#endif