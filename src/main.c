#include <stdio.h>
#include <time.h>

#include <assert.h>

#include "sort.h"

void (*sorting_functions[])(int [], int, int) = { 
    quicksort,
};

int
main(void)
{
    /* Prueba rápida de que todo funciona bien. */
    int32_t xd[4] = {10, 15, 1, 35};    
    sorting_functions[0](xd, 0, 3);
    assert(xd[0] == 1 && xd[2] == 15);

    return 0;
}
