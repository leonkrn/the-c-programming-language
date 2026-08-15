/* This program reverses its input a line at a time using the function reverse(s) that reverses the character string s */

#include <stdio.h>

#define MAXLEN  1000

int my_getline(char line[]);
void reverse(char line[]);

int main()
{
    char linbuf[MAXLEN];

    while(my_getline(linbuf) != 0) {
        reverse(linbuf);
        printf("%s", linbuf);
    }

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

void reverse(char line[])
{
    char reverse[MAXLEN];       /* array to copy the reverse stirng into */ 
    int i, j;
    i = j = 0;

    while ((line[i] != '\0') && (line[i] != '\n')) {
        ++i;
    }

    --i;        /* dont copy the '\n' or '\0' char */

    while ((reverse[j] = line[i]) && i > 0) {
        --i;
        ++j;
    }

    ++j;
    reverse[j] = '\n';
    ++j;
    reverse[j] = '\0';

    i = j = 0;
    /* copy the reverse string back into the original string to modify it in place */
    while ((line[i] = reverse[j]) != '\0') {
        ++i;
        ++j;
    }

    line[i] = '\0';
}

/*
* program outline
* reverse it
* print it
*/
