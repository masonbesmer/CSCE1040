//
//  items.cpp
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
#include <typeinfo>
#include "item.h"
#include "items.h"


using namespace std;

// items methods

int items::getcount() {return itemcount;}

void items::inccount() {itemcount++;}

void items::deccount() {itemcount--;}

void items::additem()
{
    int id; float pr, otype;
    item *temp;
    string d1, d2;
    
    cout << "Enter new item ID: ";
    cin >> id;
    cin.ignore();
    
    cout << "Enter price: ";
    cin  >> pr;
    
    cout << "Enter 1 for Preorder or 2 for Backorder"<<endl;
    cin >> otype;
    cin.ignore();
    cout << "Enter available date as xx/xx/xx: " << endl;
    cin >> d1;
    cout << "Enter ship date as xx/xx/xx: " << endl;
    cin >> d2;
    
    if (otype == 1)
      temp = new preitem(d1,d2,id,pr);
    else
      temp = new boitem(d1,d2,id,pr);
    
    itemlist.push_back(temp);
    inccount();

}

void items::delitem(int id)
{
    
    item* cust;
    for (auto it = itemlist.begin(); it !=itemlist.end(); ++it)
    {
        if ((*it)->getid() == id)
        {
            itemlist.erase(it);
        }
    }
    
    return;
}

item* items::finditem(int id)
{
    item *temp;
    for (int i =0; i < itemcount; i++)
    {
        if (itemlist[i]->getid() == id) return itemlist[i];
        
    }
    
    return NULL;

}

void items::cleanup()
{
    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
    {
        
        delete *it;
    }
    itemlist.clear();
}

void items::prtlist()
{
    
    
    for (auto it = itemlist.begin(); it !=itemlist.end(); ++it)
    {
        
        cout << "ID: " << (*it)->getid() << " price: " <<  (*it)->getprice() << endl;
      
        
        if (typeid(**it) == typeid (boitem))
        {
            boitem *tempbo = dynamic_cast<boitem*> (*it);
            cout << "Back Order Item " << "Avail Date: " << tempbo->getavdate() << " Ship date: " << tempbo->getshdate() << endl;
        }
        
        else if (typeid(**it) == typeid (preitem))
        {
            preitem *temppre = dynamic_cast<preitem *> (*it);
            cout << "Pre Order Item " << "Avail Date: " << temppre->getavdate() << " Ship date: " << temppre->getshdate() << endl;
        }
    }
}

void items::storeitems()
{
    ofstream fout;
    fout.open("items.dat");
    fout << itemcount << endl;
    
    item *temp;
    for (auto it = itemlist.begin(); it !=itemlist.end(); ++it)
    {
        temp=*it;
        fout << temp->getid() << " " <<  temp->getprice() << endl;
      
        if (typeid(**it) == typeid (boitem))
        {
            boitem *tempbo = dynamic_cast<boitem*> (temp);
            fout << "2 " << tempbo->getavdate() << " " << tempbo->getshdate() << endl;
        }
        
       else if (typeid(**it) == typeid (preitem))
        {
            preitem *temppre = dynamic_cast<preitem *> (temp);
            fout << "1 " << temppre->getavdate() << " " << temppre->getshdate() << endl;
        }
     
        
        
    }
    fout.close();
}

void items::loaditems()
{
    ifstream fin;
    int id;
    float pr;
    int itype;
    string adate, sdate;
    fin.open("items.dat");
    fin >> itemcount; fin.ignore();
    item *temp;
    
    for ( int i=0; i < itemcount; i++)
    {
        
        fin >> id >> pr >> itype;
        cout << id << pr<< itype;
        
        if (itype == 1)
        {
            cout<< "pre order"<<endl;
            fin >> adate >> sdate;
            preitem * myitem  = new preitem(adate, sdate, id, pr);
            itemlist.push_back( myitem);
        }
        
        else if (itype == 2)
        {
            cout << "Bo Order" <<endl;
            fin >> adate >> sdate;
            boitem * myitem  = new boitem(adate, sdate, id, pr);
            itemlist.push_back(myitem);
        }
    }
    fin.close();
    
}
