#include <stdio.h>

int any(char s1[], char s2[]);

int main(void) 
{
    char str[] = "about that";
    char match[] = "there";
    int index;

    index = any(str, match);

    if (index >= 0) {
        printf("first match found at index %d in s1\n", index);
    }
    
    else {
        printf("no match found\n");
    }

    return 0;
}

/* this function returns the first location in s1 where any char from s2 occurs or -1 if s1 contains no chars from s2 */
int any(char s1[], char s2[])
{
    int i = 0; 
    int j = 0;

    while (s1[i] != '\0') {
        while (s2[j] != '\0') {
            if (s1[i] == s2[j++]) {
                return i;
            }
        }
        j = 0;
        ++i;
    }

    return -1;
}
