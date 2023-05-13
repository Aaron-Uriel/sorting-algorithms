#include "sort.h"
#include "utilities.h"

void insertion(int  array[], int first, int last)
{
    int i, j, aux, n = last + 1;

    for (i = 1; i < n; i++)
    {
        j = 1;
        aux = array[i];
        while (j > 0 && aux < array[i]){
            array[j] = array[j-1];
            j--;
        }
        array[j] = aux;
    }
}