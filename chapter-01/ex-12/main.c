/* This program prints its input, one word per line */
#include <stdio.h>

#define OUT 0
#define IN  1

int main()
{
    int c, state;
    state = OUT;

    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }

        else if (state == OUT) {
            state = IN;
        }

        if (state == IN) {
            putchar(c);
        }

        else {
            putchar('\n');
        }
    }
}
