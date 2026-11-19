
#include <stdio.h>

int main(void)
{
    int units;
    int result;

    printf("Enter electricity units consumed: ");

    result = scanf("%d", &units);

    if (result != 1) {
        printf("Error: Invalid input. Enter a whole number.\n");
        return 1;
    }

    if (units < 0) {
        printf("Error: Units cannot be negative.\n");
        return 1;
    }

    long bill_paise = 5000L;

    if (units > 100 && units <= 200) {
        bill_paise += (long)(units - 100) * 225L;
    } else if (units > 200) {
        bill_paise += 100L * 225L;
        bill_paise += (long)(units - 200) * 450L;
    }

    printf("Units consumed: %d\n", units);
    printf("Total bill: Rs. %ld.%02ld\n",
           bill_paise / 100, bill_paise % 100);

    return 0;
}
