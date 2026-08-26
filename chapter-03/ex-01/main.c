#include <stdio.h>

int binsearch(int x, int v[], int n);

int binsearch(int x, int v[], int n)
{
    int low  = 0;
    int high = n - 1;
    int mid  = (high + low) / 2; // inizialize mid here to avoid undefined behaviour on first test case of the while loop

    while (low <= high && x != v[mid]) {
        if (x < v[mid]) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }

        mid = (high + low) / 2;
    }

    return (x == v[mid]) ? mid : -1;
}
