#include "driver.h"

int main()
{
    Driver d1;
    d1.PrintDriver();
    Driver d2(1, "Johnny Manziel", 123457890, 53, 'V', true, 556, true, false, "do not let this dinouncer's table");
    d2.PrintDriver();

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
    d3.PrintDriver();
}