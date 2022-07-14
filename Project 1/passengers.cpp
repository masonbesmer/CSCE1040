#include "passengers.h"

void Passengers::AddPassenger()
{
    string name;
    int id;
    if (PassengerList.empty())
    {
        id = 1;
    }
    else
    {
        id = PassengerList.rbegin()->first + 1;
    }
    char payment;
    bool handicap, pets;
    double ratingMin;
    cout << "ID of passenger will be: " << id << endl;
    cin.ignore();
    cout << "Enter the name of the passenger: "; getline(cin, name);
    cout << "Enter the payment method of the passenger ('C'ash/'D'ebit/c'R'edit): "; cin >> payment;
    cout << "Enter whether the passenger has a handicap (0/1):"; cin >> handicap;
    cout << "Enter whether the passenger has pets (0/1):"; cin >> pets;
    cout << "Enter the minimum driver rating of the passenger: "; cin >> ratingMin;

    cin.ignore();

    Passenger* passenger = new Passenger(name, id, static_cast<Payment>(payment), handicap, pets, ratingMin);
    PassengerList[id] = passenger;
    IncrementPassengerCount();

    SavePassengers();

    cout << "Passenger added successfully!" << endl;
}

void Passengers::AddPassenger(Passenger* newPassenger)
{
    //cout << "Passenger ID for passenger " << newPassenger->GetName() << " with ID#" << newPassenger->GetId() << " will be updated to " << PassengerList.size() + 1 << endl;
    int DriverID;
    if(PassengerList.empty()){
        newPassenger->SetId(1);
    }
    else{
        newPassenger->SetId(PassengerList.rbegin()->first + 1);
    }
    PassengerList[newPassenger->GetId()] = newPassenger;
    SavePassengers();
    IncrementPassengerCount();
}

void Passengers::EditPassenger()
{
    int IDtoEdit=-1;
    cout << "Enter the ID of the passenger you want to edit: "; cin >> IDtoEdit;
    Passenger* toEdit = SearchPassengerByID(IDtoEdit);
    toEdit->PrintPassenger();
    string name=toEdit->GetName();
    char payment=(char)toEdit->GetPaymentMethod();
    bool handicap=toEdit->GetHandicap();
    bool pets=toEdit->GetPets();
    double ratingMin=toEdit->GetRatingMin();

    cout << "Enter new information for the passenger (you MUST provide input for every option)" << endl;
    cin.ignore();
    cout << "Enter the name of the passenger: "; getline(cin, name);
    cout << "Enter the payment method of the passenger ('C'ash/'D'ebit/c'R'edit): "; cin >> payment;
    cout << "Enter whether the passenger has a handicap (0/1):"; cin >> handicap;
    cout << "Enter whether the passenger has pets (0/1):"; cin >> pets;
    cout << "Enter the minimum driver rating of the passenger: "; cin >> ratingMin;

    cin.ignore();

    toEdit->SetName(name);
    toEdit->SetPaymentMethod(payment);
    toEdit->SetHandicap(handicap);
    toEdit->SetPets(pets);
    toEdit->SetRatingMin(ratingMin);

    SavePassengers();
    
    cout << "Passenger " << toEdit->GetName() << " with ID#" << toEdit->GetId() << " edited successfully!" << endl;
}

void Passengers::RemovePassenger(int id)
{
    delete PassengerList[id];
    PassengerList[id] = NULL;
    SavePassengers();
    cout << "Passenger removed successfully!" << endl;
}

void Passengers::RemovePassenger()
{
    int id;
    cout << "Enter the ID of the passenger you want to remove: "; cin >> id;
    RemovePassenger(id);
}

void Passengers::IncrementPassengerCount()
{
    PassengerCount++;
}

void Passengers::DecrementPassengerCount()
{
    PassengerCount--;
}

Passenger* Passengers::SearchPassengerByID(int id)
{
    return PassengerList[id];
}

void Passengers::PrintPassengers()
{
    for(auto it = PassengerList.begin(); it != PassengerList.end(); ++it)
    {
        it->second->PrintPassenger();
    }
}

//save passengers using | as delimiter
void Passengers::SavePassengers()
{
    cout << "Saving passengers..." << endl;
    ofstream outfile;

    outfile.open("passengers.dat");
    for(auto it = PassengerList.begin(); it != PassengerList.end(); ++it)
    {
        outfile << it->second->GetName() << "|"
        << it->second->GetId() << "|"
        << char(it->second->GetPaymentMethod()) << "|"
        << it->second->GetHandicap() << "|"
        << it->second->GetPets() << "|"
        << it->second->GetRatingMin() << endl;
    }

    outfile.seekp(-1, ios::end); //remove last newline, replace with EOF
    outfile.put(' ');

    outfile.close();

    cout << "Passengers saved." << endl;
}

void Passengers::LoadPassengers()
{
    cout << "Loading passengers..." << endl;
    ifstream infile;
    infile.open("passengers.dat");
    if (infile.fail()) { cout << "Error opening file (maybe it doesn't exist?)." << endl; return; }
    string name;
    string id;
    string payment;
    string handicap;
    string pets;
    string ratingMin;

    while(!infile.eof())
    {
        getline(infile, name, '|');
        getline(infile, id, '|');
        getline(infile, payment, '|');
        getline(infile, handicap, '|');
        getline(infile, pets, '|');
        getline(infile, ratingMin);

        Passenger* passenger = new Passenger(name, stoi(id),
        static_cast<Payment>(char(payment[0])), stoi(handicap),
        stoi(pets), stod(ratingMin));

        PassengerList[stoi(id)] = passenger;
    }
    infile.close();
    cout << "Passengers loaded." << endl;
}