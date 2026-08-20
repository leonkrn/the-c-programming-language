/* This program determines the ranges of char, short, int and long variables, both signed and signed
* by printing appropriate values from standard headers and by direct computation as well as the ranges of the variables
* floating types */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    /* printing standard headers */
    printf("printing ranges of various types from standard header limits.h:\n\n");

    // char
    printf("range of char:\nsigned [%d;%d]\nunsigned [0;%u]\n", SCHAR_MIN, SCHAR_MAX, CHAR_MAX);
    printf("\n");

    // short
    printf("range of short:\nsigned [%d;%d]\nunsigned [0;%u]\n", SHRT_MIN, SHRT_MAX, USHRT_MAX);
    printf("\n");

    // int
    printf("range of int:\nsigned [%d;%d]\nunsigned [0;%u]\n", INT_MIN, INT_MAX, UINT_MAX);
    printf("\n");

    // long
    printf("range of long:\nsigned [%ld;%ld]\nunsigned [0;%lu]\n", LONG_MIN, LONG_MAX, ULONG_MAX);
    printf("\n");

    // float
    printf("range of float:\n[%f;%f]\n", FLT_MIN, FLT_MAX);
    printf("\n");

    // double
    printf("range of double:\n[%f;%f]\n", DBL_MIN, DBL_MAX);
    printf("\n");
 
    /* direct computation */
    printf("computing machine defined sizes per type:\n\n");

    // determine amount of bytes
    int x;

    // char
    char c;
    c = 1;
    x = 0;
    
    while (c != 0) {
        c = c * 2;
        ++x;
    }
    printf("char has size of %d byte(s) on this machine\n", x/8);

    // short
    short s;
    s = 1;
    x = 0;

    while (s != 0) {
        s = s * 2;
        ++x;
    }
    printf("short has size of %d byte(s) on this machine\n", x/8);

    // int
    int i;
    i = 1;
    x = 0;

    while (i != 0) {
        i = i * 2;
        ++x;
    }
    printf("int has size of %d byte(s) on this machine\n", x/8);

    // long
    long l;
    l = 1;
    x = 0;

    while (l != 0) {
        l = l * 2;
        ++x;
    }
    printf("long has size of %d byte(s) on this machine\n", x/8);

    return 0;
}

