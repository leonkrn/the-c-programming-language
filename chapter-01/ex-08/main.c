/* This program counts blanks, tabs and newlines */

#include <stdio.h>

int main()
{
    int c;
    long nb, nt, nl;

    nb = nt = nl = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            ++nb;
        }

        if (c == '\t') {
            ++nt;
        }

        if (c == '\n') {
            ++nl;
        }
    }

    printf("%ld blanks, %ld tabs and %ld newlines counted\n", nb, nt, nl);
}
