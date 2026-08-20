#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
    char str[]   = "hello, world";
    char match[] = "ol";

    printf("original string: %s\n", str);

    squeeze(str, match);
    printf("new string: %s\n", str);

    return 0;
}

/* this function deletes any character in s1 that matches a character in s2 */
void squeeze(char s1[], char s2[])
{
    int i;      // pointer at reading position
    int j;      // pointer at writing posiiton
    int k;      // pointer for s2
    int match;  // track matches (0 = no match; 1 = match)

    i = j = match = 0;

    while (s1[i] != '\0') {
        k = 0;
        while (s2[k] != '\0') {
            if (s1[i] == s2[k++]) {
                match = 1;      // there is a match
            }
        }

        if (!match) {
            s1[j++] = s1[i];
        }

        else {
            match = 0;
        }

        ++i;
    }

    s1[j] = '\0';
}
