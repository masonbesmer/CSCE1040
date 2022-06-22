#include "driver.h"

Driver::Driver()
{
    DriverName = "Johnny Manziel";
    DriverID = 0;
    DriverPhone = 1234567890;
    VehicleCapacity = 5;
    CanHandicap = true;
    Rating = 5;
    IsAvailable = true;
    AllowPets = true;
    Notes = "fsef";
}

Driver::Driver(string dname, int did, int phone, int cap, bool hcp, double rtng, bool ava, bool pets, string notes)
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

int Driver::GetDriverID()
{
    return DriverID;
}

string Driver::GetDriverName()
{
    return DriverName;
}

int Driver::GetDriverPhone()
{
    return DriverPhone;
}

int Driver::GetVehicleCapacity()
{
    return VehicleCapacity;
}

bool Driver::GetCanHandicap()
{
    return CanHandicap;
}

double Driver::GetRating()
{
    return Rating;
}

bool Driver::GetIsAvailable()
{
    return IsAvailable;
}

bool Driver::GetAllowPets()
{
    return AllowPets;
}

string Driver::GetNotes()
{
    return Notes;
}

void Driver::PrintDriver()
{
    cout << "==============================================================" << endl;
    cout << "Driver Name: " << DriverName << endl;
    cout << "Driver ID: " << DriverID << endl;
    cout << "Driver Phone: " << DriverPhone << endl;
    cout << "Vehicle Capacity: " << VehicleCapacity << endl;
    cout << "Can Handicap: " << CanHandicap << endl;
    cout << "Rating: " << Rating << endl;
    cout << "Is Available: " << IsAvailable << endl;
    cout << "Allow Pets: " << AllowPets << endl;
    cout << "Notes: " << Notes << endl;
    cout << "==============================================================" << endl;
}