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

    // use an unsigned char for masking (be aware of promotion of c to an int when having x or y as other operand -> does not matter here because of padding with 0s)
    unsigned char c;

    // create one byte of all 1s (255 is the maximimum number for usigned char)
    c = 255;

    // leftshift c by n: the rightmost n bits in c are now 0s, the rest are 1s
    c = c << n;

    // invert c: the rightmost n bits in c are now 1s, the rest are 0s (needed for masking)
    c = ~c;

    // bitwise AND x with c -> only the n rightmost bits of n will be "let through"
    x = c & x;

    // rightshift y by n bits then leftshift y by n bits: now the rightmost n bits in y are guaranteed to be 0s (needed for masking)
    y = y >> n;
    y = y << n;

    // bitwise OR x with y to get the rest of the bits from y
    x = x|y;

    return x;
}
