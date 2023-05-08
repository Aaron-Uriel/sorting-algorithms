#include "sort.h"
#include "utilities.h"

void insertion(int  array[], int first, int last)
{
    int i, j, aux, n = last;

    for (i = 1; i < n; i++)
    {
        j = 1;
        aux = array[i];
        while (j > 0 && aux < array[i]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = aux;
    }
}