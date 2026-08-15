/* This program copies its input to its output, making tabs, backspaces and backslashes visible in an unambiuous way */

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }

        if (c == '\b') {
            putchar('\\');
            putchar('b');
        }

        if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }

        if (c != '\t') {
            if (c != '\b') {
                if (c != '\\') {
                    putchar(c);
                }
            }
        }
    }
}
