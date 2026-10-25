
#include <stdio.h>
#include <limits.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE2_PAISE 225L
#define RATE3_PAISE 450L
#define FIXED_CHARGE_PAISE 5000L

typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current)
{
    return (unsigned int)(meter_t)(current - previous);
}

long compute_bill(unsigned int units)
{
    if (units <= SLAB1_UNITS)
        return FIXED_CHARGE_PAISE;

    if (units <= SLAB2_UNITS)
        return FIXED_CHARGE_PAISE
             + (long)(units - SLAB1_UNITS) * RATE2_PAISE;

    return FIXED_CHARGE_PAISE
         + (long)(SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE
         + (long)(units - SLAB2_UNITS) * RATE3_PAISE;
}

void display_bill(unsigned int units)
{
    long bill = compute_bill(units);

    printf("Units: %u | Bill: Rs. %ld.%02ld\n",
           units, bill / 100, bill % 100);
}

int main(void)
{
    printf("Maximum meter reading: %u\n", (unsigned)USHRT_MAX);

    printf("\n--- Meter consumption tests ---\n");
    printf("Normal: %u units\n", consumption(1200, 1530));
    printf("Rollover: %u units\n", consumption(65400, 120));
    printf("Boundary rollover: %u units\n", consumption(65535, 0));

    printf("\n--- Billing tests ---\n");
    display_bill(0);
    display_bill(100);
    display_bill(150);
    display_bill(200);
    display_bill(350);

    return 0;
}
