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

void Passengers::PrintPassenger()
{
    int id;
    cout << "Enter the ID of the passenger you want to print: "; cin >> id;
    PassengerList[id]->PrintPassenger();
}

void Passengers::SavePassengers()
{
    cout << "Saving passengers..." << endl;
    
    ofstream outfile;
    outfile.open("passengers.dat");

    for(auto x : PassengerList)
    {
        outfile << x.first << "|"
        << x.second->GetName() << "|"
        << x.second->GetPaymentMethod() << "|"
        << x.second->GetHandicap() << "|"
        << x.second->GetPets() << "|"
        << x.second->GetRatingMin()
        << endl;
    }

    outfile.close();
    cout << "Passengers saved." << endl;
}

void Passengers::LoadPassengers()
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