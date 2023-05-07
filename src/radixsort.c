#include <stdio.h>
#include <string.h>
#include <math.h>

#include "sort.h"

#define DIGITS 10 /* Cantidad de dígitos en un sistema decimal. */

int get_max(int array[], int size) {
    int max_number = 0;
    for (int i = 0; i < size; i += 1) {
        if (max_number < array[i]) {
            max_number = array[i];
        }
    }

    return max_number;
}

void radixsort(int array[], int first, int last) {
    const int max = get_max(array, last + 1);
    int buckets[DIGITS][last - first];
    int buckets_count[DIGITS];

    int digit, i;
    for (int digit_weight = 1; digit_weight <= max; digit_weight *= DIGITS) {
        for (i = 0; i < DIGITS ; i += 1) {
            buckets_count[i] = 0;
        }

        for (i = first; i <= last; i += 1) {
            digit = (array[i] / digit_weight) % DIGITS;
            buckets[digit][buckets_count[digit]] = array[i];
            buckets_count[digit] += 1;
        }

        i = 0;
        for (int j = 0; j < DIGITS; j += 1) {
            for (int k = 0; k < buckets_count[j]; k += 1) {
                array[i] = buckets[j][k];
                i += 1;
            }
        }
    }
}
