#include <stdio.h>

int main()
{
    // EOF (ctrl+d) prints 0, any other char prints 1
    printf("%d\n", getchar() != EOF);
}
