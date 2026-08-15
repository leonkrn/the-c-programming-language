/* This program copies its input to its output, replacing each string of blanks by a single blank */

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar(c);

            while (c == ' ') {
                c = getchar();
            }
        }

        putchar(c);
    }
}
