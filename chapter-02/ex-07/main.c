#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
    printf("%u\n", invert(220, 5, 2));
    return 0;
}

/* this function returns x with the n bits that begin at position p inverted, leaving the other bits unchanged 
 * (assuming the rightmost bit to be at position 0, and the leftmost bit at the highest position) */
unsigned invert(unsigned x, int p, int n)
{
    // create a value of all 1s with the n rightmost bits set to 0s
    unsigned z;
    z = ~0 << n;

    // invert z -> now the n rightmost bits are 1s, the rest are 0s
    z = ~z;

    // leftshift c by p+1-n -> now the n bits set to 1 in z, are ligned up with the bits in x that should be inverted
    z = z << (p+1-n);

    // bitwise XOR x with z inverts the corresponding bits in z, leaving the rest unchanged
    x = x^z;

    return x;
}


