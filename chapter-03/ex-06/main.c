#include <stdio.h>

#define MAXLEN 1000

void itoa(int n, char s[], int p);
void reverse(char s[]);

int main(void)
{
    char s[MAXLEN];

    itoa(-502, s, 7);
    printf("%s\n", s);

    return 0;
}

/* this version of itoa takes a third argument for minimum field width, which adds padding on the lefthand side of the string if necessary */
void itoa(int n, char s[], int p)
{
    int sign = (n < 0) ? 1 : 0;

    if (sign) {
        n = -n;
    }

    int i = 0;

    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) != 0);

    if (sign) {
        s[i++] = '-';
    }

    while (i < p) {
        s[i++] = ' ';
    }

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    int i = 0;
    int j = 0;

    // get length
    while (s[j+1] != '\0') {
        ++j;
    }
    int temp;

    while (i <= j) {
        temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}
