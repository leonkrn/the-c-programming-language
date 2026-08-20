#include <stdio.h>

int lower(int c);

int main(void)
{
    printf("H lowercase is %c\n", lower('H'));
    printf("Y lowercase is %c\n", lower('Y'));
    return 0;
}

/* converts c to lowercase using a ternary: ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
