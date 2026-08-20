#include <stdio.h>
#include <limits.h>

unsigned char rightrot(unsigned char x, int n);

int main(void)
{
    printf("%u\n", rightrot(201, 5));

    return 0;
}

/* this function returns x, rotated to the right by n bit positions */
unsigned char rightrot(unsigned char x, int n)
{
    // create a bitsequence of all 1s
    unsigned char c;
    c = 255;

    // leftshift c by n -> now the n rightmost bits in c are 0s, all other bits are 1s
    c = c << n;

    // invert c -> now the n rightmost bits in c are 1s, all other bits are 0s
    c = ~c;

    // bitwise and c with x to copy the n rightmost bits of x into c 
    // these are the bits that will disappear on the left on rotation by n bits, and reappear on the right
    c = c & x;

    // leftshift c such that the n rightmost bits become the n leftmost bits
    c = c << CHAR_BIT- n;

    // rightshift x by n bits to rotate
    x = x >> n;

    // bitwise OR c with x to write the n leftmost bits into x;
    x = x|c;

    return x;
}
