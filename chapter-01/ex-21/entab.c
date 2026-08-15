#include <stdio.h>

/* This program replaces space characters with tab characters if possible, such that the output is visually identical */

#define TABSTOP 8
#define MAXLEN  1000

int parse_line(char arr[]);
int get_col_pos(int col_pos, int c);


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
    int c, i, j;
    i = 0;

    int col_pos, entab, spaces;
    col_pos = spaces = 0;

    while (((c = getchar()) != EOF) && (c != '\n') && (i < MAXLEN - 2)) {

        // calculate column position before filling in char
        col_pos = get_col_pos(col_pos, c);

        // entab signals whether a '\t' char can be placed to replace spaces
        entab = spaces = 0;

        // check for blanks
        while (c == ' ') {
            ++spaces;

            if (col_pos % TABSTOP == 0) {
                entab = 1;

                c = getchar();
                col_pos = get_col_pos(col_pos, c);

                break;
            }

            c = getchar();
            col_pos = get_col_pos(col_pos, c);
        }

        if (spaces != 0) {

            if (entab == 1) {
                entab = 0;

                arr[i] = '\t';
                ++i;
            }
            
            else {

                for (j = 0; j < spaces; ++j) {
                    arr[i] = ' ';
                    ++i;
                }
            }

        }

        arr[i] = c;
        ++i;
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


int get_col_pos(int col_pos, int c) 
{
    if (c == '\t') {
        // this formula sets the columns position to the position of the next multiple of TABSTOP
        col_pos = col_pos + (TABSTOP - col_pos % TABSTOP); 
    }

    else {
        ++col_pos;
    }

    return col_pos;
}
