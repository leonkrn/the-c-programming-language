#include <stdio.h>

/* This program removes all comments from a C-codefile */

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
    int c, i, j;
    i = 0;

    while (((c = getchar()) != EOF) && (c != '\n') && (i < MAXLEN - 2)) {

        // check for comments
        if (c == '/') {

            c = getchar();

            // remove singleline comment
            if (c == '/') {
                while (c != '\n') {
                    c = getchar();
                }
                break;
            }
            
            // remove multline comment
            else if (c == '*') {

                while (1) {
                    c = getchar();

                    if (c == '*') {
                        c = getchar();
                        
                        if (c == '/') {
                            c = getchar();
                            break;
                        }
                    }
                }
            }

            // there was no comment
            else {
                arr[i] = '/';
                ++i;
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


