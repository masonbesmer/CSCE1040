#include "driver.h"
#include "passenger.h"
#include "drivers.h"

int main()
{
    Driver d3;
    d3.SetDriverID(1);
    d3.SetDriverName("Johnny Manziel");
    d3.SetDriverPhone(123457890);
    d3.SetVehicleCapacity(53);
    d3.SetCanHandicap(true);
    d3.SetRating(556);
    d3.SetIsAvailable(true);
    d3.SetAllowPets(false);
    d3.SetNotes("do not let this distract you fron the fact that in 1998 the undertaker threw mankind off hell in a cell and plummeted 16 feet through the announcer's table");

    Passenger p1;
    p1.SetName("Johnny Manziel");
    p1.SetId(1);
    p1.SetPaymentMethod('C');
    p1.SetHandicap(true);
    p1.SetPets(false);
    p1.SetRatingMin(5);

    p1.PrintPassenger();

    Drivers f;
    f.AddDriver(d3);


    return 0;
}