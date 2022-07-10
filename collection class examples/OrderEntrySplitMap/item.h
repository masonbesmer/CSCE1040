//
//  item.h
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

using namespace std;

class item {
    
private:
    int item_id;
    float price;
  
public:
    
    item (int, float);
    int getid();
    float getprice();
    void setid(int);
    void setprice(float);
    virtual void print();
    friend ostream& operator<<(ostream& st, item& it);
};

class boitem : public item
{
private:
    std::string availdate;
    std::string shipdate;
public:
    boitem (std::string d1, std::string d2, int id, float pr);
    void setavdate(std::string d);
    void setshdate( std::string d);
    std::string getavdate();
    std::string getshdate();
    void print();

    
};


class preitem : public item
{
private:
    std::string availdate;
    std::string shipdate;
public:
    preitem (std::string d1, std::string d2, int id, float pr);
    void setavdate(std::string d);
    void setshdate( std::string d);
    std::string getavdate();
    std::string getshdate();
    void print();
};

