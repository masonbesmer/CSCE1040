#include "Driver.h"

Driver::Driver()
{
    DriverID = 0;
    DriverName = "Johnny Manziel";
    DriverPhone = 1234567890;
    VehicleCapacity = 5;
    CanHandicap = true;
    Rating = 5;
    IsAvailable = true;
    AllowPets = true;
    Notes = "fsef";
}

Driver::Driver(int did, string dname, int phone, int cap, bool hcp, double rtng, bool ava, bool pets, string notes)
{
    DriverID = did;
    DriverName = dname;
    DriverPhone = phone;
    VehicleCapacity = cap;
    CanHandicap = hcp;
    Rating = rtng;
    IsAvailable = ava;
    AllowPets = pets;
    Notes = notes;
}

void Driver::SetDriverID(int id)
{
    DriverID = id;
}

void Driver::SetDriverName(string name)
{
    DriverName = name;
}

void Driver::SetDriverPhone(int phone)
{
    DriverPhone = phone;
}

void Driver::SetVehicleCapacity(int capacity)
{
    VehicleCapacity = capacity;
}

void Driver::SetCanHandicap(bool canHandicap)
{
    CanHandicap = canHandicap;
}

void Driver::SetRating(double rating)
{
    Rating = rating;
}

void Driver::SetIsAvailable(bool isAvailable)
{
    IsAvailable = isAvailable;
}

void Driver::SetAllowPets(bool allowPets)
{
    AllowPets = allowPets;
}

void Driver::SetNotes(string notes)
{
    Notes = notes;
}

void Driver::PrintDriver()
{
    cout << "Driver ID: " << DriverID << endl;
    cout << "Driver Name: " << DriverName << endl;
    cout << "Driver Phone: " << DriverPhone << endl;
    cout << "Vehicle Capacity: " << VehicleCapacity << endl;
    cout << "Can Handicap: " << CanHandicap << endl;
    cout << "Rating: " << Rating << endl;
    cout << "Is Available: " << IsAvailable << endl;
    cout << "Allow Pets: " << AllowPets << endl;
    cout << "Notes: " << Notes << endl;
}