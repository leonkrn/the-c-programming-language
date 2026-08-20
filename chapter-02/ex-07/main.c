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
    // create a value of all 1s
    unsigned char c;
    c = 255;    // maximum value of unsigned char (correpsonds to all bits set to 1)
    
    // leftshift c by n -> now the n rightmost bits are 0s, the rest are 1s
    c = c << n;

    // invert c -> now the n rightmost bits are 1s, the rest are 0s
    c = ~c;

    // leftshift c by p+1-n -> now the n bits set to 1 in c, are ligned up with the bits in x that should be inverted
    c = c << (p+1-n);

    // bitwise XOR x with c inverts the corresponding bits in c, leaving the rest unchanged
    x = x^c;

    return x;
}


