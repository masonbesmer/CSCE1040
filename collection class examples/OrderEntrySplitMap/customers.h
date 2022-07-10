//
//  Customers.h
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

#include <map>
using namespace std;

class customers
{
private:
    int custcount;

    typedef map<int, customer*> custtype;
    custtype customerlist;
public:
    customers() {custcount = 0; }
    int getcount();

    void inccount();
    void deccount();

    void addcust();
    void delcust(int);
    customer* findcust(int);
    void cleanup();
    void prtlist();
    void loadcust();
    void storecust();
};
