#ifndef DRIVERS_H
#define DRIVERS_H

#include "driver.h"

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Drivers
{
    private:
        int DriverCount;
        typedef map <int,Driver*> DriverType;
        DriverType DriverList;
    public:
        friend class Rides;
        Drivers() {DriverCount = 0;}
        void SaveDrivers();
        void LoadDrivers();
        void AddDriver(); //should be working, needs testing
        void AddDriver(Driver*); //fully implemented
        void RemoveDriver(Driver*); //needs testing, might be deleted
        void RemoveDriver(); //good to go
        void PrintDrivers();//gg
        void PrintDriver(); //good to go
        void EditDriver(); //testing needed
        void PrintActiveRides();
        void PrintDriverRides();
        int GetDriverCount(); //implemented
        void IncrementDriverCount(); //done
        void DecrementDriverCount(); //finished
        Driver* SearchDriverByID(int); //found by ID
        void PrintPassengerRides();
};

#endif