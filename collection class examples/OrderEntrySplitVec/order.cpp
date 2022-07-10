//
//  order.cpp
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//


#include <iostream>
#include <string>
#include "order.h"
using namespace std;

//order methods

order::order(int id, int id2, int id3) {orderid = id; custloc = id2; itemloc = id3;}

int order::getid() {return orderid;}

int order::getcustid() { return custloc;}

int order::getitemid() {return itemloc;}


void order::setid(int id) { orderid = id;}

void order::setcustid(int id) {custloc = id;}

void order::setitemid(int id) {itemloc = id;}


void order::print() {
    cout << "order id: " <<orderid << "customer: " << custloc << "Item: " <<itemloc <<endl;
}

