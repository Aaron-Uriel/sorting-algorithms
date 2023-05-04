#include "sort.h"
#include "utilities.h"

void
quicksort(int32_t array[], int32_t first, int32_t last)
{
    int32_t i, j, pivot, pivot_index;

    /* Escogemos pivote. */
    pivot_index = (first + last) / 2;
    pivot = array[pivot_index];

    /* Realizamos intercambios de menores y mayores que pivote. */
    i = first;
    j = last;
    do {
        while (array[i] < pivot) { i += 1; }
        while (array[j] > pivot) { j -= 1; }

        if (i <= j) {
            swap(&array[i], &array[j]);
            i += 1;
            j -= 1;
        }
    } while (i <= j);

    /* Continuamos recursivamente del lado izquierdo y el derecho del pivote. */
    if (first < j) {
        quicksort(array, first, j);
    }
    if (i < last) {
        quicksort(array, i, last);
    }
}
