//
//  orders.cpp
//  OrderEntry
//
//  Created by David Keathly on 3/29/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include "order.h"
#include "orders.h"


using namespace std;

//orders methods

int orders::getcount() {return ordcount;}

void orders::inccount() {ordcount++;}

void orders::deccount() {ordcount--;}


void orders::addorder()
{
    int id, id2, id3;
    order *temp;
    
    cout << "Enter new order ID: ";
    cin >> id;
    cin.ignore();
    
    cout << "Enter customer ID: ";
    cin >> id2;
    cin.ignore();
    
    cout << "Enter item ID: ";
    cin >> id3;
    cin.ignore();
    
    temp = new order(id,id2, id3);
    
    orderlist.push_back( temp);
    inccount();

}

void orders::delorder(int id)
{
    int ord;
    for (auto it = orderlist.begin(); it !=orderlist.end(); ++it)
    {
        if ((*it)->getid() == id)
        {
            orderlist.erase(it);
        }
        
    }
}

int orders::findorder(int id)
{
    order *temp;
     for (auto it = orderlist.begin(); it !=orderlist.end(); ++it)
    {
        if ((*it)->getid() == id) return 1;
                                                                
    }
                                                                
  return -1;
}

void orders::cleanup()
{
    for (auto it = orderlist.begin(); it !=orderlist.end(); ++it)
    {
        
        delete *it;
    }
    orderlist.clear();
}

void orders::prtlist()
{
    order *temp;
    for (auto it = orderlist.begin(); it !=orderlist.end(); ++it)
    {
        temp = *it;
        cout << "Order id: " << temp->getid() << " Customer id: " << temp->getcustid() << " item id: " << temp->getitemid() <<endl;
    }
}

void orders::storeorder()
{
    ofstream fout;
    fout.open("orders.dat");
    fout << ordcount << endl;
    
    order *temp;
    for (auto it = orderlist.begin(); it !=orderlist.end(); ++it)
    {
        temp = *it;
        fout << temp->getid() << " " << temp->getcustid() << " " << temp->getitemid() <<endl;
    }
    fout.close();
}

void orders::loadorder()
{
    ifstream fin;
    int id, itmid, cusid;
  
    fin.open("orders.dat");
    fin >> ordcount; fin.ignore();
    
    for (int i = 0; i < ordcount; i++)
    {
        fin >> id >> cusid >> itmid;
        orderlist.push_back(new order(id,cusid,itmid));
    }

    fin.close();
    
}
