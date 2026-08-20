#include <stdio.h>

int main(void)
{
    int i, c, lim;
    lim = 1000;
    char str[lim];

    /* original loop version using logical operators */
    for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        str[i] = c;
    }

    if (c == '\n') {
        str[i] = c;
        ++i;
    }

    str[i] = '\0';

    printf("%s", str);

    /* equivalent loop without using && or || (purposefully written without break statements, as they are not introduced at that point in the book)*/
    i = 0;
    int j;
    j = 1;

    while (j) {
        if (i < lim-1) {
            c = getchar();
            if (c != '\n') {
                if (c != EOF) {
                    str[i] = c;
                    ++i;
                }

                else {
                    j = 0;
                }
            }

            else {
                j = 0;
            }
        }

        else {
            j = 0;
        }
    }

    if (c == '\n') {
        str[i] = c;
        ++i;
    }

    str[i] = '\0';

    printf("%s", str);
    return 0;
}
