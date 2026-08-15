/* This program prints a vertical histogram of the length of the words received by its input */

#include <stdio.h>

#define MAXLEN 10
#define OUT 0
#define IN  1

int main()
{
    int wordlen[MAXLEN];
    int i;

    /* initialize the array */
    for (i = 0; i < MAXLEN; ++i) {
        wordlen[i] = 0;
    }

    int c, len, state;

    state = OUT;
    i = len = 0;

    /* fill the array */
    while (((c = getchar()) != EOF) && (i < MAXLEN)) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }

        else if (state == OUT) {
            state = IN;
        }

        if (state == IN) {
            ++len;
        }

        else if (state == OUT) {
            wordlen[i] = len;
            ++i;
            len = 0;
        }
    }

    printf("\n");

    /* find max in the array */
    int maxval;
    maxval = 0;

    for (i = 0; i < MAXLEN; ++i) {
        if (maxval < wordlen[i]) {
            maxval = wordlen[i];
        }
    }

    /* print the histogram */
    int j;
    for (j = maxval; j > 0; --j) {
        for (i = 0; i < MAXLEN; ++i) {
            if (wordlen[i] >= j) {
                printf("*\t");
            }

            else {
                printf(" \t");
            }
        }
        printf("\n");
    }
    printf("\n");

    /* print footer */
    for (i = 0; i < MAXLEN; ++i) {
        printf("%d\t", i);
    }
    printf("\n");
}
