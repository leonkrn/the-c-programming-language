#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    printf("%u\n", setbits(23, 2, 3, 8));
    return 0;
}

/* this function returns x with the n bits that begin at p set to the rightmost bits of y, leaving the rest of the bits in y unaltered */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // right justify the bit block of size n, starting at p (assuming the rightmost bit is index 0, and the leftmost bit the highest index)
    x = x >> (p+1-n);

    // create an unsigned char and store ~0 (a bit sequence of only 1s) leftshifted by n (n rightmost bits are 0) in it
    unsigned z;
    z = ~0 << n;

    // invert y: the rightmost n bits in y are now 1s, the rest are 0s (needed for masking)
    z = ~z;

    // bitwise AND x with y -> only the n rightmost bits of x will be "let through"
    x = z & x;

    // rightshift y by n bits then leftshift y by n bits: now the rightmost n bits in y are guaranteed to be 0s (needed for masking)
    y = y >> n;
    y = y << n;

    // bitwise OR x with y to get the rest of the bits from y
    x = x|y;

    return x;
}
