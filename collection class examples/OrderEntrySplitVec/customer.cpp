//
//  customer.cpp
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//


#include <iostream>
#include <string>
#include "customer.h"
using namespace std;

//customer methods

customer::customer(int id, string nm) { custid = id; name = nm;}

int customer::getid() {return custid;}

string customer::getname() {return name;}

customer* customer::getnext() {return next;}

void customer::setid(int id) {custid = id;}

void customer::setname(string nm) {name = nm;}

void customer::setnext(customer* np) {next = np;}

void customer::print() {
    cout << "Customer ID: " <<custid << " Name: " << name <<endl;
}
