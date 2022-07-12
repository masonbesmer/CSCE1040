#include "passengers.h"

void Passengers::AddPassenger()
{
    string name;
    int id;
    char payment;
    bool handicap, pets;
    double ratingMin;
    cout << "Enter the name of the passenger: "; getline(cin, name);
    cout << "Enter the ID of the passenger: "; cin >> id;
    cout << "Enter the payment method of the passenger ('C'ash/'D'ebit/c'R'edit): "; cin >> payment;
    cout << "Enter whether the passenger has a handicap (0/1):"; cin >> handicap;
    cout << "Enter whether the passenger has pets (0/1):"; cin >> pets;
    cout << "Enter the minimum driver rating of the passenger: "; cin >> ratingMin;

    cin.ignore();

    Passenger* passenger = new Passenger(name, id, static_cast<Payment>(payment), handicap, pets, ratingMin);
    PassengerList[id] = passenger;
    IncrementPassengerCount();

    this->SavePassengers();

    cout << "Passenger added successfully!" << endl;
}

void Passengers::AddPassenger(Passenger* newPassenger)
{
    cout << "Passenger ID for passenger " << newPassenger->GetName() << " with ID#" << newPassenger->GetId() << " will be updated to " << PassengerList.size() + 1 << endl;
    newPassenger->SetId(PassengerList.size() + 1);
    PassengerList[newPassenger->GetId()] = newPassenger;
    IncrementPassengerCount();
}

void Passengers::EditPassenger()
{
    int IDtoEdit=-1;
    cout << "Enter the ID of the passenger you want to edit: "; cin >> IDtoEdit;
    Passenger* toEdit = this->SearchPassengerByID(IDtoEdit);
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

    this->SavePassengers();
    
    cout << "Passenger edited successfully!" << endl;
}

void Passengers::RemovePassenger(int id)
{
    PassengerList.erase(id);
    this->SavePassengers();
    cout << "Passenger removed successfully!" << endl;
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
    if(PassengerList[id] != NULL)
    {
        return PassengerList[id];
    }
    else
    {
        cout << "Passenger not found!" << endl;
        return NULL;
    }
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
    ofstream outfile;
    outfile.open("passengers.dat");
    for(auto it = PassengerList.begin(); it != PassengerList.end(); ++it)
    {
        outfile << it->second->GetName() << "|" << it->second->GetId() << "|" << it->second->GetPaymentMethod() << "|" << it->second->GetHandicap() << "|" << it->second->GetPets() << "|" << it->second->GetRatingMin() << endl;
    }
    outfile.close();
}

void Passengers::LoadPassengers()
{
    ifstream infile;
    infile.open("passengers.dat");
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
        Passenger* passenger = new Passenger(name, stoi(id), static_cast<Payment>(payment[0]), stoi(handicap), stoi(pets), stod(ratingMin));
        PassengerList[stoi(id)] = passenger;
    }
}