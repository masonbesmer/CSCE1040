/*
*/
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

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
    public:
        Driver();
        Driver(int, string, int, int, bool, double, bool, bool, string);
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

        int GetDriverID();
        string GetDriverName();
        int GetDriverPhone();
        int GetVehicleCapacity();
        bool GetCanHandicap();
        double GetRating();
        bool GetIsAvailable();
        bool GetAllowPets();
        string GetNotes();
};