#include "rides.h"

int Rides::GetRideCount()
{
    return RideCount;
}

void Rides::IncrementRideCount()
{
    RideCount++;
}

void Rides::DecrementRideCount()
{
    RideCount--;
}

Ride Rides::FindRide(int id)
{
    return *RideList[id];
}

void Rides::AddRide()
{
    int RideID, PartySize;
    string PickupLocation, DropoffLocation;
    time_t PickupTime, DropoffTime;
    bool IncludesPets;
    char RideStatus;
    double Rating;

    RideID = RideList.size() + 1;

    cout << "Ride ID will be " << RideID << endl;
    cout << "Party Size: "; cin >> PartySize;
    cout << "Pickup Location: "; getline(cin, PickupLocation);
    cout << "Dropoff Location: "; getline(cin, DropoffLocation);
    cin.ignore();
    cout << "Pickup Time: "; cin >> PickupTime;
    cout << "Dropoff Time: "; cin >> DropoffTime;
    cout << "Includes Pets: "; cin >> IncludesPets;
    cout << "Ride Status /// C = Completed, L = Cancelled, A = Active: "; cin >> RideStatus;
    cout << "Rating: "; cin >> Rating;

    Status tempStatus = (Status)RideStatus;
    Ride* newRide = new Ride(RideID, PartySize, PickupLocation, DropoffLocation, PickupTime, DropoffTime, IncludesPets, tempStatus, Rating);
    RideList[RideID] = newRide;
    IncrementRideCount();
}

void Rides::AddRide(Ride *newRide)
{
    cout << "Ride ID for ride " << newRide->GetPartySize() << " people with ID#" << newRide->GetRideID() << " will be updated to " << RideList.size() + 1 << endl;
    newRide->SetRideID(RideList.size() + 1);
    RideList[newRide->GetRideID()] = newRide;
    IncrementRideCount();
}

void Rides::RemoveRide()
{
    int RideID;
    cout << "Ride ID to delete: "; cin >> RideID;
    delete RideList[RideID];
    RideList[RideID] = NULL;
    DecrementRideCount();
}

void Rides::RemoveRide(Ride *removeRide)
{
    delete RideList[removeRide->GetRideID()];
    RideList[removeRide->GetRideID()] = NULL;
    DecrementRideCount();
}

void Rides::EditRide()
{
    int RideID;
    cout << "Ride ID: "; cin >> RideID;

    Ride *tempRide = RideList[RideID];
    
    int PartySize;
    string PickupLocation, DropoffLocation;
    time_t PickupTime, DropoffTime;
    bool IncludesPets;
    char RideStatus;
    double Rating;

    cout << "For the following options, press enter for no change." << endl;
    cout << "Party Size: "; cin >> PartySize;
    cout << "Pickup Location: "; getline(cin, PickupLocation);
    cout << "Dropoff Location: "; getline(cin, DropoffLocation);
    cin.ignore();
    cout << "Pickup Time: "; cin >> PickupTime;
    cout << "Dropoff Time: "; cin >> DropoffTime;
    cout << "Includes Pets: "; cin >> IncludesPets;
    cout << "Ride Status /// C = Completed, L = Cancelled, A = Active: "; cin >> RideStatus;
    cout << "Rating: "; cin >> Rating;

    Status tempStatus = (Status)RideStatus;

    tempRide->SetPartySize(PartySize);
    tempRide->SetPickupLocation(PickupLocation);
    tempRide->SetDropoffLocation(DropoffLocation);
    tempRide->SetPickupTime(PickupTime);
    tempRide->SetDropoffTime(DropoffTime);
    tempRide->SetIncludesPets(IncludesPets);
    tempRide->SetRideStatus(tempStatus);
    tempRide->SetRating(Rating);
}

void Rides::PrintRide()
{
    int RideID;
    cout << "Ride ID: "; cin >> RideID;
    RideList[RideID]->PrintRide();
}

void Rides::PrintEveryRideEver()
{
    for (auto x : RideList)
    {
        x.second->PrintRide();
    }
}