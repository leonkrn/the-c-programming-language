/* This program prints a histogram of the frequency of different characters in its input 
 * it divides by numbers (0-9), letters and other chars (blanks, symbols, escape sequences, ...) */

#include <stdio.h>

#define CATEGORIES  12

int main()
{
    int freq[CATEGORIES];
    int i;

    /* initialize the array */
    for (i = 0; i < CATEGORIES; ++i) {
        freq[i] = 0;
    }

    int c;

    /* fill the array */
    while ((c = getchar()) != EOF) {
        if (('0' <= c) && (c <= '9')) {
            ++freq[c-'0'];
        }

        else if ((('A' <= c) && (c <= 'Z')) || (('a' <= c) && (c <= 'z'))) {
            ++freq[10];
        }

        else {
            ++freq[11];
        }
    }

    /* find the maximum value in the array */
    int maxval;
    maxval = 0;

    for (i = 0; i < CATEGORIES; ++i) {
        if (maxval < freq[i]) {
            maxval = freq[i];
        }
    }

    int j;

    /* print the histogram */
    for (i = maxval; i > 0; --i) {
        for (j = 0; j < CATEGORIES; ++j) {
            if (freq[j] >= i) {
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
    for (i = 0; i < 10; ++i) {
        printf("%d\t", i);
    }

    printf("ABC\tmisc\n");
}

