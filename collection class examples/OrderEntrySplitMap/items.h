//
//  Customers.h
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

#include <map>
using namespace std;

class items
{
private:
    int itemcount;
    std::map<int, item*> itemlist;

public:
    items() { itemcount = 0; }
    
    int getcount();

    void inccount();
    void deccount();

    void additem();
    void delitem(int);
    item *finditem(int);
    void cleanup();
    void prtlist();
    void storeitems();
    void loaditems();
};
