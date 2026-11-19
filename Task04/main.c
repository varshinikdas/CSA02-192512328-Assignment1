
#include <stdio.h>

/* Unsafe macro */
#define SQUARE_BAD(x) x * x

/* Safer macro with parentheses */
#define SQUARE(x) ((x) * (x))

/* Safer alternative using an inline function */
static inline int square(int x)
{
    return x * x;
}

int main(void)
{
    int a = 3;
    int b = 4;

    printf("Unsafe SQUARE_BAD(3 + 1) = %d\n",
           SQUARE_BAD(3 + 1));

    printf("Safe SQUARE(3 + 1) = %d\n",
           SQUARE(3 + 1));

    printf("Inline square(4) = %d\n", square(b));

    printf("Safe MAX example = %d\n",
           ((a) > (b) ? (a) : (b)));

    return 0;
}
