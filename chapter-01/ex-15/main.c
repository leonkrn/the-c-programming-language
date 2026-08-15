#include <stdio.h>

/* print Fahrenheit-Celsius table
*   for fahr = 0, 20, ..., 300; floating point version with function for conversion */

#define LOWER 0
#define UPPER 300

float convert(float fahr);

int main()
{
    float fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + 20) {
        printf("%3.0f %6.1f\n", fahr, convert(fahr));
    }

    return 0;
}

float convert(float fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
}
