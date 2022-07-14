#include "driver.h"

Driver::Driver()
{
    DriverName = "Johnny Manziel";
    DriverID = 0;
    DriverPhone = 1234567890;
    VehicleCapacity = 5;
    VehicleType = Compact;
    CanHandicap = true;
    Rating = 5;
    IsAvailable = true;
    AllowPets = true;
    Notes = "fsef";
}

Driver::Driver(int did, string dname, long phone, int cap, Type typ, bool hcp, double rtng, bool ava, bool pets, string notes)
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
    VehicleType = typ;
}

void Driver::SetDriverID(int id)
{
    DriverID = id;
}

void Driver::SetDriverName(string name)
{
    DriverName = name;
}

void Driver::SetDriverPhone(long phone)
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

long Driver::GetDriverPhone()
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

Type Driver::GetVehicleType()
{
    return VehicleType;
}

string Driver::GetNotes()
{
    return Notes;
}

void Driver::SetVehicleType(char VehicleTypes)
{
    switch (VehicleTypes)
    {
        case 'C':
            this->VehicleType = Compact;
            break;
        case 'S':
            this->VehicleType = Sedan;
            break;
        case 'U':
            this->VehicleType = SUV;
            break;
        case 'V':
            this->VehicleType = Van;
            break;
        default:
            this->VehicleType = Other;
            break;
    }
}

void Driver::PrintDriver()
{
    cout << "=====================Driver Info========================" << endl;
    cout << "Driver Name: " << DriverName << endl;
    cout << "Driver ID: " << fixed << setw(6) << setfill('0') << DriverID << endl;
    cout << "Driver Phone: " << DriverPhone << endl;
    cout << "Vehicle Capacity: " << VehicleCapacity << endl;
    cout << "Vehicle Type: ";
    switch (VehicleType)
    {
        case 'C':
            cout << "Compact" << endl;
            break;
        case 'S':
            cout << "Sedan" << endl;
            break;
        case 'U':
            cout << "Suv" << endl;
            break;
        case 'V':
            cout << "Van" << endl;
            break;
        default:
            cout << "Other" << endl;
            break;
    }
    cout << "Can Handicap: " << CanHandicap << endl;
    cout << "Rating: " << setprecision(1) << Rating << endl;
    cout << "Is Available: " << IsAvailable << endl;
    cout << "Allow Pets: " << AllowPets << endl;
    cout << "Notes: " << Notes << endl;
    cout << "========================================================" << endl;
}