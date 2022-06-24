#include "ride.h"

Ride::Ride()
{
    RideID = 0;
    PartySize = 0;
    PickupLocation = "";
    DropoffLocation = "";
    PickupTime = 0;
    DropoffTime = 0;
    IncludesPets = false;
    RideStatus = static_cast<Status>('L');;
    Rating = 0;
}

Ride::Ride(int RideID, int PartySize, string PickupLocation, string DropoffLocation, time_t PickupTime, time_t DropoffTime, bool IncludesPets, char RideStatus, double Rating)
{
    this->RideID = RideID;
    this->PartySize = PartySize;
    this->PickupLocation = PickupLocation;
    this->DropoffLocation = DropoffLocation;
    this->PickupTime = PickupTime;
    this->DropoffTime = DropoffTime;
    this->IncludesPets = IncludesPets;
    this->RideStatus = static_cast<Status>(RideStatus);
    this->Rating = Rating;
}

void Ride::SetRideID(int RideID)
{
    this->RideID = RideID;
}

void Ride::SetPartySize(int PartySize)
{
    this->PartySize = PartySize;
}

void Ride::SetPickupLocation(string PickupLocation)
{
    this->PickupLocation = PickupLocation;
}

void Ride::SetDropoffLocation(string DropoffLocation)
{
    this->DropoffLocation = DropoffLocation;
}

void Ride::SetPickupTime(time_t PickupTime)
{
    this->PickupTime = PickupTime;
}

void Ride::SetDropoffTime(time_t DropoffTime)
{
    this->DropoffTime = DropoffTime;
}

void Ride::SetIncludesPets(bool IncludesPets)
{
    this->IncludesPets = IncludesPets;
}

void Ride::SetRideStatus(char RideStatus)
{
    switch (RideStatus)
    {
        case 'A':
            this->RideStatus = Active;
            break;
        case 'C':
            this->RideStatus = Completed;
            break;
        case 'L':
            this->RideStatus = Cancelled;
            break;
    }
}

void Ride::SetRating(double Rating)
{
    this->Rating = Rating;
}

int Ride::GetRideID()
{
    return RideID;
}

int Ride::GetPartySize()
{
    return PartySize;
}

string Ride::GetPickupLocation()
{
    return PickupLocation;
}

string Ride::GetDropoffLocation()
{
    return DropoffLocation;
}

time_t Ride::GetPickupTime()
{
    return PickupTime;
}

time_t Ride::GetDropoffTime()
{
    return DropoffTime;
}

bool Ride::GetIncludesPets()
{
    return IncludesPets;
}

Status Ride::GetRideStatus()
{
    return RideStatus;
}

double Ride::GetRating()
{
    return Rating;
}

void Ride::PrintRide()
{
    cout << "Ride ID: " << RideID << endl;
    cout << "Party Size: " << PartySize << endl;
    cout << "Pickup Location: " << PickupLocation << endl;
    cout << "Dropoff Location: " << DropoffLocation << endl;
    cout << "Pickup Time: " << PickupTime << endl;
    cout << "Dropoff Time: " << DropoffTime << endl;
    cout << "Includes Pets: " << IncludesPets << endl;
    cout << "Ride Status: " << RideStatus << endl;
    cout << "Rating: " << Rating << endl;
}