#include <stdio.h>

/* This program replaces space characters with tab characters if possible, such that the output is visually identical */

#define MAXCOL  10
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

    int col_pos, last_blank;
    col_pos = 0;
    last_blank = -1;

    while (((c = getchar()) != EOF) && (c != '\n') && (i < MAXLEN - 2)) {

        // calculate column position before filling in char
        col_pos = get_col_pos(col_pos, c);

        // track the last blank character
        if ((c == ' ' || c == '\t') && (col_pos <= MAXCOL)) {
            last_blank = i;
        }

        if (col_pos >= MAXCOL) {

            if (last_blank != -1) {
                arr[last_blank] = '\n';

                if (last_blank == i) {
                    ++i;

                    // flush the buffer to not write the replaced space to the new line 
                    c = getchar();
                }

                // reset column position & last blank
                if (c == '\t') {
                    col_pos = 8;
                    last_blank = i;
                }

                else {
                    col_pos = i - last_blank;
                    last_blank = -1;
                }
            }

            else {
                arr[i] = '\n';
                ++i;

                // reset column_position
                if (c == '\t') {
                    col_pos = 8;
                }

                else {
                    col_pos = 1;
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
