
#include <stdio.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200

#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450

#define FIXED_CHARGE_PAISE 5000L

long compute_bill(int units)
{
    long energy_charge = 0;

    if (units < 0)
        return -1;

    if (units <= SLAB1_UNITS) {
        energy_charge = units * RATE1_PAISE;
    }
    else if (units <= SLAB2_UNITS) {
        energy_charge =
            (units - SLAB1_UNITS) * RATE2_PAISE;
    }
    else {
        energy_charge =
            (SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE
            + (units - SLAB2_UNITS) * RATE3_PAISE;
    }

    return FIXED_CHARGE_PAISE + energy_charge;
}

void display_bill(int units)
{
    long bill = compute_bill(units);

    if (bill < 0) {
        printf("Invalid units: %d\n", units);
        return;
    }

    printf("Units: %d | Bill: Rs. %ld.%02ld\n",
           units, bill / 100, bill % 100);
}

int main(void)
{
    display_bill(0);
    display_bill(100);
    display_bill(150);
    display_bill(200);
    display_bill(350);

    return 0;
}
