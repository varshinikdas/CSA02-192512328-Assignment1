#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

int main(void)
{
    printf("--- Data Type Sizes ---\n");
    printf("sizeof(int) = %zu bytes\n", sizeof(int));
    printf("sizeof(long) = %zu bytes\n", sizeof(long));
    printf("sizeof(long long) = %zu bytes\n", sizeof(long long));
    printf("sizeof(float) = %zu bytes\n", sizeof(float));
    printf("sizeof(double) = %zu bytes\n", sizeof(double));

    printf("\n--- Integer Ranges ---\n");
    printf("INT_MAX = %d\n", INT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);

    printf("\n--- Floating-Point Precision ---\n");
    printf("FLT_DIG = %d decimal digits\n", FLT_DIG);
    printf("DBL_DIG = %d decimal digits\n", DBL_DIG);

    printf("\n--- Billing Comparison ---\n");

    long long bill_paise = 16250;
    double bill_rupees = 162.50;

    printf("Integer paise: %lld\n", bill_paise);
    printf("Integer-paise display: Rs. %lld.%02lld\n",
           bill_paise / 100, bill_paise % 100);
    printf("Double display: Rs. %.2f\n", bill_rupees);

    printf("\n--- Large Total Example ---\n");

    long long houses = 800000LL;
    long long paise_per_house = 16250LL;
    long long total_paise = houses * paise_per_house;

    printf("Houses: %lld\n", houses);
    printf("Total bill in paise: %lld\n", total_paise);
    printf("Total bill in rupees: Rs. %lld.%02lld\n",
           total_paise / 100, total_paise % 100);

    return 0;
}
