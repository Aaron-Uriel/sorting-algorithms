#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>

#include "sort.h"
#include "utilities.h"

/* Constantes. */
#define OPTS_LIMIT 4      /* Cantidad de opciones en el menú */
                          /* principal.                      */
#define SORT_FUNC_LIMIT 5 /* Cantidad de algoritmos de       */
                          /* ordenamiento.                   */

/* Prototipos de funciones. */
void fill_array(void);
void print_array(void);
void sorting_menu(void);
void exit_program(void);

/* Globales. */
int *array; /* El arreglo que usa el programa es global. */
unsigned int array_size;

void (*menu_options[OPTS_LIMIT])(void) = { fill_array, print_array,
    sorting_menu, exit_program};

void (*sorting_functions[SORT_FUNC_LIMIT])(int [], int, int) = { 
    quicksort, radixsort, exchange, selection, insertion,
};

/* El menú principal del programa. */
void main_menu() {
    unsigned int selected_opt, inputs;
    do {
        printf("Algoritmos de ordenamiento.\n"
                "Opciones del arreglo de prueba:\n");
        printf("1.- Llenar.\n"
               "2.- Mostrar.\n"
               "3.- Ordenar.\n"
               "4.- Salir.\n");

        printf("Opción elegida: ");
        inputs = scanf("%d", &selected_opt);
        if (inputs != 1 || selected_opt > OPTS_LIMIT) {
            printf("Opción incorrecta...\n");
            clear_stdin();
            pause();
            continue;
        }

        menu_options[selected_opt - 1]();
        pause();
    } while (selected_opt != OPTS_LIMIT);
}

/*
 * Se encarga de llenar el arreglo usado en el programa con números aleatorios.
 * El arreglo es creado en la memoria dinámica, si ya se creó un arreglo con
 * anterioridad, este se libera y se vuelve a crear uno nuevo.
 */
void
fill_array()
{
    /* Si ya existe un arreglo creado, lo borramos. */
    if (array != NULL) {
        free(array);
    }

    unsigned int inputs, size;
    do {
        printf("¿De qué tamaño crear el arreglo?.\n"
               "Tamaño: ");
        inputs = scanf("%u", &size);
        if (inputs != 1) {
            printf("Tamaño no válido...");
            clear_stdin();
            pause();
            continue;
        }
    } while(inputs != 1);

    clock_t initial_time, final_time;
    double delta_time;
    initial_time = clock();
    array = malloc(size * sizeof(*array));
    array_size = size;
    for (int i = 0; i < size; i += 1) {
        array[i] = rand() % 512;
    }
    final_time = clock();
    delta_time = (double)(final_time - initial_time) / CLOCKS_PER_SEC;
    printf("Se creó un arreglo de %d elementos en %g milisegundos\n",
           size, delta_time * 1000);
}

/* Imprime el arreglo usado en el programa. */
void
print_array(void)
{
    printf("Arreglo.\n");
    printf("Elementos: ");
    for (int i = 0; i < array_size; i += 1) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("El arreglo está: %s\n", 
           (is_sorted(array, array_size))?"ordenado": "no ordenado");
}

/* Maneja el menú para escoger el algoritmo de ordenamiento. */
void 
sorting_menu(void)
{
    unsigned int selected_opt, inputs;
    do {
        printf("Ordenar arreglo.\n"
                "¿Qué algoritmo de ordenamiento desea ejecutar?:\n");
        printf("1.- Quicksort.\n"
               "2.- Radixsort.\n"
               "3.- Intercambio.\n"
               "4.- Selección.\n"
               "5.- Inserción.\n");

        printf("Opción elegida: ");
        inputs = scanf("%d", &selected_opt);
        if (inputs != 1 || selected_opt > SORT_FUNC_LIMIT) {
            printf("Opción incorrecta...\n");
            clear_stdin();
            pause();
            continue;
        }
    } while (selected_opt > SORT_FUNC_LIMIT);

    clock_t initial_time, final_time;
    double delta_time;
    initial_time = clock();
    sorting_functions[selected_opt - 1](array, 0, array_size - 1);
    final_time = clock();
    delta_time = (double)(final_time - initial_time) / CLOCKS_PER_SEC;

    printf("Arreglo de %d elementos ordenado en %g milisegundos\n",
            array_size,
            delta_time * 1000);
}

/* Termina el programa de forma normal. */
void
exit_program(void)
{
    exit(0);
}

int
main(void)
{
    /* 
     * Comprobar que las palabras con acentos se vean bien en Windows con esta
     * función.
     */
    setlocale(LC_ALL, "");
    srand(time(NULL));

    main_menu();

    return 0;
}
