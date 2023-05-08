#include "sort.h"
#include "utilities.h"

void selection(int  array[], int first, int last)
{
    int menor, i = first, j, n = last;

    for (i; i < n-1; i++)
    {
        menor = i;
        for (j = i+1; i < n; j++)
        {
            if (array[j] < array[menor])
            {
                menor = j;
            }
            if (i != menor)
            {
                swap(array[i], array[menor]);
            }
        }
    }
}