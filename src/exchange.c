#include "sort.h"
#include "utilities.h"

void exchange(int  array[], int first, int last)
{
    int i = first, j, n = last;

    for (i; i <= n-2; i++)
    {
        for (j = i+1; j <= n-1; j++)
        {
            if (array[i] > array[j])
            {
                swap(&array[i], &array[j]);
            }
        } 
    }
}
