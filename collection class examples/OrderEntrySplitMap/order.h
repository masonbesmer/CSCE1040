//
//  order.h
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

class order
{
private:
    int orderid;
    int custloc;
    int itemloc;
public:
    order(int, int, int);
    int getid();
    int getcustid();
    int getitemid();
    
    void setid(int);
    void setcustid(int);
    void setitemid(int);
    
    void print();
};
