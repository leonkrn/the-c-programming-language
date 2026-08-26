#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

void expand(char s1[], char s2[]);

int main(void)
{
    char buf[MAXLEN];

    expand("a-z", buf);
    printf("%s\n", buf);

    expand("H-X", buf);
    printf("%s\n", buf);

    expand("4-9", buf);
    printf("%s\n", buf);

    // edge cases:
    expand("-a-z", buf);
    printf("%s\n", buf);

    expand("a-b-c", buf);   // fix this
    printf("%s\n", buf);

    expand("a-z0-9", buf);
    printf("%s\n", buf);

    expand("a-c-d-h", buf);
    printf("%s\n", buf);

    return 0;
}

/* this function expands shorthand notations like a-z in s1 to the complete sequence like abcdefg...xyz in s2 */
void expand(char s1[], char s2[])
{
    int i = 0;

    // ignore whitespace
    while (isspace(s1[i])) {
        ++i;
    }

    int j = 0;

    // save leading hyphen
    int leading_hyphen = (s1[i] == '-') ? 1 : 0;

    if (leading_hyphen) {
        s2[j++] = '-';
        ++i;
    }

    int c;

    int start;
    int end;

    while (s1[i] != '\0') {

        // extract start and end of the sequence
        start = s1[i++];
        
        // the end is always the char that is not followed by a hyphen
        while (s1[i] == '-' || s1[i+1] == '-') {
            ++i;
        }

        end = s1[i++];

        // add full sequence to the string
        for (c = start; c <= end; ++c, ++j) {
            s2[j] = c;
        }
    }

    s2[j] = '\0';
}

// thoughts: when a char that is not a hyphen, is the next char, the current char is the ending char of the sequence
