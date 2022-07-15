/**
 * @file main.cpp
 * @author Mason Besmer (masonbesmer@my.unt.edu)
 * @brief 
 * @version 1.0
 * @date 2022-07-15
 * 
 * @details It is a rideshare program called U1040.
 *          It is a program that allows you to create a list of drivers and passenger and rides.
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "driver.h"
#include "passenger.h"
#include "drivers.h"
#include "ride.h"
#include "rides.h"
#include "passengers.h"

int main()
{
    // // // Driver d3;
    // //Driver a,b,c,d,e,g;

    // // //p1.PrintPassenger();

    // Drivers f;

    // // f.AddDriver(&a);
    // // f.AddDriver(&b);
    // // f.AddDriver(&c);
    // // f.AddDriver(&d);
    // // f.AddDriver(&e);
    // // f.AddDriver(&g);
    // f.LoadDrivers();
    // //f.PrintDrivers();

    // //Ride a1,a2,a3;

    // // a1.SetRideID(1);
    // // a1.SetPartySize(2);
    // // a1.SetPickupLocation("123 Main St");
    // // a1.SetDropoffLocation("456 Main St");
    // // a1.SetPickupTime(time(0));
    // // a1.SetDropoffTime(time(0));
    // // a1.SetIncludesPets(true);
    // // a1.SetRideStatus('L');
    // // a1.SetRating(5);
    // // a1.SetDriverID(1);
    // // a1.SetPassengerID(1);

    // // a2.SetRideID(2);
    // // a2.SetPartySize(3);
    // // a2.SetPickupLocation("123 Main St");
    // // a2.SetDropoffLocation("456 Main St");
    // // a2.SetPickupTime(time(0));
    // // a2.SetDropoffTime(time(0));
    // // a2.SetIncludesPets(true);
    // // a2.SetRideStatus('L');
    // // a2.SetRating(5);
    // // a2.SetDriverID(1);
    // // a2.SetPassengerID(1);

    // // a3.SetRideID(3);
    // // a3.SetPartySize(4);
    // // a3.SetPickupLocation("123 Main St");
    // // a3.SetDropoffLocation("456 Main St");
    // // a3.SetPickupTime(time(0));
    // // a3.SetDropoffTime(time(0));
    // // a3.SetIncludesPets(false);
    // // a3.SetRideStatus('L');
    // // a3.SetRating(5);
    // // a3.SetDriverID(1);
    // // a3.SetPassengerID(1);

    // Rides r;
    
    // // r.AddRide(&a1);
    // // r.AddRide(&a2);
    // // r.AddRide(&a3);
    // r.LoadRides();
    // r.LoadDrivers();
    // r.LoadPassengers();
    // r.PrintEveryRideEver();
    // r.AddRide();
    // //cout << r.CheckIfDriverCanDoPets(2, true);
    // f.EditDriver();
    // r.PrintDriverRides(1);

    // //Passenger q,x,v,j,k,l,m;

    // //Passengers z;

    // // z.AddPassenger(&q);
    // // z.AddPassenger(&x);
    // // z.AddPassenger(&v);
    // // z.AddPassenger(&j);
    // // z.AddPassenger(&k);
    // // z.AddPassenger(&l);
    // // z.AddPassenger(&m);

    // //z.LoadPassengers();
    // //p.EditPassenger();
    // //z.PrintPassengers();
    // //f.EditDriver();
    cout << "UNT Engineering CSCE1040 Project 1 Mason Besmer masonbesmer@my.unt.edu" << endl;
    cout << "Program is starting..." << endl;
    Passengers passengers;
    Rides rides;
    Drivers drivers;

    cout << "Please wait while I load some things..." << endl;
    passengers.LoadPassengers();
    rides.LoadRides();
    drivers.LoadDrivers();

    // cout << "  _    _   __    ___    _  _      ___  " << endl
    //     << " | |  | | /_ |  / _ \\  | || |    / _ \\ " << endl
    //     << " | |  | |  | | | | | | | || |_  | | | |" << endl
    //     << " | |  | |  | | | | | | |__   _| | | | |" << endl
    //     << " | |__| |  | | | |_| |    | |   | |_| |" << endl
    //     << "  \\____/   |_|  \\___/     |_|    \\___/ " << endl << endl;

    int choice = -1;
    while(choice !=0)
    {
        cout << "1. Add Passenger" << endl;
        cout << "2. Add Driver" << endl;
        cout << "3. Add Ride" << endl;
        cout << "4. Edit Driver" << endl;
        cout << "5. Edit Passenger" << endl;
        cout << "6. Edit Ride" << endl;
        cout << "7. Print Drivers" << endl;
        cout << "8. Print Passengers" << endl;
        cout << "9. Print Rides" << endl;
        cout << "10. Remove Ride" << endl;
        cout << "11. Remove Driver" << endl;
        cout << "12. Remove Passenger" << endl;
        cout << "13. Print Driver Rides" << endl;
        cout << "14. Print Passenger Rides" << endl;
        cout << "15. Print rides by Status" << endl;
        cout << "16. Print Schedule for Driver" << endl;
        cout << "17. Print Schedule for Passenger" << endl;
        cout << "18. Print Ride by ID" << endl;
        cout << "19. Print Driver by ID" << endl;
        cout << "20. Print Passenger by ID" << endl;
        cout << "21. Clear canceled rides" << endl;
        cout << "22. Clear completed rides" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
            case 1:
                cout << "Sure, lets add a passenger!" << endl;
                passengers.AddPassenger();
                break;
            case 2:
                drivers.AddDriver();
                break;
            case 3:
                rides.AddRide();
                break;
            case 4:
                drivers.EditDriver();
                break;
            case 5:
                passengers.EditPassenger();
                break;
            case 6:
                rides.EditRide();
                break;
            case 7:
                drivers.PrintDrivers();
                break;
            case 8:
                passengers.PrintPassengers();
                break;
            case 9:
                rides.PrintEveryRideEver();
                break;
            case 10:
                rides.RemoveRide();
                break;
            case 11:
                drivers.RemoveDriver();
                break;
            case 12:
                passengers.RemovePassenger();
                break;
            case 13:
                //get Driver ID from cin
                int driverID;
                cout << "Enter Driver ID: "; cin >> driverID;
                rides.PrintDriverRides(driverID);
                break;
            case 14:
                //get Passenger ID from cin
                int passengerID;
                cout << "Enter Passenger ID: "; cin >> passengerID;
                rides.PrintPassengerRides(passengerID);
                break;
            case 15:
                //get ride status from cin
                char rideStatus;
                cout << "Enter Ride Status(A=Active, L=Canceled, C=Completed): "; cin >> rideStatus;
                rides.PrintRidesByStatus(rideStatus);
                break;
            case 16:
                cout << "Please use 13 or 14 for this function" << endl;
                break;
            case 17:
                cout << "Please use 13 or 14 for this function" << endl;
                break;
            case 18:
                cout << "Lets print a ride by ID.." << endl;
                rides.PrintRide();
                break;
            case 19:
                cout << "Lets print a driver by ID.." << endl;
                drivers.PrintDriver();
                break;
            case 20:
                cout << "Lets print a passenger by ID.." << endl;
                passengers.PrintPassenger();
                break;
            case 21:
                cout << "Lets clear canceled rides.." << endl;
                rides.ClearCompletedRides();
                cout << "Completed Rides Cleared" << endl;
                break;
            case 22:
                rides.ClearCanceledRides();
                cout << "Canceled Rides Cleared" << endl;
                break;
            case 0:
                //redundant save
                rides.SaveRides();
                drivers.SaveDrivers();
                passengers.SavePassengers();
                cout << "================================" << endl;
                cout << "Thank you for using U1040." << endl;
                cout << "================================" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << endl;
    }

    return 0;
}