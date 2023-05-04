#include "utilities.h"

/* Intercambia dos valores. */
void
swap(int32_t *const a, int32_t *const b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
