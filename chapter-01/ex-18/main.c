/* This program removes trailing blanks and tabs from each line of input and deletes entirely blank lines */

#include <stdio.h>

#define MAXLEN  1000

int my_getline(char line[]);
int is_blank(char line[]);
int remove_trailing(char line[], int i);

int main()
{
    char linbuf[MAXLEN];

    while(my_getline(linbuf) != 0) {
        if (!is_blank(linbuf)) {        /* dont print blank lines */
            printf("%s", linbuf);
        }
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

    /* if the last written character is whitespace, there is trailing whitespace or the line is blank */
    if (line[i-1] == ' ' || line[i-1] == '\t') {
        i = remove_trailing(line, i);
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

int is_blank(char line[]) {
    int i, blank;

    blank = 1;

    for (i = 0; line[i] != '\0'; ++i) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
            blank = 0;
            break;
        }
    }

    return blank;
}

int remove_trailing(char line[], int i)
{
    --i;        /* go back to the last char */

    while (line[i] == ' ' || line[i] == '\t') {
        --i;
    }

    ++i;        /* move one position forward to not overwrite the last char with '\n' or '\0' back in my_getline */

    return i;
}
