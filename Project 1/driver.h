#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum Type {Compact = 'C', Sedan = 'S', SUV = 'U', Van = 'V', Other = 'O'};

class Driver
{
    private:
        int DriverID;
        string DriverName;
        int DriverPhone;
        int VehicleCapacity;
        bool CanHandicap;
        double Rating;
        bool IsAvailable;
        bool AllowPets;
        string Notes;
        Type VehicleType;

    public:
        Driver();
        Driver(int, string, int, int, Type, bool, double, bool, bool, string);
        void SetDriverID(int);
        void SetDriverName(string);
        void SetDriverPhone(int);
        void SetVehicleCapacity(int);
        void SetCanHandicap(bool);
        void SetRating(double);
        void SetIsAvailable(bool);
        void SetAllowPets(bool);
        void SetNotes(string);
        void PrintDriver();
        void SetVehicleType(char);

        int GetDriverID();
        string GetDriverName();
        int GetDriverPhone();
        int GetVehicleCapacity();
        bool GetCanHandicap();
        double GetRating();
        bool GetIsAvailable();
        bool GetAllowPets();
        string GetNotes();
        Type GetVehicleType();
};

#endif