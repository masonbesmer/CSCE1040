#include "driver.h"
#include "passenger.h"
#include "drivers.h"
#include "ride.h"
#include "rides.h"

int main()
{
    Driver d3;
    Driver a,b,c,d,e,g;

    Passenger p1;
    p1.SetName("Johnny Manziel");
    p1.SetId(1);
    p1.SetPaymentMethod('C');
    p1.SetHandicap(true);
    p1.SetPets(false);
    p1.SetRatingMin(5);

    //p1.PrintPassenger();

    Drivers f;
    f.AddDriver(&d3);
    f.AddDriver(&a);
    f.AddDriver(&b);
    f.AddDriver(&c);
    f.AddDriver(&d);
    f.AddDriver(&e);
    f.AddDriver(&g);

    f.PrintDrivers();

    Ride a1;
    Ride a2;

    a1.SetRideID(1);
    a1.SetPartySize(2);
    a1.SetPickupLocation("123 Main St");
    a1.SetDropoffLocation("456 Main St");
    a1.SetPickupTime(time(0));
    a1.SetDropoffTime(time(0));
    a1.SetIncludesPets(true);
    a1.SetRideStatus('L');
    a1.SetRating(5);

    a2.SetRideID(2);
    a2.SetPartySize(3);
    a2.SetPickupLocation("123 Main St");
    a2.SetDropoffLocation("456 Main St");
    a2.SetPickupTime(time(0));
    a2.SetDropoffTime(time(0));
    a2.SetIncludesPets(true);
    a2.SetRideStatus('L');
    a2.SetRating(5);

    Rides r;
    
    r.AddRide(&a1);
    r.AddRide(&a2);

    r.PrintRides();

    return 0;
}