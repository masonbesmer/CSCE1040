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

Ride* Rides::SearchRideByID(int id)
{
    return RideList[id];
}

void Rides::AddRide()
{
    LoadPassengers();
    LoadDrivers();
    int RideID, PartySize, DriverID, PassengerID;
    string PickupLocation, DropoffLocation;
    time_t PickupTime, DropoffTime;
    bool IncludesPets;
    char RideStatus;
    double Rating;
    if (RideList.empty())
    {
        RideID = 1;
    }
    else
    {
        RideID = RideList.rbegin()->first + 1;
    }

    PrintDriverSchedules();
    PrintPassengerSchedules();
    cout << "Ride ID will be " << RideID << endl;
    cout << "Driver ID: "; cin >> DriverID;
    cout << "Passenger ID: "; cin >> PassengerID;
    cout << "Party Size: "; cin >> PartySize;
    cin.ignore();
    cout << "Pickup Location: "; getline(cin, PickupLocation);
    cout << "Dropoff Location: "; getline(cin, DropoffLocation);
    cout << "Pickup Time: "; cin >> PickupTime;
    cout << "Dropoff Time: "; cin >> DropoffTime;
    cout << "Includes Pets: "; cin >> IncludesPets;
    cout << "Requires Handicap: "; cin >> IncludesPets;
    cout << "Ride Status /// C = Completed, L = Cancelled, A = Active: "; cin >> RideStatus;
    cout << "Rating: "; cin >> Rating;

    Status tempStatus = (Status)RideStatus;
    Ride* newRide = new Ride(RideID, PartySize, PickupLocation, DropoffLocation, PickupTime, DropoffTime, IncludesPets, tempStatus, Rating, DriverID, PassengerID);
    if (VerifyRideCanExist(newRide))
    {
        RideList[RideID] = newRide;
        SaveRides();
        IncrementRideCount();
        cout << "The ride was created sucessfully" << endl;
    }
}

void Rides::AddRide(Ride *newRide)
{
    //cout << "Ride ID for ride with " << newRide->GetPartySize() << " people with ID#" << newRide->GetRideID() << " will be updated to " << RideList.size() + 1 << endl;
    if (RideList.empty())
    {
        newRide->SetRideID(1);
    }
    else
    {
        newRide->SetRideID(RideList.rbegin()->first + 1);
    }
    RideList[newRide->GetRideID()] = newRide;
    SaveRides();
    IncrementRideCount();
}

void Rides::RemoveRide()
{
    int RideID;
    cout << "Ride ID to delete: "; cin >> RideID;
    RideList.erase(RideID);
    SaveRides();
    DecrementRideCount();
}

void Rides::RemoveRide(Ride *removeRide)
{
    RideList.erase(removeRide->GetRideID());
    SaveRides();
    DecrementRideCount();
}

void Rides::EditRide()
{
    LoadDrivers();
    LoadPassengers();
    int RideID;
    cout << "Ride ID to edit: "; cin >> RideID;

    Ride *tempRide = SearchRideByID(RideID);
    
    int PartySize=tempRide->GetPartySize();
    string PickupLocation=tempRide->GetPickupLocation();
    string DropoffLocation=tempRide->GetDropoffLocation();
    time_t PickupTime=tempRide->GetPickupTime();
    time_t DropoffTime=tempRide->GetDropoffTime();
    bool IncludesPets=tempRide->GetIncludesPets();
    char RideStatus=char(tempRide->GetRideStatus());
    double Rating=tempRide->GetRating();
    int DriverID=tempRide->GetDriverID();
    int PassengerID=tempRide->GetPassengerID();
    PrintDriverSchedules();
    PrintPassengerSchedules();
    cout << "Enter new info for Ride (you MUST provide input)." << endl;
    cout << "Party Size: "; cin >> PartySize;
    cin.ignore();
    cout << "Pickup Location: "; getline(cin, PickupLocation);
    cout << "Dropoff Location: "; getline(cin, DropoffLocation);
    cout << "Pickup Time: "; cin >> PickupTime;
    cout << "Dropoff Time: "; cin >> DropoffTime;
    cout << "Includes Pets: "; cin >> IncludesPets;
    cout << "Ride Status /// C = Completed, L = Cancelled, A = Active: "; cin >> RideStatus;
    cout << "Rating: "; cin >> Rating;
    cout << "Driver ID: "; cin >> DriverID;
    cout << "Passenger ID: "; cin >> PassengerID;

    // tempRide->SetPartySize(PartySize);
    // tempRide->SetPickupLocation(PickupLocation);
    // tempRide->SetDropoffLocation(DropoffLocation);
    // tempRide->SetPickupTime(PickupTime);
    // tempRide->SetDropoffTime(DropoffTime);
    // tempRide->SetIncludesPets(IncludesPets);
    // tempRide->SetRideStatus(RideStatus);
    // tempRide->SetRating(Rating);
    // tempRide->SetDriverID(DriverID);
    // tempRide->SetPassengerID(PassengerID);

    Status tempStatus = (Status)RideStatus;

    Ride* newRide = new Ride(RideID, PartySize, PickupLocation, DropoffLocation, PickupTime, DropoffTime, IncludesPets, tempStatus, Rating, DriverID, PassengerID);
    if (VerifyRideCanExist(newRide))
    {
        RideList[RideID] = newRide;
        SaveRides();
        IncrementRideCount();
        cout << "Ride updated." << endl;
    }
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

void Rides::PrintActiveRides()
{
    for (auto x : RideList)
    {
        if (x.second->GetRideStatus() == Active)
        {
            x.second->PrintRide();
        }
    }
}

void Rides::PrintDriverRides(int driverID)
{
    for (auto x : RideList)
    {
        if (x.second->GetDriverID() == driverID)
        {
            x.second->PrintRide();
        }
    }
}

void Rides::PrintDriverSchedules()
{
    time_t pickupTime;
    time_t dropoffTime;
    for (auto x : DriverList)
    {
        cout << "==============================" << endl;
        cout << "Schedule for Driver#" << x.second->GetDriverID() << ": " << endl;
        for (auto y : RideList)
        {
            if (y.second->GetDriverID() == x.second->GetDriverID())
            {
                pickupTime = y.second->GetPickupTime();
                dropoffTime = y.second->GetDropoffTime();
                cout << GetTimestamp(pickupTime) << " to " << GetTimestamp(dropoffTime) << endl;
            }
        }
    }
}

void Rides::PrintPassengerSchedules()
{
    time_t pickupTime;
    time_t dropoffTime;
    for (auto x : PassengerList)
    {
        cout << "==============================" << endl;
        cout << "Schedule for Passenger#" << x.second->GetId() << ": " << endl;
        for (auto y : RideList)
        {
            if (y.second->GetPassengerID() == x.second->GetId())
            {
                pickupTime = y.second->GetPickupTime();
                dropoffTime = y.second->GetDropoffTime();
                cout << GetTimestamp(pickupTime) << " to " << GetTimestamp(dropoffTime) << endl;
            }
        }
    }
}

void Rides::PrintPassengerRides(int passengerID)
{
    for (auto x : RideList)
    {
        if (x.second->GetPassengerID() == passengerID)
        {
            x.second->PrintRide();
        }
    }
}

time_t Rides::StringToEpochTime(string epochString)
{
    const char* epoch = epochString.c_str();
    time_t time = strtol(epoch, NULL, 10);
    return time;
}

//check if 
bool Rides::IsTimeBetween(time_t time1, time_t time2, time_t time3)
{
    if (time1 >= time2 && time1 <= time3)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

//check if driver has a ride at a time that conflicts with the new ride time
bool Rides::CheckIfDriverIsAvailableAtThisTime(int driverID, time_t pickupTime, time_t dropoffTime)
{
    for (auto x : RideList)
    {
        if (x.second->GetDriverID() == driverID)
        {
            if (IsTimeBetween(pickupTime, x.second->GetPickupTime(), x.second->GetDropoffTime()) == false)
            {
                if (IsTimeBetween(dropoffTime, x.second->GetPickupTime(), x.second->GetDropoffTime()) == false)
                {
                    return true;
                }
            }
        } else return true;
    }
    if (RideList.size() == 0)
    {
        return true;
    }
    return false;
}

bool Rides::CheckIfPassengerIsAvailableAtThisTime(int passengerID, time_t pickupTime, time_t dropoffTime)
{
    for (auto x : RideList)
    {
        if (x.second->GetPassengerID() == passengerID)
        {
            if (IsTimeBetween(pickupTime, x.second->GetPickupTime(), x.second->GetDropoffTime()) == false)
            {
                if (IsTimeBetween(dropoffTime, x.second->GetPickupTime(), x.second->GetDropoffTime()) == false)
                {
                    return true;
                }
            }
        } else return true;
    }
    if (RideList.size() == 0)
    {
        return true;
    }
    return false;
}

bool Rides::CheckIfDriverHasSeatsRequired(int driverID, int partySize)
{
    for (auto x : DriverList)
    {
        if (x.second->GetDriverID() == driverID)
        {
            if (x.second->GetVehicleCapacity() > partySize)
            {
                return true;
            } else return false;
        }
    }
    return false;
}

bool Rides::CheckIfDriverCanDoPets(int driverID, bool includesPets)
{
    if (!includesPets) return true;
    for (auto x : DriverList)
    {
        //x.second->PrintDriver();
        if (x.second->GetDriverID() == driverID)
        {
            //cout << " pets allowed: " << x.second->GetAllowPets() << endl;
            if (x.second->GetAllowPets() == includesPets)
            {
                return true;
            } else return false;
        }
    }
    return false;
}

bool Rides::CheckIfDriverHasCorrectRating(int driverID, double rating)
{
    for (auto x : DriverList)
    {
        if (x.second->GetDriverID() == driverID)
        {
            if (x.second->GetRating() >= rating)
            {
                return true;
            } else return false;
        }
    }
    return false;
}

bool Rides::CheckIfDriverCanDoHandicap(int driverID, int passengerID)
{
    bool includesHandicap;
    
    for (auto x : PassengerList)
    {
        if (x.second->GetId() == passengerID)
        {
            includesHandicap = x.second->GetHandicap();
        }
    }
    if (!includesHandicap) return true;
    for (auto x : DriverList)
    {
        if (x.second->GetDriverID() == driverID)
        {
            if (x.second->GetCanHandicap() == includesHandicap)
            {
                return true;
            } else return false;
        }
    }
    return false;
}

bool Rides::VerifyRideCanExist(Ride* rideToCheck)
{
    string error="";
    bool canExist = true;
    if (CheckIfDriverIsAvailableAtThisTime(rideToCheck->GetDriverID(), rideToCheck->GetPickupTime(), rideToCheck->GetDropoffTime()) == false)
    {
        error.append("Driver is not available at this time. ");
        canExist = false;
    }
    if (CheckIfPassengerIsAvailableAtThisTime(rideToCheck->GetPassengerID(), rideToCheck->GetPickupTime(), rideToCheck->GetDropoffTime()) == false)
    {
        error.append("Passenger is not available at this time. ");
        canExist = false;
    }
    if (CheckIfDriverHasSeatsRequired(rideToCheck->GetDriverID(), rideToCheck->GetPartySize()) == false)
    {
        error.append("Driver does not have enough seats. ");
        canExist = false;
    }
    if (CheckIfDriverCanDoPets(rideToCheck->GetDriverID(), rideToCheck->GetIncludesPets()) == false)
    {
        error.append("Driver does not allow pets. ");
        canExist = false;
    }
    if (CheckIfDriverHasCorrectRating(rideToCheck->GetDriverID(), rideToCheck->GetRating()) == false)
    {
        error.append("Driver does not have the correct rating. ");
        canExist = false;
    }
    if (CheckIfDriverCanDoHandicap(rideToCheck->GetDriverID(), rideToCheck->GetPassengerID()) == false)
    {
        error.append("Driver does not allow handicap. ");
        canExist = false;
    }
    if (canExist == false)
    {
        cout << error << endl;
    }
    return canExist;
}

string Rides::GetTimestamp(time_t input)
{
    return strtok(ctime(&input), "\n");
}

void Rides::PrintRidesByStatus(char status)
{
    for (auto x : RideList)
    {
        if (char(x.second->GetRideStatus()) == status)
        {
            x.second->PrintRide();
        }
    }
}

void Rides::ClearCanceledRides()
{
    for (auto x : RideList)
    {
        if (char(x.second->GetRideStatus()) == 'C')
        {
            RideList.erase(x.second->GetRideID());
            SaveRides();
        }
    }
}

void Rides::ClearCompletedRides()
{
    // for (auto x : RideList)
    // {
    //     if (char(x.second->GetRideStatus()) == 'C')
    //     {
    //         RideList.erase(x.second->GetRideID());
    //         SaveRides();
    //     }
    // }
    for (auto itr=RideList.begin(); itr!=RideList.end(); itr++)
    {
        if (char(itr->second->GetRideStatus()) == 'C')
        {
            itr = RideList.erase(itr);
        }
    }
}

void Rides::UpdateRideStatuses()
{
    for (auto x : RideList)
    {
        if (x.second->GetDropoffTime() < time(0))
        {
            x.second->SetRideStatus('C');
        }
    }
    SaveRides();
}

//save rides to rides.dat using | delimiter
void Rides::SaveRides()
{
    cout << "Saving rides..." << endl;
    ofstream outFile;
    outFile.open("rides.dat");
    for (auto x : RideList)
    {
        outFile
        << x.second->GetRideID() << "|"
        << x.second->GetPartySize() << "|"
        << x.second->GetPickupLocation() << "|"
        << x.second->GetDropoffLocation() << "|"
        << x.second->GetPickupTime() << "|"
        << x.second->GetDropoffTime() << "|"
        << x.second->GetIncludesPets() << "|"
        << char(x.second->GetRideStatus()) << "|"
        << x.second->GetRating() << "|"
        << x.second->GetDriverID() << "|"
        << x.second->GetPassengerID()
        << endl;
    }

    outFile.close();
    cout << "Rides saved." << endl;
}

void Rides::LoadRides()
{
    cout << "Loading rides..." << endl;
    ifstream inFile;
    inFile.open("rides.dat");
    string line;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }
        time_t pickup = StringToEpochTime(tokens[4]);
        time_t dropoff = StringToEpochTime(tokens[5]);
        Ride *tempRide =new Ride(
        stoi(tokens[0]), //RideID
        stoi(tokens[1]), //PartySize
        tokens[2],      //PickupLocation
        tokens[3],     //DropoffLocation
        pickup, //PickupTime
        dropoff, //DropoffTime
        stoi(tokens[6]), //IncludesPets
        char(tokens[7][0]), //RideStatus
        stod(tokens[8]), //Rating
        stoi(tokens[9]), //DriverID
        stoi(tokens[10])); //PassengerID
        RideList[tempRide->GetRideID()] = tempRide;
    }
    inFile.close();
    cout << RideList.size() << " rides loaded." << endl;
    cout << "Updating statuses of rides..." << endl;
    UpdateRideStatuses();
    cout << "Done." << endl;
}

void Rides::LoadDrivers()
{
    cout << "Loading Drivers..." << endl;
    ifstream inFile;
    inFile.open("drivers.dat");
    string line;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }
        Driver *newDriver = new Driver(
            stoi(tokens[1]),
            tokens[0],
            stol(tokens[2]),
            stoi(tokens[3]),
            (Type)(char(tokens[4][0])),
            stoi(tokens[5]),
            stod(tokens[6]),
            stoi(tokens[7]),
            stoi(tokens[8]),
            tokens[9]);
        DriverList[newDriver->GetDriverID()] = newDriver;
    }
    
    inFile.close();
    cout << DriverList.size() << " drivers loaded." << endl;
}

void Rides::LoadPassengers()
{
    cout << "Loading passengers..." << endl;
    ifstream infile;
    infile.open("passengers.dat");
    string line;
    while(getline(infile, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while(getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }
        Passenger* passenger = new Passenger(
            tokens[0],
            stoi(tokens[1]),
            char(tokens[2][0]),
            stoi(tokens[3]),
            stoi(tokens[4]),
            stod(tokens[5]));
        PassengerList[passenger->GetId()] = passenger;
    }
    infile.close();
    cout << PassengerList.size() << " passengers loaded." << endl;
}