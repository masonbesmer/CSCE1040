#ifndef DRIVERS_H
#define DRIVERS_H

#include "driver.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

class Drivers {
    private:
        int DriverCount;
        typedef map <int,Driver*> DriverType;
        DriverType DriverList;
    public:
        Drivers() {DriverCount = 0;}
        void SaveDrivers();
        void LoadDrivers();
        void AddDriver();
        void AddDriver(Driver*);
        void RemoveDriver();
        void RemoveDriver(int);
        void PrintDrivers();
        void PrintDriver();
        void EditDriver();
        void PrintActiveRides();
        void PrintDriverRides();
        int GetDriverCount();
        void IncrementDriverCount();
        void DecrementDriverCount();
        Driver FindDriver(int);
        void PrintPassengerRides();
};

#endif