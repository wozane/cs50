/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n)
{
    if (n < 0)
    {
        printf("Needle must be a positive value\n");
        return 1;
    }

    int i;

    for (i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            return value;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */

void swap(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void sort(int values[], int n)
{

    int i, j;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if(values[j] > values[j + 1])
            {
                swap(values[j], values[j + 1]);
            }
        }
    }
    return;
}
