#include "driver.h"
#include "passenger.h"
#include "drivers.h"
#include "ride.h"
#include "rides.h"
#include "passengers.h"

int main()
{
    // // Driver d3;
    Driver a,b,c,d,e,g;

    // //p1.PrintPassenger();

    Drivers f;

    // f.AddDriver(&a);
    // f.AddDriver(&b);
    // f.AddDriver(&c);
    // f.AddDriver(&d);
    // f.AddDriver(&e);
    // f.AddDriver(&g);
    f.LoadDrivers();
    f.PrintDrivers();

    // // Ride a1,a2,a3;

    // // a1.SetRideID(1);
    // // a1.SetPartySize(2);
    // // a1.SetPickupLocation("123 Main St");
    // // a1.SetDropoffLocation("456 Main St");
    // // a1.SetPickupTime(time(0));
    // // a1.SetDropoffTime(time(0));
    // // a1.SetIncludesPets(true);
    // // a1.SetRideStatus('L');
    // // a1.SetRating(5);

    // // a2.SetRideID(2);
    // // a2.SetPartySize(3);
    // // a2.SetPickupLocation("123 Main St");
    // // a2.SetDropoffLocation("456 Main St");
    // // a2.SetPickupTime(time(0));
    // // a2.SetDropoffTime(time(0));
    // // a2.SetIncludesPets(true);
    // // a2.SetRideStatus('L');
    // // a2.SetRating(5);

    // // a3.SetRideID(3);
    // // a3.SetPartySize(4);
    // // a3.SetPickupLocation("123 Main St");
    // // a3.SetDropoffLocation("456 Main St");
    // // a3.SetPickupTime(time(0));
    // // a3.SetDropoffTime(time(0));
    // // a3.SetIncludesPets(false);
    // // a3.SetRideStatus('L');
    // // a3.SetRating(5);

    // Rides r;
    
    // r.AddRide(&a1);
    // r.AddRide(&a2);
    // r.AddRide(&a3);

    // //r.PrintEveryRideEver();

    // Passenger a,b,c,d,e,f,g;

    // Passengers p;

    // p.AddPassenger(&a);
    // p.AddPassenger(&b);
    // p.AddPassenger(&c);
    // p.AddPassenger(&d);
    // p.AddPassenger(&e);
    // p.AddPassenger(&f);
    // p.AddPassenger(&g);

    // p.LoadPassengers();
    // //p.EditPassenger();
    // p.PrintPassengers();

    return 0;
}