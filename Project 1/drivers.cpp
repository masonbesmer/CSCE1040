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

Driver* Drivers::SearchDriverByID(int id) {
    return DriverList[id];
}

void Drivers::AddDriver() {

    string DriverName;
    long DriverPhone;
    int VehicleCapacity;
    bool CanHandicap;
    double Rating;
    bool IsAvailable;
    bool AllowPets;
    string Notes;
    int DriverID;
    char VehicleType;

    if(DriverList.empty()){
        DriverID=1;
    }
    else{
        DriverID = DriverList.rbegin()->first + 1;
    }

    cout << "Driver ID will be " << DriverID << endl;
    cin.ignore();
    cout << "Driver Name: "; getline(cin, DriverName);
    cout << "Notes: "; getline(cin, Notes);
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
    SaveDrivers();
    IncrementDriverCount();
    cout << "Driver Added" << endl;
}

void Drivers::AddDriver(Driver *newDriver)
{
    int DriverID;
    if(DriverList.empty()){
        DriverID=1;
    }
    else{
        DriverID = DriverList.rbegin()->first + 1;
    }
    cout << "Driver ID for driver "<< newDriver->GetDriverName() << " with ID#" << newDriver->GetDriverID() << " will be updated to " << DriverID << endl;
    newDriver->SetDriverID(DriverID);
    DriverList[DriverID] = newDriver;
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
    cout << "Enter the ID of the driver you want to edit: "; cin >> DriverID;
    
    Driver *tempDriver = SearchDriverByID(DriverID);
    tempDriver->PrintDriver();
    string DriverName=tempDriver->GetDriverName();
    long DriverPhone=tempDriver->GetDriverPhone();
    int VehicleCapacity=tempDriver->GetVehicleCapacity();
    bool CanHandicap=tempDriver->GetCanHandicap();
    double Rating=tempDriver->GetRating();
    bool IsAvailable=tempDriver->GetIsAvailable();
    bool AllowPets=tempDriver->GetAllowPets();
    string Notes=tempDriver->GetNotes();
    char VehicleType=char(tempDriver->GetVehicleType());
    
    cout << "Enter new info for Driver (you MUST provide input)." << endl;
    cin.ignore();
    cout << "Driver Name: "; getline(cin, DriverName);
    cout << "Driver Phone(1234567890 form): "; cin >> DriverPhone;
    cout << "Vehicle Capacity: "; cin >> VehicleCapacity;
    cout << "Can Handicap (0/1): "; cin >> CanHandicap;
    cout << "Rating: "; cin >> Rating;
    cout << "Is Available (0/1): "; cin >> IsAvailable;
    cout << "Allow Pets (0/1): "; cin >> AllowPets;
    cout << "Vehicle Type /// C = Compact, S = Sedan, U = SUV, V = Van, O = Other): "; cin >> VehicleType;
    cin.ignore();
    cout << "Notes: "; getline(cin, Notes);

    tempDriver->SetDriverName(DriverName);
    tempDriver->SetDriverPhone(DriverPhone);
    tempDriver->SetVehicleCapacity(VehicleCapacity);
    tempDriver->SetCanHandicap(CanHandicap);
    tempDriver->SetRating(Rating);
    tempDriver->SetIsAvailable(IsAvailable);
    tempDriver->SetAllowPets(AllowPets);
    tempDriver->SetNotes(Notes);
    tempDriver->SetVehicleType(VehicleType);

    SaveDrivers();

    cout << "Driver " << tempDriver->GetDriverName() << " with ID#" << tempDriver->GetDriverID() << " has been updated." << endl;
}

void Drivers::RemoveDriver(Driver *driver)
{
    delete DriverList[driver->GetDriverID()];
    DriverList[driver->GetDriverID()] = NULL;
    DecrementDriverCount();
    SaveDrivers();
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
    cout << "Saving Drivers..." << endl;
    ofstream outfile;
    outfile.open("drivers.dat");

    for(auto it = DriverList.begin(); it != DriverList.end(); ++it) {
        outfile
        << it->second->GetDriverName() << "|"
        << it->second->GetDriverID() << "|"
        << it->second->GetDriverPhone() << "|"
        << it->second->GetVehicleCapacity() << "|"
        << char(it->second->GetVehicleType()) << "|"
        << it->second->GetCanHandicap() << "|"
        << it->second->GetRating() << "|"
        << it->second->GetIsAvailable() << "|"
        << it->second->GetAllowPets() << "|"
        << it->second->GetNotes()
        << endl;
    }

    outfile.seekp(-1, ios::end); //remove last newline, replace with EOF
    outfile.put(' ');

    outfile.close();
    cout << "Drivers saved." << endl;
}

void Drivers::LoadDrivers()
{
    cout << "Loading drivers..." << endl;
    ifstream infile;
    infile.open("drivers.dat");
    if (infile.fail()) { cout << "Error opening file (maybe it doesn't exist?)." << endl; return; }
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
        getline(infile, DriverName, '|');
        getline(infile, intDriverID, '|');
        getline(infile, intDriverPhone, '|');
        getline(infile, intVehicleCapacity, '|');
        getline(infile, charVehicleType, '|');
        getline(infile, boolCanHandicap, '|');
        getline(infile, doubleRating, '|');
        getline(infile, boolIsAvailable, '|');
        getline(infile, boolAllowPets, '|');
        getline(infile, Notes);

        Driver* newDriver = new Driver(stoi(intDriverID), DriverName,
        stol(intDriverPhone), stoi(intVehicleCapacity),
        (Type)charVehicleType[0], stoi(boolCanHandicap),
        stod(doubleRating), stoi(boolIsAvailable),
        stoi(boolAllowPets), Notes);

        DriverList[stoi(intDriverID)] = newDriver;
    }
    infile.close();
    cout << "Drivers loaded." << endl;
}