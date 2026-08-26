#include <stdio.h>

#define MAXLEN  1000

void escape(char s[], char t[]);
void escape_rev(char s[], char t[]);

int main(void)
{
    char original[MAXLEN] = "Hello\tworld\nhow are you?\n";
    char modified[MAXLEN];

    escape(modified, original);

    printf("string before: %s\n", original);
    printf("string after: %s\n", modified);
    printf("\n");

    char original_rev[MAXLEN] = "Hello\\tworld\\nhow are you?\\n";
    char modified_rev[MAXLEN];

    escape_rev(modified_rev, original_rev);

    printf("string before: %s\n", original_rev);
    printf("string after: %s\n",modified_rev);

    return 0;
}

/* this function converts characters like newline and tab into visible escape sequences 
 * like \n and \t as it copies the string t to s, using a switch */
void escape(char s[], char t[])
{
    int i = 0;
    int j = 0;

    while (t[i] != '\0' && j < MAXLEN - 1) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                ++i;
                break;

            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                ++i;
                break;

            default:
                s[j++] = t[i++];
                break;
        }
    }
}

/* this function converts visible escape sequences like \n and \t into their corresponding
charracter like a newline or a tab as it copies the string t to s, using a switch */
void escape_rev(char s[], char t[])
{
    int i = 0;
    int j = 0;
    
    while (t[i] != '\0' && i < MAXLEN - 1) {
        switch (t[i]) {
            case '\\':
                ++i;
                // needs a nested switch here in order to evaluate the type of escape sequence
                switch (t[i]) {
                    case 'n':
                        s[j++] = '\n';
                        ++i;
                        break;

                    case 't':
                        s[j++] = '\t';
                        ++i;
                        break;

                    default:
                        s[j++] = '\\';
                        s[j++] = t[i++];
                        break;
                }
                break;

            default:
                s[j++] = t[i++];
                break;
        }
    }
}

