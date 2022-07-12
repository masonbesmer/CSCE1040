#include "passenger.h"

Passenger::Passenger()
{
    name = "default";
    id = -1;
    paymentMethod = Cash;
    handicap = false;
    pets = false;
    ratingMin = -1;
}

Passenger::Passenger(string name, int id, char payment, bool handicap, bool pets, double ratingMin)
{
    this->name = name;
    this->id = id;
    this->paymentMethod = static_cast<Payment>(payment);
    this->handicap = handicap;
    this->pets = pets;
    this->ratingMin = ratingMin;
}

void Passenger::SetName(string name)
{
    this->name = name;
}

void Passenger::SetId(int id)
{
    this->id = id;
}

void Passenger::SetPaymentMethod(char p)
{
    switch (p)
    {
    case 'C':
        this->paymentMethod = Cash;
        break;
    case 'D':
        this->paymentMethod = Debit;
        break;
    case 'R':
        this->paymentMethod = Credit;
        break;
    }
}

void Passenger::SetHandicap(bool handicap)
{
    this->handicap = handicap;
}

void Passenger::SetPets(bool pets)
{
    this->pets = pets;
}

void Passenger::SetRatingMin(double ratingMin)
{
    this->ratingMin = ratingMin;
}

string Passenger::GetName() {
    return name;
}

int Passenger::GetId() {
    return id;
}

Payment Passenger::GetPaymentMethod() {
    return paymentMethod;
}

bool Passenger::GetHandicap() {
    return handicap;
}

bool Passenger::GetPets() {
    return pets;
}

double Passenger::GetRatingMin() {
    return ratingMin;
}

void Passenger::PrintPassenger() {
    cout << "====================Passenger Info======================" << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Payment Method: ";
    switch (paymentMethod)
    {
        case 'C':
            cout << "Cash" << endl;
            break;
        case 'R':
            cout << "Credit" << endl;
            break;
        case 'D':
            cout << "Debit" << endl;
            break;
        default:
            cout << "Other" << endl;
            break;
    } 
    cout << "Handicap: " << handicap << endl;
    cout << "Pets: " << pets << endl;
    cout << "Rating Min: " << ratingMin << endl;
    cout << "========================================================" << endl;
}