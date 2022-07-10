//
//  customer.h
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//




class customer
{
private:
    int custid;
    std::string name;
    customer *next;
    
public:
    customer(int, std::string);
    int getid();
    std::string getname();
    customer* getnext();
    void setid(int);
     void setname(std::string);
    void setnext(customer*);
    void print();
};
