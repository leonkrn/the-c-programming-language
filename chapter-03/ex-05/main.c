#include <stdio.h>

#define MAXLEN 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char s[MAXLEN];

    itob(-401376, s, 16);
    printf("%s\n", s);

    return 0;
}

/* this function converts the iteger n into a base b character representation in the string s 
* (e.g. itob(n, s, 16) converts n to a hexadecimal integer in s) */
void itob(int n, char s[], int b)
{
    int i = 0;
    int sign = (n < 0) ? 1 : 0;
    int result;

    if (sign) {
        n = -n;
    }

    do {
        result = n % b;

        if (result > 9) {
            s[i++] = result - 10 + 'A';
        }

        else {
            s[i++] = result + '0';
        }
    } while ((n /= b) != 0);

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
