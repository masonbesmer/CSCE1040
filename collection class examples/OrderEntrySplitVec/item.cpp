//
//  item.cpp
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//


#include <iostream>
#include <string>
#include "item.h"
using namespace std;

//item methods

item::item (int id, float pr)  {item_id = id; price = pr;}

int item::getid()  {return item_id;}

float item::getprice() {return price;}



void item::setid(int id) {item_id = id;}

void item::setprice(float pr) {price = pr;}



void item::print() {
    cout << "Item ID: " << item_id << " Price: " << price << endl;
}

boitem::boitem (string d1, string d2, int id, float pr):item (id,pr)
{
 availdate = d1;
shipdate = d2;
}

void boitem::setavdate(string d){availdate = d;}
void boitem::setshdate( string d){shipdate = d;}
string boitem::getavdate(){return availdate;}
string boitem::getshdate(){return shipdate;}
void boitem::print()
{
    item::print();
    cout << "Available date: "<<availdate << " Ship Date: " << shipdate <<endl;
}



preitem::preitem (string d1, string d2, int id, float pr):item(id,pr)
{
    availdate = d1;
    shipdate = d2;
}

void preitem::setavdate(string d){availdate = d;}
void preitem::setshdate( string d){shipdate = d;}
string preitem::getavdate(){return availdate;}
string preitem::getshdate(){return shipdate;}
void preitem::print()
{
    item::print();
    cout << "Available date: "<<availdate << " Ship Date: " << shipdate <<endl;
}

ostream& operator<<(ostream& st, item& it)
{
    it.print();
    return st;
}

