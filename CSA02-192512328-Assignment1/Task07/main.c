
#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 2;

    /* Example 1: Integer division */
    printf("1. Integer division: 5 / 2 = %d\n", a / b);

    /* Example 2: Explicit type conversion */
    printf("2. Floating-point division: (double)5 / 2 = %.2f\n",
           (double)a / b);

    /* Example 3: Integer truncation */
    double price = 10.75;
    int truncated_price = (int)price;

    printf("3. Casting 10.75 to int = %d\n", truncated_price);

    /* Integer paise calculation */
    long bill_paise = 16250;

    printf("4. Bill in rupees: Rs. %ld.%02ld\n",
           bill_paise / 100, bill_paise % 100);

    /* Floating-point representation */
    double float_bill = 162.50;

    printf("5. Floating-point bill: Rs. %.2f\n", float_bill);

    return 0;
}
