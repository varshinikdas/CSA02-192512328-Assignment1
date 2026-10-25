
#include <stdio.h>

/* Include guard demonstration */
#ifndef BILLING_CONFIG_H
#define BILLING_CONFIG_H

#define FIXED_CHARGE 50
#define RATE_PER_UNIT 2.25

#endif

int main(void)
{
    int units = 150;
    double energy_charge = 0.0;

    if (units > 100) {
        energy_charge = (units - 100) * RATE_PER_UNIT;
    }

#ifdef DEBUG
    printf("[DEBUG] Units = %d\n", units);
    printf("[DEBUG] Fixed charge = Rs. %.2f\n",
           (double)FIXED_CHARGE);
    printf("[DEBUG] Energy charge = Rs. %.2f\n",
           energy_charge);
#endif

    printf("Electricity units: %d\n", units);
    printf("Fixed charge: Rs. %.2f\n",
           (double)FIXED_CHARGE);
    printf("Energy charge: Rs. %.2f\n",
           energy_charge);
    printf("Total bill: Rs. %.2f\n",
           FIXED_CHARGE + energy_charge);

    return 0;
}
