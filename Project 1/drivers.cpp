#include "drivers.h"
#include <typeinfo>

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

    DriverID = DriverList.size() + 1;

    cout << "Driver ID will be " << DriverID << endl;
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
    cout << "Driver ID for driver "<< newDriver->GetDriverName() << " with ID#" << newDriver->GetDriverID() << " will be updated to " << DriverList.size() + 1 << endl;
    newDriver->SetDriverID(DriverList.size() + 1);
    DriverList[newDriver->GetDriverID()] = newDriver;
    IncrementDriverCount();
    SaveDrivers();
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

void Drivers::RemoveDriver(Driver *driver)
{
    delete DriverList[driver->GetDriverID()];
    DriverList[driver->GetDriverID()] = NULL;
    DecrementDriverCount();
}

void Drivers::PrintDrivers()
{
    for (auto x : DriverList) {
        x.second->PrintDriver();
    }
}

void Drivers::PrintDriver()
{
    int DriverID;
    cout << "Driver ID: "; cin >> DriverID;
    DriverList[DriverID]->PrintDriver();
}

void Drivers::SaveDrivers()
{
    ofstream outfile;
    outfile.open("drivers.dat");
    for(auto it = DriverList.begin(); it != DriverList.end(); ++it) {
        outfile << it->second->GetDriverID() << "|" << it->second->GetDriverName() << "|" << it->second->GetDriverPhone() << "|" << it->second->GetVehicleCapacity() << "|"
        << it->second->GetVehicleType() << "|" << it->second->GetCanHandicap() << "|" << it->second->GetRating() << "|" << it->second->GetIsAvailable() << "|"
        << it->second->GetAllowPets() << "|" << it->second->GetNotes() << endl;
    }
    outfile.close();
}

void Drivers::LoadDrivers()
{
    ifstream infile;
    infile.open("drivers.dat");
    string DriverName;
    string intDriverPhone;
    string intVehicleCapacity;
    string boolCanHandicap;
    string doubleRating;
    string boolIsAvailable;
    string boolAllowPets;
    string intDriverID;
    string charVehicleType;
    string Notes;
    
    while(!infile.eof())
    {
        getline(infile, intDriverID, '|');
        getline(infile, DriverName, '|');
        getline(infile, intDriverPhone, '|');
        getline(infile, intVehicleCapacity, '|');
        getline(infile, charVehicleType, '|');
        getline(infile, boolCanHandicap, '|');
        getline(infile, doubleRating, '|');
        getline(infile, boolIsAvailable, '|');
        getline(infile, boolAllowPets, '|');
        getline(infile, Notes);

        cout << intDriverID << "|" << DriverName << "|" << intDriverPhone << "|" << intVehicleCapacity << "|" << charVehicleType << "|" << boolCanHandicap << "|"
        << doubleRating << "|" << boolIsAvailable << "|" << boolAllowPets << "|" << Notes << endl;
        cout << stoi(intDriverID) <<endl;
        //Driver* newDriver = new Driver(stoi(intDriverID), DriverName, stoi(intDriverPhone), stoi(intVehicleCapacity), (Type)charVehicleType[0],
        //stoi(boolCanHandicap), stod(doubleRating), stoi(boolIsAvailable), stoi(boolAllowPets), Notes);

        //DriverList[stoi(intDriverID)] = newDriver;
    }
}