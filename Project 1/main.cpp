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
                cout << "Lets clear completed rides.." << endl;
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