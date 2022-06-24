#include "drivers.h"

int Drivers::GetDriverCount() {
    return DriverCount;
}

void Drivers::IncrementDriverCount() {
    DriverCount++;
}

void Drivers::DecrementDriverCount() {
    DriverCount--;
}

Driver Drivers::FindDriver(int id) {
    return *DriverList[id];
}

void Drivers::AddDriver() {

    string DriverName;
    int DriverPhone;
    int VehicleCapacity;
    bool CanHandicap;
    double Rating;
    bool IsAvailable;
    bool AllowPets;
    string Notes;
    int DriverID;
    char VehicleType;

    cout << "Driver ID: "; cin >> DriverID;
    cout << "Driver Name: "; getline(cin, DriverName);
    cout << "Notes: "; getline(cin, Notes);
    cin.ignore();
    cout << "Driver Phone: "; cin >> DriverPhone;
    cout << "Vehicle Capacity: "; cin >> VehicleCapacity;
    cout << "Can Handicap: "; cin >> CanHandicap;
    cout << "Rating: "; cin >> Rating;
    cout << "Is Available: "; cin >> IsAvailable;
    cout << "Allow Pets: "; cin >> AllowPets;
    cout << "Vehicle Type /// C = Compact, S = Sedan, U = SUV, V = Van, O = Other): "; cin >> VehicleType;
    
    Type tempType = (Type)VehicleType;
    Driver *newDriver = new Driver(DriverID, DriverName, DriverPhone, VehicleCapacity, tempType, CanHandicap, Rating, IsAvailable, AllowPets, Notes);
    DriverList[DriverID] = newDriver;
    IncrementDriverCount();
}

void Drivers::AddDriver(Driver *newDriver)
{
    DriverList[newDriver->GetDriverID()] = newDriver;
    IncrementDriverCount();
}

void Drivers::RemoveDriver()
{
    int DriverID;
    cout << "Driver ID: "; cin >> DriverID;
    delete DriverList[DriverID];
    DriverList[DriverID] = NULL;
    DecrementDriverCount();
}

void Drivers::EditDriver()
{
    int DriverID;
    cout << "Driver ID: "; cin >> DriverID;
    
    Driver *tempDriver = DriverList[DriverID];
    
    string DriverName;
    int DriverPhone;
    int VehicleCapacity;
    bool CanHandicap;
    double Rating;
    bool IsAvailable;
    bool AllowPets;
    string Notes;
    char VehicleType;
    
    cout << "For the following options, press enter for no change." << endl;
    cout << "Driver Name: "; getline(cin, DriverName);
    cout << "Notes: "; getline(cin, Notes);
    cin.ignore();
    cout << "Driver Phone: "; cin >> DriverPhone;
    cout << "Vehicle Capacity: "; cin >> VehicleCapacity;
    cout << "Can Handicap: "; cin >> CanHandicap;
    cout << "Rating: "; cin >> Rating;
    cout << "Is Available: "; cin >> IsAvailable;
    cout << "Allow Pets: "; cin >> AllowPets;
    cout << "Vehicle Type /// C = Compact, S = Sedan, U = SUV, V = Van, O = Other): "; cin >> VehicleType;
    
    Type tempType = (Type)VehicleType;

    tempDriver->SetDriverName(DriverName);
    tempDriver->SetDriverPhone(DriverPhone);
    tempDriver->SetVehicleCapacity(VehicleCapacity);
    tempDriver->SetCanHandicap(CanHandicap);
    tempDriver->SetRating(Rating);
    tempDriver->SetIsAvailable(IsAvailable);
    tempDriver->SetAllowPets(AllowPets);
    tempDriver->SetNotes(Notes);
    tempDriver->SetVehicleType(tempType);
}

void Drivers::RemoveDriver(Driver *driver) {
    delete DriverList[driver->GetDriverID()];
    //DriverList[driver->GetDriverID()] = NULL;
    DecrementDriverCount();
}

void Drivers::PrintDrivers() {
    for (auto it = DriverList.begin(); it != DriverList.end(); ++it) {
        it->second->PrintDriver();
    }
}

void Drivers::PrintDriver() {
    int DriverID;
    cout << "Driver ID: "; cin >> DriverID;
    DriverList[DriverID]->PrintDriver();
}