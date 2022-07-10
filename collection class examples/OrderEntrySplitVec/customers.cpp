//
//  customers.cpp
//  OrderEntry
//
//  Created by David Keathly on 3/29/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "customer.h"
#include "customers.h"


using namespace std;

//collections methods

int customers::getcount() { return custcount;}

void customers::inccount() {custcount++;}

void customers::deccount() { custcount--;}

void customers::addcust() {
    int id; string buff;
    customer *temp;
    
    cout << "Enter new customer ID: ";
    cin >> id;
    cin.ignore();
    
    cout << "Enter name: ";
    getline(cin, buff);
 //   cin.ignore();

    temp = new customer(id,buff);
    
   
    customerlist.push_back(temp);
    inccount();
}



void customers::delcust(int id)
{
    customer* cust;
    for (auto it = customerlist.begin(); it !=customerlist.end(); ++it)
    {
        if ((*it)->getid() == id)
        {
            customerlist.erase(it);
        }
    }
    
   return;
}

customer* customers::findcust(int id)
{
    customer *temp;
    for (int i =0; i < custcount; i++)
    {
        if (customerlist[i]->getid() == id) return customerlist[i];
        
    }
  
    return NULL;
  
}

void customers::cleanup()
{
       for (auto it = customerlist.begin(); it !=customerlist.end(); ++it)
    {
        
        delete *it;
    }
    customerlist.clear();
}

void customers::prtlist()
{
 
    customer *temp;
    for (auto it = customerlist.begin(); it !=customerlist.end(); ++it)
    {
        temp = *it;
        cout << "customer id: " << temp->getid() << " Customer name: " << temp->getname() <<endl;
    }
}

void customers::storecust()
{
    ofstream fout;
    fout.open("customers.dat");
    fout << custcount << endl;
    
    customer *temp;
   for (auto it = customerlist.begin(); it !=customerlist.end(); ++it)
    {
        temp= *it;
        fout << temp->getid() << " " <<  temp->getname() << endl;
    }
    fout.close();
}

void customers::loadcust()
{
    ifstream fin;
    int id;
    string name;
    fin.open("customers.dat");
    fin >> custcount; fin.ignore();
    
    for ( int i=0; i < custcount; i++)
    {
        
        fin >> id >> name;
        customerlist.push_back( new customer(id,name));
    }
    fin.close();
    
}
