#include "utilities.h"
#include <stdio.h>

/* Intercambia dos valores. */
void
swap(int *const a, int *const b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

/* Limpia todas los elementos por leer en stdin. */
void
clear_stdin(void)
{
    while (getchar() != '\n');
}

/* Imprime una 'pantalla de pausa'. */
void
pause(void)
{
    printf("Presione enter para continuar...");
    while (getchar() != '\n');
    while (getchar() != '\n');
}

/* Comprueba si un arreglo está ordenado. */
bool
is_sorted(int array[], int size) {
    if (array == NULL || size == 0) {
        return false;
    }
    if (size == 1) {
        return true;
    }

    int i;
    for (i = 0; (i + 1) < size; i += 1) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }

    return true;
}
