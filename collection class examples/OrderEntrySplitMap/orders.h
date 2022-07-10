//
//  orders.h
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

#include <map>

class orders
{
private:
    int ordcount;

    std::map<int, order*> orderlist;
public:
    orders() {ordcount = 0; }
    
    int getcount();

    void inccount();
    void deccount();

    void addorder();
    void delorder(int);
    order *findorder(int);
    void cleanup();
    void prtlist();
    void loadorder();
    void storeorder();
    
    
};


