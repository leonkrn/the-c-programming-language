#include <stdio.h>

#define MAXLEN 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    char s[MAXLEN];

    itoa(-2147483648, s); // my machine uses 32 bit integers, so -2147483648 is the largest negative number for a signed int
    printf("%s\n", s);

    return 0;
}

void itoa(int n, char s[])
{
    int i = 0;
    int sign = (n < 0) ? 1 : 0;
    int temp = n;

    if (sign) {
        n = -n;
    }

    // check for overflow -> if that occurs we need to cast to unsigned to handle the larger value and flip the sign again
    if (n < 0 && n == temp) {
        do {
            s[i++] = (unsigned int) -n % 10 + '0';
        } while ((n /= 10) != 0);
    }

    else {
        do {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) != 0);
    }

    if (sign) {
        s[i++] = '-';
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
