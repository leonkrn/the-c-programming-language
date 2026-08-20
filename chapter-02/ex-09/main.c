#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
    unsigned x;
    x = 15;

    printf("amount of bits set to one in the number %d: %d\n", x, bitcount(x));

    return 0;
}

/* this function counts the amount of bits set to 1 in x
* using x &= (x-1) to delete the rightmost bit set to 1 (setting it to 0) */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1)) {
        ++b;
    }

    return b;
}
