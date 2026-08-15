/* This program prints all input lines that are longer than 80 characters */

#include <stdio.h>

#define MAXLEN  1000
#define LIMIT   80

int my_getline(char line[]);
int copy(char from[], char to[], int j);

int main()
{
    char linbuf[MAXLEN];    /* gets the current line input */
    char lines[MAXLEN];     /* holds all the lines longer than 80 chars */

    int len;                /* stores the length of the current line */
    len = 0;

    int j;                  /* stores the index to keep adding to the string with the longest lines */
    j = 0;

    while((len = my_getline(linbuf)) != 0) {
        if (len > LIMIT) {
            j = copy(linbuf, lines, j);
        }
    }

    printf("%s", lines);

    return 0;
}

int my_getline(char line[])
{
    int c, i;
    i = 0;

    while ((c = getchar()) != EOF && c != '\n' && i < MAXLEN-1) {
        line[i] = c;
        ++i;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

int copy(char from[], char to[], int j)
{
    int i;
    i = 0;

    while ((to[j] = from[i]) != '\0') {
        ++i;
        ++j;
    }

    to[j] = '\0';
    return j;
}
