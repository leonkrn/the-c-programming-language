#include <stdio.h>

/* This program replaces tab characters with the appropriate amount of space characters */

#define TABSTOP 8
#define MAXLEN  1000

int parse_line(char arr[]);


int main(void)
{
    char str[MAXLEN];

    while (parse_line(str) != -1) {
        printf("%s", str);
    }

    return 0;
}


int parse_line(char arr[])
{
    int c, i, j, tabs;
    i = 0;

    while (((c = getchar()) != EOF) && (c != '\n') && (i < MAXLEN - 2)) {

        if (c == '\t') {
            tabs = i + (TABSTOP - i % TABSTOP);

            for (j = 0; j < tabs; ++j) {
                arr[i] = ' ';
                ++i;
            }
        }
        
        else {
            arr[i] = c;
            ++i;
        }
    }


    if (i == MAXLEN - 2) {
        printf("array full - output will be truncated\n");

        // flush I/O buffer
        while (((c = getchar()) != EOF) && (c != '\n')) {
            ;
        }
    }

    arr[i] = '\n';
    ++i;

    arr[i] = '\0';

    if (c == EOF) {
        return -1;
    }

    else {        
        return i;
    }
}
