#include <stdio.h>

/* This function converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value */
int htoi(char s[]);

int main(void)
{
    printf("Testing function htoi:\n%d\n%d\n", htoi("0x4b1F"), htoi("48a"));
    return 0;
}

int htoi(char s[])
{
    int i;
    i = 0;

    // check for optional 0x or 0X - if its exists -> skip behind it
    if (s[1] == 'x' || s[1] == 'X') {
        i = 2;
    }

    int n;
    n = 0;

    for ( ; s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'F' || s[i] >= 'a' && s[i] <= 'f'; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = n * 16 + (s[i] - '0');
        }

        else if (s[i] >= 'A' && s[i] <= 'F') {
            n = n * 16 + (s[i] - 'A' + 10);
        }

        else {
            n = n * 16 + (s[i] - 'a' + 10);
        }
    }

    return n;
}
